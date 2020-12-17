//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      gui2/quicksimeditor/profilehelper.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_GUI2_QUICKSIMEDITOR_PROFILEHELPER_H
#define BORNAGAIN_GUI2_QUICKSIMEDITOR_PROFILEHELPER_H

#include "darefl_export.h"
#include <Sample/Slice/Slice.h>
#include <utility>
#include <vector>

//! Object that can generate the material profile of a sample as a function of depth.
namespace gui2 {

class DAREFLCORE_EXPORT ProfileHelper {
public:
    ProfileHelper(const std::vector<Slice>& sample);
    ~ProfileHelper();

    std::vector<complex_t> calculateProfile(const std::vector<double>& z_values) const;
    std::pair<double, double> defaultLimits() const;

private:
    std::vector<complex_t> m_materialdata;
    std::vector<double> m_zlimits;
    std::vector<double> m_sigmas;
};

} // namespace gui2

#endif // BORNAGAIN_GUI2_QUICKSIMEDITOR_PROFILEHELPER_H
