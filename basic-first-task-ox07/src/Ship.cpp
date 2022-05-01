#include "Ship.hpp"

Ship::Ship(const std::string& id, const std::string& name)
    : id_(id)
    , name_(name)
{
}

std::string Ship::id() const
{
    return id_;
}

std::string Ship::name() const
{
    return name_;
}