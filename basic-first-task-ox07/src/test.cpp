#include "Ship.hpp"

#include <gtest/gtest.h>

class ShipTest : public testing::Test
{
  protected:
    ShipTest();
    Ship empty_ship_;
    Ship ship_with_id_and_name_;
};

ShipTest::ShipTest()
    : empty_ship_()
    , ship_with_id_and_name_("Z3EW", "Jevenau")
{
}

TEST_F(ShipTest, IdShouldReturnEmptyIdIfIdNotSet)
{
    EXPECT_EQ(empty_ship_.id(), "");
    EXPECT_NE(ship_with_id_and_name_.id(), "");
}

TEST_F(ShipTest, IdShouldReturnCorrectShipId)
{
    EXPECT_EQ(ship_with_id_and_name_.id(), "Z3EW");
}

TEST_F(ShipTest, NameShouldReturnEmptyNameIfNameNotGiven)
{
    EXPECT_EQ(empty_ship_.id(), "");
}

TEST_F(ShipTest, NameShouldReturnNameOfNamedShip)
{
    EXPECT_EQ(ship_with_id_and_name_.name(), "Jevenau");
}
