/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#ifndef PREWORK_OBRAZ_HPP_
#define PREWORK_OBRAZ_HPP_

#include <iostream>
#include <string>
#include <vector>

namespace prework
{

struct Obraz
{
    Obraz(const std::string magic_number, const int width, const int high);//konstruktor
    //void add_pixel(const int pixel);
    Obraz(const std::string magic_number, const int width, const int high, const int skala);

    std::string magic_number() const;
    int width() const;
    int high() const;
    int skala() const;
    std::vector<std::vector<int>>& data();

private:
    std::string magic_number_;
    int width_;
    int high_;
    int skala_;
    std::vector<std::vector<int>> data_;
};


}  // namespace prework

#endif  // PREWORK_OBRAZ_HPP_
