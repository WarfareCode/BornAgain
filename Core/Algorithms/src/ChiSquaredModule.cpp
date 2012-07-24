#include "ChiSquaredModule.h"

ChiSquaredModule::ChiSquaredModule(const OutputData<double>& real_data)
: mp_simulation_data(0)
{
    mp_real_data = real_data.clone();
    mp_data_selector = new DefaultAllDataSelector();
    mp_squared_function = new DefaultSquaredFunction();
}

ChiSquaredModule::~ChiSquaredModule()
{
    delete mp_real_data;
    delete mp_simulation_data;
    delete mp_data_selector;
    delete mp_squared_function;
}

void ChiSquaredModule::setSimulationData(
        const OutputData<double>& simulation_data)
{
    delete mp_simulation_data;
    mp_simulation_data = simulation_data.clone();
}

void ChiSquaredModule::setFittingDataSelector(
        const IFittingDataSelector& selector)
{
    delete mp_data_selector;
    mp_data_selector = selector.clone();
}

void ChiSquaredModule::setChiSquaredFunction(
        const ISquaredFunction& squared_function)
{
    delete mp_squared_function;
    mp_squared_function = squared_function.clone();
}

double ChiSquaredModule::calculateChiSquared(
        const OutputData<double>* p_simulation_data)
{
    if (p_simulation_data!=0) {
        setSimulationData(*p_simulation_data);
    }
    if (mp_simulation_data==0) {
        throw LogicErrorException("No simulation data present for calculating chi squared.");
    }
    mp_data_selector->getFittingData(*mp_real_data, *mp_simulation_data,
            m_real_data_vector, m_simulation_data_vector, m_weights);
    double result = 0.0;
    size_t data_size = m_real_data_vector.size();
    for (size_t index=0; index<data_size; ++index) {
        double squared_value = mp_squared_function->calculateSquaredDifference(m_real_data_vector[index],
                m_simulation_data_vector[index]);
        result += squared_value*m_weights[index];
    }
    return result;
}