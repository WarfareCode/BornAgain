// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "AttLimits.h"
#include "IChiSquaredModule.h"
#include "IMinimizer.h"
#include "ChiSquaredModule.h"
#include "FitSuite.h"
#include "MinimizerFactory.h"
#include "OutputData.h"
#include "PythonPlusplusFitHelper.h"
#include "ChiSquaredModule.pypp.h"

namespace bp = boost::python;

struct ChiSquaredModule_wrapper : ChiSquaredModule, bp::wrapper< ChiSquaredModule > {

    ChiSquaredModule_wrapper( )
    : ChiSquaredModule( )
      , bp::wrapper< ChiSquaredModule >(){
        // null constructor
    
    }

    ChiSquaredModule_wrapper(::ChiSquaredModule const & other )
    : ChiSquaredModule( boost::ref(other) )
      , bp::wrapper< ChiSquaredModule >(){
        // copy constructor
    
    }

    virtual double calculateChiSquared(  ) {
        if( bp::override func_calculateChiSquared = this->get_override( "calculateChiSquared" ) )
            return func_calculateChiSquared(  );
        else{
            return this->ChiSquaredModule::calculateChiSquared(  );
        }
    }
    
    double default_calculateChiSquared(  ) {
        return ChiSquaredModule::calculateChiSquared( );
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

    virtual ::OutputData< double > * createChi2DifferenceMap(  ) const  {
        if( bp::override func_createChi2DifferenceMap = this->get_override( "createChi2DifferenceMap" ) )
            return func_createChi2DifferenceMap(  );
        else{
            return this->ChiSquaredModule::createChi2DifferenceMap(  );
        }
    }
    
    ::OutputData< double > * default_createChi2DifferenceMap(  ) const  {
        return ChiSquaredModule::createChi2DifferenceMap( );
    }

    virtual double getResidualValue( ::size_t index ) const  {
        if( bp::override func_getResidualValue = this->get_override( "getResidualValue" ) )
            return func_getResidualValue( index );
        else{
            return this->ChiSquaredModule::getResidualValue( index );
        }
    }
    
    double default_getResidualValue( ::size_t index ) const  {
        return ChiSquaredModule::getResidualValue( index );
    }

    virtual ::IFittingDataSelector const * getFittingDataSelector(  ) const  {
        if( bp::override func_getFittingDataSelector = this->get_override( "getFittingDataSelector" ) )
            return func_getFittingDataSelector(  );
        else{
            return this->IChiSquaredModule::getFittingDataSelector(  );
        }
    }
    
    ::IFittingDataSelector const * default_getFittingDataSelector(  ) const  {
        return IChiSquaredModule::getFittingDataSelector( );
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

    virtual ::IOutputDataNormalizer const * getOutputDataNormalizer(  ) const  {
        if( bp::override func_getOutputDataNormalizer = this->get_override( "getOutputDataNormalizer" ) )
            return func_getOutputDataNormalizer(  );
        else{
            return this->IChiSquaredModule::getOutputDataNormalizer(  );
        }
    }
    
    ::IOutputDataNormalizer const * default_getOutputDataNormalizer(  ) const  {
        return IChiSquaredModule::getOutputDataNormalizer( );
    }

    virtual ::IOutputDataNormalizer * getOutputDataNormalizer(  ) {
        if( bp::override func_getOutputDataNormalizer = this->get_override( "getOutputDataNormalizer" ) )
            return func_getOutputDataNormalizer(  );
        else{
            return this->IChiSquaredModule::getOutputDataNormalizer(  );
        }
    }
    
    ::IOutputDataNormalizer * default_getOutputDataNormalizer(  ) {
        return IChiSquaredModule::getOutputDataNormalizer( );
    }

    virtual double getValue(  ) const  {
        if( bp::override func_getValue = this->get_override( "getValue" ) )
            return func_getValue(  );
        else{
            return this->IChiSquaredModule::getValue(  );
        }
    }
    
    double default_getValue(  ) const  {
        return IChiSquaredModule::getValue( );
    }

    virtual void setFittingDataSelector( ::IFittingDataSelector const & selector ) {
        if( bp::override func_setFittingDataSelector = this->get_override( "setFittingDataSelector" ) )
            func_setFittingDataSelector( boost::ref(selector) );
        else{
            this->IChiSquaredModule::setFittingDataSelector( boost::ref(selector) );
        }
    }
    
    void default_setFittingDataSelector( ::IFittingDataSelector const & selector ) {
        IChiSquaredModule::setFittingDataSelector( boost::ref(selector) );
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

    virtual void setOutputDataNormalizer( ::IOutputDataNormalizer const & data_normalizer ) {
        if( bp::override func_setOutputDataNormalizer = this->get_override( "setOutputDataNormalizer" ) )
            func_setOutputDataNormalizer( boost::ref(data_normalizer) );
        else{
            this->IChiSquaredModule::setOutputDataNormalizer( boost::ref(data_normalizer) );
        }
    }
    
    void default_setOutputDataNormalizer( ::IOutputDataNormalizer const & data_normalizer ) {
        IChiSquaredModule::setOutputDataNormalizer( boost::ref(data_normalizer) );
    }

};

void register_ChiSquaredModule_class(){

    bp::class_< ChiSquaredModule_wrapper, bp::bases< IChiSquaredModule > >( "ChiSquaredModule", bp::init< >() )    
        .def( bp::init< ChiSquaredModule const & >(( bp::arg("other") )) )    
        .def( 
            "calculateChiSquared"
            , (double ( ::ChiSquaredModule::* )(  ) )(&::ChiSquaredModule::calculateChiSquared)
            , (double ( ChiSquaredModule_wrapper::* )(  ) )(&ChiSquaredModule_wrapper::default_calculateChiSquared) )    
        .def( 
            "clone"
            , (::ChiSquaredModule * ( ::ChiSquaredModule::* )(  ) const)(&::ChiSquaredModule::clone)
            , (::ChiSquaredModule * ( ChiSquaredModule_wrapper::* )(  ) const)(&ChiSquaredModule_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "createChi2DifferenceMap"
            , (::OutputData< double > * ( ::ChiSquaredModule::* )(  ) const)(&::ChiSquaredModule::createChi2DifferenceMap)
            , (::OutputData< double > * ( ChiSquaredModule_wrapper::* )(  ) const)(&ChiSquaredModule_wrapper::default_createChi2DifferenceMap)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "getResidualValue"
            , (double ( ::ChiSquaredModule::* )( ::size_t ) const)(&::ChiSquaredModule::getResidualValue)
            , (double ( ChiSquaredModule_wrapper::* )( ::size_t ) const)(&ChiSquaredModule_wrapper::default_getResidualValue)
            , ( bp::arg("index") ) )    
        .def( 
            "getFittingDataSelector"
            , (::IFittingDataSelector const * ( ::IChiSquaredModule::* )(  ) const)(&::IChiSquaredModule::getFittingDataSelector)
            , (::IFittingDataSelector const * ( ChiSquaredModule_wrapper::* )(  ) const)(&ChiSquaredModule_wrapper::default_getFittingDataSelector)
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "getIntensityFunction"
            , (::IIntensityFunction const * ( ::IChiSquaredModule::* )(  ) const)(&::IChiSquaredModule::getIntensityFunction)
            , (::IIntensityFunction const * ( ChiSquaredModule_wrapper::* )(  ) const)(&ChiSquaredModule_wrapper::default_getIntensityFunction)
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "getOutputDataNormalizer"
            , (::IOutputDataNormalizer const * ( ::IChiSquaredModule::* )(  ) const)(&::IChiSquaredModule::getOutputDataNormalizer)
            , (::IOutputDataNormalizer const * ( ChiSquaredModule_wrapper::* )(  ) const)(&ChiSquaredModule_wrapper::default_getOutputDataNormalizer)
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "getOutputDataNormalizer"
            , (::IOutputDataNormalizer * ( ::IChiSquaredModule::* )(  ) )(&::IChiSquaredModule::getOutputDataNormalizer)
            , (::IOutputDataNormalizer * ( ChiSquaredModule_wrapper::* )(  ) )(&ChiSquaredModule_wrapper::default_getOutputDataNormalizer)
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "getValue"
            , (double ( ::IChiSquaredModule::* )(  ) const)(&::IChiSquaredModule::getValue)
            , (double ( ChiSquaredModule_wrapper::* )(  ) const)(&ChiSquaredModule_wrapper::default_getValue) )    
        .def( 
            "setFittingDataSelector"
            , (void ( ::IChiSquaredModule::* )( ::IFittingDataSelector const & ) )(&::IChiSquaredModule::setFittingDataSelector)
            , (void ( ChiSquaredModule_wrapper::* )( ::IFittingDataSelector const & ) )(&ChiSquaredModule_wrapper::default_setFittingDataSelector)
            , ( bp::arg("selector") ) )    
        .def( 
            "setIntensityFunction"
            , (void ( ::IChiSquaredModule::* )( ::IIntensityFunction const & ) )(&::IChiSquaredModule::setIntensityFunction)
            , (void ( ChiSquaredModule_wrapper::* )( ::IIntensityFunction const & ) )(&ChiSquaredModule_wrapper::default_setIntensityFunction)
            , ( bp::arg("intensity_function") ) )    
        .def( 
            "setOutputDataNormalizer"
            , (void ( ::IChiSquaredModule::* )( ::IOutputDataNormalizer const & ) )(&::IChiSquaredModule::setOutputDataNormalizer)
            , (void ( ChiSquaredModule_wrapper::* )( ::IOutputDataNormalizer const & ) )(&ChiSquaredModule_wrapper::default_setOutputDataNormalizer)
            , ( bp::arg("data_normalizer") ) );

}