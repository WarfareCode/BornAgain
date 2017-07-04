// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/CommonWidgets/ItemSelectorWidget.h
//! @brief     Defines class ItemSelectorWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef ITEMSELECTORWIDGET_H
#define ITEMSELECTORWIDGET_H

#include "WinDllMacros.h"
#include <QWidget>
#include <QItemSelectionModel>

class SessionModel;
class SessionItem;
class QItemSelection;
class QModelIndex;
class QAbstractItemDelegate;
class QListView;

//! The ItemSelectorWidget class holds QListView to show top level items of SessionModel.
//! Used in InstrumentView, ImportDataView, JobSelectorView to switch between items.

class BA_CORE_API_ ItemSelectorWidget : public QWidget
{
    Q_OBJECT

public:
    ItemSelectorWidget(QWidget* parent = 0);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    void setModel(SessionModel* model);
    void setItemDelegate(QAbstractItemDelegate* delegate);

    QItemSelectionModel* selectionModel();
    QListView* listView();

public slots:
    void select(const QModelIndex &index, QItemSelectionModel::SelectionFlags command);
    void updateSelection();
    void selectLast();

signals:
    void selectionChanged(SessionItem* item);
    void contextMenuRequest(const QPoint& point, const QModelIndex& index);

private slots:
    void onSelectionChanged(const QItemSelection& selected, const QItemSelection&);
    void onCustomContextMenuRequested(const QPoint& point);

protected:
    void connectModel();
    void disconnectModel();
    void showEvent(class QShowEvent*);

    QListView* m_listView;
    SessionModel* m_model;
};

#endif // ITEMSELECTORWIDGET_H