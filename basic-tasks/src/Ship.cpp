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
    : Ship(id, name, speed, maxCrew, 0)
{ }

Ship::Ship(const std::string& id,
           const std::string& name,
           double speed)
    : Ship(id, name, speed, 0, 0)
{
}

Ship::Ship(const std::string& id, double speed, unsigned maxCrew)
    : Ship(id, "", speed, maxCrew, 0)
{
}

Ship::Ship(const std::string& id, const std::string& name)
    : Ship(id, name, 0.0, 0, 0)
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

unsigned Ship::crew() const
{
    return crew_;
}

void Ship::setName(const std::string& newName)
{
    name_ = newName;
}

Ship& Ship::operator+=(int crewToAdd)
{
    unsigned new_crew_number = crew_ + crewToAdd;
    if (new_crew_number <= maxCrew_) {
        crew_ = new_crew_number;
    }

    return *this;
}
