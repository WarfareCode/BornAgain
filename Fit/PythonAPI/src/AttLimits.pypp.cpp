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
#include "AttLimits.pypp.h"

namespace bp = boost::python;

struct AttLimits_wrapper : AttLimits, bp::wrapper< AttLimits > {

    AttLimits_wrapper(AttLimits const & arg )
    : AttLimits( arg )
      , bp::wrapper< AttLimits >(){
        // copy constructor
        
    }

    AttLimits_wrapper( )
    : AttLimits( )
      , bp::wrapper< AttLimits >(){
        // null constructor
    
    }

    virtual double getLowerLimit(  ) const  {
        if( bp::override func_getLowerLimit = this->get_override( "getLowerLimit" ) )
            return func_getLowerLimit(  );
        else{
            return this->AttLimits::getLowerLimit(  );
        }
    }
    
    double default_getLowerLimit(  ) const  {
        return AttLimits::getLowerLimit( );
    }

    virtual double getUpperLimit(  ) const  {
        if( bp::override func_getUpperLimit = this->get_override( "getUpperLimit" ) )
            return func_getUpperLimit(  );
        else{
            return this->AttLimits::getUpperLimit(  );
        }
    }
    
    double default_getUpperLimit(  ) const  {
        return AttLimits::getUpperLimit( );
    }

    virtual bool hasLowerAndUpperLimits(  ) const  {
        if( bp::override func_hasLowerAndUpperLimits = this->get_override( "hasLowerAndUpperLimits" ) )
            return func_hasLowerAndUpperLimits(  );
        else{
            return this->AttLimits::hasLowerAndUpperLimits(  );
        }
    }
    
    bool default_hasLowerAndUpperLimits(  ) const  {
        return AttLimits::hasLowerAndUpperLimits( );
    }

    virtual bool hasLowerLimit(  ) const  {
        if( bp::override func_hasLowerLimit = this->get_override( "hasLowerLimit" ) )
            return func_hasLowerLimit(  );
        else{
            return this->AttLimits::hasLowerLimit(  );
        }
    }
    
    bool default_hasLowerLimit(  ) const  {
        return AttLimits::hasLowerLimit( );
    }

    virtual bool hasUpperLimit(  ) const  {
        if( bp::override func_hasUpperLimit = this->get_override( "hasUpperLimit" ) )
            return func_hasUpperLimit(  );
        else{
            return this->AttLimits::hasUpperLimit(  );
        }
    }
    
    bool default_hasUpperLimit(  ) const  {
        return AttLimits::hasUpperLimit( );
    }

    virtual bool isFixed(  ) const  {
        if( bp::override func_isFixed = this->get_override( "isFixed" ) )
            return func_isFixed(  );
        else{
            return this->AttLimits::isFixed(  );
        }
    }
    
    bool default_isFixed(  ) const  {
        return AttLimits::isFixed( );
    }

    virtual void removeLimits(  ) {
        if( bp::override func_removeLimits = this->get_override( "removeLimits" ) )
            func_removeLimits(  );
        else{
            this->AttLimits::removeLimits(  );
        }
    }
    
    void default_removeLimits(  ) {
        AttLimits::removeLimits( );
    }

    virtual void removeLowerLimit(  ) {
        if( bp::override func_removeLowerLimit = this->get_override( "removeLowerLimit" ) )
            func_removeLowerLimit(  );
        else{
            this->AttLimits::removeLowerLimit(  );
        }
    }
    
    void default_removeLowerLimit(  ) {
        AttLimits::removeLowerLimit( );
    }

    virtual void removeUpperLimit(  ) {
        if( bp::override func_removeUpperLimit = this->get_override( "removeUpperLimit" ) )
            func_removeUpperLimit(  );
        else{
            this->AttLimits::removeUpperLimit(  );
        }
    }
    
    void default_removeUpperLimit(  ) {
        AttLimits::removeUpperLimit( );
    }

    virtual void setFixed( bool is_fixed ) {
        if( bp::override func_setFixed = this->get_override( "setFixed" ) )
            func_setFixed( is_fixed );
        else{
            this->AttLimits::setFixed( is_fixed );
        }
    }
    
    void default_setFixed( bool is_fixed ) {
        AttLimits::setFixed( is_fixed );
    }

    virtual void setLimits( double xmin, double xmax ) {
        if( bp::override func_setLimits = this->get_override( "setLimits" ) )
            func_setLimits( xmin, xmax );
        else{
            this->AttLimits::setLimits( xmin, xmax );
        }
    }
    
    void default_setLimits( double xmin, double xmax ) {
        AttLimits::setLimits( xmin, xmax );
    }

    virtual void setLowerLimit( double value ) {
        if( bp::override func_setLowerLimit = this->get_override( "setLowerLimit" ) )
            func_setLowerLimit( value );
        else{
            this->AttLimits::setLowerLimit( value );
        }
    }
    
    void default_setLowerLimit( double value ) {
        AttLimits::setLowerLimit( value );
    }

