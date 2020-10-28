// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Base/Axis/FixedBinAxis.h
//! @brief     Defines class FixedBinAxis.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_AXIS_FIXEDBINAXIS_H
#define BORNAGAIN_CORE_AXIS_FIXEDBINAXIS_H

#include "Base/Axis/IAxis.h"

//! Axis with fixed bin size.
//! @ingroup tools

class FixedBinAxis : public IAxis
{
public:
    //! FixedBinAxis constructor.
    //! @param name Axis name
    //! @param nbins number of bins
    //! @param start low edge of first bin
    //! @param end upper edge of last bin
    FixedBinAxis(const std::string& name, size_t nbins, double start, double end);
    virtual ~FixedBinAxis() {}

    FixedBinAxis* clone() const;

    size_t size() const { return m_nbins; }

    double operator[](size_t index) const;

    Bin1D getBin(size_t index) const;

    double getMin() const { return m_start; }
    double getMax() const { return m_end; }

    double getBinCenter(size_t index) const { return (*this)[index]; }

    size_t findClosestIndex(double value) const;

    std::vector<double> getBinCenters() const;

    std::vector<double> getBinBoundaries() const;

    FixedBinAxis* createClippedAxis(double left, double right) const;

    std::string pyString(const std::string& units, size_t) const final;

protected:
    void print(std::ostream& ostr) const;
    virtual bool equals(const IAxis& other) const;

private:
    size_t m_nbins;
    double m_start;
    double m_end;
};

#endif // BORNAGAIN_CORE_AXIS_FIXEDBINAXIS_H