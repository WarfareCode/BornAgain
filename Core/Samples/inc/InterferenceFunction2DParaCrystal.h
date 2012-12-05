#ifndef INTERFERENCEFUNCTION2DPARACRYSTAL_H_
#define INTERFERENCEFUNCTION2DPARACRYSTAL_H_
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   InterferenceFunction2DParaCrystal.h
//! @brief  Definition of InterferenceFunction2DParaCrystal class
//! @author Scientific Computing Group at FRM II
//! @date   Oct 17, 2012

#include "IInterferenceFunction.h"
#include "FTDistributions.h"

class InterferenceFunction2DParaCrystal : public IInterferenceFunction
{
public:
    InterferenceFunction2DParaCrystal(double length_1, double length_2, double alpha_lattice, double xi=0.0, double corr_length=0.0);
    virtual ~InterferenceFunction2DParaCrystal();
    virtual InterferenceFunction2DParaCrystal *clone() const {
        InterferenceFunction2DParaCrystal *p_new = new InterferenceFunction2DParaCrystal(m_lattice_lengths[0], m_lattice_lengths[1], m_alpha_lattice, m_xi, m_corr_length);
        p_new->setDomainSizes(m_domain_sizes[0], m_domain_sizes[1]);
        p_new->setProbabilityDistributions(*m_pdfs[0], *m_pdfs[1]);
        p_new->setIntegrationOverXi(m_integrate_xi);
        return p_new;
    }
    static InterferenceFunction2DParaCrystal *createSquare(double peak_distance, double corr_length=0.0,
            double domain_size_1=0.0, double domain_size_2=0.0);
    static InterferenceFunction2DParaCrystal *createHexagonal(double peak_distance, double corr_length=0.0,
            double domain_size_1=0.0, double domain_size_2=0.0);

    void setDomainSizes(double size_1, double size_2) {
        m_domain_sizes[0] = size_1;
        m_domain_sizes[1] = size_2;
    }

    void setProbabilityDistributions(const IFTDistribution2D &pdf_1, const IFTDistribution2D &pdf_2);

    void setIntegrationOverXi(bool integrate_xi) { m_integrate_xi = integrate_xi; }

    virtual double evaluate(const cvector_t &q) const;

    //! add parameters from local pool to external pool and call recursion over direct children
    virtual std::string addParametersToExternalPool(std::string path, ParameterPool *external_pool, int copy_number=-1) const;
protected:
    void transformToPrincipalAxes(double qx, double qy, double gamma, double delta, double &q_pa_1, double &q_pa_2) const;
    double m_lattice_lengths[2];
    double m_alpha_lattice; //!< Angle between lattice basis vectors
    double m_xi; //!< Orientation of the lattice wrt beam axis x
    bool m_integrate_xi; //!< Integrate over the orientation xi
    IFTDistribution2D *m_pdfs[2];
    double m_corr_length;
    bool m_use_corr_length;
    double m_domain_sizes[2];
private:
    //! copy constructor and assignment operator are hidden since there is a clone method
    InterferenceFunction2DParaCrystal(const InterferenceFunction2DParaCrystal &);
    InterferenceFunction2DParaCrystal &operator=(const InterferenceFunction2DParaCrystal &);

    //! initialize pool parameters, i.e. register some of class members for later access via parameter pool
    virtual void init_parameters();

    //! Calculate interference function for fixed rotation xi
    double interferenceForXi(double xi, void *params) const;

    //! calculate interference function for fixed xi in 1d
    double interference1D(double qx, double qy, double xi, size_t index) const;

    complex_t FTPDF(double qx, double qy, double xi, size_t index) const;

    mutable double m_qx;
    mutable double m_qy;

};

#endif /* INTERFERENCEFUNCTION2DPARACRYSTAL_H_ */