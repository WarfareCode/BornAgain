// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/JobItem.cpp
//! @brief     Implements class JobItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "JobItem.h"
#include "ComboProperty.h"
#include "IntensityDataItem.h"
#include "SampleModel.h"
#include "InstrumentModel.h"
#include "MultiLayerItem.h"
#include "InstrumentItem.h"
#include "JobResultsPresenter.h"
#include "SimulationOptionsItem.h"
#include "GUIHelpers.h"
#include <QDebug>

const QString JobItem::P_IDENTIFIER = "Identifier";
const QString JobItem::P_SAMPLE_NAME = "Sample";
const QString JobItem::P_INSTRUMENT_NAME = "Instrument";
const QString JobItem::P_WITH_FITTING = "With Fitting";
const QString JobItem::P_STATUS = "Status";
const QString JobItem::P_BEGIN_TIME = "Begin Time";
const QString JobItem::P_END_TIME = "End Time";
const QString JobItem::P_COMMENTS = "Comments";
const QString JobItem::P_PROGRESS = "Progress";
const QString JobItem::T_SAMPLE = "Sample Tag";
const QString JobItem::T_INSTRUMENT = "Instrument Tag";
const QString JobItem::T_OUTPUT = "Output Tag";
const QString JobItem::T_REALDATA = "Real Data Tag";
const QString JobItem::T_PARAMETER_TREE = "Parameter Tree";
const QString JobItem::T_SIMULATION_OPTIONS = "Simulation Options";

JobItem::JobItem()
    : SessionItem(Constants::JobItemType)
{
    setItemName(Constants::JobItemType);
    addProperty(P_IDENTIFIER, QString())->setVisible(false);
    addProperty(P_SAMPLE_NAME, QString())->setEditable(false);
    addProperty(P_INSTRUMENT_NAME, QString())->setEditable(false);
    addProperty(P_WITH_FITTING, false)->setVisible(false);

    ComboProperty status;
    status << Constants::STATUS_IDLE << Constants::STATUS_RUNNING << Constants::STATUS_COMPLETED
           << Constants::STATUS_CANCELED << Constants::STATUS_FAILED;
    addProperty(P_STATUS, status.getVariant())->setEditable(false);

    addProperty(P_BEGIN_TIME, QString())->setEditable(false);
    addProperty(P_END_TIME, QString())->setEditable(false);
    addProperty(P_COMMENTS, QString())->setVisible(false);
    addProperty(P_PROGRESS, 0)->setVisible(false);

    registerTag(T_SAMPLE, 1, 1, QStringList() << Constants::MultiLayerType);
    registerTag(T_INSTRUMENT, 1, 1, QStringList() << Constants::InstrumentType);
    registerTag(T_OUTPUT, 1, 1, QStringList() << Constants::IntensityDataType);
    registerTag(T_REALDATA, 1, 1, QStringList() << Constants::IntensityDataType);
    registerTag(T_PARAMETER_TREE, 0, -1, QStringList() << Constants::ParameterLabelType
                << Constants::ParameterType);
    registerTag(T_SIMULATION_OPTIONS, 1, 1, QStringList() << Constants::SimulationOptionsType);


    mapper()->setOnChildPropertyChange(
                [this](SessionItem* item, const QString &name)
    {
        if (item->modelType() == Constants::IntensityDataType
            && name == IntensityDataItem::P_AXES_UNITS) {
            auto intensityItem = dynamic_cast<IntensityDataItem *>(item);
            JobResultsPresenter::updateDataAxes(intensityItem, getInstrumentItem());
            qDebug() << "QQQQ" << item->modelType() << name;

        }
    });
}

JobItem::~JobItem()
{
}

QString JobItem::getIdentifier() const
{
    return getItemValue(P_IDENTIFIER).toString();
}

void JobItem::setIdentifier(const QString &identifier)
{
    setItemValue(JobItem::P_IDENTIFIER, identifier);
}

IntensityDataItem *JobItem::getIntensityDataItem()
{
    return dynamic_cast<IntensityDataItem*>(getItem(T_OUTPUT));
}

