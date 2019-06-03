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
    Obraz(); // konstruktor bezparametryczny
    //void add_pixel(const int pixel);
    Obraz(const std::string magic_number, const int width, const int high, const int skala);//konstruktor

    // ponizsze funkcje sa getterami, tzn pozwalaja sie dostac do prywatnych memberow klasy "z zewnatrz", funkcje zwracaja odpowiednich memberow
    std::string magic_number() const;
    int width() const;
    int high() const;
    int skala() const;
    std::string fileName() const;
    std::vector<std::vector<int>>& data();
    std::vector<std::vector<int>> data() const;

    // setter do ustawiania nazwy pliku obrazka
    void set_fileName(const std::string& fileName);

private:
    // ponizej znajudja sie membery klasy opisujace mozliwe parametry obrazka
    std::string magic_number_; // numer magiczny, P1 (bit map) lub P2 (grey map) lub P3 (color map)
    std::string fileName_; // nazwa pliku ktory byl odczytany, lub nadany jako nowy do zapisu
    int width_; // szerokosc
    int high_; // wysokosc
    int skala_; // maxymalny stopien szarosci, przerwaznie 255
    std::vector<std::vector<int>> data_; // zmienna przechowujaca wartosci nasycenia kolorem poszczegolnych pixeli
};


}  // namespace prework

#endif  // PREWORK_OBRAZ_HPP_
