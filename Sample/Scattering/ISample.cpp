// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/Scattering/ISample.cpp
//! @brief     Implements class ISample.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Sample/Scattering/ISample.h"
#include "Base/Types/Exceptions.h"
#include "Param/Base/ParameterPool.h"
#include "Sample/Material/Material.h"
#include <algorithm>
#include <sstream>

ISample::ISample(const NodeMeta& meta, const std::vector<double>& PValues) : INode(meta, PValues) {}

std::vector<const Material*> ISample::containedMaterials() const
{
    std::vector<const Material*> result;
    if (const Material* p_material = material())
        result.push_back(p_material);
    for (auto child : getChildren()) {
        if (const ISample* sample = dynamic_cast<const ISample*>(child)) {
            for (const Material* p_material : sample->containedMaterials())
                result.push_back(p_material);
        }
    }
    return result;
}

bool ISample::isMagnetic() const
{
    const auto materials = containedMaterials();
    return std::any_of(materials.cbegin(), materials.cend(),
                       [](const Material* mat) { return mat->isMagneticMaterial(); });
}
