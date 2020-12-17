//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      Device/Beam/IFootprintFactor.cpp
//! @brief     Implements interface IFootprintFactor.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "Device/Beam/IFootprintFactor.h"
#include <stdexcept>

IFootprintFactor::IFootprintFactor(const NodeMeta& meta, const std::vector<double>& PValues)
    : INode(nodeMetaUnion(
                {{"BeamToSampleWidthRatio", "", "ratio of beam width to sample width", 0, INF, 1.}},
                meta),
            PValues)
    , m_width_ratio(m_P[0])
{
    if (m_P[0] < 0.0)
        throw std::runtime_error(
            "Error in IFootprintFactor::setWidthRatio: width ratio is negative");
}

IFootprintFactor::~IFootprintFactor() = default;

void IFootprintFactor::setWidthRatio(double width_ratio)
{
    if (width_ratio < 0.0)
        throw std::runtime_error(
            "Error in IFootprintFactor::setWidthRatio: width ratio is negative");
    m_P[0] = width_ratio;
}
