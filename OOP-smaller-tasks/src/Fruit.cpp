#include "Fruit.hpp"

namespace cargo {

Fruit::Fruit(std::string name,
             int amountKg,
             double basePrice,
             double timeToSpoil)
    : Cargo(name, amountKg, basePrice)
    , expiry_time_(timeToSpoil)
    , time_left_(timeToSpoil)
{ }

std::string Fruit::name() const
{
    return name_;
}

std::size_t Fruit::amount() const
{
    return amount_;
}

double Fruit::price() const
{
    double worth_factor = time_left_ / expiry_time_;
    return worth_factor * basePrice_;
}

double Fruit::basePrice() const
{
    return basePrice_;
}

Fruit& Fruit::operator--()
{
    time_left_ -= 1.0;
    return *this;
}

double Fruit::timeBeforeExpiry() const
{
    return time_left_;
}

}   // namespace cargo
