// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/Lattice/Lattice.cpp
//! @brief     Implements class Lattice.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Sample/Lattice/Lattice.h"
#include "Base/Const/MathConstants.h"
#include "Base/Vector/Transform3D.h"
#include "Param/Base/RealParameter.h"
#include "Sample/Lattice/ISelectionRule.h"
#include <gsl/gsl_linalg.h>

Lattice::Lattice()
    : m_a({1.0, 0.0, 0.0})
    , m_b({0.0, 1.0, 0.0})
    , m_c({0.0, 0.0, 1.0})
{
    setName("Lattice");
    initialize();
}

Lattice::Lattice(const kvector_t a1, const kvector_t a2, const kvector_t a3)
    : m_a(a1), m_b(a2), m_c(a3)
{
    setName("Lattice");
    initialize();
}

Lattice::Lattice(const Lattice& lattice)
    : INode()
    , m_a(lattice.m_a)
    , m_b(lattice.m_b)
    , m_c(lattice.m_c)
{
    setName("Lattice");
    initialize();
    if (lattice.m_selection_rule)
        setSelectionRule(*lattice.m_selection_rule);
}

Lattice::~Lattice() = default;

void Lattice::initialize()
{
    computeReciprocalVectors();
    if (!parameter(XComponentName("BasisA"))) {
        registerVector("BasisA", &m_a, "nm");
        registerVector("BasisB", &m_b, "nm");
        registerVector("BasisC", &m_c, "nm");
    }
}

void Lattice::onChange()
{
    computeReciprocalVectors();
}

Lattice Lattice::transformed(const Transform3D& transform) const
{
    kvector_t a1 = transform.transformed(m_a);
    kvector_t a2 = transform.transformed(m_b);
    kvector_t a3 = transform.transformed(m_c);
    Lattice result = {a1, a2, a3};
    if (m_selection_rule)
        result.setSelectionRule(*m_selection_rule);
    return result;
}

//! Currently unused but may be useful for checks
kvector_t Lattice::getMillerDirection(double h, double k, double l) const
{
    kvector_t direction = h * m_ra + k * m_rb + l * m_rc;
    return direction.unit();
}

double Lattice::volume() const
{
    return std::abs(m_a.dot(m_b.cross(m_c)));
}

//! Currently only used in tests
void Lattice::getReciprocalLatticeBasis(kvector_t& b1, kvector_t& b2, kvector_t& b3) const
{
    b1 = m_ra;
    b2 = m_rb;
    b3 = m_rc;
}

ivector_t Lattice::getNearestLatticeVectorCoordinates(const kvector_t vector_in) const
{
    double a1_coord = vector_in.dot(m_ra) / M_TWOPI;
    double a2_coord = vector_in.dot(m_rb) / M_TWOPI;
    double a3_coord = vector_in.dot(m_rc) / M_TWOPI;
    int c1 = static_cast<int>(std::floor(a1_coord + 0.5));
    int c2 = static_cast<int>(std::floor(a2_coord + 0.5));
    int c3 = static_cast<int>(std::floor(a3_coord + 0.5));
    return ivector_t(c1, c2, c3);
}

ivector_t Lattice::getNearestReciprocalLatticeVectorCoordinates(const kvector_t vector_in) const
{
    double b1_coord = vector_in.dot(m_a) / M_TWOPI;
    double b2_coord = vector_in.dot(m_b) / M_TWOPI;
    double b3_coord = vector_in.dot(m_c) / M_TWOPI;
    int c1 = static_cast<int>(std::floor(b1_coord + 0.5));
    int c2 = static_cast<int>(std::floor(b2_coord + 0.5));
    int c3 = static_cast<int>(std::floor(b3_coord + 0.5));
    return ivector_t(c1, c2, c3);
}

std::vector<kvector_t> Lattice::reciprocalLatticeVectorsWithinRadius(const kvector_t input_vector,
                                                                     double radius) const
{
    ivector_t nearest_coords = getNearestReciprocalLatticeVectorCoordinates(input_vector);

    int max_X = static_cast<int>(std::floor(m_a.mag() * radius / M_TWOPI + 0.5));
    int max_Y = static_cast<int>(std::floor(m_b.mag() * radius / M_TWOPI + 0.5));
    int max_Z = static_cast<int>(std::floor(m_c.mag() * radius / M_TWOPI + 0.5));

    std::vector<kvector_t> ret;
    for (int index_X = -max_X; index_X <= max_X; ++index_X) {
        for (int index_Y = -max_Y; index_Y <= max_Y; ++index_Y) {
            for (int index_Z = -max_Z; index_Z <= max_Z; ++index_Z) {
                ivector_t coords(index_X + nearest_coords[0], index_Y + nearest_coords[1],
                                 index_Z + nearest_coords[2]);
                if (m_selection_rule && !m_selection_rule->coordinateSelected(coords))
                    continue;
                kvector_t latticePoint = coords[0] * m_ra + coords[1] * m_rb + coords[2] * m_rc;
                if ((latticePoint - input_vector).mag() <= radius)
                    ret.push_back(latticePoint);
            }
        }
    }
    return ret;
}

void Lattice::computeReciprocalVectors() const
{
    kvector_t a23 = m_b.cross(m_c);
    kvector_t a31 = m_c.cross(m_a);
    kvector_t a12 = m_a.cross(m_b);
    m_ra = M_TWOPI / m_a.dot(a23) * a23;
    m_rb = M_TWOPI / m_b.dot(a31) * a31;
    m_rc = M_TWOPI / m_c.dot(a12) * a12;
}

void Lattice::setSelectionRule(const ISelectionRule& selection_rule)
{
    m_selection_rule.reset(selection_rule.clone());
}
