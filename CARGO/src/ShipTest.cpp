#include "Ship.hpp"

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace ship::test {

using cargo::Alcohol;
using cargo::Cargo;
using cargo::Fruit;
using cargo::Item;
using cargo::Rarity;
using namespace testing;

class ShipTest : public testing::Test
{
  protected:
    ShipTest();
    Ship empty_ship_;
    Ship ship_with_id_and_name_;
    Ship ship_with_id_name_speed_;
    Ship ship_with_max_crew_;
    Ship ship_with_capacity_;
    Ship jevenau_;

    std::shared_ptr<Cargo> beer_;
    std::shared_ptr<Cargo> strawberries_;
    std::shared_ptr<Cargo> smartphones_;
};

ShipTest::ShipTest()
    : empty_ship_()
    , ship_with_id_and_name_("Z3EW", "Jevenau", 14, 10, 2100)
    , ship_with_id_name_speed_("B4EZ", "Morning Star", 10.2)
    , ship_with_max_crew_("EYNN", "Sniadecki", 15.5, 800)
    , ship_with_capacity_("AE4E", "MSC Incredible", 13.5, 30, 4000)
    , jevenau_("Z3EW", "Jevenau", 14, 10, 2100)
    , beer_(std::make_shared<Alcohol>("Beer- light", 2000, 50.0, 5.0))
    , strawberries_(std::make_shared<Fruit>("strawberries", 4500, 12.5, 9.0))
    , smartphones_(std::make_shared<Item>("Smartphones", 1500, 1200, Rarity::common))
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

TEST_F(ShipTest, CargoHoldShouldReturnTheReferenceToCargoHoldContainer)
{
    const auto& cargo_hold = jevenau_.cargoHold();

    EXPECT_EQ(cargo_hold.size(), 0);
}

TEST_F(ShipTest, LoadShouldBeAbleToAddCargoToShipsVectorOfCargos)
{
    jevenau_.load(beer_);
    jevenau_.load(strawberries_);
    jevenau_.load(smartphones_);

    EXPECT_THAT(jevenau_.cargoHold(), ElementsAre(beer_, strawberries_, smartphones_));
}

TEST_F(ShipTest, UnloadShouldRemoveCargoFromCargoHoldContainer)
{
    jevenau_.load(beer_);
    jevenau_.load(strawberries_);
    jevenau_.load(smartphones_);
    auto size_before_unloading = jevenau_.cargoHold().size();

    jevenau_.unload(strawberries_.get());

    EXPECT_NE(jevenau_.cargoHold().size(), size_before_unloading);
    EXPECT_THAT(jevenau_.cargoHold(), ElementsAre(beer_, smartphones_));
}

TEST_F(ShipTest, UnloadShouldNOTchangeCargoHoldContainerIfRequestedCargoIsNotInTheHold)
{
    jevenau_.load(beer_);
    jevenau_.load(smartphones_);
    auto size_before_unloading = jevenau_.cargoHold().size();

    jevenau_.unload(strawberries_.get());

    EXPECT_EQ(jevenau_.cargoHold().size(), size_before_unloading);
    EXPECT_THAT(jevenau_.cargoHold(), ElementsAre(beer_, smartphones_));
}
}   // namespace ship::test
