// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Multilayer/SpecularMagnetic.h
//! @brief     Defines namespace SpecularMagnetic.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef SPECULARMAGNETICOLDSTRATEGY_H
#define SPECULARMAGNETICOLDSTRATEGY_H

#include "MatrixRTCoefficients.h"
#include "Vectors3D.h"
#include <vector>
#include <memory>

class Slice;

//! Implements the matrix formalism for the calculation of wave amplitudes of
//! the coherent wave solution in a multilayer with magnetization.
//! @ingroup algorithms_internal

class SpecularMagneticOldStrategy
{
public:
    typedef std::unique_ptr<const ILayerRTCoefficients> single_coeff_t;
    typedef std::vector<single_coeff_t> coeffs_t;

    //! Computes refraction angle reflection/transmission coefficients
    //! for given sliced multilayer and wavevector k
    BA_CORE_API_ coeffs_t
    Execute(const std::vector<Slice>& slices, const kvector_t& k) const;

    BA_CORE_API_ coeffs_t
    Execute(const std::vector<Slice>& slices, const std::vector<complex_t>& kz) const;

}; // class SpecularMagneticOldStrategy

#endif // SPECULARMAGNETICOLDSTRATEGY_H
