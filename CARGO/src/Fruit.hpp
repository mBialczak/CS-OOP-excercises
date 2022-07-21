#pragma once

#include "Cargo.hpp"

namespace cargo {

class Fruit : public Cargo
{
  public:
    Fruit(std::string name,
          int amountKg,
          double basePrice,
          double timeToSpoil);
    virtual ~Fruit() = default;
    // getters
    std::string name() const override;
    std::size_t amount() const override;
    double price() const override;
    double basePrice() const override;
    double timeBeforeExpiry() const;
    // setters
    virtual Fruit& operator--();   // decrease time to spoil

  protected:
    double expiry_time_;
    double time_left_;
};
}   // namespace cargo
