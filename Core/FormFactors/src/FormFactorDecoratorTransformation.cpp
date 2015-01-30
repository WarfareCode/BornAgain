// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/src/FormFactorDecoratorTransformation.cpp
//! @brief     Implements class FormFactorDecoratorTransformation
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FormFactorDecoratorTransformation.h"



FormFactorDecoratorTransformation *FormFactorDecoratorTransformation::clone() const
{
    FormFactorDecoratorTransformation *result =  new FormFactorDecoratorTransformation(
                mp_form_factor->clone(), *mP_transform.get());

    result->setName(getName());
    return result;
}



