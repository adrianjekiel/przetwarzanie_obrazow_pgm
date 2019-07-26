/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#ifndef PREWORK_FILTERRUNNER_HPP_
#define PREWORK_FILTERRUNNER_HPP_

#include <iostream>
#include "Obraz.hpp"
#include "Filtry.hpp"

namespace prework
{

class FilterRunner{
public:
    Obraz progowanie(Obraz obraz);
    Obraz zmiana_poziomow(Obraz obraz);
    Obraz korekcja_gamma(Obraz obraz);
    Obraz konturowanie(Obraz obraz);
    Obraz rozmycie_pionowe(Obraz obraz);
    Obraz rozmycie_poziome(Obraz obraz);
    Obraz rozciaganie_histogramu(Obraz obraz);
    Obraz splot(const std::string& maska, Obraz obraz);

private:
    Filtry filtry;
};



}  // namespace prework

#endif  // PREWORK_FILTERRUNNER_HPP_
