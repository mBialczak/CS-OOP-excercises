#pragma once

#include <string>
class Ship
{
  public:
    Ship() = default;
    Ship(const std::string& id, const std::string& name);
    std::string id() const;
    std::string name() const;
    double speed() const;

  private:
    std::string id_;
    std::string name_;
    double speed_;
};