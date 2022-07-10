#pragma once

#include <string>

namespace ship {
class Ship
{
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
    // Setters
    void setName(const std::string& newName);
    Ship& operator+=(int crewToAdd);
    Ship& operator-=(int crewToSubstruct);

  private:
    std::string id_;
    std::string name_;
    double speed_;
    int maxCrew_;
    int crew_;
    unsigned capacity_;
};
}   //  namespace ship
