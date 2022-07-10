#include "Cargo.hpp"

namespace cargo {

Cargo::Cargo(std::string name, int amountKg, double basePrice)
    : name_(name)
    , amount_(amountKg)
    , basePrice_(basePrice)
{ }

Cargo& Cargo::operator+=(int amountKg)
{
    amount_ += amountKg;
    return *this;
}

Cargo& Cargo::operator-=(int amountKg)
{
    int new_amount = amount_ - amountKg;
    if (!(new_amount < 0)) {
        amount_ = new_amount;
    }

    return *this;
}
}   // namespace cargo
