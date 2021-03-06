//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/viewmodel/mvvm/editors/customeventfilters.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_VIEWMODEL_MVVM_EDITORS_CUSTOMEVENTFILTERS_H
#define BORNAGAIN_MVVM_VIEWMODEL_MVVM_EDITORS_CUSTOMEVENTFILTERS_H

#include "mvvm/viewmodel_export.h"
#include <QObject>

namespace ModelView {

//! Event filter to prevent loss of the focus.
//! Can be used in the context of QTreeView and similar widgets to call external editor. Such an
//! editor is created by clicking on a cell of a tree and it appears as  modal window on top of a
//! tree.

class MVVM_VIEWMODEL_EXPORT LostFocusFilter : public QObject {
    Q_OBJECT

public:
    LostFocusFilter(QObject* parent = nullptr);

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
};

//! Event filter to install on combo boxes and spin boxes to ignore wheel events during scrolling.
//! Helpful than the spin box is a child of some larger scroll area.

class MVVM_VIEWMODEL_EXPORT WheelEventFilter : public QObject {
    Q_OBJECT

public:
    WheelEventFilter(QObject* parent = nullptr);

protected:
    bool eventFilter(QObject* obj, QEvent* event);
};

} // namespace ModelView

#endif // BORNAGAIN_MVVM_VIEWMODEL_MVVM_EDITORS_CUSTOMEVENTFILTERS_H
