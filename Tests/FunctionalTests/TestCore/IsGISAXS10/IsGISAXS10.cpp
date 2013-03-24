#include "IsGISAXS10.h"
#include "FormFactorCylinder.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "LayerDecorator.h"
#include "MaterialManager.h"
#include "MultiLayer.h"
#include "OutputDataIOFactory.h"
#include "ParticleDecoration.h"
#include "Simulation.h"
#include "Units.h"
#include "Utils.h"

#include <iostream>
#include <cmath>


FunctionalTests::IsGISAXS10::IsGISAXS10()
    : m_name("IsGISAXS10")
    , m_description("Cylinders with interference on top of substrate")
    , m_result(0)
{ }


void FunctionalTests::IsGISAXS10::run()
{
    // building sample
    MultiLayer multi_layer;
    const IMaterial *p_air_material = MaterialManager::getHomogeneousMaterial("Air10", 1.0, 0.0);
    const IMaterial *p_substrate_material = MaterialManager::getHomogeneousMaterial("Substrate10", 1.0-5e-6, 2e-8);
    Layer air_layer;
    air_layer.setMaterial(p_air_material);
    Layer substrate_layer;
    substrate_layer.setMaterial(p_substrate_material);

    IInterferenceFunction *p_interference_function = new InterferenceFunction1DParaCrystal(20.0*Units::nanometer,7*Units::nanometer, 1e7*Units::nanometer);
    complex_t n_particle(1.0-5e-5, 2e-8);
    ParticleDecoration particle_decoration(new Particle(n_particle, new FormFactorCylinder(5*Units::nanometer, 5*Units::nanometer)));
    particle_decoration.addInterferenceFunction(p_interference_function);

    LayerDecorator air_layer_decorator(air_layer, particle_decoration);

    multi_layer.addLayer(air_layer_decorator);
    multi_layer.addLayer(substrate_layer);

    // building simulation
    Simulation simulation;
    simulation.setDetectorParameters(100, 0.0*Units::degree, 2.0*Units::degree, 100, 0.0*Units::degree, 2.0*Units::degree, true);
    simulation.setBeamParameters(1.0*Units::angstrom, -0.2*Units::degree, 0.0*Units::degree);
    simulation.setSample(multi_layer);

    // running simulation and copying data
    simulation.runSimulation();
    m_result = simulation.getOutputDataClone();
}


int FunctionalTests::IsGISAXS10::analyseResults()
{
    const double threshold(1e-10);

    // retrieving reference data
    std::string filename = Utils::FileSystem::GetHomePath() + "Tests/FunctionalTests/TestCore/IsGISAXS10/isgisaxs10_reference.ima.gz";
    OutputData<double > *reference = OutputDataIOFactory::getOutputData(filename);

    // calculating average relative difference
    *m_result -= *reference;
    *m_result /= *reference;
    double diff(0);
    for(OutputData<double>::const_iterator it=m_result->begin(); it!=m_result->end(); ++it) {
        diff+= std::fabs(*it);
    }
    diff /= m_result->getAllocatedSize();

    bool status_ok(true);
    if( diff > threshold || std::isnan(diff)) status_ok=false;
    delete reference;

    std::cout << m_name << " " << m_description << " " << (status_ok ? "[OK]" : "[FAILED]") << std::endl;
    return (int)status_ok;
}


#ifdef STANDALONE
int main()
{
    FunctionalTests::IsGISAXS10 test;
    test.run();

    return test.analyseResults();
}
#endif
