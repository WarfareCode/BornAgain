// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence 
//! @brief automatically generated boost::python code for PythonCoreAPI  

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "PythonFitList.h"
#include "FitSuiteParameters.pypp.h"

namespace bp = boost::python;

void register_FitSuiteParameters_class(){

    { //::FitSuiteParameters
        typedef bp::class_< FitSuiteParameters > FitSuiteParameters_exposer_t;
        FitSuiteParameters_exposer_t FitSuiteParameters_exposer = FitSuiteParameters_exposer_t( "FitSuiteParameters", bp::init< >() );
        bp::scope FitSuiteParameters_scope( FitSuiteParameters_exposer );
        { //::FitSuiteParameters::getValues
        
            typedef ::std::vector< double > ( ::FitSuiteParameters::*getValues_function_type )(  ) const;
            
            FitSuiteParameters_exposer.def( 
                "getValues"
                , getValues_function_type( &::FitSuiteParameters::getValues ) );
        
        }
    }

}