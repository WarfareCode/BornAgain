//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Export/SampleToPython.cpp
//! @brief     Implements class SampleToPython.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "Core/Export/SampleToPython.h"
#include "Base/Utils/Assert.h"
#include "Base/Vector/Transform3D.h"
#include "Core/Export/INodeUtils.h"
#include "Core/Export/ModelKeyHandler.h"
#include "Core/Export/PyFmt.h"
#include "Core/Export/PyFmt2.h"
#include "Sample/Aggregate/InterferenceFunctions.h"
#include "Sample/Aggregate/ParticleLayout.h"
#include "Sample/Lattice/Lattice2D.h"
#include "Sample/Lattice/Lattice3D.h"
#include "Sample/Multilayer/Layer.h"
#include "Sample/Multilayer/MultiLayer.h"
#include "Sample/Particle/Crystal.h"
#include "Sample/Particle/MesoCrystal.h"
#include "Sample/Particle/Particle.h"
#include "Sample/Particle/ParticleComposition.h"
#include "Sample/Particle/ParticleCoreShell.h"
#include "Sample/Particle/ParticleDistribution.h"
#include "Sample/Scattering/IFormFactor.h"
#include "Sample/Slice/LayerInterface.h"
#include "Sample/Slice/LayerRoughness.h"
#include <iomanip>
#include <map>

using pyfmt::indent;

namespace {

void setRotationInformation(const IParticle* particle, std::string name,
                            std::ostringstream& result) {
    if (particle->rotation()) {
        switch (particle->rotation()->getTransform3D().getRotationType()) {
        case Transform3D::EULER: {
            double alpha, beta, gamma;
            particle->rotation()->getTransform3D().calculateEulerAngles(&alpha, &beta, &gamma);
            result << indent() << name << "_rotation = ba.RotationEuler("
                   << pyfmt::printDegrees(alpha) << ", " << pyfmt::printDegrees(beta) << ", "
                   << pyfmt::printDegrees(gamma) << ")\n";
            break;
        }
        case Transform3D::XAXIS: {
            double alpha = particle->rotation()->getTransform3D().calculateRotateXAngle();
            result << indent() << name << "_rotation = ba.RotationX(" << pyfmt::printDegrees(alpha)
                   << ")\n";
            break;
        }
        case Transform3D::YAXIS: {
            double alpha = particle->rotation()->getTransform3D().calculateRotateYAngle();
            result << indent() << name << "_rotation = ba.RotationY(" << pyfmt::printDegrees(alpha)
                   << ")\n";
            break;
        }
        case Transform3D::ZAXIS: {
            double alpha = particle->rotation()->getTransform3D().calculateRotateZAngle();
            result << indent() << name << "_rotation = ba.RotationZ(" << pyfmt::printDegrees(alpha)
                   << ")\n";
            break;
        }
        }
        result << indent() << name << ".setRotation(" << name << "_rotation)\n";
    }
}

void setPositionInformation(const IParticle* particle, std::string name,
                            std::ostringstream& result) {
    kvector_t pos = particle->position();
    if (pos == kvector_t())
        return;

    result << indent() << name << "_position = kvector_t(" << pyfmt::printNm(pos.x()) << ", "
           << pyfmt::printNm(pos.y()) << ", " << pyfmt::printNm(pos.z()) << ")\n";
    result << indent() << name << ".setPosition(" << name << "_position)\n";
}

} // namespace

//  ************************************************************************************************
//  class SampleToPython
//  ************************************************************************************************

std::string SampleToPython::generateSampleCode(const MultiLayer& multilayer) {
    initLabels(multilayer);
    return defineGetSample();
}

void SampleToPython::initLabels(const MultiLayer& multilayer) {
    m_objs.reset(new ModelKeyHandler());

    m_objs->insertModel("sample", &multilayer);
    for (const auto* x : multilayer.containedMaterials())
        m_objs->insertModel("mat_" + x->getName(), x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<Layer>(multilayer))
        m_objs->insertModel("layer", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<LayerRoughness>(multilayer))
        m_objs->insertModel("roughness", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<ParticleLayout>(multilayer))
        m_objs->insertModel("layout", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<IFormFactor>(multilayer))
        m_objs->insertModel("ff", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<IInterferenceFunction>(multilayer))
        m_objs->insertModel("iff", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<Particle>(multilayer))
        m_objs->insertModel("particle", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<ParticleComposition>(multilayer))
        m_objs->insertModel("particle", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<ParticleCoreShell>(multilayer))
        m_objs->insertModel("particle", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<MesoCrystal>(multilayer))
        m_objs->insertModel("particle", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<ParticleDistribution>(multilayer))
        m_objs->insertModel("particle_distrib", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<Lattice2D>(multilayer))
        m_objs->insertModel("lattice", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<Lattice3D>(multilayer))
        m_objs->insertModel("lattice", x);
    for (const auto* x : INodeUtils::AllDescendantsOfType<Crystal>(multilayer))
        m_objs->insertModel("crystal", x);
}

