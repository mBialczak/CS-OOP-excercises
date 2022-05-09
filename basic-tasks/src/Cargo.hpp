#pragma once

#include <string>

class Cargo
{
  public:
    Cargo(std::string name, int amount_kg);
    // getters
    std::string name() const;
    int amount() const;

  private:
    std::string name_;   // name of the cargo
    int amount_;   // amount in kg
};