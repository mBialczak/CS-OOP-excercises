#include "Cargo.hpp"

#include <gtest/gtest.h>

class CargoTest : public testing::Test
{
  protected:
    // CargoTest();

    Cargo bananas { "banana", 3500, 1.05 };
};

TEST_F(CargoTest, NameShouldReturnNameOfTheCargo)
{
    EXPECT_EQ(bananas.name(), "banana");
}

TEST_F(CargoTest, AmountShouldReturnAmountOfCargoI)
{
    EXPECT_EQ(bananas.amount(), 3500);
}

TEST_F(CargoTest, BasePriceShouldReturnBasePriceOfTheCargo)
{
    EXPECT_EQ(bananas.basePrice(), 1.05);
}

TEST_F(CargoTest, CompoundAddOperatorShouldAddAmountOfCargo)
{
    bananas += 400;
    EXPECT_EQ(bananas.amount(), 3900);
}

TEST_F(CargoTest, CompoundSubstractOperatorShouldDecrementAmountOfCargo)
{
    bananas -= 500;
    EXPECT_EQ(bananas.amount(), 3000);
}

TEST_F(CargoTest, CompoundSubOperatorShouldWorkForExactAmountNullification)
{
    bananas -= 3500;
    EXPECT_EQ(bananas.amount(), 0);
}

TEST_F(CargoTest, CompoundSubstractOperatorShoulDoNothingIfAttemptToRemoveMoreCargoThanThereIs)
{
    bananas -= 5000;
    EXPECT_EQ(bananas.amount(), 3500);
}