// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FitKernel/inc/AttLimits.h
//! @brief     Defines class AttLimits.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef ATTLIMITS_H
#define ATTLIMITS_H

#include "WinDllMacros.h"
#include <iostream>
#include <iomanip>


//! @class AttLimits
//! @ingroup fitting
//! @brief Limits for fit parameters

class BA_CORE_API_ AttLimits
{
 public:
    AttLimits() : m_has_lower_limit(false), m_has_upper_limit(false), m_is_fixed(false), m_lower_limit(0), m_upper_limit(0) {}
    virtual ~AttLimits(){}

    //! if has lower limit
    virtual bool hasLowerLimit() const { return m_has_lower_limit; }
    //! Returns lower limit
    virtual double getLowerLimit() const { return m_lower_limit; }
    //! Sets lower limit
    virtual void setLowerLimit(double value) { m_lower_limit = value; m_has_lower_limit = true; }
    //! remove lower limit
    virtual void removeLowerLimit() { m_lower_limit = 0.0; m_has_lower_limit = false; }

    //! if has upper limit
    virtual bool hasUpperLimit() const { return m_has_upper_limit; }
    //! Returns upper limit
    virtual double getUpperLimit() const { return m_upper_limit; }
    //! Sets upper limit
    virtual void setUpperLimit(double value) { m_upper_limit = value; m_has_upper_limit = true; }
    //! remove upper limit
    virtual void removeUpperLimit() { m_upper_limit = 0.0; m_has_upper_limit = false; }

    //! if has lower and upper limit
    virtual bool hasLowerAndUpperLimits() const { return (m_has_lower_limit && m_has_upper_limit); }

    //! Sets object fixed
    virtual void setFixed(bool is_fixed) { m_is_fixed = is_fixed; }
    //! if object is fixed at some value
    virtual bool isFixed() const { return m_is_fixed; }

    //! Sets lower and upper limits
    virtual void setLimits(double xmin, double xmax) { setLowerLimit(xmin); setUpperLimit(xmax); }
    //! remove limits
    virtual void removeLimits() { removeLowerLimit(); removeUpperLimit(); }

    // ---------
    // static creation methods

    //! Creates an object bounded from the left
    static AttLimits lowerLimited(double bound_value) { return AttLimits(true, false, false, bound_value, 0.0); }

    //! Creates an object bounded from the right
    static AttLimits upperLimited(double bound_value) { return AttLimits(false, true, false, 0.0, bound_value); }

    //! Creates an object bounded from the left and right
    static AttLimits limited(double left_bound_value, double right_bound_value)  { return AttLimits(true, true, false, left_bound_value, right_bound_value); }

    //! Creates an object withoud bounds (default)
    static AttLimits limitless() { return AttLimits(); }

    //! Creates a fixed value object
    static AttLimits fixed() { return AttLimits(false, false, true, 0.0, 0.0); }

    //! Prints class
    friend std::ostream& operator<<(std::ostream& ostr, const AttLimits& m) { m.print(ostr); return ostr; }

 protected:
    AttLimits(bool has_lower_limit, bool has_upper_limit, bool is_fixed, double lower_limit, double upper_limit)
        : m_has_lower_limit(has_lower_limit)
        , m_has_upper_limit(has_upper_limit)
        , m_is_fixed(is_fixed)
        , m_lower_limit(lower_limit)
        , m_upper_limit(upper_limit) { }

    bool   m_has_lower_limit; //! parameter has lower bound
    bool   m_has_upper_limit; //! parameter has upper bound
    bool   m_is_fixed; //! parameter is fixed
    double m_lower_limit; //! minimum allowed value
    double m_upper_limit; //! maximum allowed value

    //! Prints class
    void print(std::ostream& ostr) const
    {
        if(isFixed()) {
            ostr << "fixed";
        }else if(!hasLowerLimit() && !hasUpperLimit() ) {
            ostr << "free";
        } else if(hasLowerLimit() && !hasUpperLimit()) {
            ostr << "lim("  << std::fixed <<std::setprecision(2) << m_lower_limit << ",)";
        }else if(hasUpperLimit() && !hasLowerLimit()) {
            ostr << "lim(," << std::fixed <<std::setprecision(2) << m_upper_limit << ",)";
        }else if(hasLowerAndUpperLimits()) {
            ostr << "lim(" << std::fixed <<std::setprecision(2) << m_lower_limit << "," << std::fixed <<std::setprecision(2) << m_upper_limit << ")";

        }
    }
};

#endif // LIMITS_H


