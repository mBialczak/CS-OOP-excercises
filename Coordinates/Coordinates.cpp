#include "Coordinates.hpp"

#include <cmath>

namespace coords {

Coordinates::Coordinates(double positionX, double positionY)
    : x_(positionX)
    , y_(positionY)
{
}

double Coordinates::distance(const Coordinates& first, const Coordinates& second)
{
    double xDifference = second.x_ - first.x_;
    double yDifference = second.y_ - first.y_;

    return sqrt(pow(xDifference, 2) + pow(yDifference, 2));
}

}   // namespace coords
