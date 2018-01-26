#include "google_test.h"
#include "Beam.h"
#include "RectangularDetector.h"
#include "UnitConverters.h"
#include "Units.h"
#include "Vectors3D.h"

namespace {
const double det_width = 200.0;
const double det_height = 140.0;
const double det_distance = 1000.0;
const size_t det_nx = 100u;
const size_t det_ny = 70u;
}

class RectangularConverterTest : public ::testing::Test
{
public:
    RectangularConverterTest();
    ~RectangularConverterTest();
protected:
    RectangularDetector m_detector;
    Beam m_beam;
    double m_phi, m_alpha;
    double m_kiz, m_kfy, m_kfz;
};

RectangularConverterTest::RectangularConverterTest()
    : m_detector(det_nx, det_width, det_ny, det_height)
{
    m_beam.setCentralK(1.0, 1.0*Units::deg, 0.0);
    m_detector.setPerpendicularToSampleX(det_distance, det_width/2.0, 0.0);
    m_detector.init(m_beam);
    m_phi = std::atan2(det_width/2.0, det_distance);
    m_alpha = std::atan2(det_height, det_distance/std::cos(m_phi));
    auto k_i = m_beam.getCentralK();
    m_kiz = k_i.z();
    double K = 2.0*M_PI/m_beam.getWavelength();
    m_kfy = K*std::sin(m_phi);
    m_kfz = K*std::sin(m_alpha);
}

RectangularConverterTest::~RectangularConverterTest() = default;

TEST_F(RectangularConverterTest, RectangularConverter)
{
    RectangularConverter converter(m_detector, m_beam);

    EXPECT_EQ(converter.dimension(), 2u);

    EXPECT_DOUBLE_EQ(converter.calculateMin(0, AxesUnits::DEFAULT), 0.0);
    EXPECT_DOUBLE_EQ(converter.calculateMin(0, AxesUnits::NBINS), 0.0);
    EXPECT_DOUBLE_EQ(converter.calculateMin(0, AxesUnits::MM), 0.0);
    EXPECT_NEAR(converter.calculateMin(0, AxesUnits::RADIANS), -m_phi, m_phi*1e-10);
    EXPECT_NEAR(converter.calculateMin(0, AxesUnits::DEGREES), Units::rad2deg(-m_phi),
                Units::rad2deg(m_phi)*1e-10);
    EXPECT_NEAR(converter.calculateMin(0, AxesUnits::QSPACE), -m_kfy, m_kfy*1e-10);

    EXPECT_DOUBLE_EQ(converter.calculateMax(0, AxesUnits::DEFAULT), det_width);
    EXPECT_DOUBLE_EQ(converter.calculateMax(0, AxesUnits::NBINS), static_cast<double>(det_nx));
    EXPECT_DOUBLE_EQ(converter.calculateMax(0, AxesUnits::MM), det_width);
    EXPECT_NEAR(converter.calculateMax(0, AxesUnits::RADIANS), m_phi, m_phi*1e-10);
    EXPECT_NEAR(converter.calculateMax(0, AxesUnits::DEGREES), Units::rad2deg(m_phi),
                Units::rad2deg(m_phi)*1e-10);
    EXPECT_NEAR(converter.calculateMax(0, AxesUnits::QSPACE), m_kfy, m_kfy*1e-10);

    EXPECT_DOUBLE_EQ(converter.calculateMin(1, AxesUnits::DEFAULT), 0.0);
    EXPECT_DOUBLE_EQ(converter.calculateMin(1, AxesUnits::NBINS), 0.0);
    EXPECT_DOUBLE_EQ(converter.calculateMin(1, AxesUnits::MM), 0.0);
    EXPECT_DOUBLE_EQ(converter.calculateMin(1, AxesUnits::RADIANS), 0.0);
    EXPECT_DOUBLE_EQ(converter.calculateMin(1, AxesUnits::DEGREES), 0.0);
    EXPECT_NEAR(converter.calculateMin(1, AxesUnits::QSPACE), - m_kiz, std::abs(m_kiz)*1e-10);

    EXPECT_DOUBLE_EQ(converter.calculateMax(1, AxesUnits::DEFAULT), det_height);
    EXPECT_DOUBLE_EQ(converter.calculateMax(1, AxesUnits::NBINS), static_cast<double>(det_ny));
    EXPECT_DOUBLE_EQ(converter.calculateMax(1, AxesUnits::MM), det_height);
    EXPECT_NEAR(converter.calculateMax(1, AxesUnits::RADIANS), m_alpha, m_alpha*1e-10);
    EXPECT_NEAR(converter.calculateMax(1, AxesUnits::DEGREES), Units::rad2deg(m_alpha),
                Units::rad2deg(m_alpha)*1e-10);
    EXPECT_NEAR(converter.calculateMax(1, AxesUnits::QSPACE), m_kfz - m_kiz,
                std::abs(m_kfz - m_kiz)*1e-10);

    EXPECT_THROW(converter.calculateMin(2, AxesUnits::DEFAULT), std::runtime_error);
    EXPECT_THROW(converter.calculateMax(2, AxesUnits::DEFAULT), std::runtime_error);
}

