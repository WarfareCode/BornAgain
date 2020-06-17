// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Shapes/Dot.cpp
//! @brief     Implements class Dot.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Dot.h"

Dot::Dot()
{
    m_vertices.push_back(kvector_t(0.0, 0.0, 0.0));
}

Dot::~Dot() {}
