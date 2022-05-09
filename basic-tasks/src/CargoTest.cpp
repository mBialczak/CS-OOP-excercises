#include "Cargo.hpp"

#include <gtest/gtest.h>

TEST(CargoTest, NameShouldReturnNameOfTheCargo)
{
    std::string cargo_name { "banana" };
    Cargo bananas { cargo_name };
    EXPECT_EQ(bananas.name(), cargo_name);
}