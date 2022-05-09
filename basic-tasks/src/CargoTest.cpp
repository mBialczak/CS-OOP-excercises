#include "Cargo.hpp"

#include <gtest/gtest.h>

class CargoTest : public testing::Test
{
  protected:
    // CargoTest();

    Cargo bananas { "banana", 3500 };
};

TEST_F(CargoTest, NameShouldReturnNameOfTheCargo)
{
    EXPECT_EQ(bananas.name(), "banana");
}

TEST_F(CargoTest, AmountShouldReturnAmountOfCargoI)
{
    EXPECT_EQ(bananas.amount(), 3500);
}