#include "TestIsGISAXS2.h"
#include "IsGISAXS02.h"
#include "IsGISAXSTools.h"
#include "OutputDataIOFactory.h"
#include "Utils.h"

#include <fstream>


TestIsGISAXS2::TestIsGISAXS2() : IFunctionalTest("TestIsGISAXS2")
{
    setOutputPath(Utils::FileSystem::GetHomePath()+"./Examples/IsGISAXS_examples/ex-2/" );
}


void TestIsGISAXS2::execute()
{
    FunctionalTests::IsGISAXS02 test;
    test.run();

    OutputDataIOFactory::writeOutputData(*test.getOutputData(), getOutputPath()+"this_bimodal.ima");
}


void TestIsGISAXS2::finalise()
{
    std::string isgi_file(getOutputPath()+"isgi_bimodal.ima.gz");
    std::string this_file(getOutputPath()+"this_bimodal.ima");

    OutputData<double> *isgi_data = OutputDataIOFactory::getOutputData(isgi_file);
    OutputData<double> *our_data = OutputDataIOFactory::getOutputData(this_file);

    IsGISAXSTools::drawOutputDataComparisonResults(*our_data, *isgi_data, "TestIsGISAXS2_c1", "Mixture of cylindrical particles with different size distribution");

    delete isgi_data;
    delete our_data;
}

