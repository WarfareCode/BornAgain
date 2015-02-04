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
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "ParticleDistribution.pypp.h"

namespace bp = boost::python;

struct ParticleDistribution_wrapper : ParticleDistribution, bp::wrapper< ParticleDistribution > {

    ParticleDistribution_wrapper(::IParticle const & prototype, ::ParameterDistribution const & par_distr )
    : ParticleDistribution( boost::ref(prototype), boost::ref(par_distr) )
      , bp::wrapper< ParticleDistribution >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::ParticleDistribution * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->ParticleDistribution::clone(  );
        }
    }
    
    ::ParticleDistribution * default_clone(  ) const  {
        return ParticleDistribution::clone( );
    }

    virtual ::ParticleDistribution * cloneInvertB(  ) const  {
        if( bp::override func_cloneInvertB = this->get_override( "cloneInvertB" ) )
            return func_cloneInvertB(  );
        else{
            return this->ParticleDistribution::cloneInvertB(  );
        }
    }
    
    ::ParticleDistribution * default_cloneInvertB(  ) const  {
        return ParticleDistribution::cloneInvertB( );
    }

    virtual ::IFormFactor * createFormFactor( ::complex_t wavevector_scattering_factor ) const  {
        if( bp::override func_createFormFactor = this->get_override( "createFormFactor" ) )
            return func_createFormFactor( wavevector_scattering_factor );
        else{
            return this->ParticleDistribution::createFormFactor( wavevector_scattering_factor );
        }
    }
    
    ::IFormFactor * default_createFormFactor( ::complex_t wavevector_scattering_factor ) const  {
        return ParticleDistribution::createFormFactor( wavevector_scattering_factor );
    }

    virtual ::IMaterial const * getAmbientMaterial(  ) const  {
        if( bp::override func_getAmbientMaterial = this->get_override( "getAmbientMaterial" ) )
            return func_getAmbientMaterial(  );
        else{
            return this->ParticleDistribution::getAmbientMaterial(  );
        }
    }
    
    ::IMaterial const * default_getAmbientMaterial(  ) const  {
        return ParticleDistribution::getAmbientMaterial( );
    }

    virtual void applyTransformation( ::Geometry::Transform3D const & transform ) {
        if( bp::override func_applyTransformation = this->get_override( "applyTransformation" ) )
            func_applyTransformation( boost::ref(transform) );
        else{
            this->IParticle::applyTransformation( boost::ref(transform) );
        }
    }
    
    void default_applyTransformation( ::Geometry::Transform3D const & transform ) {
        IParticle::applyTransformation( boost::ref(transform) );
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

    virtual bool containsMagneticMaterial(  ) const  {
        if( bp::override func_containsMagneticMaterial = this->get_override( "containsMagneticMaterial" ) )
            return func_containsMagneticMaterial(  );
        else{
            return this->ISample::containsMagneticMaterial(  );
        }
    }
    
    bool default_containsMagneticMaterial(  ) const  {
        return ISample::containsMagneticMaterial( );
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

    virtual ::ICompositeSample * getCompositeSample(  ) {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample * default_getCompositeSample(  ) {
        return ICompositeSample::getCompositeSample( );
    }

    virtual ::ICompositeSample const * getCompositeSample(  ) const  {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample const * default_getCompositeSample(  ) const  {
        return ICompositeSample::getCompositeSample( );
    }

    virtual ::IFormFactor const * getSimpleFormFactor(  ) const  {
        if( bp::override func_getSimpleFormFactor = this->get_override( "getSimpleFormFactor" ) )
            return func_getSimpleFormFactor(  );
        else{
            return this->IParticle::getSimpleFormFactor(  );
        }
    }
    
    ::IFormFactor const * default_getSimpleFormFactor(  ) const  {
        return IParticle::getSimpleFormFactor( );
    }

    virtual bool hasDistributedFormFactor(  ) const  {
        if( bp::override func_hasDistributedFormFactor = this->get_override( "hasDistributedFormFactor" ) )
            return func_hasDistributedFormFactor(  );
        else{
            return this->IParticle::hasDistributedFormFactor(  );
        }
    }
    
    bool default_hasDistributedFormFactor(  ) const  {
        return IParticle::hasDistributedFormFactor( );
    }

    virtual bool preprocess(  ) {
        if( bp::override func_preprocess = this->get_override( "preprocess" ) )
            return func_preprocess(  );
        else{
            return this->ISample::preprocess(  );
        }
    }
    
    bool default_preprocess(  ) {
        return ISample::preprocess( );
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

    virtual void printSampleTree(  ) {
        if( bp::override func_printSampleTree = this->get_override( "printSampleTree" ) )
            func_printSampleTree(  );
        else{
            this->ISample::printSampleTree(  );
        }
    }
    
    void default_printSampleTree(  ) {
        ISample::printSampleTree( );
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
        if( dynamic_cast< ParticleDistribution_wrapper * >( boost::addressof( inst ) ) ){
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

    virtual void setTransformation( ::Geometry::Transform3D const & transform ) {
        if( bp::override func_setTransformation = this->get_override( "setTransformation" ) )
            func_setTransformation( boost::ref(transform) );
        else{
            this->IParticle::setTransformation( boost::ref(transform) );
        }
    }
    
    void default_setTransformation( ::Geometry::Transform3D const & transform ) {
        IParticle::setTransformation( boost::ref(transform) );
    }

    virtual ::std::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ICompositeSample::size(  );
        }
    }
    
    ::std::size_t default_size(  ) const  {
        return ICompositeSample::size( );
    }

    virtual void transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        if( bp::override func_transferToCPP = this->get_override( "transferToCPP" ) )
            func_transferToCPP(  );
        else{
            this->ICloneable::transferToCPP(  );
        }
    }
    
    void default_transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        ICloneable::transferToCPP( );
    }

    PyObject* m_pyobj;

};

void register_ParticleDistribution_class(){

    { //::ParticleDistribution
        typedef bp::class_< ParticleDistribution_wrapper, bp::bases< IParticle >, std::auto_ptr< ParticleDistribution_wrapper >, boost::noncopyable > ParticleDistribution_exposer_t;
        ParticleDistribution_exposer_t ParticleDistribution_exposer = ParticleDistribution_exposer_t( "ParticleDistribution", bp::init< IParticle const &, ParameterDistribution const & >(( bp::arg("prototype"), bp::arg("par_distr") )) );
        bp::scope ParticleDistribution_scope( ParticleDistribution_exposer );
        { //::ParticleDistribution::clone
        
            typedef ::ParticleDistribution * ( ::ParticleDistribution::*clone_function_type)(  ) const;
            typedef ::ParticleDistribution * ( ParticleDistribution_wrapper::*default_clone_function_type)(  ) const;
            
            ParticleDistribution_exposer.def( 
                "clone"
                , clone_function_type(&::ParticleDistribution::clone)
                , default_clone_function_type(&ParticleDistribution_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ParticleDistribution::cloneInvertB
        
            typedef ::ParticleDistribution * ( ::ParticleDistribution::*cloneInvertB_function_type)(  ) const;
            typedef ::ParticleDistribution * ( ParticleDistribution_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            ParticleDistribution_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ParticleDistribution::cloneInvertB)
                , default_cloneInvertB_function_type(&ParticleDistribution_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ParticleDistribution::createFormFactor
        
            typedef ::IFormFactor * ( ::ParticleDistribution::*createFormFactor_function_type)( ::complex_t ) const;
            typedef ::IFormFactor * ( ParticleDistribution_wrapper::*default_createFormFactor_function_type)( ::complex_t ) const;
            
            ParticleDistribution_exposer.def( 
                "createFormFactor"
                , createFormFactor_function_type(&::ParticleDistribution::createFormFactor)
                , default_createFormFactor_function_type(&ParticleDistribution_wrapper::default_createFormFactor)
                , ( bp::arg("wavevector_scattering_factor") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ParticleDistribution::getAmbientMaterial
        
            typedef ::IMaterial const * ( ::ParticleDistribution::*getAmbientMaterial_function_type)(  ) const;
            typedef ::IMaterial const * ( ParticleDistribution_wrapper::*default_getAmbientMaterial_function_type)(  ) const;
            
            ParticleDistribution_exposer.def( 
                "getAmbientMaterial"
                , getAmbientMaterial_function_type(&::ParticleDistribution::getAmbientMaterial)
                , default_getAmbientMaterial_function_type(&ParticleDistribution_wrapper::default_getAmbientMaterial)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ParticleDistribution::getParameterDistribution
        
            typedef ::ParameterDistribution ( ::ParticleDistribution::*getParameterDistribution_function_type)(  ) const;
            
            ParticleDistribution_exposer.def( 
                "getParameterDistribution"
                , getParameterDistribution_function_type( &::ParticleDistribution::getParameterDistribution ) );
        
        }
        { //::IParticle::applyTransformation
        
            typedef void ( ::IParticle::*applyTransformation_function_type)( ::Geometry::Transform3D const & ) ;
            typedef void ( ParticleDistribution_wrapper::*default_applyTransformation_function_type)( ::Geometry::Transform3D const & ) ;
            
            ParticleDistribution_exposer.def( 
                "applyTransformation"
                , applyTransformation_function_type(&::IParticle::applyTransformation)
                , default_applyTransformation_function_type(&ParticleDistribution_wrapper::default_applyTransformation)
                , ( bp::arg("transform") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type)(  ) ;
            typedef bool ( ParticleDistribution_wrapper::*default_areParametersChanged_function_type)(  ) ;
            
            ParticleDistribution_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&ParticleDistribution_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type)(  ) ;
            typedef void ( ParticleDistribution_wrapper::*default_clearParameterPool_function_type)(  ) ;
            
            ParticleDistribution_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&ParticleDistribution_wrapper::default_clearParameterPool) );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( ParticleDistribution_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            ParticleDistribution_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&ParticleDistribution_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type)(  ) const;
            typedef ::ParameterPool * ( ParticleDistribution_wrapper::*default_createParameterTree_function_type)(  ) const;
            
            ParticleDistribution_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&ParticleDistribution_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample * ( ::ICompositeSample::*getCompositeSample_function_type)(  ) ;
            typedef ::ICompositeSample * ( ParticleDistribution_wrapper::*default_getCompositeSample_function_type)(  ) ;
            
            ParticleDistribution_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&ParticleDistribution_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ICompositeSample::*getCompositeSample_function_type)(  ) const;
            typedef ::ICompositeSample const * ( ParticleDistribution_wrapper::*default_getCompositeSample_function_type)(  ) const;
            
            ParticleDistribution_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&ParticleDistribution_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IParticle::getSimpleFormFactor
        
            typedef ::IFormFactor const * ( ::IParticle::*getSimpleFormFactor_function_type)(  ) const;
            typedef ::IFormFactor const * ( ParticleDistribution_wrapper::*default_getSimpleFormFactor_function_type)(  ) const;
            
            ParticleDistribution_exposer.def( 
                "getSimpleFormFactor"
                , getSimpleFormFactor_function_type(&::IParticle::getSimpleFormFactor)
                , default_getSimpleFormFactor_function_type(&ParticleDistribution_wrapper::default_getSimpleFormFactor)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IParticle::hasDistributedFormFactor
        
            typedef bool ( ::IParticle::*hasDistributedFormFactor_function_type)(  ) const;
            typedef bool ( ParticleDistribution_wrapper::*default_hasDistributedFormFactor_function_type)(  ) const;
            
            ParticleDistribution_exposer.def( 
                "hasDistributedFormFactor"
                , hasDistributedFormFactor_function_type(&::IParticle::hasDistributedFormFactor)
                , default_hasDistributedFormFactor_function_type(&ParticleDistribution_wrapper::default_hasDistributedFormFactor) );
        
        }
        { //::ISample::preprocess
        
            typedef bool ( ::ISample::*preprocess_function_type)(  ) ;
            typedef bool ( ParticleDistribution_wrapper::*default_preprocess_function_type)(  ) ;
            
            ParticleDistribution_exposer.def( 
                "preprocess"
                , preprocess_function_type(&::ISample::preprocess)
                , default_preprocess_function_type(&ParticleDistribution_wrapper::default_preprocess) );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type)(  ) const;
            typedef void ( ParticleDistribution_wrapper::*default_printParameters_function_type)(  ) const;
            
            ParticleDistribution_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&ParticleDistribution_wrapper::default_printParameters) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( ParticleDistribution_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            ParticleDistribution_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&ParticleDistribution_wrapper::default_printSampleTree) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            ParticleDistribution_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &ParticleDistribution_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type)( ::std::string const &,double ) ;
            typedef bool ( ParticleDistribution_wrapper::*default_setParameterValue_function_type)( ::std::string const &,double ) ;
            
            ParticleDistribution_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&ParticleDistribution_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type)(  ) ;
            typedef void ( ParticleDistribution_wrapper::*default_setParametersAreChanged_function_type)(  ) ;
            
            ParticleDistribution_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&ParticleDistribution_wrapper::default_setParametersAreChanged) );
        
        }
        { //::IParticle::setTransformation
        
            typedef void ( ::IParticle::*setTransformation_function_type)( ::Geometry::Transform3D const & ) ;
            typedef void ( ParticleDistribution_wrapper::*default_setTransformation_function_type)( ::Geometry::Transform3D const & ) ;
            
            ParticleDistribution_exposer.def( 
                "setTransformation"
                , setTransformation_function_type(&::IParticle::setTransformation)
                , default_setTransformation_function_type(&ParticleDistribution_wrapper::default_setTransformation)
                , ( bp::arg("transform") ) );
        
        }
        { //::ICompositeSample::size
        
            typedef ::std::size_t ( ::ICompositeSample::*size_function_type)(  ) const;
            typedef ::std::size_t ( ParticleDistribution_wrapper::*default_size_function_type)(  ) const;
            
            ParticleDistribution_exposer.def( 
                "size"
                , size_function_type(&::ICompositeSample::size)
                , default_size_function_type(&ParticleDistribution_wrapper::default_size) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( ParticleDistribution_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            ParticleDistribution_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&ParticleDistribution_wrapper::default_transferToCPP) );
        
        }
    }

}
