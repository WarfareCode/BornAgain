// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Material/IMaterial.cpp
//! @brief     Implements class IMaterial.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "IMaterial.h"
#include "Exceptions.h"
#include "HomogeneousMagneticMaterial.h"
#include "WavevectorInfo.h"

std::ostream& operator<<(std::ostream& ostr, const IMaterial& m)
{
    m.print(ostr);
    return ostr;
}

#ifndef SWIG
Eigen::Matrix2cd IMaterial::getSpecularScatteringMatrix(const kvector_t k) const
{
    Eigen::Matrix2cd result;
    WavevectorInfo wavevectors(k, k, 2.0*M_PI/k.mag());
    result = (4.0*M_PI*getScatteringMatrix(wavevectors)
              - k.magxy2() * Eigen::Matrix2cd::Identity())/k.mag2();
    return result;
}
#endif // SWIG

//! Returns true if *this agrees with other in all parameters.
bool IMaterial::operator==(const IMaterial& other) const
{
    if( getName()!=other.getName() )
        return false;
    if( getRefractiveIndex().real() != other.getRefractiveIndex().real() )
        return false;
    if( getRefractiveIndex().imag() != other.getRefractiveIndex().imag() )
        return false;
    if( isScalarMaterial() != other.isScalarMaterial() )
        return false;
    auto p_this  = dynamic_cast<const HomogeneousMagneticMaterial*>(this);
    auto p_other = dynamic_cast<const HomogeneousMagneticMaterial*>(&other);
    if (p_this && p_other && p_this->getMagneticField() != p_other->getMagneticField() )
        return false;
    return true;
}
