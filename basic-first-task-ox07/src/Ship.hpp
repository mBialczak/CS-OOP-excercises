#pragma once

#include <string>
class Ship
{
  public:
    Ship() = default;
    Ship(const std::string& id, const std::string& name);
    Ship(const std::string& id, const std::string& name, double speed);
    Ship(const std::string& id, const std::string& name, double speed, unsigned maxCrew);
    std::string id() const;
    std::string name() const;
    double speed() const;
    unsigned maxCrew() const;

  private:
    std::string id_;
    std::string name_;
    double speed_;
    unsigned maxCrew_;
};
