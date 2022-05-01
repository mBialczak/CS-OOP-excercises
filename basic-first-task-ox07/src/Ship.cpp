#include "Ship.hpp"

Ship::Ship(const std::string& id)
    : id_(id)
{
}

std::string Ship::id() const
{
    return id_;
}