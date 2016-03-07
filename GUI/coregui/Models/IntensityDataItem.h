// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/NIntensityDataItem.h
//! @brief     Defines class NIntensityDataItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef INTENSITYDATAITEM_H
#define INTENSITYDATAITEM_H

#include "SessionItem.h"
#include "OutputData.h"
#include "IDetector2D.h"
#include <QMap>

class GISASSimulation;


class BA_CORE_API_ IntensityDataItem : public SessionItem
{
    Q_OBJECT
public:
    static const QString P_PROJECTIONS_FLAG;
    static const QString P_IS_INTERPOLATED;
    static const QString P_GRADIENT;
    static const QString P_ZAXIS_MIN;
    static const QString P_ZAXIS_MAX;
    static const QString P_AXES_UNITS;
    static const QString P_PROPERTY_PANEL_FLAG;
    static const QString P_XAXIS;
    static const QString P_YAXIS;
    static const QString P_ZAXIS;
    static const QString T_MASKS;

    explicit IntensityDataItem();
    virtual ~IntensityDataItem();

    OutputData<double> *getOutputData() { return m_data.get(); }
    const OutputData<double> *getOutputData() const { return m_data.get(); }
    void setOutputData(OutputData<double> *data);

    //! returns lower and upper zoom ranges of x-axis
    double getLowerX() const;
    double getUpperX() const;

    //! returns min and max range of x-axis as given by IntensityData
    double getXmin() const;
    double getXmax() const;

    //! returns lower and upper zoom ranges of y-axis
    double getLowerY() const;
    double getUpperY() const;

    //! returns min and max range of y-axis as given by IntensityData
    double getYmin() const;
    double getYmax() const;

    //! returns lower and upper zoom ranges of z-axis
    double getLowerZ() const;
    double getUpperZ() const;

    QString getGradient() const;
    bool isLogz() const;
    bool isInterpolated() const;
    QString getXaxisTitle() const;
    QString getYaxisTitle() const;

    //! return true if min, max range of Z-axis is locked (change not allowed)
    bool isZAxisLocked() const;
    void setZAxisLocked(bool state);

    void setNameFromProposed(const QString &proposed_name);

    virtual QString getSelectedAxesUnits() const;

signals:
    void intensityModified();

public slots:
    void setLowerX(double xmin);
    void setUpperX(double xmax);
    void setLowerY(double ymin);
    void setUpperY(double ymax);
    void setLowerAndUpperZ(double zmin, double zmax);
    void setLowerZ(double zmin);
    void setUpperZ(double zmax);
    void setLogz(bool logz);
    void setInterpolated(bool interp);
    void setXaxisTitle(QString xtitle);
    void setYaxisTitle(QString ytitle);
    void setAxesRangeToData();

private:
    std::unique_ptr<OutputData<double> > m_data; //!< simulation results
};

#endif // NINTENSITYDATAITEM_H

