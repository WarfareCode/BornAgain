//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      gui2/materialeditor/materialeditortoolbar.cpp
//! @brief     Implements class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "gui2/materialeditor/materialeditortoolbar.h"
#include "gui2/mainwindow/styleutils.h"
#include "gui2/materialeditor/materialeditoractions.h"
#include <QAction>
#include <QToolButton>

namespace gui2 {

MaterialEditorToolBar::MaterialEditorToolBar(MaterialEditorActions* actions, QWidget* parent)
    : QToolBar(parent) {
    StyleUtils::SetToolBarStyleTextBesides(this);

    auto action = new QAction("Add material", this);
    action->setIcon(QIcon(":/icons/plus-circle-outline.svg"));
    action->setToolTip("Adds new material at the bottom of the list");
    connect(action, &QAction::triggered, actions, &MaterialEditorActions::onAddMaterial);
    addAction(action);

    action = new QAction("Clone", this);
    action->setIcon(QIcon(":/icons/plus-circle-multiple-outline.svg"));
    action->setToolTip("Clones selected material");
    connect(action, &QAction::triggered, actions, &MaterialEditorActions::onCloneMaterial);
    addAction(action);

    action = new QAction("Remove", this);
    action->setIcon(QIcon(":/icons/beaker-remove-outline.svg"));
    action->setToolTip("Removes selected material");
    connect(action, &QAction::triggered, actions, &MaterialEditorActions::onRemoveMaterial);
    addAction(action);

    addSeparator();

    action = new QAction("Up", this);
    action->setIcon(QIcon(":/icons/arrow-up-circle-outline.svg"));
    action->setToolTip("Moves selected material up");
    connect(action, &QAction::triggered, actions, &MaterialEditorActions::onMoveUp);
    addAction(action);

    action = new QAction("Down", this);
    action->setIcon(QIcon(":/icons/arrow-down-circle-outline.svg"));
    action->setToolTip("Moves selected material down");
    connect(action, &QAction::triggered, actions, &MaterialEditorActions::onMoveDown);
    addAction(action);

    addSeparator();

    action = new QAction("Import", this);
    action->setIcon(QIcon(":/icons/import.svg"));
    action->setToolTip("Imports materials from file");
    connect(action, &QAction::triggered, actions, &MaterialEditorActions::onImport);
    addAction(action);

    action = new QAction("Export", this);
    action->setIcon(QIcon(":/icons/export.svg"));
    action->setToolTip("Exports materials to file");
    connect(action, &QAction::triggered, actions, &MaterialEditorActions::onExport);
    addAction(action);
}

} // namespace gui2