SampleToPython::SampleToPython() = default;

SampleToPython::~SampleToPython() = default;

std::string SampleToPython::defineGetSample() const {
    return "def get_sample():\n" + defineMaterials() + defineFormFactors() + defineParticles()
           + defineCoreShellParticles() + defineParticleCompositions() + defineLattices2D()
           + defineLattices3D() + defineCrystals() + defineMesoCrystals()
           + defineParticleDistributions() + defineInterferenceFunctions() + defineParticleLayouts()
           + defineRoughnesses() + defineLayers() + defineMultiLayers() + "\n\n";
}

const std::map<MATERIAL_TYPES, std::string> factory_names{
    {MATERIAL_TYPES::RefractiveMaterial, "HomogeneousMaterial"},
    {MATERIAL_TYPES::MaterialBySLD, "MaterialBySLD"}};

std::string SampleToPython::defineMaterials() const {
    std::vector<const Material*> v = m_objs->objectsOfType<Material>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << indent() << "# Define materials\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        const std::string& factory_name = factory_names.at(s->typeID());
        const complex_t& data = s->materialData();
        if (s->isScalarMaterial()) {
            result << indent() << key << " = ba." << factory_name << "(\"" << s->getName() << "\", "
                   << pyfmt::printDouble(data.real()) << ", " << pyfmt::printDouble(data.imag())
                   << ")\n";
        } else {
            kvector_t magnetic_field = s->magnetization();
            result << indent() << "magnetic_field = kvector_t(" << magnetic_field.x() << ", "
                   << magnetic_field.y() << ", " << magnetic_field.z() << ")\n";
            result << indent() << key << " = ba." << factory_name << "(\"" << s->getName();
            result << "\", " << pyfmt::printDouble(data.real()) << ", "
                   << pyfmt::printDouble(data.imag()) << ", "
                   << "magnetic_field)\n";
        }
    }
    return result.str();
}

std::string SampleToPython::defineLayers() const {
    std::vector<const Layer*> v = m_objs->objectsOfType<Layer>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << "\n" << indent() << "# Define layers\n";
    result << std::setprecision(12);
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        result << indent() << key << " = ba.Layer(" << m_objs->obj2key(s->material());
        if (s->thickness() != 0)
            result << ", " << pyfmt::printNm(s->thickness());
        result << ")\n";
        if (s->numberOfSlices() != 1)
            result << indent() << key << ".setNumberOfSlices(" << s->numberOfSlices() << ")\n";
        for (const auto* layout : s->layouts())
            result << indent() << key << ".addLayout(" << m_objs->obj2key(layout) << ")\n";
    }
    return result.str();
}

std::string SampleToPython::defineRoughnesses() const {
    std::vector<const LayerRoughness*> v = m_objs->objectsOfType<LayerRoughness>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Define roughness\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        result << indent() << key << " = ba.LayerRoughness(" << pyfmt2::argumentList(s) << ")\n";
    }
    return result.str();
}

std::string SampleToPython::defineFormFactors() const {
    std::vector<const IFormFactor*> v = m_objs->objectsOfType<IFormFactor>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << "\n" << indent() << "# Define form factors\n";
    result << std::setprecision(12);
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        result << indent() << key << " = ba.FormFactor" << s->getName() << "("
               << pyfmt2::argumentList(s) << ")\n";
    }
    return result.str();
}

