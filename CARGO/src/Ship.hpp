#pragma once

#include "Cargo.hpp"

#include <memory>
#include <string>
#include <vector>

namespace ship {

class Ship
{
    using CargoHoldContainer = std::vector<std::shared_ptr<cargo::Cargo>>;

  public:
    // Constructors
    Ship() = default;
    Ship(const std::string& id, const std::string& name);
    Ship(const std::string& id, const std::string& name, double speed);
    Ship(const std::string& id, const std::string& name, double speed, unsigned maxCrew);
    Ship(const std::string& id, double speed, unsigned maxCrew);
    Ship(const std::string& id, const std::string& name, double speed, unsigned maxCrew, unsigned capacity);
    // Getters
    std::string id() const;
    std::string name() const;
    double speed() const;
    int maxCrew() const;
    unsigned capacity() const;
    int crew() const;
    const CargoHoldContainer& cargoHold() const;

    // Setters
    void setName(const std::string& newName);
    // Functionality
    void load(std::shared_ptr<cargo::Cargo> cargo);
    void unload(const cargo::Cargo* const cargo);
    Ship& operator+=(int crewToAdd);
    Ship& operator-=(int crewToSubstruct);

  private:
    std::string id_;
    std::string name_;
    double speed_;
    int maxCrew_;
    int crew_;
    unsigned capacity_;
    CargoHoldContainer cargo_hold_;
};
}   //  namespace ship
