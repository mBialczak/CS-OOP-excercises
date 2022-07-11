#pragma once

#include "Cargo.hpp"
namespace cargo {

enum class Rarity
{
    common,
    rare,
    epic,
    legendary
};

class Item : public Cargo
{
  public:
    Item(std::string name,
         int pieces,
         double topPrice,
         Rarity rarity);
    virtual ~Item() = default;
    // getters
    std::string name() const override;
    std::size_t amount() const override;
    double price() const override;
    double basePrice() const override;

  protected:
    Rarity rarity_;
    double real_value_;
};
}   // namespace cargo
