#include "Alcohol.hpp"
#include "Fruit.hpp"

#include <gtest/gtest.h>

namespace cargo::test {

class CargoTest : public testing::Test
{
  protected:
    Fruit bananas { "banana", 3500, 1.05, 10.0 };
    Alcohol vodka { "vodka", 2000, 20.0, 40.0 };
};

TEST_F(CargoTest, NameShouldReturnNameOfTheCargo)
{
    EXPECT_EQ(bananas.name(), "banana");
    EXPECT_EQ(vodka.name(), "vodka");
}

TEST_F(CargoTest, AmountShouldReturnAmountOfCargoI)
{
    EXPECT_EQ(bananas.amount(), 3500);
    EXPECT_EQ(vodka.amount(), 2000);
}

TEST_F(CargoTest, BasePriceShouldReturnBasePriceOfTheCargo)
{
    EXPECT_EQ(bananas.basePrice(), 1.05);
    EXPECT_EQ(vodka.basePrice(), 20.0);
}

TEST_F(CargoTest, CompoundAddOperatorShouldAddAmountOfCargo)
{
    bananas += 400;
    vodka += 100;
    EXPECT_EQ(bananas.amount(), 3900);
    EXPECT_EQ(vodka.amount(), 2100);
}

TEST_F(CargoTest, CompoundSubstractOperatorShouldDecrementAmountOfCargo)
{
    bananas -= 500;
    vodka -= 300;
    EXPECT_EQ(bananas.amount(), 3000);
    EXPECT_EQ(vodka.amount(), 1700);
}

TEST_F(CargoTest, CompoundSubOperatorShouldWorkForExactAmountNullification)
{
    bananas -= 3500;
    vodka -= 2000;
    EXPECT_EQ(bananas.amount(), 0);
    EXPECT_EQ(vodka.amount(), 0);
}

TEST_F(CargoTest, CompoundSubstractOperatorShoulDoNothingIfAttemptToRemoveMoreCargoThanThereIs)
{
    bananas -= 5000;
    vodka -= 4000;
    EXPECT_EQ(bananas.amount(), 3500);
    EXPECT_EQ(vodka.amount(), 2000);
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

TEST_F(CargoTest, AlcoholConstructorShouldThrowInvalidArgumentIfPercentageGivenHigherThan96)
{
    EXPECT_THROW({ (Alcohol("Super Strong Alc",
                            1000,
                            50.0,
                            100.0)); },
                 std::invalid_argument);
}

TEST_F(CargoTest, AlcoholConstructorShouldNOTthrowIfGivenCorrectArguments)
{
    EXPECT_NO_THROW({ (Alcohol { "Super Mocny",
                                 2000,
                                 2.5,
                                 8.0 }); });
}

TEST_F(CargoTest, ForAlcoholPecentageShouldReturnPercentageAssignedDuringConstruction)
{
    EXPECT_EQ(vodka.percentage(), 40.0);
}

TEST_F(CargoTest, ForAlcoholPriceShouldReturnPriceCorrectedForAlcoholPercentage)
{
    double vodkas_alcohol_value = vodka.percentage() / Alcohol::max_alc_value * vodka.basePrice();

    EXPECT_DOUBLE_EQ(vodka.price(), vodkas_alcohol_value);
}

}   // namespace cargo::test
