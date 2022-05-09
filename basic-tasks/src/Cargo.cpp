#include "Cargo.hpp"

Cargo::Cargo(std::string name, int amount_kg)
    : name_(name)
    , amount_(amount_kg)
{ }

std::string Cargo::name() const
{
    return name_;
}

int Cargo::amount() const
{
    return amount_;
}