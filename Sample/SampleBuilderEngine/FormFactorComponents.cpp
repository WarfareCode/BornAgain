//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      Sample/SampleBuilderEngine/FormFactorComponents.cpp
//! @brief     Implements sample components for complex sample builders.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "Sample/SampleBuilderEngine/FormFactorComponents.h"
#include "Base/Const/Units.h"

//  ************************************************************************************************
FormFactorComponents::FormFactorComponents()
//  ************************************************************************************************
{
    add("AnisoPyramid", new FormFactorAnisoPyramid(10.0, 20.0, 5.0, Units::deg2rad(54.73)));

    add("Box", new FormFactorBox(10.0, 20.0, 5.0));

    //  TODO: activate this when supported by GUI
    //    add("CantellatedCube", new FormFactorCantellatedCube(15.0, 6.0));

    add("Cone", new FormFactorCone(5.0, 6.0, Units::deg2rad(54.73)));

    add("Cone6", new FormFactorCone6(2. / sqrt(3.) * 5.0, 5.0, Units::deg2rad(54.73)));

    add("Cuboctahedron", new FormFactorCuboctahedron(10.0, 5.0, 1.0, Units::deg2rad(54.73)));

    add("Cylinder", new FormFactorCylinder(5.0, 10.0));

    add("Dodecahedron", new FormFactorDodecahedron(5.0));

    add("Dot", new FormFactorDot(5.0));

    add("EllipsoidalCylinder", new FormFactorEllipsoidalCylinder(5.0, 10.0, 15.0));

    add("FullSphere", new FormFactorFullSphere(5.0));

    add("FullSpheroid", new FormFactorFullSpheroid(5.0, 10.0));

    add("HemiEllipsoid", new FormFactorHemiEllipsoid(5.0, 10.0, 15.0));

    add("Icosahedron", new FormFactorIcosahedron(10.0));

    add("Prism3", new FormFactorPrism3(10.0, 5.0));

    add("Prism6", new FormFactorPrism6(2. / sqrt(3.) * 5.0, 5.0));

    add("Pyramid", new FormFactorPyramid(10.0, 5.0, Units::deg2rad(54.73)));

    add("CosineRippleBox", new FormFactorCosineRippleBox(100.0, 20.0, 4.0));

    add("SawtoothRippleBox", new FormFactorSawtoothRippleBox(100.0, 20.0, 4.0, 0.0));

    add("Tetrahedron", new FormFactorTetrahedron(10.0, 4.0, Units::deg2rad(54.73)));

    add("TruncatedCube", new FormFactorTruncatedCube(15.0, 6.0));

    add("TruncatedSphere", new FormFactorTruncatedSphere(5.0, 7.0, 0));

    add("TruncatedSpheroid", new FormFactorTruncatedSpheroid(5.0, 7.0, 1.0, 0));
}
