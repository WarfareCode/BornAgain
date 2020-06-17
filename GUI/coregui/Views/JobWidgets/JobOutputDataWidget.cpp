// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/JobWidgets/JobOutputDataWidget.cpp
//! @brief     Implements class JobOutputDataWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "JobOutputDataWidget.h"
#include "JobItem.h"
#include "JobModel.h"
#include "JobResultsPresenter.h"
#include "JobViewFlags.h"
#include "mainwindow_constants.h"
#include <QVBoxLayout>

namespace
{
const bool reuse_widget = true;
}

JobOutputDataWidget::JobOutputDataWidget(JobModel* jobModel, QWidget* parent)
    : QWidget(parent), m_stackedWidget(new ItemStackPresenter<JobResultsPresenter>(reuse_widget))
{
    setWindowTitle(QLatin1String("Job OutputData"));
    setObjectName("JobOutputDataWidget");

    setMinimumSize(400, 400);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    mainLayout->addWidget(m_stackedWidget);

    m_stackedWidget->setMinimumSize(600, 600);
    m_stackedWidget->setModel(jobModel);

    setLayout(mainLayout);
}

void JobOutputDataWidget::setItem(JobItem* jobItem)
{
    if (!isValidJobItem(jobItem)) {
        m_stackedWidget->hideWidgets();
        return;
    }

    m_stackedWidget->setItem(jobItem);
}

void JobOutputDataWidget::onActivityChanged(int activity)
{
    if (auto widget = m_stackedWidget->currentWidget())
        widget->setPresentation(static_cast<JobViewFlags::EActivities>(activity));
}

bool JobOutputDataWidget::isValidJobItem(JobItem* item)
{
    if (!item)
        return false;

    // do not show running job items, the rest (canceled, fitted, etc) are shown
    return !item->isRunning();
}
