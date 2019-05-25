/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "Obraz.hpp"

namespace prework
{

Obraz::Obraz(const std::string magic_number, const int width, const int high):
    magic_number_(magic_number), //nabijanie
    width_(width),
    high_(high)
{
    std::cout << "C-tor" << std::endl;
}

Obraz::Obraz(const std::string magic_number, const int width, const int high, const int skala):
    magic_number_(magic_number), //nabijanie
    width_(width),
    high_(high),
    skala_(skala)
{
    std::cout << "C-tor" << std::endl;
}

std::string Obraz::magic_number() const
{
    return magic_number_;
}

int Obraz::width() const
{
    return width_;
}

int Obraz::high() const
{
    return high_;
}

int Obraz::skala() const
{
    return skala_;
}

std::vector<std::vector<int>>& Obraz::data()
{
   return data_;
}
}  // namespace prework
