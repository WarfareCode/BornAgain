//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/Core/Std/Check.cpp
//! @brief     Implements function checkSimulation for core standard test
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "BABuild.h"
#include "BATesting.h"
#include "Base/Utils/FileSystemUtils.h"
#include "Core/Simulation/SimulationFactory.h"
#include "Device/Histo/IntensityDataIOFactory.h"
#include "Device/Instrument/IntensityDataFunctions.h"
#include "Sample/Multilayer/MultiLayer.h"
#include "Sample/StandardSamples/SampleBuilderFactory.h"
#include <iostream>

bool checkSimulation(const std::string& name, const ISimulation& direct_simulation,
                     const double limit) {
    const auto result_data = direct_simulation.result().data();

    std::unique_ptr<OutputData<double>> reference;

    // Load reference if available
    ASSERT(name != "");
    try {
        const std::string refPath = FileSystemUtils::jointPath(
            BATesting::ReferenceDir_Std(), name + ".int.gz");
        std::cout << "- compare with reference: " << refPath << "\n";
        reference.reset(IntensityDataIOFactory::readOutputData(refPath));
    } catch (const std::exception&) {
        std::cout << "Failure: reference not found\n";
        std::cout << "  note: we proceed with the simulation to create a new one\n";
    }

    // Compare with reference if available.
    if (reference) {
        std::cout << "- check diff" << std::endl;
        if (IntensityDataFunctions::checkRelativeDifference(*reference, *result_data, limit)) {
            std::cout << "- success" << std::endl;
            return true; // regular exit
        }
        std::cout << "Failure ..." << std::endl;
    }

    // Save simulation, as it differs from reference.
    FileSystemUtils::createDirectories(BATesting::TestOutDir_Std());
    std::string out_fname =
        FileSystemUtils::jointPath(BATesting::TestOutDir_Std(), name + ".int.gz");
    IntensityDataIOFactory::writeOutputData(*result_data, out_fname);
    std::cout << "New simulation result: " << out_fname << "\n"
              << "To visualize an intensity map, use " << BABuild::buildBinDir() << "/plot_int.py;"
              << "   to plot a difference image, use " << BABuild::buildBinDir()
              << "/plot_diff_int.py\n"
              << "If the new result is correct, then move it to "
              << BATesting::ReferenceDir_Core() << "/\n";

    return false;
}
