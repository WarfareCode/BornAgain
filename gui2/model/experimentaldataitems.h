//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      gui2/model/experimentaldataitems.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_GUI2_MODEL_EXPERIMENTALDATAITEMS_H
#define BORNAGAIN_GUI2_MODEL_EXPERIMENTALDATAITEMS_H

#include "darefl_export.h"
#include "mvvm/standarditems/containeritem.h"
#include "mvvm/standarditems/graphviewportitem.h"

namespace ModelView {
class Data1DItem;
}

namespace gui2 {

//! Holds a collection of GraphItem's for simultaneous plotting, as well as all information
//! related to plotting properties. Used in the context of importing of 1D data. Serves as an input
//! for GraphCanvas widget.

class DAREFLCORE_EXPORT CanvasItem : public ModelView::GraphViewportItem {
public:
    CanvasItem();

protected:
    std::pair<double, double> data_yaxis_range() const override;
};

//! Holds a collection of CanvasItem.
//! Used in the context of importing of 1D data, when user groups different GraphItem's
//! on different canvas for later plotting.

class DAREFLCORE_EXPORT CanvasContainerItem : public ModelView::ContainerItem {
public:
    CanvasContainerItem();

    std::vector<CanvasItem*> canvasItems() const;
};

//! Holds a collection of Data1DItem's with raw data as imported by the user.
//! The order of items in the collection chronologically corresponds to user activity.
//! All other plotting entities (GraphItems) are linked to data items in this container.

class DAREFLCORE_EXPORT ExperimentalDataContainerItem : public ModelView::ContainerItem {
public:
    ExperimentalDataContainerItem();

    std::vector<ModelView::Data1DItem*> dataItems() const;
};

} // namespace gui2

#endif // BORNAGAIN_GUI2_MODEL_EXPERIMENTALDATAITEMS_H
