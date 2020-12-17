// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef BORNAGAIN_MVVM_MODEL_MVVM_MODEL_COMPARATORS_H
#define BORNAGAIN_MVVM_MODEL_MVVM_MODEL_COMPARATORS_H

#include "mvvm/model_export.h"

namespace ModelView {

//! Helper class to register variant comparators.

class MVVM_MODEL_EXPORT Comparators {
public:
    static void registerComparators();
    static bool registered();

private:
    static bool m_is_registered;
};

} // namespace ModelView

#endif // BORNAGAIN_MVVM_MODEL_MVVM_MODEL_COMPARATORS_H