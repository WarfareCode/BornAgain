//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Export/SampleLabelHandler.h
//! @brief     Defines classes LabelMap and SampleLabelHandler.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_CORE_EXPORT_SAMPLELABELHANDLER_H
#define BORNAGAIN_CORE_EXPORT_SAMPLELABELHANDLER_H

#include "Core/Export/OrderedMap.h"
#include <map>
#include <vector>

class IModel;

class IRotation;

template <class Key> class LabelMap : public OrderedMap<Key, std::string> {};

//! The handler which construct labels for sample variables during python script generation.
//! @ingroup tools_internal

class SampleLabelHandler {
public:
    typedef LabelMap<const IRotation*> rotations_t;

    SampleLabelHandler() {}
    rotations_t* rotationsMap() { return &m_RotationsLabel; }

    std::string labelRotation(const IRotation* sample);

    void insertRotation(const IRotation* sample);

    void insertKeyedObject(const std::string& key, const IModel* s);

    template <class T> std::vector<const T*> objectsOfType() const;
    std::string obj2key(const IModel* s) const;

private:
    rotations_t m_RotationsLabel;

    std::map<std::string, std::vector<const IModel*>> m_objects;
};


template <class T> std::vector<const T*> SampleLabelHandler::objectsOfType() const {
    std::vector<const T*> ret;
    for (auto it: m_objects)
        for (const IModel* s : it.second)
            if (const auto* c = dynamic_cast<const T*>(s); c)
                ret.emplace_back(c);
    return ret;
}

#endif // BORNAGAIN_CORE_EXPORT_SAMPLELABELHANDLER_H
