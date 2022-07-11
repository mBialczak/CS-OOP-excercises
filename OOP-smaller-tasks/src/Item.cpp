#include "Item.hpp"

namespace cargo {
namespace {
    constexpr double common_val_factor = 0.4;
    constexpr double rare_val_factor = 3.0;
    constexpr double epic_val_factor = 10.0;
    constexpr double legendary_val_factor = 100.0;
}   // namespace

Item::Item(std::string name,
           int pieces,
           double topPrice,
           Rarity rarity)
    : Cargo(name, pieces, topPrice)
    , rarity_(rarity)
{
    switch (rarity_) {
        case Rarity::common:
            real_value_ = basePrice_ * common_val_factor;
            break;
        case Rarity::rare:
            real_value_ = basePrice_ * rare_val_factor;
            break;
        case Rarity::epic:
            real_value_ = basePrice_ * epic_val_factor;
            break;
        case Rarity::legendary:
            real_value_ = basePrice_ * legendary_val_factor;
            break;
        default:
            real_value_ = basePrice_;
    }
}

std::string Item::name() const
{
    return name_;
}

std::size_t Item::amount() const
{
    return amount_;
}

double Item::price() const
{
    return real_value_;
}

double Item::basePrice() const
{
    return basePrice_;
}
}   // namespace cargo