std::string SampleToPython::defineInterferenceFunctions() const {
    std::vector<const IInterferenceFunction*> v = m_objs->objectsOfType<IInterferenceFunction>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Define interference functions\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);

        if (dynamic_cast<const InterferenceFunctionNone*>(s))
            result << indent() << key << " = ba.InterferenceFunctionNone()\n";

        else if (const auto* iff = dynamic_cast<const InterferenceFunction1DLattice*>(s)) {
            result << indent() << key << " = ba.InterferenceFunction1DLattice("
                   << pyfmt::printNm(iff->getLength()) << ", " << pyfmt::printDegrees(iff->getXi())
                   << ")\n";

            const auto* pdf = INodeUtils::OnlyChildOfType<IFTDecayFunction1D>(*iff);

            if (pdf->decayLength() != 0.0)
                result << indent() << key << "_pdf  = ba." << pdf->getName() << "("
                       << pyfmt2::argumentList(pdf) << ")\n"
                       << indent() << key << ".setDecayFunction(" << key << "_pdf)\n";

        } else if (const auto* iff =
                       dynamic_cast<const InterferenceFunctionRadialParaCrystal*>(s)) {
            result << indent() << key << " = ba.InterferenceFunctionRadialParaCrystal("
                   << pyfmt::printNm(iff->peakDistance()) << ", "
                   << pyfmt::printNm(iff->dampingLength()) << ")\n";

            if (iff->kappa() != 0.0)
                result << indent() << key << ".setKappa(" << pyfmt::printDouble(iff->kappa())
                       << ")\n";

            if (iff->domainSize() != 0.0)
                result << indent() << key << ".setDomainSize("
                       << pyfmt::printDouble(iff->domainSize()) << ")\n";

            const auto* pdf = INodeUtils::OnlyChildOfType<IFTDistribution1D>(*iff);

            if (pdf->omega() != 0.0)
                result << indent() << key << "_pdf  = ba." << pdf->getName() << "("
                       << pyfmt2::argumentList(pdf) << ")\n"
                       << indent() << key << ".setProbabilityDistribution(" << key << "_pdf)\n";

        } else if (const auto* iff = dynamic_cast<const InterferenceFunction2DLattice*>(s)) {
            const auto* lattice = INodeUtils::OnlyChildOfType<Lattice2D>(*iff);

            result << indent() << key << " = ba.InterferenceFunction2DLattice("
                   << m_objs->obj2key(lattice) << ")\n";

            const auto* pdf = INodeUtils::OnlyChildOfType<IFTDecayFunction2D>(*iff);

            result << indent() << key << "_pdf  = ba." << pdf->getName() << "("
                   << pyfmt2::argumentList(pdf) << ")\n"
                   << indent() << key << ".setDecayFunction(" << key << "_pdf)\n";

            if (iff->integrationOverXi() == true)
                result << indent() << key << ".setIntegrationOverXi(True)\n";

        } else if (const auto* iff = dynamic_cast<const InterferenceFunctionFinite2DLattice*>(s)) {
            const auto* lattice = INodeUtils::OnlyChildOfType<Lattice2D>(*iff);

            result << indent() << key << " = ba.InterferenceFunctionFinite2DLattice("
                   << m_objs->obj2key(lattice) << ", " << iff->numberUnitCells1() << ", "
                   << iff->numberUnitCells2() << ")\n";

            if (iff->integrationOverXi() == true)
                result << indent() << key << ".setIntegrationOverXi(True)\n";

        } else if (const auto* iff = dynamic_cast<const InterferenceFunction2DParaCrystal*>(s)) {
            const auto* lattice = INodeUtils::OnlyChildOfType<Lattice2D>(*iff);
            std::vector<double> domainSize = iff->domainSizes();

            result << indent() << key << " = ba.InterferenceFunction2DParaCrystal("
                   << m_objs->obj2key(lattice) << ", " << pyfmt::printNm(iff->dampingLength())
                   << ", " << pyfmt::printNm(domainSize[0]) << ", " << pyfmt::printNm(domainSize[1])
                   << ")\n";

            if (iff->integrationOverXi() == true)
                result << indent() << key << ".setIntegrationOverXi(True)\n";

            const auto pdf_vector = INodeUtils::ChildNodesOfType<IFTDistribution2D>(*iff);
            if (pdf_vector.size() != 2)
                continue;
            const IFTDistribution2D* pdf = pdf_vector[0];

            result << indent() << key << "_pdf_1  = ba." << pdf->getName() << "("
                   << pyfmt2::argumentList(pdf) << ")\n";

            pdf = pdf_vector[1];

            result << indent() << key << "_pdf_2  = ba." << pdf->getName() << "("
                   << pyfmt2::argumentList(pdf) << ")\n";
            result << indent() << key << ".setProbabilityDistributions(" << key << "_pdf_1, " << key
                   << "_pdf_2)\n";

        } else if (const auto* lattice_hd = dynamic_cast<const InterferenceFunctionHardDisk*>(s)) {
            result << indent() << key << " = ba.InterferenceFunctionHardDisk("
                   << pyfmt::printNm(lattice_hd->radius()) << ", "
                   << pyfmt::printDouble(lattice_hd->density()) << ")\n";

        } else
            throw std::runtime_error(
                "Bug: ExportToPython::defineInterferenceFunctions() called with unexpected "
                "IInterferenceFunction "
                + s->getName());

        if (s->positionVariance() > 0.0) {
            result << indent() << key << ".setPositionVariance("
                   << pyfmt::printNm2(s->positionVariance()) << ")\n";
        }
    }
    return result.str();
}

