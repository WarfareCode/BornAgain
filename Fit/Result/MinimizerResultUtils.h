//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Result/MinimizerResultUtils.h
//! @brief     Declares MinimizerResultUtils namespace.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_FIT_RESULT_MINIMIZERRESULTUTILS_H
#define BORNAGAIN_FIT_RESULT_MINIMIZERRESULTUTILS_H

#include <string>

class RootMinimizerAdapter;
namespace Fit
{
class Parameters;
}

//! Utility functions to generate reports

namespace MinimizerResultUtils
{

//! Reports results of minimization in the form of multi-line string
std::string reportToString(const RootMinimizerAdapter& minimizer);

//! Reports fit parameters settings and final results
std::string reportParameters(const Fit::Parameters& parameters);

}; // namespace MinimizerResultUtils

#endif // BORNAGAIN_FIT_RESULT_MINIMIZERRESULTUTILS_H
