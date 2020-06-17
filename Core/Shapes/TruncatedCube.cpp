// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Shapes/TruncatedCube.cpp
//! @brief     Implements class TruncatedCube.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "TruncatedCube.h"

TruncatedCube::TruncatedCube(double length, double removed_length)
{
    double L2 = length / 2.0;
    double t = removed_length;
    m_vertices = {{-L2 + t, -L2, 0.0},    {-L2, -L2 + t, 0.0},    {-L2, -L2, t},
                  {L2 - t, -L2, 0.0},     {L2, -L2 + t, 0.0},     {L2, -L2, t},
                  {-L2 + t, L2, 0.0},     {-L2, L2 - t, 0.0},     {-L2, L2, t},
                  {L2 - t, L2, 0.0},      {L2, L2 - t, 0.0},      {L2, L2, t},
                  {-L2 + t, -L2, length}, {-L2, -L2 + t, length}, {-L2, -L2, length - t},
                  {L2 - t, -L2, length},  {L2, -L2 + t, length},  {L2, -L2, length - t},
                  {-L2 + t, L2, length},  {-L2, L2 - t, length},  {-L2, L2, length - t},
                  {L2 - t, L2, length},   {L2, L2 - t, length},   {L2, L2, length - t}};
}

TruncatedCube::~TruncatedCube() {}
