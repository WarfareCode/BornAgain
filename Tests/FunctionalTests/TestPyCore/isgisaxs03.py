# IsGISAXS03 example: Cylinder formfactor in BA and DWBA
import sys
import os
import numpy
import gzip

sys.path.append(os.path.abspath(
                os.path.join(os.path.split(__file__)[0],
                '..', '..', '..', 'lib')))

from libBornAgainCore import *

# ----------------------------------
# describe sample and run simulation
# ----------------------------------
def RunSimulationDWBA():
    
    # defining materials
    mAmbience = MaterialManager.getHomogeneousMaterial("Air", 1.0, 0.0 )
    mSubstrate = MaterialManager.getHomogeneousMaterial("Substrate", 1.0-6e-6, 2e-8 )    
    # collection of particles
    n_particle = complex(1.0-6e-4, 2e-8)    
    cylinder_ff = FormFactorCylinder(5*nanometer, 5*nanometer)
    cylinder = Particle(n_particle, cylinder_ff)
    particle_decoration = ParticleDecoration()
    particle_decoration.addParticle(cylinder, 0.0, 1.0)
    interference = InterferenceFunctionNone()
    particle_decoration.addInterferenceFunction(interference)
    # air layer with particles and substrate form multi layer
    air_layer = Layer(mAmbience)
    air_layer_decorator = LayerDecorator(air_layer, particle_decoration)
    substrate_layer = Layer(mSubstrate, 0)
    
    multi_layer = MultiLayer()
    multi_layer.addLayer(air_layer_decorator)
    multi_layer.addLayer(substrate_layer)
    
    # build and run experiment
    simulation = Simulation()
    simulation.setDetectorParameters(100,0.0*degree, 2.0*degree, 100, 0.0*degree, 2.0*degree, True)
    simulation.setBeamParameters(1.0*angstrom, -0.2*degree, 0.0*degree)
    simulation.setSample(multi_layer)
    simulation.runSimulation()
    # intensity data
    return GetOutputData(simulation)


# ----------------------------------
# describe sample and run simulation - IsGISAXS3 functional test: cylinder in the air
# ----------------------------------
def RunSimulationBA():
     # defining materials
    mAmbience = MaterialManager.getHomogeneousMaterial("Air", 1.0, 0.0 )
    mSubstrate = MaterialManager.getHomogeneousMaterial("Substrate", 1.0-6e-6, 2e-8 )
    # collection of particles
    n_particle = complex(1.0-6e-4, 2e-8)
    cylinder_ff = FormFactorCylinder(5*nanometer, 5*nanometer)
    cylinder = Particle(n_particle, cylinder_ff)
    particle_decoration = ParticleDecoration()
    particle_decoration.addParticle(cylinder, 0.0, 1.0)
    interference = InterferenceFunctionNone()
    particle_decoration.addInterferenceFunction(interference)
    
    air_layer = Layer(mAmbience)
    air_layer_decorator = LayerDecorator(air_layer, particle_decoration)
    substrate_layer = Layer(mSubstrate, 0)
    multi_layer = MultiLayer()
    multi_layer.addLayer(air_layer_decorator)
    
    # build and run experiment
    simulation = Simulation()
    simulation.setDetectorParameters(100,0.0*degree, 2.0*degree, 100, 0.0*degree, 2.0*degree, True)
    simulation.setBeamParameters(1.0*angstrom, -0.2*degree, 0.0*degree)
    simulation.setSample(multi_layer)
    simulation.runSimulation()
    return GetOutputData(simulation)


