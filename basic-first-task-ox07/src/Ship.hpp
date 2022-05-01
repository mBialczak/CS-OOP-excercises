#pragma once

#include <string>
class Ship
{
  public:
    Ship() = default;
    Ship(const std::string& id);
    std::string id() const;

  private:
    std::string id_;
};