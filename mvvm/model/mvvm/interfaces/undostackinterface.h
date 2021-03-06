//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/model/mvvm/interfaces/undostackinterface.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_MODEL_MVVM_INTERFACES_UNDOSTACKINTERFACE_H
#define BORNAGAIN_MVVM_MODEL_MVVM_INTERFACES_UNDOSTACKINTERFACE_H

#include <memory>
#include <string>

class QUndoCommand;

namespace ModelView {

class AbstractItemCommand;

//! Interface class for undo/redo stack.

class UndoStackInterface {
public:
    virtual ~UndoStackInterface() = default;

    //! Executes the command, then pushes it in the stack for possible undo.
    //! Current design relies on shared pointer. This is done
    //! a) to retrieve result of the command from another place
    //! b) to adapt the command for QUndoStack
    //! c) to bypass QUndoStack behavior which wants to have an ownership
    virtual void execute(std::shared_ptr<AbstractItemCommand> command) = 0;

    virtual bool isActive() const = 0;
    virtual bool canUndo() const = 0;
    virtual bool canRedo() const = 0;
    virtual int index() const = 0;
    virtual int count() const = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
    virtual void clear() = 0;
    virtual void setUndoLimit(int limit) = 0;

    virtual void beginMacro(const std::string& name) = 0;
    virtual void endMacro() = 0;
};

} // namespace ModelView

#endif // BORNAGAIN_MVVM_MODEL_MVVM_INTERFACES_UNDOSTACKINTERFACE_H
