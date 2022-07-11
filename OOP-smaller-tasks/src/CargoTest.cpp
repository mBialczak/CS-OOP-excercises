#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"

#include <gtest/gtest.h>

namespace cargo::test {

class CargoTest : public testing::Test
{
  protected:
    Fruit bananas { "banana", 3'500, 1.05, 10.0 };
    Alcohol vodka { "vodka", 2'000, 20.0, 40.0 };
    Item commonItem { "ordinary classic guitar", 10, 1'000, Rarity::common };
    Item rareItem { "custom electric guitar", 2, 1'000, Rarity::rare };
    Item epicItem { "signed custom acoustic", 1, 1'000, Rarity::epic };
    Item legendaryItem { "Santana's guitar", 1, 1'000, Rarity::legendary };
};

TEST_F(CargoTest, NameShouldReturnNameOfTheCargo)
{
    EXPECT_EQ(bananas.name(), "banana");
    EXPECT_EQ(vodka.name(), "vodka");
    EXPECT_EQ(epicItem.name(), "signed custom acoustic");
}

TEST_F(CargoTest, AmountShouldReturnAmountOfCargo)
{
    EXPECT_EQ(bananas.amount(), 3500);
    EXPECT_EQ(vodka.amount(), 2000);
    EXPECT_EQ(commonItem.amount(), 10);
}

TEST_F(CargoTest, BasePriceShouldReturnBasePriceOfTheCargo)
{
    EXPECT_EQ(bananas.basePrice(), 1.05);
    EXPECT_EQ(vodka.basePrice(), 20.0);
    EXPECT_EQ(legendaryItem.basePrice(), 1000.0);
}

TEST_F(CargoTest, CompoundAddOperatorShouldAddAmountOfCargo)
{
    bananas += 400;
    vodka += 100;
    epicItem += 1;
    EXPECT_EQ(bananas.amount(), 3900);
    EXPECT_EQ(vodka.amount(), 2100);
    EXPECT_EQ(epicItem.amount(), 2);
}

TEST_F(CargoTest, CompoundSubstractOperatorShouldDecrementAmountOfCargo)
{
    bananas -= 500;
    vodka -= 300;
    commonItem -= 5;
    EXPECT_EQ(bananas.amount(), 3000);
    EXPECT_EQ(vodka.amount(), 1700);
    EXPECT_EQ(commonItem.amount(), 5);
}

TEST_F(CargoTest, CompoundSubOperatorShouldWorkForExactAmountNullification)
{
    bananas -= 3500;
    vodka -= 2000;
    rareItem -= 2;
    EXPECT_EQ(bananas.amount(), 0);
    EXPECT_EQ(vodka.amount(), 0);
    EXPECT_EQ(rareItem.amount(), 0);
}

TEST_F(CargoTest, CompoundSubstractOperatorShoulDoNothingIfAttemptToRemoveMoreCargoThanThereIs)
{
    bananas -= 5000;
    vodka -= 4000;
    legendaryItem -= 2;
    EXPECT_EQ(bananas.amount(), 3500);
    EXPECT_EQ(vodka.amount(), 2000);
    EXPECT_EQ(legendaryItem.amount(), 1);
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

TEST_F(CargoTest, ForItemPriceShouldBeDeterminedBasedOnItemsRarity)
{
    EXPECT_EQ(commonItem.price(), commonItem.basePrice() * 0.40);
    EXPECT_EQ(rareItem.price(), rareItem.basePrice() * 3.0);
    EXPECT_EQ(epicItem.price(), epicItem.basePrice() * 10.0);
    EXPECT_EQ(legendaryItem.price(), legendaryItem.basePrice() * 100.0);
}
}   // namespace cargo::test
