// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Shapes/Triangle.cpp
//! @brief     Implements class Triangle.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Triangle.h"

Triangle::Triangle(double length, double z)
{
    m_vertices = TriangleVertices(length, z);
}

Triangle::~Triangle() {}
