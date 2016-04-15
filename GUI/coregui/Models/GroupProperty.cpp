// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/GroupProperty.cpp
//! @brief     Implements class GroupProperty
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "GroupProperty.h"
#include "GUIHelpers.h"
#include "ItemFactory.h"
#include <QDebug>


GroupProperty::GroupProperty(QString group_name)
    : m_group_name(std::move(group_name))
    , m_group_type(UNDEFINED)
    , m_groupItem(0)
{
}

GroupProperty::EGroupType GroupProperty::type() const
{
    return m_group_type;
}

SessionItem *GroupProperty::getCurrentItem()
{
    qDebug() << "GroupProperty::getCurrentItem()" << m_groupItem;
    if(m_groupItem) return m_groupItem->getChildByName(this->getCurrentType());
    return 0;
}

void GroupProperty::setGroupItem(SessionItem *groupItem)
{
    Q_ASSERT(groupItem);
    m_groupItem = groupItem;
    SessionItem *item = createCorrespondingItem();
    m_groupItem->insertItem(-1, item);
}

SessionItem *GroupProperty::createCorrespondingItem()
{
    SessionItem *result = ItemFactory::createItem(getCurrentType());
    if(type() == FIXED) {
        setCurrentLabel(result->itemLabel());
    }
    return result;
}

QString GroupProperty::getGroupName() const
{
    return m_group_name;
}

QString GroupProperty::getCurrentType() const
{
    return m_current_type;
}

void GroupProperty::setCurrentType(const QString &type, bool)
{
    qDebug() << "GGG GroupProperty::setCurrentType(const QString &type)" << type;
    if(type == getCurrentType()) return;

    SessionItem *prevItem = getCurrentItem();
    m_current_type = type;

    if(m_groupItem) {
        if (auto item = m_groupItem->getChildByName(m_current_type)) {
            item->setVisible(true);
            item->setEnabled(true);
        } else {
            SessionItem *new_item = createCorrespondingItem();
            m_groupItem->insertItem(-1, new_item);
        }

        if(prevItem) {
            prevItem->setVisible(false);
            prevItem->setEnabled(false);
        }

        m_groupItem->emitDataChanged();
    }
}

QString GroupProperty::getCurrentLabel() const
{
    return m_type_label_map.at(m_current_type);
}

void GroupProperty::setCurrentLabel(const QString &label)
{
    if(type() == FIXED) {
        m_type_label_map[m_current_type] = label;
//        if(m_groupItem) {
//            m_groupItem->emitDataChanged();
//        }
////        if(m_groupItem) m_groupItem->getItem(getGroupName())->emitValueChanged();
////        if(m_groupItem) {
////            qDebug() << "!!!" << m_groupItem
////        }
    }
}

QStringList GroupProperty::getTypes() const
{
    QStringList result;
    for (const auto& key_value_pair : m_type_label_map) {
        result << key_value_pair.first;
    }
    return result;
}

QStringList GroupProperty::getLabels() const
{
    QStringList result;
    for (const auto& key_value_pair : m_type_label_map) {
        result << key_value_pair.second;
    }
    return result;
}

int GroupProperty::index() const
{
    return toIndex(m_current_type);
}

int GroupProperty::toIndex(const QString &type) const
{
    QStringList name_list = getTypes();
    for (int i = 0; i < name_list.size(); ++i) {
        if (type == name_list[i]) {
            return i;
        }
    }
    return -1;
}

QString GroupProperty::toString(int index) const
{
    QStringList name_list = getTypes();
    if (index<0 || index>=name_list.size()) {
        return QString();
    }
    return name_list[index];
}

bool GroupProperty::isFixed() const
{
    return m_group_type == GroupProperty::FIXED;
}

void GroupProperty::setGroupMap(std::map<QString, QString> group_map)
{
    m_type_label_map = std::move(group_map);
    setCurrentType(m_type_label_map.begin()->first);
}

void GroupProperty::setGroupType(GroupProperty::EGroupType group_type)
{
    m_group_type = group_type;
}