std::string SampleToPython::defineParticleLayouts() const {
    std::vector<const ParticleLayout*> v = m_objs->objectsOfType<ParticleLayout>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Define particle layouts\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        result << indent() << key << " = ba.ParticleLayout()\n";
        const auto particles = INodeUtils::ChildNodesOfType<IAbstractParticle>(*s);
        for (const auto* particle : particles) {
            double abundance = particle->abundance();
            result << indent() << key << ".addParticle(" << m_objs->obj2key(particle) << ", "
                   << pyfmt::printDouble(abundance) << ")\n";
        }
        if (const auto* iff = INodeUtils::OnlyChildOfType<IInterferenceFunction>(*s))
            result << indent() << key << ".setInterferenceFunction(" << m_objs->obj2key(iff)
                   << ")\n";
        result << indent() << key << ".setWeight(" << s->weight() << ")\n";
        result << indent() << key << ".setTotalParticleSurfaceDensity("
               << s->totalParticleSurfaceDensity() << ")\n";
    }
    return result.str();
}

std::string SampleToPython::defineParticles() const {
    std::vector<const Particle*> v = m_objs->objectsOfType<Particle>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Define particles\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        const auto* ff = INodeUtils::OnlyChildOfType<IFormFactor>(*s);
        ASSERT(ff);
        result << indent() << key << " = ba.Particle(" << m_objs->obj2key(s->material()) << ", "
               << m_objs->obj2key(ff) << ")\n";
        setRotationInformation(s, key, result);
        setPositionInformation(s, key, result);
    }
    return result.str();
}

std::string SampleToPython::defineCoreShellParticles() const {
    std::vector<const ParticleCoreShell*> v = m_objs->objectsOfType<ParticleCoreShell>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Define core shell particles\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        result << indent() << key << " = ba.ParticleCoreShell("
               << m_objs->obj2key(s->shellParticle()) << ", " << m_objs->obj2key(s->coreParticle())
               << ")\n";
        setRotationInformation(s, key, result);
        setPositionInformation(s, key, result);
    }
    return result.str();
}

std::string SampleToPython::defineParticleDistributions() const {
    std::vector<const ParticleDistribution*> v = m_objs->objectsOfType<ParticleDistribution>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Define particles with parameter following a distribution\n";
    int index = 1;
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        const std::string units = s->mainUnits();
        ParameterDistribution par_distr = s->parameterDistribution();
        // building distribution functions
        std::string s_distr = "distr_" + std::to_string(index);
        result << indent() << s_distr << " = "
               << pyfmt2::printDistribution(*par_distr.getDistribution(), units) << "\n";

        // building parameter distribution
        std::string s_par_distr = "par_distr_" + std::to_string(index);

        result << indent() << s_par_distr << " = "
               << pyfmt2::printParameterDistribution(par_distr, s_distr, units) << "\n";

        // linked parameters
        std::vector<std::string> linked_pars = par_distr.getLinkedParameterNames();
        if (!linked_pars.empty()) {
            result << indent() << s_par_distr;
            for (size_t i = 0; i < linked_pars.size(); ++i)
                result << ".linkParameter(\"" << linked_pars[i] << "\")";
            result << "\n";
        }

        auto particle = INodeUtils::OnlyChildOfType<IParticle>(*s);
        if (!particle)
            continue;
        result << indent() << key << " = ba.ParticleDistribution(" << m_objs->obj2key(particle)
               << ", " << s_par_distr << ")\n";
        index++;
    }
    return result.str();
}

std::string SampleToPython::defineParticleCompositions() const {
    std::vector<const ParticleComposition*> v = m_objs->objectsOfType<ParticleComposition>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Define composition of particles at specific positions\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        result << indent() << key << " = ba.ParticleComposition()\n";
        const auto particle_list = INodeUtils::ChildNodesOfType<IParticle>(*s);
        for (const auto* particle : particle_list) {
            result << indent() << key << ".addParticle(" << m_objs->obj2key(particle) << ")\n";
        }
        setRotationInformation(s, key, result);
        setPositionInformation(s, key, result);
    }
    return result.str();
}

std::string SampleToPython::defineMesoCrystals() const {
    std::vector<const MesoCrystal*> v = m_objs->objectsOfType<MesoCrystal>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Define mesocrystals\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        auto crystal = INodeUtils::OnlyChildOfType<Crystal>(*s);
        auto outer_shape = INodeUtils::OnlyChildOfType<IFormFactor>(*s);
        if (!crystal || !outer_shape)
            continue;
        result << indent() << key << " = ba.MesoCrystal(";
        result << m_objs->obj2key(crystal) << ", ";
        result << m_objs->obj2key(outer_shape) << ")\n";
        setRotationInformation(s, key, result);
        setPositionInformation(s, key, result);
    }
    return result.str();
}

