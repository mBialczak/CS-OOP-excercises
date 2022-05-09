#pragma once

#include <string>

class Cargo
{
  public:
    Cargo(std::string name);
    std::string name() const;

  private:
    std::string name_;
};