#pragma once

#include <string>
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
    unsigned maxCrew() const;
    unsigned capacity() const;
    unsigned crew() const;
    // Setters
    void setName(const std::string& newName);
    Ship& operator+=(int crewToAdd);

  private:
    std::string id_;
    std::string name_;
    double speed_;
    unsigned maxCrew_;
    unsigned crew_;
    unsigned capacity_;
};
