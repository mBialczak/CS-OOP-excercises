#include "DryFruit.hpp"

namespace cargo {

DryFruit::DryFruit(std::string name,
                   int amountKg,
                   double basePrice,
                   double timeToSpoil)
    : Fruit(name, amountKg, basePrice, timeToSpoil)
{ }

std::string DryFruit::name() const
{
    return "dried " + name_;
}

double DryFruit::price() const
{
    return 3 * Fruit::price();
}

DryFruit& DryFruit::operator--()
{
    if (counter_ == 10) {
        Fruit::operator--();
        counter_ = 1;
    }
    ++counter_;

    return *this;
}
}   // namespace cargo
