// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/StandardSamples/TwoDimLatticeBuilder.cpp
//! @brief     Implements class IsGISAXS06Builder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Sample/StandardSamples/TwoDimLatticeBuilder.h"
#include "Base/Const/Units.h"
#include "Sample/Aggregate/InterferenceFunction2DLattice.h"
#include "Sample/Aggregate/InterferenceFunction2DSuperLattice.h"
#include "Sample/Aggregate/InterferenceFunctionFinite2DLattice.h"
#include "Sample/Aggregate/ParticleLayout.h"
#include "Sample/HardParticle/FormFactorCylinder.h"
#include "Sample/Multilayer/Layer.h"
#include "Sample/Multilayer/MultiLayer.h"
#include "Sample/Particle/Particle.h"
#include "Sample/Particle/ParticleComposition.h"
#include "Sample/StandardSamples/ReferenceMaterials.h"

MultiLayer* Basic2DLatticeBuilder::buildSample() const
{
    Layer vacuum_layer(refMat::Vacuum);
    Layer substrate_layer(refMat::Substrate);

    std::unique_ptr<InterferenceFunction2DLattice> P_interference_function(
        new InterferenceFunction2DLattice(5.0 * Units::nanometer, 10.0 * Units::nanometer,
                                          30.0 * Units::deg, 10.0 * Units::deg));

    FTDecayFunction2DCauchy pdf(300.0 * Units::nanometer / 2.0 / M_PI,
                                100.0 * Units::nanometer / 2.0 / M_PI, 0);
    P_interference_function->setDecayFunction(pdf);

    // particles
    ParticleLayout particle_layout;
    FormFactorCylinder ff_cyl(5.0 * Units::nanometer, 5.0 * Units::nanometer);
    Particle particle(refMat::Particle, ff_cyl);
    particle_layout.addParticle(particle, 1.0);

    particle_layout.setInterferenceFunction(*P_interference_function);

    vacuum_layer.addLayout(particle_layout);

    MultiLayer* multi_layer = new MultiLayer();
    multi_layer->addLayer(vacuum_layer);
    multi_layer->addLayer(substrate_layer);
    return multi_layer;
}

// -----------------------------------------------------------------------------
// lattice #1:
// -----------------------------------------------------------------------------
MultiLayer* SquareLatticeBuilder::buildSample() const
{
    Layer vacuum_layer(refMat::Vacuum);
    Layer substrate_layer(refMat::Substrate);

    std::unique_ptr<InterferenceFunction2DLattice> P_interference_function{
        InterferenceFunction2DLattice::createSquare(10.0 * Units::nanometer, 0)};
    FTDecayFunction2DCauchy pdf(300.0 * Units::nanometer / 2.0 / M_PI,
                                100.0 * Units::nanometer / 2.0 / M_PI, 0);
    P_interference_function->setDecayFunction(pdf);

    // particles
    ParticleLayout particle_layout;
    FormFactorCylinder ff_cyl(5.0 * Units::nanometer, 5.0 * Units::nanometer);
    Particle particle(refMat::Particle, ff_cyl);
    particle_layout.addParticle(particle, 1.0);

    particle_layout.setInterferenceFunction(*P_interference_function);

    vacuum_layer.addLayout(particle_layout);

    MultiLayer* multi_layer = new MultiLayer();
    multi_layer->addLayer(vacuum_layer);
    multi_layer->addLayer(substrate_layer);
    return multi_layer;
}

// -----------------------------------------------------------------------------
// lattice #2: centered
// -----------------------------------------------------------------------------
MultiLayer* CenteredSquareLatticeBuilder::buildSample() const
{
    Layer vacuum_layer(refMat::Vacuum);
    Layer substrate_layer(refMat::Substrate);

    InterferenceFunction2DLattice interference_function(10.0 * Units::nanometer,
                                                        10.0 * Units::nanometer, M_PI / 2.0, 0);
    FTDecayFunction2DCauchy pdf(300.0 * Units::nanometer / 2.0 / M_PI,
                                100.0 * Units::nanometer / 2.0 / M_PI, 0);
    interference_function.setDecayFunction(pdf);

    FormFactorCylinder ff_cyl(5.0 * Units::nanometer, 5.0 * Units::nanometer);
    Particle cylinder(refMat::Particle, ff_cyl);
    std::vector<kvector_t> positions;
    kvector_t position_1(0.0, 0.0, 0.0);
    kvector_t position_2(5.0 * Units::nanometer, -5.0 * Units::nanometer, 0.0);
    positions.push_back(position_1);
    positions.push_back(position_2);
    ParticleComposition basis;
    basis.addParticles(cylinder, positions);

    ParticleLayout particle_layout;
    particle_layout.addParticle(basis);
    particle_layout.setInterferenceFunction(interference_function);
    vacuum_layer.addLayout(particle_layout);

    MultiLayer* multi_layer = new MultiLayer();
    multi_layer->addLayer(vacuum_layer);
    multi_layer->addLayer(substrate_layer);
    return multi_layer;
}

