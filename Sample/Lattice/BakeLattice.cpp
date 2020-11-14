// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/Lattice/BakeLattice.cpp
//! @brief     Implements class Lattice.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Sample/Lattice/BakeLattice.h"
#include "Sample/Lattice/Lattice.h"
#include "Sample/Lattice/ILatticeOrientation.h"

Lattice bake::createCubicLattice(double a)
{
    kvector_t a1(a, 0.0, 0.0);
    kvector_t a2(0.0, a, 0.0);
    kvector_t a3(0.0, 0.0, a);
    return Lattice(a1, a2, a3);
}

Lattice bake::createFCCLattice(double a)
{
    double b = a / 2.0;
    kvector_t a1(0.0, b, b);
    kvector_t a2(b, 0.0, b);
    kvector_t a3(b, b, 0.0);
    return Lattice(a1, a2, a3);
}

Lattice bake::createHexagonalLattice(double a, double c)
{
    kvector_t a1(a, 0.0, 0.0);
    kvector_t a2(-a / 2.0, std::sqrt(3.0) * a / 2.0, 0.0);
    kvector_t a3(0.0, 0.0, c);
    return Lattice(a1, a2, a3);
}

Lattice bake::createHCPLattice(double a, double c)
{
    kvector_t a1(a, 0.0, 0.0);
    kvector_t a2(-a / 2.0, std::sqrt(3.0) * a / 2.0, 0);
    kvector_t a3(a / 2.0, a / std::sqrt(3.0) / 2.0, c / 2.0);
    return Lattice(a1, a2, a3);
}

Lattice bake::createTetragonalLattice(double a, double c)
{
    kvector_t a1(a, 0.0, 0.0);
    kvector_t a2(0.0, a, 0.0);
    kvector_t a3(0.0, 0.0, c);
    return Lattice(a1, a2, a3);
}

Lattice bake::createBCTLattice(double a, double c)
{
    kvector_t a1(a, 0.0, 0.0);
    kvector_t a2(0.0, a, 0.0);
    kvector_t a3(a / 2.0, a / 2.0, c / 2.0);
    return Lattice(a1, a2, a3);
}

// TODO RECONSIDER: do we really need or want the LatticeOrientation machinery? If yes, simplify!

Lattice bake::createOrientedFCCLattice(double lattice_constant,
                                       const ILatticeOrientation& orientation)
{
    const Lattice l1 = bake::createCubicLattice(1.0);
    std::unique_ptr<ILatticeOrientation> P_orientation(orientation.clone());
    P_orientation->usePrimitiveLattice(l1);
    const Transform3D trafo = P_orientation->transformation();
    const Lattice fcc = bake::createFCCLattice(lattice_constant);
    return fcc.transformed(trafo);
}

Lattice bake::createOrientedHCPLattice(double a, double c, const ILatticeOrientation& orientation)
{
    const Lattice l1 = bake::createHexagonalLattice(1.0, c / a);
    std::unique_ptr<ILatticeOrientation> P_orientation(orientation.clone());
    P_orientation->usePrimitiveLattice(l1);
    const Transform3D trafo = P_orientation->transformation();
    const Lattice hcp = bake::createHCPLattice(a, c);
    return hcp.transformed(trafo);
}

Lattice bake::createOrientedBCTLattice(double a, double c, const ILatticeOrientation& orientation)
{
    const Lattice l1 = bake::createTetragonalLattice(1.0, c / a);
    std::unique_ptr<ILatticeOrientation> P_orientation(orientation.clone());
    P_orientation->usePrimitiveLattice(l1);
    const Transform3D trafo = P_orientation->transformation();
    const Lattice hcp = bake::createBCTLattice(a, c);
    return hcp.transformed(trafo);
}
