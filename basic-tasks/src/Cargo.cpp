#include "Cargo.hpp"

Cargo::Cargo(std::string name)
    : name_(name)
{ }

std::string Cargo::name() const
{
    return name_;
}