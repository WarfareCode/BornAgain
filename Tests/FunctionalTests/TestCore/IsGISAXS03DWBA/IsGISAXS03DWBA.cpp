#include "IsGISAXS03DWBA.h"
#include "OutputDataIOFactory.h"
#include "SampleBuilderFactory.h"
#include "Simulation.h"
#include "Utils.h"
#include "Units.h"
#include "MathFunctions.h"
#include "SimulationRegistry.h"
#include <iostream>
#include <cmath>


FunctionalTests::IsGISAXS03DWBA::IsGISAXS03DWBA()
    : m_name("IsGISAXS03DWBA")
    , m_description("Cylinders in DWBA")
    , m_result(0)
	, m_reference(0)
{ }


void FunctionalTests::IsGISAXS03DWBA::run(const std::string &path_to_data)
{

    SimulationRegistry sim_registry;
    Simulation *simulation = sim_registry.createSimulation("isgisaxs03_dwba");

    // loading reference data
    std::string filename = path_to_data + "isgisaxs03_reference_DWBA.ima.gz";
    m_reference = OutputDataIOFactory::readIntensityData(filename);

    simulation->runSimulation();

    m_result = simulation->getIntensityData();
    delete simulation;
}


int FunctionalTests::IsGISAXS03DWBA::analyseResults()
{
    const double threshold(2e-10);

    // Calculating average relative difference.
    *m_result -= *m_reference;
    *m_result /= *m_reference;

    double diff(0);
    for(OutputData<double>::const_iterator it =
            m_result->begin(); it!=m_result->end(); ++it) {
        diff+= std::fabs(*it);
    }
    diff /= m_result->getAllocatedSize();

    // Assess result.
	bool status_ok(true);
    if( diff > threshold || std::isnan(diff)) status_ok=false;

    std::cout << " diff " << diff << std::endl;
    std::cout << m_name << " " << m_description << " " <<
            (status_ok ? "[OK]" : "[FAILED]") << std::endl;
    return (status_ok ? 0 : 1);
}


#ifdef STANDALONE
std::string GetPathToData(int argc, char **argv)
{
    if(argc == 2) return argv[1];
    return Utils::FileSystem::GetPathToData("../../../ReferenceData/BornAgain/", argv[0]);
}

int main(int argc, char **argv)
{
    FunctionalTests::IsGISAXS03DWBA test;
    test.run(GetPathToData(argc, argv));
    return test.analyseResults();
}
#endif