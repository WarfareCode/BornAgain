// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/StandardSamples/ParticleInVacuumBuilder.cpp
//! @brief     Implements class ParticleInVacuumBuilder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Core/StandardSamples/ParticleInVacuumBuilder.h"
#include "Core/Aggregate/ParticleLayout.h"
#include "Core/Basics/Exceptions.h"
#include "Core/Basics/Units.h"
#include "Core/Material/MaterialFactoryFuncs.h"
#include "Core/Multilayer/Layer.h"
#include "Core/Multilayer/MultiLayer.h"
#include "Core/Particle/Particle.h"
#include "Core/SampleBuilderEngine/SampleComponents.h"
#include "Core/includeIncludes/FormFactors.h"

namespace {
FormFactorComponents ff_components;
}

ParticleInVacuumBuilder::ParticleInVacuumBuilder()
    : m_ff(new FormFactorFullSphere(5.0 * Units::nanometer))
{
}

MultiLayer* ParticleInVacuumBuilder::buildSample() const
{
    Material vacuum_material = HomogeneousMaterial("Vacuum", 0.0, 0.0);
    Material particle_material = HomogeneousMaterial("Particle", 6e-4, 2e-8);

    Layer vacuum_layer(vacuum_material);

    Particle particle(particle_material, *m_ff);
    ParticleLayout particle_layout(particle);
    vacuum_layer.addLayout(particle_layout);

    MultiLayer* result = new MultiLayer;
    result->addLayer(vacuum_layer);
    return result;
}

MultiLayer* ParticleInVacuumBuilder::createSampleByIndex(size_t index)
{
    auto name = ff_components.keys().at(index);
    m_ff.reset(ff_components.getItem(name)->clone());
    setName(name);
    return buildSample();
}

size_t ParticleInVacuumBuilder::size()
{
    return ff_components.size();
}
