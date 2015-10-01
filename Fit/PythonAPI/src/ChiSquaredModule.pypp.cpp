// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonFitList.h"
#include "ChiSquaredModule.pypp.h"

namespace bp = boost::python;

struct ChiSquaredModule_wrapper : ChiSquaredModule, bp::wrapper< ChiSquaredModule > {

    ChiSquaredModule_wrapper( )
    : ChiSquaredModule( )
      , bp::wrapper< ChiSquaredModule >(){
        // null constructor
    m_pyobj = 0;
    }

    ChiSquaredModule_wrapper(::ChiSquaredModule const & other )
    : ChiSquaredModule( boost::ref(other) )
      , bp::wrapper< ChiSquaredModule >(){
        // copy constructor
    m_pyobj = 0;
    }

    virtual ::ChiSquaredModule * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->ChiSquaredModule::clone(  );
        }
    }
    
    ::ChiSquaredModule * default_clone(  ) const  {
        return ChiSquaredModule::clone( );
    }

    virtual ::IIntensityFunction const * getIntensityFunction(  ) const  {
        if( bp::override func_getIntensityFunction = this->get_override( "getIntensityFunction" ) )
            return func_getIntensityFunction(  );
        else{
            return this->IChiSquaredModule::getIntensityFunction(  );
        }
    }
    
    ::IIntensityFunction const * default_getIntensityFunction(  ) const  {
        return IChiSquaredModule::getIntensityFunction( );
    }

    virtual ::IIntensityNormalizer const * getIntensityNormalizer(  ) const  {
        if( bp::override func_getIntensityNormalizer = this->get_override( "getIntensityNormalizer" ) )
            return func_getIntensityNormalizer(  );
        else{
            return this->IChiSquaredModule::getIntensityNormalizer(  );
        }
    }
    
    ::IIntensityNormalizer const * default_getIntensityNormalizer(  ) const  {
        return IChiSquaredModule::getIntensityNormalizer( );
    }

    virtual ::IIntensityNormalizer * getIntensityNormalizer(  ) {
        if( bp::override func_getIntensityNormalizer = this->get_override( "getIntensityNormalizer" ) )
            return func_getIntensityNormalizer(  );
        else{
            return this->IChiSquaredModule::getIntensityNormalizer(  );
        }
    }
    
    ::IIntensityNormalizer * default_getIntensityNormalizer(  ) {
        return IChiSquaredModule::getIntensityNormalizer( );
    }

    virtual void setIntensityFunction( ::IIntensityFunction const & intensity_function ) {
        if( bp::override func_setIntensityFunction = this->get_override( "setIntensityFunction" ) )
            func_setIntensityFunction( boost::ref(intensity_function) );
        else{
            this->IChiSquaredModule::setIntensityFunction( boost::ref(intensity_function) );
        }
    }
    
    void default_setIntensityFunction( ::IIntensityFunction const & intensity_function ) {
        IChiSquaredModule::setIntensityFunction( boost::ref(intensity_function) );
    }

    virtual void setIntensityNormalizer( ::IIntensityNormalizer const & data_normalizer ) {
        if( bp::override func_setIntensityNormalizer = this->get_override( "setIntensityNormalizer" ) )
            func_setIntensityNormalizer( boost::ref(data_normalizer) );
        else{
            this->IChiSquaredModule::setIntensityNormalizer( boost::ref(data_normalizer) );
        }
    }
    
    void default_setIntensityNormalizer( ::IIntensityNormalizer const & data_normalizer ) {
        IChiSquaredModule::setIntensityNormalizer( boost::ref(data_normalizer) );
    }

    PyObject* m_pyobj;

};

