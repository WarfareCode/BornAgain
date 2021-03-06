//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/tests/testmodel/vectoritem.test.cpp
//! @brief     Implements class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "google_test.h"
#include "mvvm/model/itemutils.h"
#include "mvvm/model/sessionmodel.h"
#include "mvvm/standarditems/vectoritem.h"

using namespace ModelView;

//! VectorItem tests.

class VectorItemTest : public ::testing::Test {
public:
    ~VectorItemTest();
};

VectorItemTest::~VectorItemTest() = default;

//! Initial state of item when it is created outside of model context.

TEST_F(VectorItemTest, initialState)
{
    VectorItem item;

    EXPECT_TRUE(Utils::IsSinglePropertyTag(item, VectorItem::P_X));
    EXPECT_TRUE(Utils::IsSinglePropertyTag(item, VectorItem::P_Y));
    EXPECT_TRUE(Utils::IsSinglePropertyTag(item, VectorItem::P_Z));

    EXPECT_FALSE(item.isEditable());

    EXPECT_EQ(item.property<double>(VectorItem::P_X), 0.0);
    EXPECT_EQ(item.property<double>(VectorItem::P_Y), 0.0);
    EXPECT_EQ(item.property<double>(VectorItem::P_Z), 0.0);

    // default label
    EXPECT_EQ(item.data<std::string>(), "(0, 0, 0)");
}

//! Initial state of item in model context

TEST_F(VectorItemTest, initialStateFromModel)
{
    SessionModel model;
    auto item = model.insertItem<VectorItem>();

    EXPECT_EQ(item->property<double>(VectorItem::P_X), 0.0);
    EXPECT_EQ(item->property<double>(VectorItem::P_Y), 0.0);
    EXPECT_EQ(item->property<double>(VectorItem::P_Z), 0.0);

    // default label
    EXPECT_EQ(item->data<std::string>(), "(0, 0, 0)");

    // changing vector component
    item->setProperty(VectorItem::P_X, 1.0);
    EXPECT_EQ(item->data<std::string>(), "(1, 0, 0)");
}
