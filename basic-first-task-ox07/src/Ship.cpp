#include "Ship.hpp"

Ship::Ship(const std::string& id,
           const std::string& name,
           double speed)
    : id_(id)
    , name_(name)
    , speed_(speed)
{
}

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

double Ship::speed() const
{
    return speed_;
}

unsigned Ship::maxCrew() const
{
    return maxCrew_;
}
