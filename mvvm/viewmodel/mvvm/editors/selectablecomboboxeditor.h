//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/viewmodel/mvvm/editors/selectablecomboboxeditor.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_VIEWMODEL_MVVM_EDITORS_SELECTABLECOMBOBOXEDITOR_H
#define BORNAGAIN_MVVM_VIEWMODEL_MVVM_EDITORS_SELECTABLECOMBOBOXEDITOR_H

#include "mvvm/editors/customeditor.h"

class QComboBox;
class QStandardItemModel;

namespace ModelView {

class WheelEventFilter;

//! Adds multi-selection capabilities to QComboBox.

class MVVM_VIEWMODEL_EXPORT SelectableComboBoxEditor : public CustomEditor {
    Q_OBJECT

public:
    explicit SelectableComboBoxEditor(QWidget* parent = nullptr);

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

    bool is_persistent() const override;

protected slots:
    void onModelDataChanged(const QModelIndex&, const QModelIndex&, const QVector<int>&);

    void onClickedList(const QModelIndex& index);

protected:
    void update_components() override;

private:
    bool eventFilter(QObject* obj, QEvent* event) override;
    void setConnected(bool isConnected);
    void updateBoxLabel();

    bool isClickToSelect(QObject* obj, QEvent* event) const;
    bool isClickToExpand(QObject* obj, QEvent* event) const;

    QComboBox* m_box{nullptr};
    WheelEventFilter* m_wheelEventFilter{nullptr};
    QStandardItemModel* m_model{nullptr};
};

} // namespace ModelView

#endif // BORNAGAIN_MVVM_VIEWMODEL_MVVM_EDITORS_SELECTABLECOMBOBOXEDITOR_H
