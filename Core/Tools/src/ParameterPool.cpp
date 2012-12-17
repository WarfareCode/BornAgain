#include "ParameterPool.h"
#include "Exceptions.h"
#include "Utils.h"
#include <iostream>
#include <sstream>


/* ************************************************************************* */
// constructors
/* ************************************************************************* */
ParameterPool::ParameterPool()
{
}

ParameterPool::~ParameterPool()
{
    clear();
}

ParameterPool::ParameterPool(const ParameterPool &other)
{
    m_map = other.m_map;
}

ParameterPool *ParameterPool::clone()
{
    ParameterPool *new_pool = new ParameterPool(*this);
    return new_pool;
}

/* ************************************************************************* */
// Clear the parameter container
/* ************************************************************************* */
void ParameterPool::clear()
{
    m_map.clear();
}

/* ************************************************************************* */
// Registering parameter with given name. Name should be different for each
// register.
/* ************************************************************************* */
bool ParameterPool::registerParameter(const std::string &name, double *parameter_address)
{
    parameter_t par(parameter_address);
    return addParameter(name, par);
}

bool ParameterPool::addParameter(const std::string &name, parameter_t par)
{
    parametermap_t::iterator it = m_map.find(name);
    if( it!=m_map.end() ) {
        print(std::cout);
        std::ostringstream os;
        os << "ParameterPool::registerParameter() -> Warning! Registering parameter with same name '" << name << "'. Previous link will be replaced ";
        throw RuntimeErrorException(os.str());
    }
    return m_map.insert(parametermap_t::value_type(name, par ) ).second;
}

/* ************************************************************************* */
// Clone method that adds a prefix to parameter's keys
/* ************************************************************************* */
ParameterPool *ParameterPool::cloneWithPrefix(const std::string &prefix)
{
    ParameterPool *new_pool = new ParameterPool;
    for(parametermap_t::iterator it=m_map.begin(); it!= m_map.end(); ++it)
    {
        new_pool->addParameter(prefix+it->first, it->second);
    }
    return new_pool;
}

/* ************************************************************************* */
// copy parameters of given pool to the external pool while adding prefix to
// local parameter keys
/* ************************************************************************* */
void ParameterPool::copyToExternalPool(const std::string &prefix, ParameterPool *external_pool) const
{
    for(parametermap_t::const_iterator it=m_map.begin(); it!= m_map.end(); ++it) {
        external_pool->addParameter(prefix+it->first, it->second);
    }
}

/* ************************************************************************* */
// return parameter with given name
/* ************************************************************************* */
ParameterPool::parameter_t ParameterPool::getParameter(const std::string &name) const
{
    parametermap_t::const_iterator it = m_map.find(name);
    if( it!=m_map.end() ) {
        return (*it).second;
    } else {
//        std::cout << "ParameterPool::getParameter() -> Warning. No parameter with name '" << name << std::endl;
//        return parameter_t(0);
        throw LogicErrorException("ParameterPool::getParameter() -> Warning. No parameter with name '"+name+"'");
    }
}


/* ************************************************************************* */
// return vector of parameters which fit pattern
/* ************************************************************************* */
std::vector<ParameterPool::parameter_t >  ParameterPool::getMatchedParameters(const std::string &wildcards) const
{
    std::vector<ParameterPool::parameter_t > selected_parameters;
    // loop over all parameters in the pool
    for(parametermap_t::const_iterator it=m_map.begin(); it!= m_map.end(); ++it) {
        // (*it).first - parameter key, (*it).second - parameter itself
        // parameters whose key match pattern is added to the FitMultiParameter container
        if( Utils::StringMatchText::WildcardPattern( (*it).first, wildcards ) ) {
            selected_parameters.push_back((*it).second);
        }
    }
    if( selected_parameters.empty() ) {
        std::cout << "ParameterPool::getMatchedParameters() -> Warning! No parameters satisfying  criteria '" << wildcards << "' have been found" << std::endl;
        std::cout << "Existing keys are:" << std::endl;
        for(parametermap_t::const_iterator it=m_map.begin(); it!= m_map.end(); ++it) std::cout << (*it).first << std::endl;
        throw LogicErrorException("ParameterPool::getMatchedParameters() -> Error! No parameters with given wildcard.");
    }
    return selected_parameters;
}



/* ************************************************************************* */
// set parameter value
/* ************************************************************************* */
bool ParameterPool::setParameterValue(const std::string &name, double value)
{
    parameter_t x = getParameter(name);
    if( x.isNull() ) {
        std::cout << "ParameterPool::setParameterValue() -> Warning. No parameter with name '" << name << "'" << std::endl;
        throw LogicErrorException("ParameterPool::setParameterValue() -> Warning. No such parameter");
        return false;
    }
    x.setValue(value);
    return true;
}

/* ************************************************************************* */
// set parameter value
/* ************************************************************************* */
int ParameterPool::setMatchedParametersValue(const std::string &wildcards, double value)
{
    int npars(0);
    for(parametermap_t::iterator it=m_map.begin(); it!= m_map.end(); ++it) {
        if( Utils::StringMatchText::WildcardPattern( (*it).first, wildcards ) ) {
            (*it).second.setValue(value);
            npars++;
        }
    }
    return npars;
}

/* ************************************************************************* */
// print content on the screen
/* ************************************************************************* */
void ParameterPool::print(std::ostream &ostr) const
{
    const int number_of_pars_in_line(4);
    if( m_map.size() ) {
        // printing in one line
        if(m_map.size() < number_of_pars_in_line) {
            ostr << "POOL_" << m_map.size();
            ostr << "(";
            for(parametermap_t::const_iterator it=m_map.begin(); it!= m_map.end(); ++it) {
                std::cout << "'" << (*it).first << "'" << ":" << it->second.getValue() << " " ;
            }
            ostr << ")";
        // printing in several lines
        } else {
            for(parametermap_t::const_iterator it=m_map.begin(); it!= m_map.end(); ++it) {
                std::cout << "'" << (*it).first << "'" << ":" << it->second.getValue() << std::endl;
            }
        }
    }
}
