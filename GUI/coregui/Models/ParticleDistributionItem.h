// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/ParticleDistributionItem.h
//! @brief     Defines class ParticleDistributionItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef PARTICLEDISTRIBUTIONITEM_H
#define PARTICLEDISTRIBUTIONITEM_H

#include "ParticleDistribution.h"
#include "SessionGraphicsItem.h"

#include <QStringList>

class ParameterPool;

class BA_CORE_API_ ParticleDistributionItem : public SessionGraphicsItem
{
    Q_OBJECT
public:
    static const QString P_DISTRIBUTED_PARAMETER;
    static const QString P_DISTRIBUTION;
    static const QString NO_SELECTION;
    static const QString T_PARTICLES;
    explicit ParticleDistributionItem();
    virtual ~ParticleDistributionItem();

    std::unique_ptr<ParticleDistribution> createParticleDistribution() const;

public slots:
    void updateParameterList();

private:
    QStringList getChildParameterNames() const;
    QStringList extractFromParameterPool(const ParameterPool *pool) const;
};

#endif // PARTICLEDISTRIBUTIONITEM_H

