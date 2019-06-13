/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include <iostream>
#include "run.hpp"
#include "FileManager.hpp"
#include "Obraz.hpp"
#include "Filtry.hpp"

namespace prework
{

void run()
{
    // w celach testowych zahardkowana nazwa pliku
    std::string fileName{"balloons.ascii.pgm"};

    // stworz klase odpowiedzialna za wczytywanie, zapisywanie i wyswietlanie pliku obrazka
    auto manager = prework::FileManager();

    // stworz klase odpowiedzialna za nakladanie filtrow na obrazek
    auto filtry = prework::Filtry();

    // wczytaj obrazek
    auto obraz = manager.loadData(fileName);

    // wyswietl obrazek za pomoca programu display
    manager.wyswietl(obraz);

    // naloz filtr progowanie
    auto obraz_po_progowaniu = filtry.progowanie(40, obraz);

    // zapisz obraz po progowaniu
    manager.saveData(obraz_po_progowaniu);

    // wyswietl obraz po progowaniu
    manager.wyswietl(obraz_po_progowaniu);


    // naloz filtr zmiana poziomow
    auto obraz_po_zmianie_poziomow = filtry.zmiana_poziomow(10, 70, obraz);

    // zapisz obraz po zmianie poziomow
    manager.saveData(obraz_po_zmianie_poziomow);

    // wyswietl obraz po zmianie poziomow
    manager.wyswietl(obraz_po_zmianie_poziomow);

    // naloz filtr korekcja gamma
    auto obraz_po_korekcji_gamma = filtry.kor_gamma(1.5, obraz);

    //zapisz obraz po korekcji gamma
    manager.saveData(obraz_po_korekcji_gamma);

    //wyswietl obraz po korekcji gamma
    manager.wyswietl(obraz_po_korekcji_gamma);

    // naloz filtr konturowanie
    auto obraz_po_konturowaniu = filtry.kontur(obraz);

    //zapisz obraz po konturowaniu
    manager.saveData(obraz_po_konturowaniu);

    //wyswietl obraz po konturowaniu
    manager.wyswietl(obraz_po_konturowaniu);

}

}  // namespace prework
