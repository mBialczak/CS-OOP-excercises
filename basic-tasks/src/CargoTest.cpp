#include "Fruit.hpp"

#include <gtest/gtest.h>

namespace cargo::test {

class CargoTest : public testing::Test
{
  protected:
    Fruit bananas { "banana", 3500, 1.05, 10 };
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

TEST_F(CargoTest, ForFruitGetPriceShouldReflectWorthFactorDecrease)
{
    double price_before_decrease = bananas.price();
    double starting_time_to_expiry = bananas.timeBeforeExpiry();
    double expected_time_left = starting_time_to_expiry - 2.0;
    double expected_worth_factor = expected_time_left / starting_time_to_expiry;
    double expected_price = expected_worth_factor * price_before_decrease;
    --bananas;
    --bananas;

    ASSERT_EQ(bananas.basePrice(), price_before_decrease);
    EXPECT_LT(bananas.price(), price_before_decrease);
    EXPECT_NEAR(bananas.price(), expected_price, 0.0001);
}

TEST_F(CargoTest, ForFruitOperatorMinusMinusShouldDecreaseTimeToSpoilByOne)
{
    auto expiry_time_before_decrease = bananas.timeBeforeExpiry();
    --bananas;
    --bananas;

    EXPECT_LT(bananas.timeBeforeExpiry(), expiry_time_before_decrease);
    EXPECT_EQ(bananas.timeBeforeExpiry(), expiry_time_before_decrease - 2);
}

TEST_F(CargoTest, ForFruitTimeToSpoilShouldReturnTimeLeftToSpoil)
{
    --bananas;
    --bananas;

    EXPECT_EQ(bananas.timeBeforeExpiry(), 8);
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
}   // namespace cargo::test
