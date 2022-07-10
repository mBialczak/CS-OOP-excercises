#pragma once

#include "Cargo.hpp"

namespace cargo {

class Alcohol : public Cargo
{
  public:
    Alcohol(std::string name,
            int litres,
            double basePriceOf96,
            double percentage);
    virtual ~Alcohol() = default;
    // getters
    std::string name() const override;
    std::size_t amount() const override;
    double price() const override;
    double basePrice() const override;
    double percentage() const;
    // setters

    static constexpr double max_alc_value = 96.0;

  protected:
    double percentage_;
};
}   // namespace cargo
