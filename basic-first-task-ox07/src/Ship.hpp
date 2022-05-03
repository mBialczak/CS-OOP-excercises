#pragma once

#include <string>
class Ship
{
  public:
    Ship() = default;
    Ship(const std::string& id, const std::string& name);
    Ship(const std::string& id, const std::string& name, double speed);
    Ship(const std::string& id, const std::string& name, double speed, unsigned maxCrew);
    Ship(const std::string& id, const std::string& name, double speed, unsigned maxCrew, unsigned capacity);
    std::string id() const;
    std::string name() const;
    double speed() const;
    unsigned maxCrew() const;
    unsigned capacity() const;

  private:
    std::string id_;
    std::string name_;
    double speed_;
    unsigned maxCrew_;
    unsigned capacity_;
};
