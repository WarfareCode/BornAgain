// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/IntensityDataItem.h
//! @brief     Defines class IntensityDataItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef INTENSITYDATAITEM_H
#define INTENSITYDATAITEM_H

#include "DataItem.h"

class BasicAxisItem;
class MaskContainerItem;
class ProjectionContainerItem;

class BA_CORE_API_ IntensityDataItem : public DataItem
{
public:
    static const QString P_PROJECTIONS_FLAG;
    static const QString P_TITLE;
    static const QString P_IS_INTERPOLATED;
    static const QString P_GRADIENT;
    static const QString P_XAXIS;
    static const QString P_YAXIS;
    static const QString P_ZAXIS;
    static const QString T_MASKS;
    static const QString T_PROJECTIONS;

    IntensityDataItem();

    void setOutputData(OutputData<double>* data) override;
    void setRawDataVector(const OutputData<double>* data) override;

    int getNbinsX() const;
    int getNbinsY() const;

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

    void updateDataRange();
    void computeDataRange();
    QPair<double, double> dataRange() const;

    const BasicAxisItem* xAxisItem() const;
    BasicAxisItem* xAxisItem();
    const BasicAxisItem* yAxisItem() const;
    BasicAxisItem* yAxisItem();
    const BasicAxisItem* zAxisItem() const;
    BasicAxisItem* zAxisItem();

    void resetView();

    MaskContainerItem* maskContainerItem();
    ProjectionContainerItem* projectionContainerItem();

    void setXaxisTitle(QString xtitle) override;
    void setYaxisTitle(QString ytitle) override;
    void setAxesRangeToData() override;
    void updateAxesUnits(const InstrumentItem* instrument) override;

    //! Returns data to default state (no dimensional units, default axes' names)
    void resetToDefault() override;

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

private:
    void updateAxesZoomLevel();
    void updateAxesLabels();
};

#endif // INTENSITYDATAITEM_H

