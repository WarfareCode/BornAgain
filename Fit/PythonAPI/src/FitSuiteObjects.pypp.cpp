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
#include "FitSuiteObjects.pypp.h"

namespace bp = boost::python;

struct FitSuiteObjects_wrapper : FitSuiteObjects, bp::wrapper< FitSuiteObjects > {

    FitSuiteObjects_wrapper( )
    : FitSuiteObjects( )
      , bp::wrapper< FitSuiteObjects >(){
        // null constructor
    
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else{
            return this->IParameterized::areParametersChanged(  );
        }
    }
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else{
            this->IParameterized::clearParameterPool(  );
        }
    }
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else{
            return this->IParameterized::createParameterTree(  );
        }
    }
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else{
            this->IParameterized::printParameters(  );
        }
    }
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else{
            return this->IParameterized::setParameterValue( name, value );
        }
    }
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else{
            this->IParameterized::setParametersAreChanged(  );
        }
    }
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

};

void register_FitSuiteObjects_class(){

    { //::FitSuiteObjects
        typedef bp::class_< FitSuiteObjects_wrapper, bp::bases< IParameterized >, boost::noncopyable > FitSuiteObjects_exposer_t;
        FitSuiteObjects_exposer_t FitSuiteObjects_exposer = FitSuiteObjects_exposer_t( "FitSuiteObjects", "The class containing vector of FitObject (simulation and real data) to fi.", bp::no_init );
        bp::scope FitSuiteObjects_scope( FitSuiteObjects_exposer );
        FitSuiteObjects_exposer.def( bp::init< >() );
        { //::FitSuiteObjects::add
        
            typedef void ( ::FitSuiteObjects::*add_function_type)( ::GISASSimulation const &,::OutputData< double > const &,double ) ;
            
            FitSuiteObjects_exposer.def( 
                "add"
                , add_function_type( &::FitSuiteObjects::add )
                , ( bp::arg("simulation"), bp::arg("real_data"), bp::arg("weight")=1.0e+0 )
                , "Adds to kit pair of (simulation, real data) for consecutive simulation." );
        
        }
        { //::FitSuiteObjects::clear
        
            typedef void ( ::FitSuiteObjects::*clear_function_type)(  ) ;
            
            FitSuiteObjects_exposer.def( 
                "clear"
                , clear_function_type( &::FitSuiteObjects::clear )
                , "clear all data." );
        
        }
        { //::FitSuiteObjects::getChiSquaredMap
        
            typedef ::OutputData< double > * ( ::FitSuiteObjects::*getChiSquaredMap_function_type)( ::std::size_t ) const;
            
            FitSuiteObjects_exposer.def( 
                "getChiSquaredMap"
                , getChiSquaredMap_function_type( &::FitSuiteObjects::getChiSquaredMap )
                , ( bp::arg("i_item")=(::std::size_t)(0) )
                , bp::return_value_policy< bp::manage_new_object >()
                , "Returns new chi-squared map from corresponding FitObject @param i_item Index of FitObject \n\n:Parameters:\n  - 'i_item' - Index of FitObject\n" );
        
        }
        { //::FitSuiteObjects::getChiSquaredValue
        
            typedef double ( ::FitSuiteObjects::*getChiSquaredValue_function_type)(  ) const;
            
            FitSuiteObjects_exposer.def( 
                "getChiSquaredValue"
                , getChiSquaredValue_function_type( &::FitSuiteObjects::getChiSquaredValue )
                , "Returns chi2 calculated over whole dataset." );
        
        }
        { //::FitSuiteObjects::getNumberOfFitObjects
        
            typedef ::std::size_t ( ::FitSuiteObjects::*getNumberOfFitObjects_function_type)(  ) const;
            
            FitSuiteObjects_exposer.def( 
                "getNumberOfFitObjects"
                , getNumberOfFitObjects_function_type( &::FitSuiteObjects::getNumberOfFitObjects )
                , "Returns number of fit objects (simulation/real data pairs)." );
        
        }
        { //::FitSuiteObjects::getRealData
        
            typedef ::OutputData< double > const * ( ::FitSuiteObjects::*getRealData_function_type)( ::std::size_t ) const;
            
            FitSuiteObjects_exposer.def( 
                "getRealData"
                , getRealData_function_type( &::FitSuiteObjects::getRealData )
                , ( bp::arg("i_item")=(::std::size_t)(0) )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Returns real data from corresponding FitObject @param i_item Index of FitObject \n\n:Parameters:\n  - 'i_item' - Index of FitObject\n" );
        
        }
        { //::FitSuiteObjects::getResidualValue
        
            typedef double ( ::FitSuiteObjects::*getResidualValue_function_type)( ::std::size_t ) ;
            
            FitSuiteObjects_exposer.def( 
                "getResidualValue"
                , getResidualValue_function_type( &::FitSuiteObjects::getResidualValue )
                , ( bp::arg("global_index") )
                , "Returns residuals for single data element @pars global_index index accross all element in FitElement vector " );
        
        }
        { //::FitSuiteObjects::getSimulationData
        
            typedef ::OutputData< double > const * ( ::FitSuiteObjects::*getSimulationData_function_type)( ::std::size_t ) const;
            
            FitSuiteObjects_exposer.def( 
                "getSimulationData"
                , getSimulationData_function_type( &::FitSuiteObjects::getSimulationData )
                , ( bp::arg("i_item")=(::std::size_t)(0) )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Returns simulated data from corresponding FitObject @param i_item Index of FitObject \n\n:Parameters:\n  - 'i_item' - Index of FitObject\n" );
        
        }
        { //::FitSuiteObjects::getSizeOfDataSet
        
            typedef ::std::size_t ( ::FitSuiteObjects::*getSizeOfDataSet_function_type)(  ) const;
            
            FitSuiteObjects_exposer.def( 
                "getSizeOfDataSet"
                , getSizeOfDataSet_function_type( &::FitSuiteObjects::getSizeOfDataSet )
                , "Returns total number of data points (number of all non-masked channels in all fit objects)." );
        
        }
        { //::FitSuiteObjects::runSimulations
        
            typedef void ( ::FitSuiteObjects::*runSimulations_function_type)(  ) ;
            
            FitSuiteObjects_exposer.def( 
                "runSimulations"
                , runSimulations_function_type( &::FitSuiteObjects::runSimulations )
                , "run all simulation defined in fit pairs." );
        
        }
        { //::FitSuiteObjects::setChiSquaredModule
        
            typedef void ( ::FitSuiteObjects::*setChiSquaredModule_function_type)( ::IChiSquaredModule const & ) ;
            
            FitSuiteObjects_exposer.def( 
                "setChiSquaredModule"
                , setChiSquaredModule_function_type( &::FitSuiteObjects::setChiSquaredModule )
                , ( bp::arg("chi2_module") )
                , "Replaces default ChiSquaredModule with new one." );
        
        }
        { //::FitSuiteObjects::setNfreeParameters
        
            typedef void ( ::FitSuiteObjects::*setNfreeParameters_function_type)( int ) ;
            
            FitSuiteObjects_exposer.def( 
                "setNfreeParameters"
                , setNfreeParameters_function_type( &::FitSuiteObjects::setNfreeParameters )
                , ( bp::arg("nfree_parameters") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type)(  ) ;
            typedef bool ( FitSuiteObjects_wrapper::*default_areParametersChanged_function_type)(  ) ;
            
            FitSuiteObjects_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&FitSuiteObjects_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type)(  ) ;
            typedef void ( FitSuiteObjects_wrapper::*default_clearParameterPool_function_type)(  ) ;
            
            FitSuiteObjects_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&FitSuiteObjects_wrapper::default_clearParameterPool) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type)(  ) const;
            typedef ::ParameterPool * ( FitSuiteObjects_wrapper::*default_createParameterTree_function_type)(  ) const;
            
            FitSuiteObjects_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&FitSuiteObjects_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type)(  ) const;
            typedef void ( FitSuiteObjects_wrapper::*default_printParameters_function_type)(  ) const;
            
            FitSuiteObjects_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&FitSuiteObjects_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type)( ::std::string const &,double ) ;
            typedef bool ( FitSuiteObjects_wrapper::*default_setParameterValue_function_type)( ::std::string const &,double ) ;
            
            FitSuiteObjects_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&FitSuiteObjects_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type)(  ) ;
            typedef void ( FitSuiteObjects_wrapper::*default_setParametersAreChanged_function_type)(  ) ;
            
            FitSuiteObjects_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&FitSuiteObjects_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
