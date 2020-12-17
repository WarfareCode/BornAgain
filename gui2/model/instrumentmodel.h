// ************************************************************************** //
//
//  Reflectometry simulation software prototype
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef BORNAGAIN_GUI2_MODEL_INSTRUMENTMODEL_H
#define BORNAGAIN_GUI2_MODEL_INSTRUMENTMODEL_H

#include "darefl_export.h"
#include "mvvm/model/sessionmodel.h"

namespace gui2 {

//! Model to store specular instruments settings.

class DAREFLCORE_EXPORT InstrumentModel : public ModelView::SessionModel {
public:
    InstrumentModel(std::shared_ptr<ModelView::ItemPool> pool = {});
};

} // namespace gui2

#endif // BORNAGAIN_GUI2_MODEL_INSTRUMENTMODEL_H