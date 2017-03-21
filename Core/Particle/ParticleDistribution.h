// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Particle/ParticleDistribution.h
//! @brief     Defines class ParticleDistribution.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef PARTICLEDISTRIBUTION_H
#define PARTICLEDISTRIBUTION_H

#include "IAbstractParticle.h"
#include "ParameterDistribution.h"

class IParticle;

//! A particle type that is a parametric distribution of IParticle's.
//! @ingroup samples

class BA_CORE_API_ ParticleDistribution : public IAbstractParticle
{
public:
    ParticleDistribution(const IParticle& prototype, const ParameterDistribution& par_distr);

    ParticleDistribution* clone() const final;
    ParticleDistribution* cloneInvertB() const final;

    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }

    //! Returns list of new particles generated according to a distribution.
    std::vector<const IParticle*> generateParticles() const;

    //! Returns the distributed parameter data
    ParameterDistribution parameterDistribution() const { return m_par_distribution; }

    //! Returns particle.
    const IParticle* particle() const { return mP_particle.get(); }

    std::vector<const INode*> getChildren() const;

private:
    std::unique_ptr<IParticle> mP_particle;
    ParameterDistribution m_par_distribution;
};

#endif // PARTICLEDISTRIBUTION_H
