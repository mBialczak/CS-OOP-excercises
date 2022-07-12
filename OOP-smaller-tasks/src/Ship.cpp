#include "Ship.hpp"

namespace ship {

Ship::Ship(const std::string& id,
           const std::string& name,
           double speed,
           unsigned maxCrew,
           unsigned capacity)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , crew_(0)
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

int Ship::maxCrew() const
{
    return maxCrew_;
}

unsigned Ship::capacity() const
{
    return capacity_;
}

int Ship::crew() const
{
    return crew_;
}

const Ship::CargoHoldContainer& Ship::cargoHold() const
{
    return cargo_hold_;
}

void Ship::setName(const std::string& newName)
{
    name_ = newName;
}

Ship& Ship::operator+=(int crewToAdd)
{
    int new_crew_number = crew_ + crewToAdd;
    if (new_crew_number <= maxCrew_) {
        crew_ = new_crew_number;
    }

    return *this;
}

void Ship::load(std::shared_ptr<::cargo::Cargo> cargo)
{
    cargo_hold_.emplace_back(cargo);
}

void Ship::unload(const cargo::Cargo* const cargo)
{
    std::erase_if(cargo_hold_,
                  [cargo](const auto& cargoSptr) {
                      return cargoSptr.get() == cargo;
                  });
}

Ship& Ship::operator-=(int crewToSubstruct)
{
    int new_crew_number = crew_ - crewToSubstruct;
    if (new_crew_number >= 0) {
        crew_ = new_crew_number;
    }

    return *this;
}
}   // namespace ship