void register_ChiSquaredModule_class(){

    { //::ChiSquaredModule
        typedef bp::class_< ChiSquaredModule_wrapper, bp::bases< IChiSquaredModule >, std::auto_ptr< ChiSquaredModule_wrapper > > ChiSquaredModule_exposer_t;
        ChiSquaredModule_exposer_t ChiSquaredModule_exposer = ChiSquaredModule_exposer_t( "ChiSquaredModule", "Calculation of chi2 between two data set.", bp::init< >() );
        bp::scope ChiSquaredModule_scope( ChiSquaredModule_exposer );
        ChiSquaredModule_exposer.def( bp::init< ChiSquaredModule const & >(( bp::arg("other") )) );
        { //::ChiSquaredModule::clone
        
            typedef ::ChiSquaredModule * ( ::ChiSquaredModule::*clone_function_type)(  ) const;
            typedef ::ChiSquaredModule * ( ChiSquaredModule_wrapper::*default_clone_function_type)(  ) const;
            
            ChiSquaredModule_exposer.def( 
                "clone"
                , clone_function_type(&::ChiSquaredModule::clone)
                , default_clone_function_type(&ChiSquaredModule_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IChiSquaredModule::getIntensityFunction
        
            typedef ::IIntensityFunction const * ( ::IChiSquaredModule::*getIntensityFunction_function_type)(  ) const;
            typedef ::IIntensityFunction const * ( ChiSquaredModule_wrapper::*default_getIntensityFunction_function_type)(  ) const;
            
            ChiSquaredModule_exposer.def( 
                "getIntensityFunction"
                , getIntensityFunction_function_type(&::IChiSquaredModule::getIntensityFunction)
                , default_getIntensityFunction_function_type(&ChiSquaredModule_wrapper::default_getIntensityFunction)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IChiSquaredModule::getIntensityNormalizer
        
            typedef ::IIntensityNormalizer const * ( ::IChiSquaredModule::*getIntensityNormalizer_function_type)(  ) const;
            typedef ::IIntensityNormalizer const * ( ChiSquaredModule_wrapper::*default_getIntensityNormalizer_function_type)(  ) const;
            
            ChiSquaredModule_exposer.def( 
                "getIntensityNormalizer"
                , getIntensityNormalizer_function_type(&::IChiSquaredModule::getIntensityNormalizer)
                , default_getIntensityNormalizer_function_type(&ChiSquaredModule_wrapper::default_getIntensityNormalizer)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IChiSquaredModule::getIntensityNormalizer
        
            typedef ::IIntensityNormalizer * ( ::IChiSquaredModule::*getIntensityNormalizer_function_type)(  ) ;
            typedef ::IIntensityNormalizer * ( ChiSquaredModule_wrapper::*default_getIntensityNormalizer_function_type)(  ) ;
            
            ChiSquaredModule_exposer.def( 
                "getIntensityNormalizer"
                , getIntensityNormalizer_function_type(&::IChiSquaredModule::getIntensityNormalizer)
                , default_getIntensityNormalizer_function_type(&ChiSquaredModule_wrapper::default_getIntensityNormalizer)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IChiSquaredModule::setIntensityFunction
        
            typedef void ( ::IChiSquaredModule::*setIntensityFunction_function_type)( ::IIntensityFunction const & ) ;
            typedef void ( ChiSquaredModule_wrapper::*default_setIntensityFunction_function_type)( ::IIntensityFunction const & ) ;
            
            ChiSquaredModule_exposer.def( 
                "setIntensityFunction"
                , setIntensityFunction_function_type(&::IChiSquaredModule::setIntensityFunction)
                , default_setIntensityFunction_function_type(&ChiSquaredModule_wrapper::default_setIntensityFunction)
                , ( bp::arg("intensity_function") ) );
        
        }
        { //::IChiSquaredModule::setIntensityNormalizer
        
            typedef void ( ::IChiSquaredModule::*setIntensityNormalizer_function_type)( ::IIntensityNormalizer const & ) ;
            typedef void ( ChiSquaredModule_wrapper::*default_setIntensityNormalizer_function_type)( ::IIntensityNormalizer const & ) ;
            
            ChiSquaredModule_exposer.def( 
                "setIntensityNormalizer"
                , setIntensityNormalizer_function_type(&::IChiSquaredModule::setIntensityNormalizer)
                , default_setIntensityNormalizer_function_type(&ChiSquaredModule_wrapper::default_setIntensityNormalizer)
                , ( bp::arg("data_normalizer") ) );
        
        }
    }

}