    virtual void setUpperLimit( double value ) {
        if( bp::override func_setUpperLimit = this->get_override( "setUpperLimit" ) )
            func_setUpperLimit( value );
        else{
            this->AttLimits::setUpperLimit( value );
        }
    }
    
    void default_setUpperLimit( double value ) {
        AttLimits::setUpperLimit( value );
    }

};

void register_AttLimits_class(){

    bp::class_< AttLimits_wrapper >( "AttLimits", bp::init< >() )    
        .def( 
            "fixed"
            , (::AttLimits (*)(  ))( &::AttLimits::fixed ) )    
        .def( 
            "getLowerLimit"
            , (double ( ::AttLimits::* )(  ) const)(&::AttLimits::getLowerLimit)
            , (double ( AttLimits_wrapper::* )(  ) const)(&AttLimits_wrapper::default_getLowerLimit) )    
        .def( 
            "getUpperLimit"
            , (double ( ::AttLimits::* )(  ) const)(&::AttLimits::getUpperLimit)
            , (double ( AttLimits_wrapper::* )(  ) const)(&AttLimits_wrapper::default_getUpperLimit) )    
        .def( 
            "hasLowerAndUpperLimits"
            , (bool ( ::AttLimits::* )(  ) const)(&::AttLimits::hasLowerAndUpperLimits)
            , (bool ( AttLimits_wrapper::* )(  ) const)(&AttLimits_wrapper::default_hasLowerAndUpperLimits) )    
        .def( 
            "hasLowerLimit"
            , (bool ( ::AttLimits::* )(  ) const)(&::AttLimits::hasLowerLimit)
            , (bool ( AttLimits_wrapper::* )(  ) const)(&AttLimits_wrapper::default_hasLowerLimit) )    
        .def( 
            "hasUpperLimit"
            , (bool ( ::AttLimits::* )(  ) const)(&::AttLimits::hasUpperLimit)
            , (bool ( AttLimits_wrapper::* )(  ) const)(&AttLimits_wrapper::default_hasUpperLimit) )    
        .def( 
            "isFixed"
            , (bool ( ::AttLimits::* )(  ) const)(&::AttLimits::isFixed)
            , (bool ( AttLimits_wrapper::* )(  ) const)(&AttLimits_wrapper::default_isFixed) )    
        .def( 
            "limited"
            , (::AttLimits (*)( double,double ))( &::AttLimits::limited )
            , ( bp::arg("left_bound_value"), bp::arg("right_bound_value") ) )    
        .def( 
            "limitless"
            , (::AttLimits (*)(  ))( &::AttLimits::limitless ) )    
        .def( 
            "lowerLimited"
            , (::AttLimits (*)( double ))( &::AttLimits::lowerLimited )
            , ( bp::arg("bound_value") ) )    
        .def( 
            "removeLimits"
            , (void ( ::AttLimits::* )(  ) )(&::AttLimits::removeLimits)
            , (void ( AttLimits_wrapper::* )(  ) )(&AttLimits_wrapper::default_removeLimits) )    
        .def( 
            "removeLowerLimit"
            , (void ( ::AttLimits::* )(  ) )(&::AttLimits::removeLowerLimit)
            , (void ( AttLimits_wrapper::* )(  ) )(&AttLimits_wrapper::default_removeLowerLimit) )    
        .def( 
            "removeUpperLimit"
            , (void ( ::AttLimits::* )(  ) )(&::AttLimits::removeUpperLimit)
            , (void ( AttLimits_wrapper::* )(  ) )(&AttLimits_wrapper::default_removeUpperLimit) )    
        .def( 
            "setFixed"
            , (void ( ::AttLimits::* )( bool ) )(&::AttLimits::setFixed)
            , (void ( AttLimits_wrapper::* )( bool ) )(&AttLimits_wrapper::default_setFixed)
            , ( bp::arg("is_fixed") ) )    
        .def( 
            "setLimits"
            , (void ( ::AttLimits::* )( double,double ) )(&::AttLimits::setLimits)
            , (void ( AttLimits_wrapper::* )( double,double ) )(&AttLimits_wrapper::default_setLimits)
            , ( bp::arg("xmin"), bp::arg("xmax") ) )    
        .def( 
            "setLowerLimit"
            , (void ( ::AttLimits::* )( double ) )(&::AttLimits::setLowerLimit)
            , (void ( AttLimits_wrapper::* )( double ) )(&AttLimits_wrapper::default_setLowerLimit)
            , ( bp::arg("value") ) )    
        .def( 
            "setUpperLimit"
            , (void ( ::AttLimits::* )( double ) )(&::AttLimits::setUpperLimit)
            , (void ( AttLimits_wrapper::* )( double ) )(&AttLimits_wrapper::default_setUpperLimit)
            , ( bp::arg("value") ) )    
        .def( 
            "upperLimited"
            , (::AttLimits (*)( double ))( &::AttLimits::upperLimited )
            , ( bp::arg("bound_value") ) )    
        .staticmethod( "fixed" )    
        .staticmethod( "limited" )    
        .staticmethod( "limitless" )    
        .staticmethod( "lowerLimited" )    
        .staticmethod( "upperLimited" )    
        .def( bp::self_ns::str( bp::self ) );

}