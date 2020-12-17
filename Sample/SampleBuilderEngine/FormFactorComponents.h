//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      Sample/SampleBuilderEngine/FormFactorComponents.h
//! @brief     Defines sample components for complex sample builders.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifdef SWIG
#error no need to expose this header to Swig
#endif

#ifndef USER_API
#ifndef BORNAGAIN_SAMPLE_SAMPLEBUILDERENGINE_FORMFACTORCOMPONENTS_H
#define BORNAGAIN_SAMPLE_SAMPLEBUILDERENGINE_FORMFACTORCOMPONENTS_H

#include "Sample/HardParticle/HardParticles.h"
#include "Sample/SampleBuilderEngine/IRegistry.h"

//! @class FormFactorComponents
//! @brief Predefined form factors for functional tests.

class FormFactorComponents : public IRegistry<IFormFactor> {
public:
    FormFactorComponents();
};

#endif // BORNAGAIN_SAMPLE_SAMPLEBUILDERENGINE_FORMFACTORCOMPONENTS_H
#endif // USER_API