TEST_F(RectangularConverterTest, RectangularConverterClone)
{
    RectangularConverter converter(m_detector, m_beam);
    std::unique_ptr<RectangularConverter> P_clone(converter.clone());

    EXPECT_EQ(P_clone->dimension(), 2u);

    EXPECT_DOUBLE_EQ(P_clone->calculateMin(0, AxesUnits::DEFAULT), 0.0);
    EXPECT_DOUBLE_EQ(P_clone->calculateMin(0, AxesUnits::NBINS), 0.0);
    EXPECT_DOUBLE_EQ(P_clone->calculateMin(0, AxesUnits::MM), 0.0);
    EXPECT_NEAR(P_clone->calculateMin(0, AxesUnits::RADIANS), -m_phi, m_phi*1e-10);
    EXPECT_NEAR(P_clone->calculateMin(0, AxesUnits::DEGREES), Units::rad2deg(-m_phi),
                Units::rad2deg(m_phi)*1e-10);
    EXPECT_NEAR(P_clone->calculateMin(0, AxesUnits::QSPACE), -m_kfy, m_kfy*1e-10);

    EXPECT_DOUBLE_EQ(P_clone->calculateMax(0, AxesUnits::DEFAULT), det_width);
    EXPECT_DOUBLE_EQ(P_clone->calculateMax(0, AxesUnits::NBINS), static_cast<double>(det_nx));
    EXPECT_DOUBLE_EQ(P_clone->calculateMax(0, AxesUnits::MM), det_width);
    EXPECT_NEAR(P_clone->calculateMax(0, AxesUnits::RADIANS), m_phi, m_phi*1e-10);
    EXPECT_NEAR(P_clone->calculateMax(0, AxesUnits::DEGREES), Units::rad2deg(m_phi),
                Units::rad2deg(m_phi)*1e-10);
    EXPECT_NEAR(P_clone->calculateMax(0, AxesUnits::QSPACE), m_kfy, m_kfy*1e-10);

    EXPECT_DOUBLE_EQ(P_clone->calculateMin(1, AxesUnits::DEFAULT), 0.0);
    EXPECT_DOUBLE_EQ(P_clone->calculateMin(1, AxesUnits::NBINS), 0.0);
    EXPECT_DOUBLE_EQ(P_clone->calculateMin(1, AxesUnits::MM), 0.0);
    EXPECT_DOUBLE_EQ(P_clone->calculateMin(1, AxesUnits::RADIANS), 0.0);
    EXPECT_DOUBLE_EQ(P_clone->calculateMin(1, AxesUnits::DEGREES), 0.0);
    EXPECT_NEAR(P_clone->calculateMin(1, AxesUnits::QSPACE), - m_kiz, std::abs(m_kiz)*1e-10);

    EXPECT_DOUBLE_EQ(P_clone->calculateMax(1, AxesUnits::DEFAULT), det_height);
    EXPECT_DOUBLE_EQ(P_clone->calculateMax(1, AxesUnits::NBINS), static_cast<double>(det_ny));
    EXPECT_DOUBLE_EQ(P_clone->calculateMax(1, AxesUnits::MM), det_height);
    EXPECT_NEAR(P_clone->calculateMax(1, AxesUnits::RADIANS), m_alpha, m_alpha*1e-10);
    EXPECT_NEAR(P_clone->calculateMax(1, AxesUnits::DEGREES), Units::rad2deg(m_alpha),
                Units::rad2deg(m_alpha)*1e-10);
    EXPECT_NEAR(P_clone->calculateMax(1, AxesUnits::QSPACE), m_kfz - m_kiz,
                std::abs(m_kfz - m_kiz)*1e-10);

    EXPECT_THROW(P_clone->calculateMin(2, AxesUnits::DEFAULT), std::runtime_error);
    EXPECT_THROW(P_clone->calculateMax(2, AxesUnits::DEFAULT), std::runtime_error);
}
