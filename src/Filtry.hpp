/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#ifndef PREWORK_FILTRY_HPP_
#define PREWORK_FILTRY_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <Obraz.hpp>


namespace prework
{

class Filtry
{
public:
    Obraz progowanie(const int& procent, Obraz obraz_do_progowania);
    Obraz zmiana_poziomow(const int& czern, const int& biel, Obraz obraz_do_zmiany_poziomow);

};



}  // namespace prework

#endif  // PREWORK_FILTRY_HPP_
