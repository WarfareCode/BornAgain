// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/mainwindow/projectdocument.cpp
//! @brief     Implements class ProjectDocument
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "projectdocument.h"
#include "ApplicationModels.h"
#include "DocumentModel.h"
#include "MaterialModel.h"
#include "InstrumentModel.h"
#include "JobQueueData.h"
#include "JobModel.h"
#include "JobItem.h"
#include "IntensityDataItem.h"
#include "SampleModel.h"
#include "IntensityDataIOFactory.h"
#include "BAVersion.h"
#include "WarningMessageService.h"
#include "MessageContainer.h"
#include "GUIHelpers.h"
#include "JobResultsPresenter.h"
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QDir>
#include <QModelIndex>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDebug>

namespace {
const QString OPEN_FILE_ERROR = "OPEN_FILE_ERROR";
const QString EXCEPTION_THROW = "EXCEPTION_THROW";
const QString XML_FORMAT_ERROR = "XML_FORMAT_ERROR";
const QString minimal_supported_version = "1.5.0";
}

ProjectDocument::ProjectDocument()
    : m_applicationModels(0)
    , m_modified(false), m_documentStatus(STATUS_OK), m_messageService(0)
{
    setObjectName("ProjectDocument");
}

ProjectDocument::ProjectDocument(const QString &projectFileName)
    : m_applicationModels(0)
    , m_modified(false), m_documentStatus(STATUS_OK), m_messageService(0)
{
    setObjectName("ProjectDocument");
    setProjectFileName(projectFileName);
}

QString ProjectDocument::getProjectName() const
{
    return m_project_name;
}

void ProjectDocument::setProjectName(const QString &text)
{
    m_project_name = text;
    emit modified();
}

QString ProjectDocument::getProjectDir() const
{
    return m_project_dir;
}

void ProjectDocument::setProjectDir(const QString &text)
{
    m_project_dir = text;
}

QString ProjectDocument::getProjectFileName() const
{
    QString result = getProjectDir() + "/" + getProjectName() + getProjectFileExtension();
    return result;
}

void ProjectDocument::setProjectFileName(const QString &projectFileName)
{
    QFileInfo info(projectFileName);
    setProjectName(info.baseName());
    setProjectDir(info.path());
}

QString ProjectDocument::getProjectFileExtension()
{
    return QString(".pro");
}

void ProjectDocument::setApplicationModels(ApplicationModels *applicationModels)
{
    if (applicationModels != m_applicationModels) {
        disconnectModels();
        m_applicationModels = applicationModels;
        connectModels();
    }
}

bool ProjectDocument::save()
{
    reviseOutputData();
    QString filename = getProjectFileName();

    QFile file(filename);
    if (!file.open(QFile::ReadWrite | QIODevice::Truncate | QFile::Text)) {
        qDebug() << "ProjectDocument::save() -> Error! Can't save file";
        return false;
    }
    writeTo(&file);
    file.close();
    m_applicationModels->saveNonXMLData(getProjectDir());

    m_modified = false;
    emit modified();

    return true;
}

bool ProjectDocument::load(const QString &project_file_name)
{
    m_documentStatus = STATUS_OK;

    setProjectFileName(project_file_name);

    QFile file(getProjectFileName());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        m_messageService->send_message(this, OPEN_FILE_ERROR, file.errorString());
        m_documentStatus = EDocumentStatus(m_documentStatus|STATUS_FAILED);
        return false;
    }

    try {
        // loading project file
        disconnectModels();
        readFrom(&file);
        file.close();
        m_applicationModels->loadNonXMLData(getProjectDir());
        connectModels();

    } catch (const std::exception &ex) {
        m_documentStatus = EDocumentStatus(m_documentStatus | STATUS_FAILED);
        m_messageService->send_message(this, EXCEPTION_THROW, QString(ex.what()));
        return false;
    }

    return true;
}

bool ProjectDocument::hasValidNameAndPath()
{
    return (!m_project_name.isEmpty() && !m_project_dir.isEmpty());
}

bool ProjectDocument::isModified()
{
    return m_modified;
}

void ProjectDocument::setMessageService(WarningMessageService *messageService)
{
    m_messageService = messageService;
}

