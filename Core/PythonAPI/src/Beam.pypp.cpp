// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "Beam.pypp.h"

namespace bp = boost::python;

struct Beam_wrapper : Beam, bp::wrapper< Beam > {

    Beam_wrapper( )
    : Beam( )
      , bp::wrapper< Beam >(){
        // null constructor
    
    }

    Beam_wrapper(::Beam const & other )
    : Beam( boost::ref(other) )
      , bp::wrapper< Beam >(){
        // copy constructor
    
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

    virtual void registerParameter( ::std::string const & name, double * parpointer ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer );
        }
        else{
            IParameterized::registerParameter( name, parpointer );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer ){
        if( dynamic_cast< Beam_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
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

void register_Beam_class(){

    { //::Beam
        typedef bp::class_< Beam_wrapper, bp::bases< IParameterized > > Beam_exposer_t;
        Beam_exposer_t Beam_exposer = Beam_exposer_t( "Beam", bp::init< >() );
        bp::scope Beam_scope( Beam_exposer );
        Beam_exposer.def( bp::init< Beam const & >(( bp::arg("other") )) );
        { //::Beam::SetSpinUpFraction
        
            typedef void ( ::Beam::*SetSpinUpFraction_function_type)( double ) ;
            
            Beam_exposer.def( 
                "SetSpinUpFraction"
                , SetSpinUpFraction_function_type( &::Beam::SetSpinUpFraction )
                , ( bp::arg("up_fraction") ) );
        
        }
        { //::Beam::getAlpha
        
            typedef double ( ::Beam::*getAlpha_function_type)(  ) const;
            
            Beam_exposer.def( 
                "getAlpha"
                , getAlpha_function_type( &::Beam::getAlpha ) );
        
        }
        { //::Beam::getCentralK
        
            typedef ::cvector_t ( ::Beam::*getCentralK_function_type)(  ) const;
            
            Beam_exposer.def( 
                "getCentralK"
                , getCentralK_function_type( &::Beam::getCentralK ) );
        
        }
        { //::Beam::getIntensity
        
            typedef double ( ::Beam::*getIntensity_function_type)(  ) const;
            
            Beam_exposer.def( 
                "getIntensity"
                , getIntensity_function_type( &::Beam::getIntensity ) );
        
        }
        { //::Beam::getPhi
        
            typedef double ( ::Beam::*getPhi_function_type)(  ) const;
            
            Beam_exposer.def( 
                "getPhi"
                , getPhi_function_type( &::Beam::getPhi ) );
        
        }
        { //::Beam::getWavelength
        
            typedef double ( ::Beam::*getWavelength_function_type)(  ) const;
            
            Beam_exposer.def( 
                "getWavelength"
                , getWavelength_function_type( &::Beam::getWavelength ) );
        
        }
        { //::Beam::operator=
        
            typedef ::Beam & ( ::Beam::*assign_function_type)( ::Beam const & ) ;
            
            Beam_exposer.def( 
                "assign"
                , assign_function_type( &::Beam::operator= )
                , ( bp::arg("other") )
                , bp::return_self< >() );
        
        }
        { //::Beam::setCentralK
        
            typedef void ( ::Beam::*setCentralK_function_type)( double,double,double ) ;
            
            Beam_exposer.def( 
                "setCentralK"
                , setCentralK_function_type( &::Beam::setCentralK )
                , ( bp::arg("lambda"), bp::arg("alpha_i"), bp::arg("phi_i") ) );
        
        }
        { //::Beam::setIntensity
        
            typedef void ( ::Beam::*setIntensity_function_type)( double ) ;
            
            Beam_exposer.def( 
                "setIntensity"
                , setIntensity_function_type( &::Beam::setIntensity )
                , ( bp::arg("intensity") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type)(  ) ;
            typedef bool ( Beam_wrapper::*default_areParametersChanged_function_type)(  ) ;
            
            Beam_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&Beam_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type)(  ) ;
            typedef void ( Beam_wrapper::*default_clearParameterPool_function_type)(  ) ;
            
            Beam_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&Beam_wrapper::default_clearParameterPool) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type)(  ) const;
            typedef ::ParameterPool * ( Beam_wrapper::*default_createParameterTree_function_type)(  ) const;
            
            Beam_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&Beam_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type)(  ) const;
            typedef void ( Beam_wrapper::*default_printParameters_function_type)(  ) const;
            
            Beam_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&Beam_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            Beam_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &Beam_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type)( ::std::string const &,double ) ;
            typedef bool ( Beam_wrapper::*default_setParameterValue_function_type)( ::std::string const &,double ) ;
            
            Beam_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&Beam_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type)(  ) ;
            typedef void ( Beam_wrapper::*default_setParametersAreChanged_function_type)(  ) ;
            
            Beam_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&Beam_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
