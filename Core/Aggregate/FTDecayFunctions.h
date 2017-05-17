// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Aggregate/FTDecayFunctions.h
//! @brief     Defines classes IFTDecayFunction1D, IFTDecayFunction2D,
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FTDECAYFUNCTIONS_H
#define FTDECAYFUNCTIONS_H

#include "ICloneable.h"
#include "INode.h"
#include "MathConstants.h"

//! Interface for a one-dimensional decay function,
//!   with evaluate(q) returning the Fourier transform,
//!   normalized to \f$\int dq\; {\rm evaluate}(q) = 1\f$.
//! @ingroup distribution_internal
class BA_CORE_API_ IFTDecayFunction1D : public ICloneable, public INode
{
public:    
    //! Constructor of one-dimensional decay function.
    //! @param decay_length: half-width of the distribution in nanometers
    IFTDecayFunction1D(double decay_length) : m_decay_length(decay_length) {}
    virtual IFTDecayFunction1D* clone() const=0;
    virtual double evaluate(double q) const=0;
    double decayLength() const { return m_decay_length; }
    friend std::ostream& operator<<(std::ostream& ostr, const IFTDecayFunction1D& m) {
        m.print(ostr); return ostr; }

protected:
    virtual void print(std::ostream& ostr) const;
    virtual void init_parameters();
    double m_decay_length;
};


//! One-dimensional Cauchy decay function in reciprocal space;
//! corresponds to exp(-|x|/decay_length) in real space.
//! @ingroup decayFT
class BA_CORE_API_ FTDecayFunction1DCauchy : public IFTDecayFunction1D
{
public:
    FTDecayFunction1DCauchy(double decay_length);
    virtual FTDecayFunction1DCauchy* clone() const {
        return new FTDecayFunction1DCauchy(m_decay_length); }
    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }
    double evaluate(double q) const final;
};


//! One-dimensional Gauss decay function in reciprocal space;
//! corresponds to exp[-x^2/(2*decay_length^2)] in real space.
//! @ingroup decayFT
class BA_CORE_API_ FTDecayFunction1DGauss : public IFTDecayFunction1D
{
public:
    FTDecayFunction1DGauss(double decay_length);
    virtual FTDecayFunction1DGauss* clone() const {
        return new FTDecayFunction1DGauss(m_decay_length); }
    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }
    double evaluate(double q) const final;
};


//! One-dimensional triangle decay function in reciprocal space;
//! corresponds to 1-|x|/decay_length if |x|<decay_length (and 0 otherwise) in real space.
//! @ingroup decayFT
class BA_CORE_API_ FTDecayFunction1DTriangle : public IFTDecayFunction1D
{
public:
    FTDecayFunction1DTriangle(double decay_length);
    virtual FTDecayFunction1DTriangle* clone() const {
        return new FTDecayFunction1DTriangle(m_decay_length); }
    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }
    double evaluate(double q) const final;
};


//! One-dimensional pseudo-Voigt decay function in reciprocal space;
//! corresponds to eta*Gauss + (1-eta)*Cauchy.
//! @ingroup decayFT
class BA_CORE_API_ FTDecayFunction1DVoigt : public IFTDecayFunction1D
{
public:
    //! Constructor of one-dimensional decay function.
    //! @param decay_length: half-width of the distribution in nanometers
    //! @param eta: parameter [0,1] to balance between Cauchy (eta=0.0) and Gauss (eta=1.0)
    FTDecayFunction1DVoigt(double decay_length, double eta);
    virtual FTDecayFunction1DVoigt* clone() const {
        return new FTDecayFunction1DVoigt(m_decay_length, m_eta); }
    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }
    double evaluate(double q) const final;
    double getEta() const { return m_eta;}
protected:
    virtual void init_parameters();
    double m_eta;
};


//! Interface for two-dimensional decay function in reciprocal space.
//! @ingroup decayFT_internal
class BA_CORE_API_ IFTDecayFunction2D : public ICloneable, public INode
{
public:
    IFTDecayFunction2D(double decay_length_x, double decay_length_y,
                       double gamma=0, double delta=M_PI_2);
    virtual IFTDecayFunction2D* clone() const=0;

    //! set angle between first lattice vector and X-axis of distribution (both in direct space)
    void setGamma(double gamma) { m_gamma = gamma; }

    //! get angle between first lattice vector and X-axis of distribution (both in direct space)
    double getGamma() const { return m_gamma; }

    //! get angle between X- and Y-axis of distribution (in direct space)
    double getDelta() const { return m_delta; }

    //! get coherence length in X-direction
    double getDecayLengthX() const { return m_omega_x; }

    //! get coherence length in Y-direction
    double getDecayLengthY() const { return m_omega_y; }

    //! evaluate Fourier transformed decay function for q in X,Y coordinates
    virtual double evaluate(double qx, double qy) const=0;

    //! transform back to a*, b* basis:
    void transformToStarBasis(double qX, double qY,
            double alpha, double a, double b, double& qa, double& qb) const;

    friend std::ostream& operator<<(std::ostream& ostr, const IFTDecayFunction2D& m)
    { m.print(ostr); return ostr; }

protected:
    virtual void print(std::ostream& ostr) const;
    virtual void init_parameters();
    double m_omega_x;
    double m_omega_y;
    double m_gamma;
    double m_delta;
};


//! Two-dimensional Cauchy decay function in reciprocal space;
//! corresponds to exp(-r) in real space,
//! with \f$r=\sqrt{(\frac{x}{\omega_x})^2 + (\frac{y}{\omega_y})^2}\f$.
//! @ingroup decayFT
class BA_CORE_API_ FTDecayFunction2DCauchy : public IFTDecayFunction2D
{
public:
    FTDecayFunction2DCauchy(double decay_length_x, double decay_length_y,
                            double gamma=0, double delta=M_PI_2);
    virtual FTDecayFunction2DCauchy* clone() const {
        return new FTDecayFunction2DCauchy(m_omega_x, m_omega_y, m_gamma, m_delta); }
    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }

    double evaluate(double qx, double qy) const final;
};


//! Two-dimensional Gauss decay function in reciprocal space;
//! corresponds to exp(-r^2/2) in real space,
//! with \f$r=\sqrt{(\frac{x}{\omega_x})^2 + (\frac{y}{\omega_y})^2}\f$.
//! @ingroup decayFT
class BA_CORE_API_ FTDecayFunction2DGauss : public IFTDecayFunction2D
{
public:
    FTDecayFunction2DGauss(double decay_length_x, double decay_length_y,
                           double gamma=0, double delta=M_PI_2);
    virtual FTDecayFunction2DGauss* clone() const {
        return new FTDecayFunction2DGauss(m_omega_x, m_omega_y, m_gamma, m_delta); }
    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }

    double evaluate(double qx, double qy) const final;
};

//! Two-dimensional pseudo-Voigt decay function in reciprocal space;
//! corresponds to eta*Gauss + (1-eta)*Cauchy.
//! @ingroup decayFT
class BA_CORE_API_ FTDecayFunction2DVoigt : public IFTDecayFunction2D
{
public:
    FTDecayFunction2DVoigt(double decay_length_x, double decay_length_y, double eta,
                           double gamma=0, double delta=M_PI_2);
    virtual FTDecayFunction2DVoigt* clone() const {
        return new FTDecayFunction2DVoigt(m_omega_x, m_omega_y, m_eta, m_gamma, m_delta); }
    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }

    double evaluate(double qx, double qy) const final;

    virtual double getEta() const { return m_eta; }

protected:
    virtual void init_parameters();
    double m_eta;
};

#endif // FTDECAYFUNCTIONS_H
