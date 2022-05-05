#include "Ship.hpp"

#include <gtest/gtest.h>

class ShipTest : public testing::Test
{
  protected:
    ShipTest();
    Ship empty_ship_;
    Ship ship_with_id_and_name_;
    Ship ship_with_id_name_speed;
    Ship ship_with_max_crew;
    Ship ship_with_capacity;
};

ShipTest::ShipTest()
    : empty_ship_()
    , ship_with_id_and_name_("Z3EW", "Jevenau")
    , ship_with_id_name_speed("B4EZ", "Morning Star", 10.2)
    , ship_with_max_crew("EYNN", "Sniadecki", 15.5, 800)
    , ship_with_capacity("AE4E", "MSC Incredible", 13.5, 30, 4000)
{
}

TEST_F(ShipTest, UninitializedShipShouldReturnCorrectValues)
{
    EXPECT_EQ(empty_ship_.id(), "");
    EXPECT_EQ(empty_ship_.name(), "");
    EXPECT_EQ(empty_ship_.speed(), 0.0);
    EXPECT_EQ(empty_ship_.maxCrew(), 0);
    EXPECT_EQ(empty_ship_.capacity(), 0);
}
TEST_F(ShipTest, IdShouldReturnCorrectShipId)
{
    EXPECT_EQ(ship_with_id_and_name_.id(), "Z3EW");
}

TEST_F(ShipTest, NameShouldReturnNameOfNamedShip)
{
    EXPECT_EQ(ship_with_id_and_name_.name(), "Jevenau");
}

TEST_F(ShipTest, SpeedShouldReturnCorrectSpeedOfTheShip)
{
    EXPECT_EQ(ship_with_id_name_speed.speed(), 10.2);
}

TEST_F(ShipTest, MaxCrewShouldReturnShipsMaxCrewWhenSet)
{
    EXPECT_EQ(ship_with_max_crew.maxCrew(), 800);
}

TEST_F(ShipTest, CapacityShouldReturnShipsCapacityWhenSet)
{
    EXPECT_EQ(ship_with_capacity.capacity(), 4000);
}

TEST_F(ShipTest, SetNameShouldSetNameInAValidWay)
{
    std::string new_name("Newly Build one");
    empty_ship_.setName(new_name);
    EXPECT_EQ(empty_ship_.name(), new_name);
}

TEST_F(ShipTest, CrewShouldReturnCurrentNumberOfCrewEnroled)
{
    EXPECT_EQ(empty_ship_.crew(), 0);
}

TEST_F(ShipTest, CompoundAddAssingOperShouldAddCrewToTheShip)
{
    ship_with_max_crew += 10;
    auto new_crew_number = ship_with_max_crew.crew();
    EXPECT_EQ(new_crew_number, 10);
}
