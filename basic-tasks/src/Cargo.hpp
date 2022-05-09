#pragma once

#include <string>

class Cargo
{
  public:
    Cargo(std::string name, int amountKg, double basePrice);
    // getters
    std::string name() const;
    int amount() const;
    double basePrice() const;
    // setters
    Cargo& operator+=(int amountKg);

  private:
    std::string name_;   // name of the cargo
    int amount_;   // amount in kg
    double basePrice_;
};