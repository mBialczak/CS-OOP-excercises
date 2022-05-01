#pragma once

#include <string>
class Ship
{
  public:
    Ship() = default;
    Ship(const std::string& id);
    std::string id() const;
    std::string name() const;

  private:
    std::string id_;
    std::string name_;
};