QString JobItem::getStatus() const
{
    ComboProperty combo_property = getItemValue(P_STATUS).value<ComboProperty>();
    return combo_property.getValue();
}

void JobItem::setStatus(const QString &status)
{
    ComboProperty combo_property = getItemValue(P_STATUS).value<ComboProperty>();
    combo_property.setValue(status);
    setItemValue(P_STATUS, combo_property.getVariant());
    if(status == Constants::STATUS_FAILED) {
        if(IntensityDataItem *intensityItem = getIntensityDataItem()) {
            if(intensityItem->getOutputData())
                intensityItem->getOutputData()->setAllTo(0.0);
                emit intensityItem->emitDataChanged();
        }
    }
}

bool JobItem::isIdle() const
{
    ComboProperty combo_property = getItemValue(P_STATUS).value<ComboProperty>();
    return combo_property.getValue() == Constants::STATUS_IDLE;
}

bool JobItem::isRunning() const
{
    ComboProperty combo_property = getItemValue(P_STATUS).value<ComboProperty>();
    return combo_property.getValue() == Constants::STATUS_RUNNING;
}

bool JobItem::isCompleted() const
{
    ComboProperty combo_property = getItemValue(P_STATUS).value<ComboProperty>();
    return combo_property.getValue() == Constants::STATUS_COMPLETED;
}

bool JobItem::isCanceled() const
{
    ComboProperty combo_property = getItemValue(P_STATUS).value<ComboProperty>();
    return combo_property.getValue() == Constants::STATUS_CANCELED;
}

bool JobItem::isFailed() const
{
    ComboProperty combo_property = getItemValue(P_STATUS).value<ComboProperty>();
    return combo_property.getValue() == Constants::STATUS_FAILED;
}

void JobItem::setBeginTime(const QString &begin_time)
{
    setItemValue(P_BEGIN_TIME, begin_time);
}

void JobItem::setEndTime(const QString &end_time)
{
    setItemValue(P_END_TIME, end_time);
}

QString JobItem::getComments() const
{
    return getItemValue(P_COMMENTS).toString();
}

void JobItem::setComments(const QString &comments)
{
    setItemValue(P_COMMENTS, comments);
}

int JobItem::getProgress() const
{
    return getItemValue(P_PROGRESS).toInt();
}

void JobItem::setProgress(int progress)
{
    setItemValue(P_PROGRESS, progress);
}

int JobItem::getNumberOfThreads() const
{
    return getSimulationOptions()->getNumberOfThreads();
}

void JobItem::setRunPolicy(const QString &run_policy)
{
    getSimulationOptions()->setRunPolicy(run_policy);
}

bool JobItem::runImmediately() const
{
    return getSimulationOptions()->runImmediately();
}

bool JobItem::runInBackground() const
{
    return getSimulationOptions()->runInBackground();
}

//! Returns MultiLayerItem of this JobItem, if from_backup=true, then backup'ed version of
//! multilayer will be used
MultiLayerItem *JobItem::getMultiLayerItem()
{
    return dynamic_cast<MultiLayerItem*>(getItem(T_SAMPLE));
}

//! Returns InstrumentItem of this JobItem, if from_backup=true, then backup'ed version of
//! the instrument will be used
InstrumentItem *JobItem::getInstrumentItem()
{
    return dynamic_cast<InstrumentItem*>(getItem(T_INSTRUMENT));
}

void JobItem::setResults(const GISASSimulation *simulation)
{
    IntensityDataItem *intensityItem = getIntensityDataItem();
    Q_ASSERT(intensityItem);

    JobResultsPresenter::setResults(intensityItem, simulation);
}

SimulationOptionsItem *JobItem::getSimulationOptions()
{
    return const_cast<SimulationOptionsItem *>(static_cast<const JobItem*>(this)->getSimulationOptions());
}

const SimulationOptionsItem *JobItem::getSimulationOptions() const
{
    const SimulationOptionsItem *result = dynamic_cast<const SimulationOptionsItem *>(getItem(T_SIMULATION_OPTIONS));
    if(!result) {
        throw GUIHelpers::Error("JobItem::getSimulationOptions() -> Error. "
                                "Can't get SimulationOptionsItem");
    }
    return result;
}