ProjectDocument::EDocumentStatus ProjectDocument::getDocumentStatus() const
{
    return m_documentStatus;
}

bool ProjectDocument::isReady() const
{
    return (m_documentStatus == STATUS_OK);
}

bool ProjectDocument::hasWarnings() const
{
    return (m_documentStatus & STATUS_WARNING);
}

bool ProjectDocument::hasErrors() const
{
    return (m_documentStatus & STATUS_FAILED);
}

QString ProjectDocument::getDocumentVersion() const
{
    QString result(m_currentVersion);
    if(result.isEmpty()) result = GUIHelpers::getBornAgainVersionString();
    return result;
}

void ProjectDocument::onModelChanged()
{
    m_modified = true;
    emit modified();
}

void ProjectDocument::readFrom(QIODevice *device)
{
    QXmlStreamReader reader(device);

    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.isStartElement()) {
            if (reader.name() == ProjectDocumentXML::BornAgainTag) {
                m_currentVersion = reader.attributes()
                                            .value(ProjectDocumentXML::BornAgainVersionAttribute)
                                            .toString();
                if(!GUIHelpers::isVersionMatchMinimal(m_currentVersion, minimal_supported_version)) {
                    m_documentStatus = EDocumentStatus(m_documentStatus | STATUS_FAILED);
                    QString message = QString("Can't open document version '%1', "
                        "minimal supported version '%2'").arg(m_currentVersion)
                            .arg(minimal_supported_version);
                    m_messageService->send_message(this, OPEN_FILE_ERROR, message);
                    return;
                }

            }

            else if (reader.name() == ProjectDocumentXML::InfoTag) {
                //
            } else {
                m_applicationModels->readFrom(&reader, m_messageService);
                if(m_messageService->hasWarnings(m_applicationModels)) {
                    m_documentStatus = EDocumentStatus(m_documentStatus|STATUS_WARNING);
                }
            }

        }
    }

    if (reader.hasError()) {
        m_documentStatus = EDocumentStatus(m_documentStatus | STATUS_FAILED);
        m_messageService->send_message(this, XML_FORMAT_ERROR, reader.errorString());
        return;
    }

    m_applicationModels->jobModel()->modelLoaded();
}

void ProjectDocument::writeTo(QIODevice *device)
{
    QXmlStreamWriter writer(device);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("BornAgain");
    QString version_string = GUIHelpers::getBornAgainVersionString();
    writer.writeAttribute("Version", version_string);

    writer.writeStartElement(ProjectDocumentXML::InfoTag);
    writer.writeAttribute(ProjectDocumentXML::InfoNameAttribute, getProjectName());
    writer.writeEndElement(); // InfoTag

    m_applicationModels->writeTo(&writer);

    writer.writeEndElement(); // BornAgain tag
    writer.writeEndDocument();
}

//! Adjusts name of IntensityData item to possibly changed name of JobItem. Take care of old
//! *.int files in project directory by removing them.
void ProjectDocument::reviseOutputData()
{
    JobModel *jobModel = m_applicationModels->jobModel();
    Q_ASSERT(jobModel);

    for (int i = 0; i < jobModel->rowCount(QModelIndex()); ++i) {
        JobItem *jobItem = jobModel->getJobItemForIndex(jobModel->index(i, 0, QModelIndex()));
        IntensityDataItem *dataItem = jobItem->getIntensityDataItem();
        if (dataItem) {
            // handling case when user has renamed jobItem and we have to clean previous
            // *.int file
            QString filename = getProjectDir() + "/" + dataItem->itemName();
            QFile fin(filename);
            if (fin.exists()) {
                fin.remove();
            }

            // making new name of *.int file from jobItem name
            dataItem->setNameFromProposed(jobItem->itemName());
        }
    }
}

void ProjectDocument::disconnectModels()
{
    if(m_applicationModels) {
        disconnect(m_applicationModels, SIGNAL(modelChanged()), this,
                   SLOT(onModelChanged()));
    }
}

void ProjectDocument::connectModels()
{
    if(m_applicationModels) {
        connect(m_applicationModels, SIGNAL(modelChanged()), this,
                   SLOT(onModelChanged()), Qt::UniqueConnection);
    }
}
