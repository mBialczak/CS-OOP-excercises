#include "Ship.hpp"

#include <gtest/gtest.h>

TEST(ShipClassTests, ShouldBeAbleToCreateShipClass)
{
    Ship empty_ship;
}

TEST(ShipClassTests, GetIdShouldReturnEmptyIdIfIdNotSet)
{
    Ship empty_ship;
    Ship named_ship { "Z3EW", "Jevenau" };

    auto empty_name = empty_ship.id();
    auto non_empty_name = named_ship.id();

    EXPECT_EQ("", empty_name);
    EXPECT_NE("", non_empty_name);
}

TEST(ShipClassTests, IdShouldReturnCorrectShipId)
{
    Ship jevenau { "Z3EW", "Jevenau" };

    auto id = jevenau.id();

    EXPECT_EQ(id, "Z3EW");
}

TEST(ShipClassTests, ShouldReturnEmptyNameIfNameNotGiven)
{
    Ship no_namer;

    auto name = no_namer.name();

    EXPECT_EQ("", name);
}

TEST(ShipClassTests, ShouldReturnNameOfShip)
{
    Ship ruler { "E5WR", "Arklow Ruler" };

    auto name = ruler.name();

    EXPECT_EQ("Arklow Ruler", name);
}
