// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Shapes/Pyramid3.h
//! @brief     Defines class Pyramid3.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef PYRAMID3_H
#define PYRAMID3_H

#include "IShape.h"

class Pyramid3 : public IShape
{
public:
    Pyramid3(double length, double height, double alpha);
    ~Pyramid3();

private:
    static const double sqrt3;
};

#endif // PYRAMID3_H
