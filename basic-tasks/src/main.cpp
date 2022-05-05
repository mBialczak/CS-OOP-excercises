#include "Ship.hpp"

#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[])
{
    Ship empty_ship;
    std::cout << "Empty ship ID:\t" << empty_ship.id() << "\n"
              << "Empty ship name:\t" << empty_ship.name() << "\n"
              << "Empty ship speed:\t" << empty_ship.speed() << "\n"
              << "Empty ship maxCrew:\t" << empty_ship.maxCrew() << "\n"
              << "Empty ship capacity:\t" << empty_ship.capacity() << std::endl;

    return 0;
}
