//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      gui2/materialeditor/materialeditorwidget.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_GUI2_MATERIALEDITOR_MATERIALEDITORWIDGET_H
#define BORNAGAIN_GUI2_MATERIALEDITOR_MATERIALEDITORWIDGET_H

#include "darefl_export.h"
#include <QWidget>
#include <memory>

namespace ModelView {
class ViewModel;
class ViewModelDelegate;
} // namespace ModelView

namespace gui2 {

class ApplicationModels;
class MaterialModel;
class MaterialTableView;
class MaterialTreeView;
class MaterialSelectionModel;

//! Widget to hold material table (MaterialTreeView) and all corresponding models and delegates.
//! Belongs to MaterialEditor.

class DAREFLCORE_EXPORT MaterialEditorWidget : public QWidget {
    Q_OBJECT

public:
    MaterialEditorWidget(QWidget* parent = nullptr);
    ~MaterialEditorWidget();

    void setModels(ApplicationModels* models);

    MaterialSelectionModel* selectionModel() const;

private:
    MaterialModel* m_materialModel{nullptr};
    std::unique_ptr<ModelView::ViewModel> m_viewModel;
    MaterialSelectionModel* m_selectionModel{nullptr};
    MaterialTreeView* m_materialView{nullptr};
    std::unique_ptr<ModelView::ViewModelDelegate> m_delegate;
};

} // namespace gui2

#endif // BORNAGAIN_GUI2_MATERIALEDITOR_MATERIALEDITORWIDGET_H
