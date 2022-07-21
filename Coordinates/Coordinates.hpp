#pragma once

namespace coords {

struct Coordinates
{
    Coordinates(double positionX, double positionY);
    static double distance(const Coordinates& first, const Coordinates& second);
    bool operator==(const Coordinates& otherPosition) const = default;

    double x_;
    double y_;
};

}   // namespace coords
