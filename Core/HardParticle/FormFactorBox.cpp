// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/HardParticle/FormFactorBox.cpp
//! @brief     Implements class FormFactorBox.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "FormFactorBox.h"
#include "BornAgainNamespace.h"
#include "MathFunctions.h"
#include "RealParameter.h"

//! Constructor of a rectangular cuboid.
//! @param length: length of the base in nanometers
//! @param width: width of the base in nanometers
//! @param height: height of the box in nanometers
FormFactorBox::FormFactorBox(double length, double width, double height)
    : m_length(length), m_width(width), m_height(height)
{
    setName(BornAgain::FFBoxType);
    registerParameter(BornAgain::Length, &m_length).setUnit(BornAgain::UnitsNm).setNonnegative();
    registerParameter(BornAgain::Width, &m_width).setUnit(BornAgain::UnitsNm).setNonnegative();
    registerParameter(BornAgain::Height, &m_height).setUnit(BornAgain::UnitsNm).setNonnegative();
    onChange();
}

complex_t FormFactorBox::evaluate_for_q(cvector_t q) const
{
    complex_t qzHdiv2 = m_height / 2 * q.z();
    return m_height * m_length * m_width * MathFunctions::sinc(m_length / 2 * q.x())
           * MathFunctions::sinc(m_width / 2 * q.y()) * MathFunctions::sinc(qzHdiv2)
           * exp_I(qzHdiv2);
}

IFormFactor* FormFactorBox::sliceFormFactor(ZLimits limits, const IRotation& rot,
                                            kvector_t translation) const
{
    auto effects = computeSlicingEffects(limits, translation, m_height);
    FormFactorBox slicedff(m_length, m_width, m_height - effects.dz_bottom - effects.dz_top);
    return CreateTransformedFormFactor(slicedff, rot, effects.position);
}

void FormFactorBox::onChange()
{
}
