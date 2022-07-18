#pragma once

#include "Fruit.hpp"

namespace cargo {

class DryFruit : public Fruit
{
  public:
    DryFruit(std::string name,
             int amountKg,
             double basePrice,
             double timeToSpoil);
    ~DryFruit() override = default;

    double price() const override;
    std::string name() const override;
    DryFruit& operator--() override;   // decrease time to spoil

  private:
    std::size_t counter_ = 1;
};
}   // namespace cargo
