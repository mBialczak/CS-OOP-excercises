#include "Cargo.hpp"

Cargo::Cargo(std::string name, int amountKg, double basePrice)
    : name_(name)
    , amount_(amountKg)
    , basePrice_(basePrice)
{ }

std::string Cargo::name() const
{
    return name_;
}

int Cargo::amount() const
{
    return amount_;
}

double Cargo::basePrice() const
{
    return basePrice_;
}