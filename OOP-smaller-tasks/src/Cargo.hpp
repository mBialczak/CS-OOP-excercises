#pragma once

#include <string>

namespace cargo{
class Cargo
{
  public:
    Cargo(std::string name, int amountKg, double basePrice);
    virtual ~Cargo() = default;
    // getters
    virtual std::string name() const = 0;
    virtual std::size_t amount() const = 0;
    virtual double price() const = 0;
    virtual double basePrice() const = 0;
    // setters
    virtual Cargo& operator+=(int amountKg);   // add cargo amount
    virtual Cargo& operator-=(int amountKg);   // decrement cargo amount

  protected:
    std::string name_;   // name of the cargo
    int amount_;   // amount in kg
    double basePrice_;
};
}   // namespace cargo
