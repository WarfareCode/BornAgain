// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Particle/FormFactorWeighted.cpp
//! @brief     Implements class FormFactorWeighted.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "FormFactorWeighted.h"
#include "BornAgainNamespace.h"

FormFactorWeighted::FormFactorWeighted()
{
    setName(BornAgain::FormFactorWeightedType);
}

FormFactorWeighted::~FormFactorWeighted()
{
    for (size_t index = 0; index < m_form_factors.size(); ++index)
        delete m_form_factors[index];
}

FormFactorWeighted* FormFactorWeighted::clone() const
{
    FormFactorWeighted* result = new FormFactorWeighted();
    for (size_t index = 0; index < m_form_factors.size(); ++index)
        result->addFormFactor(*m_form_factors[index], m_weights[index]);
    return result;
}

double FormFactorWeighted::radialExtension() const
{
    double result{0.0};
    for (size_t index = 0; index < m_form_factors.size(); ++index)
        result += m_weights[index] * m_form_factors[index]->radialExtension();
    return result;
}

double FormFactorWeighted::bottomZ(const IRotation& rotation) const
{
    if (m_form_factors.size() == 0)
        throw std::runtime_error("FormFactorWeighted::bottomZ() -> Error: "
                                 "'this' contains no form factors.");
    double zmin = m_form_factors[0]->bottomZ(rotation);
    for (size_t index = 1; index < m_form_factors.size(); ++index)
        zmin = std::min(zmin, m_form_factors[index]->bottomZ(rotation));
    return zmin;
}

double FormFactorWeighted::topZ(const IRotation& rotation) const
{
    if (m_form_factors.size() == 0)
        throw std::runtime_error("FormFactorWeighted::topZ() -> Error: "
                                 "'this' contains no form factors.");
    double zmax = m_form_factors[0]->topZ(rotation);
    for (size_t index = 1; index < m_form_factors.size(); ++index)
        zmax = std::min(zmax, m_form_factors[index]->topZ(rotation));
    return zmax;
}

void FormFactorWeighted::addFormFactor(const IFormFactor& form_factor, double weight)
{
    m_form_factors.push_back(form_factor.clone());
    m_weights.push_back(weight);
}

void FormFactorWeighted::setAmbientMaterial(Material material)
{
    for (size_t index = 0; index < m_form_factors.size(); ++index)
        m_form_factors[index]->setAmbientMaterial(material);
}

complex_t FormFactorWeighted::evaluate(const WavevectorInfo& wavevectors) const
{
    complex_t result(0.0, 0.0);
    for (size_t index = 0; index < m_form_factors.size(); ++index)
        result += m_weights[index] * m_form_factors[index]->evaluate(wavevectors);
    return result;
}

Eigen::Matrix2cd FormFactorWeighted::evaluatePol(const WavevectorInfo& wavevectors) const
{
    Eigen::Matrix2cd result = Eigen::Matrix2cd::Zero();
    for (size_t index = 0; index < m_form_factors.size(); ++index)
        result += m_weights[index] * m_form_factors[index]->evaluatePol(wavevectors);
    return result;
}