// -----------------------------------------------------------------------------
// lattice #3: rotated
// -----------------------------------------------------------------------------
MultiLayer* RotatedSquareLatticeBuilder::buildSample() const
{
    Layer vacuum_layer(refMat::Vacuum);
    Layer substrate_layer(refMat::Substrate);

    std::unique_ptr<InterferenceFunction2DLattice> P_interference_function{
        InterferenceFunction2DLattice::createSquare(10.0 * Units::nanometer, 30.0 * Units::degree)};
    FTDecayFunction2DCauchy pdf(300.0 * Units::nanometer / 2.0 / M_PI,
                                100.0 * Units::nanometer / 2.0 / M_PI, 30.0 * Units::degree);
    P_interference_function->setDecayFunction(pdf);

    ParticleLayout particle_layout;
    // particle
    FormFactorCylinder ff_cyl(5.0 * Units::nanometer, 5.0 * Units::nanometer);
    kvector_t position(0.0, 0.0, 0.0);
    Particle p(refMat::Particle, ff_cyl);
    p.setPosition(position);
    particle_layout.addParticle(p);
    particle_layout.setInterferenceFunction(*P_interference_function);

    vacuum_layer.addLayout(particle_layout);

    MultiLayer* multi_layer = new MultiLayer();
    multi_layer->addLayer(vacuum_layer);
    multi_layer->addLayer(substrate_layer);
    return multi_layer;
}

// -----------------------------------------------------------------------------
// lattice #4: finite square
// -----------------------------------------------------------------------------
MultiLayer* FiniteSquareLatticeBuilder::buildSample() const
{
    Layer vacuum_layer(refMat::Vacuum);
    Layer substrate_layer(refMat::Substrate);

    std::unique_ptr<InterferenceFunctionFinite2DLattice> P_interference_function{
        InterferenceFunctionFinite2DLattice::createSquare(10.0 * Units::nanometer, 0.0, 40, 40)};
    P_interference_function->setPositionVariance(1.0);

    // particles
    ParticleLayout particle_layout;
    FormFactorCylinder ff_cyl(5.0 * Units::nanometer, 5.0 * Units::nanometer);
    Particle particle(refMat::Particle, ff_cyl);
    particle_layout.addParticle(particle, 1.0);

    particle_layout.setInterferenceFunction(*P_interference_function);

    vacuum_layer.addLayout(particle_layout);

    MultiLayer* multi_layer = new MultiLayer();
    multi_layer->addLayer(vacuum_layer);
    multi_layer->addLayer(substrate_layer);
    return multi_layer;
}

// -----------------------------------------------------------------------------
// lattice #5: superlattice
// -----------------------------------------------------------------------------
MultiLayer* SuperLatticeBuilder::buildSample() const
{
    Layer vacuum_layer(refMat::Vacuum);
    Layer substrate_layer(refMat::Substrate);

    std::unique_ptr<InterferenceFunction2DSuperLattice> P_interference_function{
        InterferenceFunction2DSuperLattice::createSquare(200.0 * Units::nanometer, 0.0, 40, 40)};
    std::unique_ptr<InterferenceFunctionFinite2DLattice> P_substructure{
        InterferenceFunctionFinite2DLattice::createSquare(10.0 * Units::nanometer, 0.0, 10, 10)};
    P_interference_function->setSubstructureIFF(*P_substructure);
    P_interference_function->setPositionVariance(1.0);

    // particles
    ParticleLayout particle_layout;
    FormFactorCylinder ff_cyl(5.0 * Units::nanometer, 10.0 * Units::nanometer);
    Particle particle(refMat::Vacuum, ff_cyl);
    particle_layout.addParticle(particle, 1.0, kvector_t(0.0, 0.0, -10.0 * Units::nanometer));

    particle_layout.setInterferenceFunction(*P_interference_function);
    particle_layout.setTotalParticleSurfaceDensity(100.0 / 4e4);

    substrate_layer.addLayout(particle_layout);

    MultiLayer* multi_layer = new MultiLayer();
    multi_layer->addLayer(vacuum_layer);
    multi_layer->addLayer(substrate_layer);
    return multi_layer;
}