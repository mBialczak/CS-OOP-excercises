#include "Alcohol.hpp"

#include <stdexcept>

namespace cargo {

Alcohol::Alcohol(std::string name,
                 int litres,
                 double basePriceOf96,
                 double percentage)
    : Cargo(name, litres, basePriceOf96)
    , percentage_(percentage)
{
    if (percentage > max_alc_value) {
        throw std::invalid_argument("max alcohol value allowed is 96");
    }
}

std::string Alcohol::name() const
{
    return name_;
}

std::size_t Alcohol::amount() const
{
    return amount_;
}

double Alcohol::price() const
{
    return percentage_ / max_alc_value * basePrice_;
}

double Alcohol::basePrice() const
{
    return basePrice_;
}

double Alcohol::percentage() const
{
    return percentage_;
}
}   // namespace cargo
