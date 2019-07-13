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
    Obraz zmiana_poziomow(const int& czern, const int& biel, Obraz obraz);
    Obraz kor_gamma(const double &wartosc, Obraz obraz);
    Obraz kontur(Obraz obraz);
    Obraz rozmycie_poz(Obraz obraz,const int r);
    Obraz rozmycie_pio(Obraz obraz, const int r);
    Obraz histogram(Obraz obraz);
    Obraz splot(const std::string& maska, Obraz obraz);
private:
    bool are_negative_coefficients(const std::vector<int>&);
    std::pair<std::vector<int>, std::vector<int>> min_max (const Obraz& obraz);
    void normalize_positive(Obraz& obraz, const std::vector<int>& wspolczynniki);
    void normalize_negative(Obraz& obraz, const std::vector<int>& wspolczynniki);
};



}  // namespace prework

#endif  // PREWORK_FILTRY_HPP_
