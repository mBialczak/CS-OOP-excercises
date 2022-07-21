#include "Coordinates.hpp"

#include "gtest/gtest.h"

namespace coords::ut {

TEST(CoordinatesTest, shouldBeConstructibleFromTwoPositionArguments)
{
    Coordinates position { 0.5, 2.0 };
}

TEST(CoordinatesTest, shouldBeComparableWithEqualityOperator)
{
    Coordinates position1 { 0.5, 2.0 };
    Coordinates position2 { position1 };

    EXPECT_EQ(position1, position2);
}

TEST(CoordinatesTest, shouldBeComparableWithInequalityOperator)
{
    Coordinates position1 { 0.5, 2.0 };
    Coordinates position2 { 3.0, 4.0 };

    bool isNotEqual = position1 != position2;
    EXPECT_TRUE(isNotEqual);
}

TEST(CoordinatesTest, staticDistanceShouldReturnCartesianDistanceBetweenTwoPositions)
{
    Coordinates position1 { 2.0, 2.0 };
    Coordinates position2 { 3.0, 4.0 };

    double expectedDistance = 2.236067;
    double calculatedDistance = Coordinates::distance(position1, position2);

    EXPECT_NEAR(expectedDistance, calculatedDistance, 0.000001);
}

}   // namespace coords::ut