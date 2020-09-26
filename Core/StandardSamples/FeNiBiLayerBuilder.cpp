// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/StandardSamples/FeNiBiLayerBuilder.cpp
//! @brief     Defines various sample builder classes to
//!            test polarized specular computations
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Core/StandardSamples/FeNiBiLayerBuilder.h"
#include "Core/Basics/Complex.h"
#include "Core/Basics/PhysicalConstants.h"
#include "Core/Basics/Units.h"
#include "Core/Material/MaterialFactoryFuncs.h"
#include "Core/Multilayer/Layer.h"
#include "Core/Multilayer/LayerRoughness.h"
#include "Core/Multilayer/MultiLayer.h"
#include "Core/Multilayer/RoughnessModels.h"

namespace
{
auto constexpr rhoMconst = -PhysConsts::m_n * PhysConsts::g_factor_n * PhysConsts::mu_N
    / PhysConsts::h_bar / PhysConsts::h_bar * 1e-27;

class Options
{
public:
    int _NBiLayers = 4;
    double _angle = 0.;
    double _magnetizationMagnitude = 1.e7;
    double _thicknessFe = 100. * Units::angstrom;
    double _thicknessNi = 40. * Units::angstrom;
    double _sigmaRoughness = 0.;
    int _effectiveSLD = 0;
    RoughnessModel _roughnessModel = RoughnessModel::TANH;

    Options() {}
    Options NBiLayers(int n)
        {
            _NBiLayers = n;
            return *this;
        }
    Options angle(double angle)
        {
            _angle = angle;
            return *this;
        }
    Options magnetizationMagnitude(double M)
        {
            _magnetizationMagnitude = M;
            return *this;
        }
    Options thicknessFe(double t)
        {
            _thicknessFe = t;
            return *this;
        }
    Options thicknessNi(double t)
        {
            _thicknessNi = t;
            return *this;
        }
    Options sigmaRoughness(double r)
        {
            _sigmaRoughness = r;
            return *this;
        }
    Options effectiveSLD(int i)
        {
            _effectiveSLD = i;
            return *this;
        }
    Options roughnessModel(RoughnessModel rm)
        {
            _roughnessModel = rm;
            return *this;
        }
};
//! Creates the sample demonstrating an Fe-Ni Bilayer with and without roughness
//! @ingroup standard_samples
class FeNiBiLayer
{
    static constexpr auto sldFe = complex_t{8.02e-06, 0};
    static constexpr auto sldAu = complex_t{4.6665e-6, 0};
    static constexpr auto sldNi = complex_t{9.4245e-06, 0};

    int NBiLayers;
    double angle;
    double magnetizationMagnitude;
    double thicknessFe;
    double thicknessNi;
    double sigmaRoughness;
    int effectiveSLD;
    RoughnessModel roughnessModel;

    kvector_t magnetizationVector;

    std::unique_ptr<MultiLayer> sample;

    std::unique_ptr<MultiLayer> constructSample();

public:

    FeNiBiLayer(Options opt = {})
        : NBiLayers(opt._NBiLayers), angle(opt._angle),
          magnetizationMagnitude(opt._magnetizationMagnitude), thicknessFe(opt._thicknessFe),
          thicknessNi(opt._thicknessNi), sigmaRoughness(opt._sigmaRoughness),
          effectiveSLD(opt._effectiveSLD), roughnessModel(opt._roughnessModel)
        {
            if (angle != 0. && effectiveSLD != 0.)
                throw std::runtime_error("Cannot perform scalar computation "
                                         "for non-colinear magnetization");

            magnetizationVector = kvector_t(magnetizationMagnitude * std::sin(angle),
                                            magnetizationMagnitude * std::cos(angle), 0);
            sample = constructSample();
        }

    MultiLayer* release() { return sample.release(); }
};

}

const complex_t FeNiBiLayer::sldFe;
const complex_t FeNiBiLayer::sldAu;
const complex_t FeNiBiLayer::sldNi;

std::unique_ptr<MultiLayer> FeNiBiLayer::constructSample()
{
    auto sample = std::make_unique<MultiLayer>();

    auto m_ambient = MaterialBySLD("Ambient", 0.0, 0.0);
    auto m_Fe =
        effectiveSLD == 0
        ? MaterialBySLD("Fe", sldFe.real(), sldFe.imag(), magnetizationVector)
        : MaterialBySLD("Fe", sldFe.real() + effectiveSLD * rhoMconst * magnetizationMagnitude,
                        sldFe.imag(), kvector_t{0, 0, 0});

    auto m_Ni = MaterialBySLD("Ni", sldNi.real(), sldNi.imag());
    auto m_Substrate = MaterialBySLD("Au", sldAu.real(), sldAu.imag());

    Layer l_Fe{m_Fe, thicknessFe};
    Layer l_Ni{m_Ni, thicknessNi};

    LayerRoughness roughness{sigmaRoughness, 0., 0.};
    sample->addLayer(Layer{m_ambient});

    for (auto i = 0; i < NBiLayers; ++i) {
        sample->addLayerWithTopRoughness(l_Fe, roughness);
        sample->addLayerWithTopRoughness(l_Ni, roughness);
    }

    sample->addLayerWithTopRoughness(Layer{m_Substrate}, roughness);
    sample->setRoughnessModel(roughnessModel);
    return sample;
}

MultiLayer* FeNiBiLayerBuilder::buildSample() const
{
    auto sample = FeNiBiLayer{Options()};
    return sample.release();
}

MultiLayer* FeNiBiLayerTanhBuilder::buildSample() const
{
    auto sample = FeNiBiLayer{Options()
                              .sigmaRoughness(2. * Units::angstrom)
                              .roughnessModel(RoughnessModel::TANH)};
    return sample.release();
}

MultiLayer* FeNiBiLayerNCBuilder::buildSample() const
{
    auto sample = FeNiBiLayer{Options()
                              .sigmaRoughness(2. * Units::angstrom)
                              .roughnessModel(RoughnessModel::NEVOT_CROCE)};
    return sample.release();
}

MultiLayer* FeNiBiLayerSpinFlipBuilder::buildSample() const
{
    auto sample = FeNiBiLayer{Options().angle(38. * Units::degree)};
    return sample.release();
}

MultiLayer* FeNiBiLayerSpinFlipTanhBuilder::buildSample() const
{
    auto sample = FeNiBiLayer{Options()
                              .angle(38 * Units::degree)
                              .sigmaRoughness(2. * Units::angstrom)
                              .roughnessModel(RoughnessModel::TANH)};
    return sample.release();
}

MultiLayer* FeNiBiLayerSpinFlipNCBuilder::buildSample() const
{
    auto sample = FeNiBiLayer{Options()
                              .angle(38 * Units::degree)
                              .sigmaRoughness(2. * Units::angstrom)
                              .roughnessModel(RoughnessModel::NEVOT_CROCE)};
    return sample.release();
}
