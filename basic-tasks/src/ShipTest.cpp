#include "Ship.hpp"

#include <gtest/gtest.h>

namespace ship::test {

class ShipTest : public testing::Test
{
  public:
    ShipTest();
    Ship empty_ship_;
    Ship ship_with_id_and_name_;
    Ship ship_with_id_name_speed_;
    Ship ship_with_max_crew_;
    Ship ship_with_capacity_;
    Ship jevenau_;
};

ShipTest::ShipTest()
    : empty_ship_()
    , ship_with_id_and_name_("Z3EW", "Jevenau", 14, 10, 2100)
    , ship_with_id_name_speed_("B4EZ", "Morning Star", 10.2)
    , ship_with_max_crew_("EYNN", "Sniadecki", 15.5, 800)
    , ship_with_capacity_("AE4E", "MSC Incredible", 13.5, 30, 4000)
    , jevenau_("Z3EW", "Jevenau", 14, 10, 2100)
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
    EXPECT_EQ(ship_with_id_name_speed_.speed(), 10.2);
}

TEST_F(ShipTest, MaxCrewShouldReturnShipsMaxCrewWhenSet)
{
    EXPECT_EQ(ship_with_max_crew_.maxCrew(), 800);
}

TEST_F(ShipTest, CapacityShouldReturnShipsCapacityWhenSet)
{
    EXPECT_EQ(ship_with_capacity_.capacity(), 4000);
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
    ship_with_max_crew_ += 10;
    auto new_crew_number = ship_with_max_crew_.crew();
    EXPECT_EQ(new_crew_number, 10);
}

TEST_F(ShipTest, AddinCrewWithOperatorShouldDoNothingIfMaxCrewExceeded)
{
    jevenau_ += 5;
    jevenau_ += 3;
    // another addition exceeding crew max should not change the crew number
    jevenau_ += 7;
    auto crew = jevenau_.crew();
    EXPECT_EQ(crew, 8);
}

TEST_F(ShipTest, CompoundSubstractionOperatorShouldSubstructCrew)
{
    jevenau_ += 10;
    jevenau_ -= 3;
    auto current_crew = jevenau_.crew();
    EXPECT_EQ(current_crew, 7);
}

TEST_F(ShipTest, CompoundSubstractionShouldDoNothingIfCrewWouldFallBelowZero)
{

    jevenau_ += 4;
    jevenau_ -= 6;
    auto current_crew = jevenau_.crew();
    EXPECT_EQ(current_crew, 4);
}
}   // namespace ship::test
