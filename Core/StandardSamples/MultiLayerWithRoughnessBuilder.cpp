// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/StandardSamples/MultiLayerWithRoughnessBuilder.cpp
//! @brief     Implement class MultiLayerWithRoughnessBuilder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "MultiLayerWithRoughnessBuilder.h"
#include "BornAgainNamespace.h"
#include "Layer.h"
#include "LayerRoughness.h"
#include "MaterialFactoryFuncs.h"
#include "MultiLayer.h"
#include "RealParameter.h"
#include "Units.h"

MultiLayerWithRoughnessBuilder::MultiLayerWithRoughnessBuilder()
    : m_thicknessA(2.5 * Units::nanometer), m_thicknessB(5.0 * Units::nanometer),
      m_sigma(1.0 * Units::nanometer), m_hurst(0.3), m_lateralCorrLength(5.0 * Units::nanometer),
      m_crossCorrLength(10.0 * Units::nanometer)
{
}

MultiLayer* MultiLayerWithRoughnessBuilder::buildSample() const
{
    MultiLayer* multi_layer = new MultiLayer();
    Material air_material = HomogeneousMaterial("Air", 0., 0.);
    Material substrate_material = HomogeneousMaterial("Substrate", 15e-6, 0.0);
    Material part_a_material = HomogeneousMaterial("PartA", 5e-6, 0.0);
    Material part_b_material = HomogeneousMaterial("PartB", 10e-6, 0.0);

    Layer air_layer(air_material, 0);
    Layer partA_layer(part_a_material, m_thicknessA);
    Layer partB_layer(part_b_material, m_thicknessB);
    Layer substrate_layer(substrate_material, 0);

    LayerRoughness roughness(m_sigma, m_hurst, m_lateralCorrLength);

    multi_layer->addLayer(air_layer);
    for (int i = 0; i < 5; ++i) {
        multi_layer->addLayerWithTopRoughness(partA_layer, roughness);
        multi_layer->addLayerWithTopRoughness(partB_layer, roughness);
    }

    multi_layer->addLayerWithTopRoughness(substrate_layer, roughness);
    multi_layer->setCrossCorrLength(m_crossCorrLength);
    return multi_layer;
}
