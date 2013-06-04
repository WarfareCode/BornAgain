#include "MaterialBrowserView.h"
#include "MaterialBrowserModel.h"
#include "MaterialManager.h"
#include <styledbar.h>
#include <manhattanstyle.h>

#include <QTableView>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QCloseEvent>
#include <QStatusBar>
#include <QToolBar>
#include <QtGlobal>
#include <QApplication>
#include <QAction>
#include <iostream>

int MaterialBrowserView::m_nmaterial = 0;

MaterialBrowserView::MaterialBrowserView(QWidget *parent)
    : QDialog(parent)
    , m_tableView(0)
    , m_tableModel(0)
    , m_statusBar(0)
    , m_toolBar(0)
{
    std::cout << "MaterialEditorView::MaterialEditorView() ->  " << std::endl;
    setMinimumSize(128, 128);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_tableView = new MyTableView(this);
    m_tableModel = new MaterialBrowserModel(0);
    m_tableView->setModel( m_tableModel );
    m_tableView->horizontalHeader()->setStretchLastSection(true);

    m_toolBar = new QToolBar(this);
    m_toolBar->setFixedHeight(28);
    m_toolBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    const int size = style()->pixelMetric(QStyle::PM_SmallIconSize);
    m_toolBar->setIconSize(QSize(size, size));
    m_toolBar->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    m_statusBar = new QStatusBar(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(m_toolBar);
    layout->addWidget(m_tableView);
    layout->addWidget(m_statusBar);
    setLayout(layout);

    SetupActions();

    show();
}


MaterialBrowserView::~MaterialBrowserView()
{
    std::cout << "MaterialBrowserView::~MaterialBrowserView() ->" << std::endl;
}


void MaterialBrowserView::SetupActions()
{
    QAction *addMaterialAction = new QAction(QIcon(":/SampleDesigner/images/card--plus.png"), tr("Add material"), this);
    connect(addMaterialAction, SIGNAL(triggered()), this, SLOT(addMaterial()));
    m_toolBar->addAction(addMaterialAction);

    QAction *removeMaterialAction = new QAction(QIcon(":/SampleDesigner/images/card--minus.png"), tr("Remove selected material"), this);
    connect(removeMaterialAction, SIGNAL(triggered()), this, SLOT(removeMaterial()));
    m_toolBar->addAction(removeMaterialAction);
}


void MaterialBrowserView::addMaterial()
{
    QString name = QString("unnamed%1").arg(m_nmaterial);
    std::cout << "MaterialBrowserView::addMaterial() -> " << name.toStdString() << std::endl;
    MaterialManager::instance().getHomogeneousMaterial(name.toStdString(), 1.0, 0.0);
    m_tableModel->UpdateMaterials();
    m_tableView->scrollToBottom();

    m_nmaterial++;
}


void MaterialBrowserView::removeMaterial()
{
    std::cout << "MaterialBrowserView::removeMaterial() -> " << std::endl;
    QModelIndexList selectedList = m_tableView->selectionModel()->selectedRows();
    if( !selectedList.size() ) {
        m_statusBar->showMessage("Select one or more rows to delete materials", 3000);
    }

    for(int i=0; i<selectedList.size(); ++i) {
        m_tableModel->RemoveMaterial(selectedList[i].row());
        std::cout << "XXX " << i << " " << selectedList[i].row()<< std::endl;
    }
}


void MaterialBrowserView::closeEvent(QCloseEvent *event)
{
    std::cout << "MaterialBrowserView::closeEvent() ->" << std::endl;
    emit WindowClosed();
    event->accept();
}