# ----------------------------------
# describe sample and run simulation - IsGISAXS3 functional test: cylinder in the air with size distribution
# ----------------------------------
def RunSimulationBA_Size():
    # defining materials
    mAmbience = MaterialManager.getHomogeneousMaterial("Air", 1.0, 0.0 )
    mSubstrate = MaterialManager.getHomogeneousMaterial("Substrate", 1.0-6e-6, 2e-8 )

    multi_layer = MultiLayer()

    n_particle = complex(1.0-6e-4, 2e-8)
    cylinder_ff = FormFactorCylinder(5*nanometer, 5*nanometer)
    particle_decoration = ParticleDecoration()
    # preparing prototype of nano particle
    radius = 5*nanometer
    sigma = 0.2*radius
    nano_particle = Particle(n_particle, cylinder_ff)
    # radius of nanoparticles will be sampled with gaussian probability
    nbins = 100
    nfwhm = 2
    stochastic_gaussian = StochasticDoubleGaussian(radius, sigma)
    par = StochasticSampledParameter(stochastic_gaussian, nbins, nfwhm)

    builder = ParticleBuilder()
    builder.setPrototype(nano_particle,"/Particle/FormFactorCylinder/radius", par)
    builder.plantParticles(particle_decoration)
    interference = InterferenceFunctionNone()
    particle_decoration.addInterferenceFunction(interference)    

    air_layer = Layer(mAmbience)
    air_layer_decorator = LayerDecorator(air_layer, particle_decoration)
    multi_layer.addLayer(air_layer_decorator)

    # build and run experiment  
    simulation = Simulation()
    simulation.setDetectorParameters(100,0.0*degree, 2.0*degree, 100, 0.0*degree, 2.0*degree, True)
    simulation.setBeamParameters(1.0*angstrom, -0.2*degree, 0.0*degree)
    simulation.setSample(multi_layer)
    simulation.runSimulation()
    return GetOutputData(simulation)

      
# ----------------------------------
# read reference data from file
# ----------------------------------
def GetReferenceData():
    path = os.path.split(__file__)[0]
    if path: path +="/"
    fBA = gzip.open(path+'../TestCore/IsGISAXS03/isgisaxs03_reference_BA.ima.gz', 'rb')
    referenceBA=numpy.fromstring(fBA.read(),numpy.float64,sep=' ')
    fBA.close()
    fBA_Size = gzip.open(path+'../TestCore/IsGISAXS03/isgisaxs03_reference_BA_size.ima.gz', 'rb')
    referenceBA_Size=numpy.fromstring(fBA_Size.read(),numpy.float64,sep=' ')
    fBA_Size.close()
    fDWBA = gzip.open(path+'../TestCore/IsGISAXS03/isgisaxs03_reference_DWBA.ima.gz', 'rb')
    referenceDWBA=numpy.fromstring(fDWBA.read(),numpy.float64,sep=' ')
    fDWBA.close()
    reference=numpy.concatenate((referenceBA,referenceBA_Size,referenceDWBA),axis=0)  
    return reference


# --------------------------------------------------------------
# calculate numeric difference between result and reference data
# --------------------------------------------------------------
def GetDifference(data, reference):
    reference = reference.reshape(data.shape)
    # calculating relative average difference
    data -= reference
    diff=0.0
    epsilon = sys.float_info.epsilon
    for x, y in numpy.ndindex(data.shape):
        v1 = data[x][y]
        v2 = reference[x][y]
        if v1 <= epsilon and v2 <= epsilon:
            diff += 0.0
        elif(v2 <= epsilon):
            diff += abs(v1/epsilon)
        else:
            diff += abs(v1/v2)
    return diff/data.size


# --------------------------------------------------------------
# run test and analyse test results
# --------------------------------------------------------------
def RunTest():
    resultBA = RunSimulationBA()
    resultDWBA = RunSimulationDWBA()
    resultBA_Size = RunSimulationBA_Size()
    result = numpy.concatenate((resultBA,resultBA_Size,resultDWBA),axis=0)
    reference = GetReferenceData()

    diff = GetDifference(result, reference)
    status = "OK"
    if(diff > 1e-10 or numpy.isnan(diff)): status = "FAILED"
    return "IsGISAXS03", "Cylinder formfactor in BA and DWBA", status

   
#-------------------------------------------------------------
# main()
#-------------------------------------------------------------
if __name__ == '__main__':
  name,description,status = RunTest()
  print name,description,status

