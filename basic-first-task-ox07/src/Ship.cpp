#include "Ship.hpp"

Ship::Ship(const std::string& id,
           const std::string& name,
           double speed,
           unsigned maxCrew,
           unsigned capacity)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
{ }

Ship::Ship(const std::string& id,
           const std::string& name,
           double speed,
           unsigned maxCrew)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
{ }

Ship::Ship(const std::string& id,
           const std::string& name,
           double speed)
    : id_(id)
    , name_(name)
    , speed_(speed)
{
}

Ship::Ship(const std::string& id, double speed, unsigned maxCrew)
    : Ship(id, "", speed, maxCrew, 0)
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

unsigned Ship::capacity() const
{
    return capacity_;
}
