// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "Bin.h"
#include "Crystal.h"
#include "DiffuseParticleInfo.h"
#include "FTDistributions.h"
#include "FormFactorBox.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorParallelepiped.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "HomogeneousMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Instrument.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "InterferenceFunction2DLattice.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "InterferenceFunctionNone.h"
#include "Lattice.h"
#include "Lattice2DIFParameters.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "Lattice2DIFParameters.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "Particle.h"
#include "ParticleBuilder.h"
#include "ParticleCoreShell.h"
#include "ParticleDecoration.h"
#include "ParticleInfo.h"
#include "PositionParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Simulation.h"
#include "SimulationParameters.h"
#include "IStochasticParameter.h"
#include "StochasticGaussian.h"
#include "StochasticSampledParameter.h"
#include "StochasticDoubleGate.h"
#include "Transform3D.h"
#include "Types.h"
#include "Units.h"
#include "LayerRoughness.pypp.h"

namespace bp = boost::python;

struct LayerRoughness_wrapper : LayerRoughness, bp::wrapper< LayerRoughness > {

    LayerRoughness_wrapper( )
    : LayerRoughness( )
      , bp::wrapper< LayerRoughness >(){
        // null constructor
    
    }

    LayerRoughness_wrapper(double sigma, double hurstParameter, double latteralCorrLength )
    : LayerRoughness( sigma, hurstParameter, latteralCorrLength )
      , bp::wrapper< LayerRoughness >(){
        // constructor
    
    }

    virtual ::LayerRoughness * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->LayerRoughness::clone(  );
        }
    }
    
    ::LayerRoughness * default_clone(  ) const  {
        return LayerRoughness::clone( );
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

    virtual void print_structure(  ) {
        if( bp::override func_print_structure = this->get_override( "print_structure" ) )
            func_print_structure(  );
        else{
            this->ISample::print_structure(  );
        }
    }
    
    void default_print_structure(  ) {
        ISample::print_structure( );
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

void register_LayerRoughness_class(){

    bp::class_< LayerRoughness_wrapper, boost::noncopyable >( "LayerRoughness", bp::init< >() )    
        .def( bp::init< double, double, double >(( bp::arg("sigma"), bp::arg("hurstParameter"), bp::arg("latteralCorrLength") )) )    
        .def( 
            "clone"
            , (::LayerRoughness * ( ::LayerRoughness::* )(  ) const)(&::LayerRoughness::clone)
            , (::LayerRoughness * ( LayerRoughness_wrapper::* )(  ) const)(&LayerRoughness_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "getHurstParameter"
            , (double ( ::LayerRoughness::* )(  ) const)(& ::LayerRoughness::getHurstParameter ) )    
        .def( 
            "getLatteralCorrLength"
            , (double ( ::LayerRoughness::* )(  ) const)(& ::LayerRoughness::getLatteralCorrLength ) )    
        .def( 
            "getSigma"
            , (double ( ::LayerRoughness::* )(  ) const)(& ::LayerRoughness::getSigma ) )    
        .def( 
            "setHurstParameter"
            , (void ( ::LayerRoughness::* )( double ) )(& ::LayerRoughness::setHurstParameter )
            , ( bp::arg("hurstParameter") ) )    
        .def( 
            "setLatteralCorrLength"
            , (void ( ::LayerRoughness::* )( double ) )(& ::LayerRoughness::setLatteralCorrLength )
            , ( bp::arg("latteralCorrLength") ) )    
        .def( 
            "setSigma"
            , (void ( ::LayerRoughness::* )( double ) )(& ::LayerRoughness::setSigma )
            , ( bp::arg("sigma") ) )    
        .def( 
            "areParametersChanged"
            , (bool ( ::IParameterized::* )(  ) )(&::IParameterized::areParametersChanged)
            , (bool ( LayerRoughness_wrapper::* )(  ) )(&LayerRoughness_wrapper::default_areParametersChanged) )    
        .def( 
            "createParameterTree"
            , (::ParameterPool * ( ::IParameterized::* )(  ) const)(&::IParameterized::createParameterTree)
            , (::ParameterPool * ( LayerRoughness_wrapper::* )(  ) const)(&LayerRoughness_wrapper::default_createParameterTree)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "printParameters"
            , (void ( ::IParameterized::* )(  ) const)(&::IParameterized::printParameters)
            , (void ( LayerRoughness_wrapper::* )(  ) const)(&LayerRoughness_wrapper::default_printParameters) )    
        .def( 
            "print_structure"
            , (void ( ::ISample::* )(  ) )(&::ISample::print_structure)
            , (void ( LayerRoughness_wrapper::* )(  ) )(&LayerRoughness_wrapper::default_print_structure) )    
        .def( 
            "setParametersAreChanged"
            , (void ( ::IParameterized::* )(  ) )(&::IParameterized::setParametersAreChanged)
            , (void ( LayerRoughness_wrapper::* )(  ) )(&LayerRoughness_wrapper::default_setParametersAreChanged) )    
        .def( bp::self_ns::str( bp::self ) );

}
