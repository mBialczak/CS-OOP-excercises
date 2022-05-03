#include "Ship.hpp"

#include <gtest/gtest.h>

class ShipTest : public testing::Test
{
  protected:
    ShipTest();
    Ship empty_ship_;
    Ship ship_with_id_and_name_;
    Ship ship_with_id_name_speed;
};

ShipTest::ShipTest()
    : empty_ship_()
    , ship_with_id_and_name_("Z3EW", "Jevenau")
    , ship_with_id_name_speed("B4EZ", "Morning Star", 10.2)
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

TEST_F(ShipTest, SpeedShouldReturnZeroIfNotSet)
{
    EXPECT_EQ(empty_ship_.speed(), 0);
}

TEST_F(ShipTest, SpeedShouldReturnCorrectSpeedOfTheShip)
{
    EXPECT_EQ(ship_with_id_name_speed.speed(), 10.2);
}

TEST_F(ShipTest, MaxCrewShouldReturnZeroForEmptyShip)
{
    EXPECT_EQ(empty_ship_.maxCrew(), 0);
}
