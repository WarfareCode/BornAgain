//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/view/mvvm/plotting/sceneadapterinterface.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_VIEW_MVVM_PLOTTING_SCENEADAPTERINTERFACE_H
#define BORNAGAIN_MVVM_VIEW_MVVM_PLOTTING_SCENEADAPTERINTERFACE_H

#include "mvvm/view_export.h"

class QRectF;

namespace ModelView {

//! Interface to convert coordinates of "scene" to coordinates of "widget".
//! Used in the context of QCustomPlot being embedded into QGraphicsScene. Converts QGraphicsScene
//! coordinates in the coordinates of local system of QCustomPlot and vice versa.

class MVVM_VIEW_EXPORT SceneAdapterInterface {
public:
    virtual ~SceneAdapterInterface() = default;

    //! convert local x-coordinate to scene coordinate
    virtual double toSceneX(double) const = 0;

    //! convert local y-coordinate to scene coordinate
    virtual double toSceneY(double) const = 0;

    //! convert scene x-coordinate to local axis coordinate
    virtual double fromSceneX(double) const = 0;

    //! convert scene y-coordinate to local axis coordinate
    virtual double fromSceneY(double) const = 0;

    //! returns viewport rectangle in scene coordinates
    virtual QRectF viewportRectangle() const = 0;
};

} // namespace ModelView

#endif // BORNAGAIN_MVVM_VIEW_MVVM_PLOTTING_SCENEADAPTERINTERFACE_H