std::string SampleToPython::defineLattices2D() const {
    std::vector<const Lattice2D*> v = m_objs->objectsOfType<Lattice2D>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Define 2D lattices\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        result << indent() << key << " = ba.BasicLattice2D(\n";
        result << indent() << indent() << pyfmt::printNm(s->length1()) << ", "
               << pyfmt::printNm(s->length2()) << ", " << pyfmt::printDegrees(s->latticeAngle())
               << ", " << pyfmt::printDegrees(s->rotationAngle()) << ")\n";
    }
    return result.str();
}

std::string SampleToPython::defineLattices3D() const {
    std::vector<const Lattice3D*> v = m_objs->objectsOfType<Lattice3D>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Define 3D lattices\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        kvector_t bas_a = s->getBasisVectorA();
        kvector_t bas_b = s->getBasisVectorB();
        kvector_t bas_c = s->getBasisVectorC();
        result << indent() << key << " = ba.Lattice3D(\n";
        result << indent() << indent() << "ba.kvector_t(" << pyfmt::printNm(bas_a.x()) << ", "
               << pyfmt::printNm(bas_a.y()) << ", " << pyfmt::printNm(bas_a.z()) << "),\n";
        result << indent() << indent() << "ba.kvector_t(" << pyfmt::printNm(bas_b.x()) << ", "
               << pyfmt::printNm(bas_b.y()) << ", " << pyfmt::printNm(bas_b.z()) << "),\n";
        result << indent() << indent() << "ba.kvector_t(" << pyfmt::printNm(bas_c.x()) << ", "
               << pyfmt::printNm(bas_c.y()) << ", " << pyfmt::printNm(bas_c.z()) << "))\n";
    }
    return result.str();
}

std::string SampleToPython::defineCrystals() const {
    std::vector<const Crystal*> v = m_objs->objectsOfType<Crystal>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Define crystals\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        const auto* lattice = INodeUtils::OnlyChildOfType<Lattice3D>(*s);
        const auto* basis = INodeUtils::OnlyChildOfType<IParticle>(*s);
        if (!lattice || !basis)
            continue;
        result << indent() << key << " = ba.Crystal(";
        result << m_objs->obj2key(basis) << ", ";
        result << m_objs->obj2key(lattice) << ")\n";
    }
    return result.str();
}

std::string SampleToPython::defineMultiLayers() const {
    std::vector<const MultiLayer*> v = m_objs->objectsOfType<MultiLayer>();
    if (v.empty())
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    ASSERT(v.size() == 1); // as long as there is exactly one sample, we shall use the singular
    result << "\n" << indent() << "# Define sample\n";
    for (const auto* s : v) {
        const std::string& key = m_objs->obj2key(s);
        result << indent() << key << " = ba.MultiLayer()\n";
        double ccl = s->crossCorrLength();
        if (ccl > 0.0)
            result << indent() << key << ".setCrossCorrLength(" << ccl << ")\n";
        auto external_field = s->externalField();
        if (external_field.mag() > 0.0) {
            std::string field_name = key + "_external_field";
            result << indent() << field_name << " = kvector_t("
                   << pyfmt::printScientificDouble(external_field.x()) << ", "
                   << pyfmt::printScientificDouble(external_field.y()) << ", "
                   << pyfmt::printScientificDouble(external_field.z()) << ")\n";
            result << indent() << key << ".setExternalField(" << field_name << ")\n";
        }
        size_t numberOfLayers = s->numberOfLayers();
        if (numberOfLayers) {
            result << indent() << key << ".addLayer(" << m_objs->obj2key(s->layer(0)) << ")\n";

            size_t layerIndex = 1;
            while (layerIndex != numberOfLayers) {
                const LayerInterface* layerInterface = s->layerInterface(layerIndex - 1);
                if (const LayerRoughness* rough = layerInterface->getRoughness())
                    result << indent() << key << ".addLayerWithTopRoughness("
                           << m_objs->obj2key(s->layer(layerIndex)) << ", "
                           << m_objs->obj2key(rough) << ")\n";
                else
                    result << indent() << key << ".addLayer("
                           << m_objs->obj2key(s->layer(layerIndex)) << ")\n";
                layerIndex++;
            }
        }
        result << "\n" << indent() << "return " << key << "\n";
    }
    return result.str();
}
