//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/view/mvvm/plotting/colormapinfoformatter.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_VIEW_MVVM_PLOTTING_COLORMAPINFOFORMATTER_H
#define BORNAGAIN_MVVM_VIEW_MVVM_PLOTTING_COLORMAPINFOFORMATTER_H

#include "mvvm/plotting/statusstringformatterinterface.h"

class QCustomPlot;

namespace ModelView {

//! Formats status string for current mouse position in QCPColorMap.
//! Includes coordinates of mouse pointer in viewport axes coordinates, add bins info for
//! QCPColorMap beneath.

class MVVM_VIEW_EXPORT ColorMapInfoFormatter : public StatusStringFormatterInterface {
public:
    //! Returns status string representing data in color map.
    //! @params x: mouse x-position given in axis viewport coordinates
    //! @params y: mouse y-position given in axis viewport coordinates
    std::string status_string(QCustomPlot* custom_plot, double x, double y) const override;
};

} // namespace ModelView

#endif // BORNAGAIN_MVVM_VIEW_MVVM_PLOTTING_COLORMAPINFOFORMATTER_H
