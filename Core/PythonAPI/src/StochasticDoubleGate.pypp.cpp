// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "StochasticDoubleGate.pypp.h"

namespace bp = boost::python;

struct StochasticDoubleGate_wrapper : StochasticDoubleGate, bp::wrapper< StochasticDoubleGate > {

    StochasticDoubleGate_wrapper(double min, double max )
    : StochasticDoubleGate( min, max )
      , bp::wrapper< StochasticDoubleGate >(){
        // constructor
    
    }

    virtual ::StochasticDoubleGate * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->StochasticDoubleGate::clone(  );
        }
    }
    
    ::StochasticDoubleGate * default_clone(  ) const  {
        return StochasticDoubleGate::clone( );
    }

    virtual double getFWHM(  ) const  {
        if( bp::override func_getFWHM = this->get_override( "getFWHM" ) )
            return func_getFWHM(  );
        else{
            return this->StochasticDoubleGate::getFWHM(  );
        }
    }
    
    double default_getFWHM(  ) const  {
        return StochasticDoubleGate::getFWHM( );
    }

    virtual double probabilityDensity( double value ) const  {
        if( bp::override func_probabilityDensity = this->get_override( "probabilityDensity" ) )
            return func_probabilityDensity( value );
        else{
            return this->StochasticDoubleGate::probabilityDensity( value );
        }
    }
    
    double default_probabilityDensity( double value ) const  {
        return StochasticDoubleGate::probabilityDensity( value );
    }

    virtual void setToRandom(  ) {
        if( bp::override func_setToRandom = this->get_override( "setToRandom" ) )
            func_setToRandom(  );
        else{
            this->StochasticDoubleGate::setToRandom(  );
        }
    }
    
    void default_setToRandom(  ) {
        StochasticDoubleGate::setToRandom( );
    }

    virtual double getRandom(  ) {
        if( bp::override func_getRandom = this->get_override( "getRandom" ) )
            return func_getRandom(  );
        else{
            return this->StochasticParameter< double >::getRandom(  );
        }
    }
    
    double default_getRandom(  ) {
        return StochasticParameter< double >::getRandom( );
    }

    virtual void setToAverage(  ) {
        if( bp::override func_setToAverage = this->get_override( "setToAverage" ) )
            func_setToAverage(  );
        else{
            this->StochasticParameter< double >::setToAverage(  );
        }
    }
    
    void default_setToAverage(  ) {
        StochasticParameter< double >::setToAverage( );
    }

};

void register_StochasticDoubleGate_class(){

    { //::StochasticDoubleGate
        typedef bp::class_< StochasticDoubleGate_wrapper, bp::bases< StochasticParameter< double > >, boost::noncopyable > StochasticDoubleGate_exposer_t;
        StochasticDoubleGate_exposer_t StochasticDoubleGate_exposer = StochasticDoubleGate_exposer_t( "StochasticDoubleGate", bp::init< double, double >(( bp::arg("min"), bp::arg("max") )) );
        bp::scope StochasticDoubleGate_scope( StochasticDoubleGate_exposer );
        { //::StochasticDoubleGate::clone
        
            typedef ::StochasticDoubleGate * ( ::StochasticDoubleGate::*clone_function_type)(  ) const;
            typedef ::StochasticDoubleGate * ( StochasticDoubleGate_wrapper::*default_clone_function_type)(  ) const;
            
            StochasticDoubleGate_exposer.def( 
                "clone"
                , clone_function_type(&::StochasticDoubleGate::clone)
                , default_clone_function_type(&StochasticDoubleGate_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::StochasticDoubleGate::getFWHM
        
            typedef double ( ::StochasticDoubleGate::*getFWHM_function_type)(  ) const;
            typedef double ( StochasticDoubleGate_wrapper::*default_getFWHM_function_type)(  ) const;
            
            StochasticDoubleGate_exposer.def( 
                "getFWHM"
                , getFWHM_function_type(&::StochasticDoubleGate::getFWHM)
                , default_getFWHM_function_type(&StochasticDoubleGate_wrapper::default_getFWHM) );
        
        }
        { //::StochasticDoubleGate::getStdDev
        
            typedef double ( ::StochasticDoubleGate::*getStdDev_function_type)(  ) const;
            
            StochasticDoubleGate_exposer.def( 
                "getStdDev"
                , getStdDev_function_type( &::StochasticDoubleGate::getStdDev ) );
        
        }
        { //::StochasticDoubleGate::probabilityDensity
        
            typedef double ( ::StochasticDoubleGate::*probabilityDensity_function_type)( double ) const;
            typedef double ( StochasticDoubleGate_wrapper::*default_probabilityDensity_function_type)( double ) const;
            
            StochasticDoubleGate_exposer.def( 
                "probabilityDensity"
                , probabilityDensity_function_type(&::StochasticDoubleGate::probabilityDensity)
                , default_probabilityDensity_function_type(&StochasticDoubleGate_wrapper::default_probabilityDensity)
                , ( bp::arg("value") ) );
        
        }
        { //::StochasticDoubleGate::setToRandom
        
            typedef void ( ::StochasticDoubleGate::*setToRandom_function_type)(  ) ;
            typedef void ( StochasticDoubleGate_wrapper::*default_setToRandom_function_type)(  ) ;
            
            StochasticDoubleGate_exposer.def( 
                "setToRandom"
                , setToRandom_function_type(&::StochasticDoubleGate::setToRandom)
                , default_setToRandom_function_type(&StochasticDoubleGate_wrapper::default_setToRandom) );
        
        }
        { //::StochasticParameter< double >::getRandom
        
            typedef StochasticDoubleGate exported_class_t;
            typedef double ( exported_class_t::*getRandom_function_type)(  ) ;
            typedef double ( StochasticDoubleGate_wrapper::*default_getRandom_function_type)(  ) ;
            
            StochasticDoubleGate_exposer.def( 
                "getRandom"
                , getRandom_function_type(&::StochasticParameter< double >::getRandom)
                , default_getRandom_function_type(&StochasticDoubleGate_wrapper::default_getRandom) );
        
        }
        { //::StochasticParameter< double >::setToAverage
        
            typedef StochasticDoubleGate exported_class_t;
            typedef void ( exported_class_t::*setToAverage_function_type)(  ) ;
            typedef void ( StochasticDoubleGate_wrapper::*default_setToAverage_function_type)(  ) ;
            
            StochasticDoubleGate_exposer.def( 
                "setToAverage"
                , setToAverage_function_type(&::StochasticParameter< double >::setToAverage)
                , default_setToAverage_function_type(&StochasticDoubleGate_wrapper::default_setToAverage) );
        
        }
    }

}
