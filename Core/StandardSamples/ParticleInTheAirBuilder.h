// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/StandardSamples/ParticleInTheAirBuilder.h
//! @brief     Defines class ParticleInTheAirBuilder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_STANDARDSAMPLES_PARTICLEINTHEAIRBUILDER_H
#define BORNAGAIN_CORE_STANDARDSAMPLES_PARTICLEINTHEAIRBUILDER_H

#include "Core/SampleBuilderEngine/ISampleBuilder.h"
#include <memory>

class IFormFactor;

//! The ParticleInTheAirBuilder class generates a multilayer with single air layer
//! populated with particles of certain types.
//! Requires IComponentService which generates form factors, used for bulk form factors testing.
//! @ingroup standard_samples

class ParticleInTheAirBuilder : public ISampleBuilder
{
public:
    ParticleInTheAirBuilder();
    virtual MultiLayer* buildSample() const;

    MultiLayer* createSampleByIndex(size_t index);
    size_t size();

protected:
    std::unique_ptr<IFormFactor> m_ff;
};

#endif // BORNAGAIN_CORE_STANDARDSAMPLES_PARTICLEINTHEAIRBUILDER_H
