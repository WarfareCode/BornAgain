// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/FitView.cpp
//! @brief     Implements class FitView
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FitView.h"
#include "RealDataWidget.h"
#include "FitParameterWidget.h"
#include "RunFitWidget.h"
#include "FitToolBar.h"
#include "qdebug.h"
#include "mainwindow.h"
#include <QTabWidget>
#include <QVBoxLayout>


FitView::FitView(FitProxyModel *fitProxyModel, MainWindow *mainWindow)
    : QWidget(mainWindow)
    , m_fitProxyModel(fitProxyModel)
{

    m_realDataWidget = new RealDataWidget();
    m_fitParameterWidget = new FitParameterWidget(m_fitProxyModel);
    m_runFitWidget = new RunFitWidget();

    m_tabWidget = new QTabWidget();
    m_tabWidget->insertTab(REAL_DATA, m_realDataWidget, tr("Real Data"));
    m_tabWidget->insertTab(FIT_PARAMETER, m_fitParameterWidget, tr("Fit Parameters"));
    m_tabWidget->insertTab(RUN_FIT, m_runFitWidget, tr("Run Fit"));

    connect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onChangeTabWidget(int)));


    m_toolBar = new FitToolBar(this);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
    mainLayout->addWidget(m_toolBar);
    mainLayout->addWidget(m_tabWidget);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);
}


void FitView::onChangeTabWidget(int /*index*/)
{

}
