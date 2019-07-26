/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include <iostream>
#include "run.hpp"
#include "FileManager.hpp"
#include "Obraz.hpp"
#include "Maski.hpp"
#include "FilterRunner.hpp"

namespace prework
{

// typ wyliczeniowy, moglby byc int, albo string, ale w tym wypadku zawezamy nieprawidlowe uzycia (bo np ktos moze podac 10, albo pusty string
// a takiego menu 10 czy pustego stringa nie bedzie, poza tym 10 to "magic number" ktora nie wiadomo co wskazuje xd
// enum lepsiejszy xD
enum class Menu { Glowne, Proste_filtry, Zaawansowane_filtry};

// filter runner jako global variable, po prostu zeby nie przekazywac caly czas przez referencje do roznych funkcji
FilterRunner filter_runner;

void print_menu(const Menu& typ_menu)
{
    if (typ_menu == Menu::Glowne)
    {
        std::cout<< "Witaj w glownym menu" << std::endl;
        std::cout<< "NAJLEPSZEGO PROGRAMU GRAFICZNEGO"<<std::endl<<std::endl;
        std::cout<< "Opcje:" << std::endl;
        std::cout<< "1 : WCZYTAJ OBRAZ " << std::endl;
        std::cout<< "2 : MENU PROSTYCH FILTROW " << std::endl;
        std::cout<< "3 : MENU TRUDNYCH FILTROW " << std::endl;
        std::cout<< "4 : ZAPISZ OBRAZ " << std::endl;
        std::cout<< "5 : WYSWIETL OBRAZ " << std::endl;
        std::cout<< "0 : WYJDZ Z PROGRAMU " << std::endl;
        std::cout<< "Co chcesz zrobic?" << std::endl;
    }
    else if (typ_menu == Menu::Proste_filtry)
    {
        std::cout<< "Witaj w menu prostych filtrow.." << std::endl;
        std::cout<< "Opcje:" << std::endl;
        std::cout<< "1. progowanie" << std::endl;
        std::cout<< "2. zmiana poziomow" << std::endl;
        std::cout<< "3. korekcja gamma " << std::endl;
        std::cout<< "4. konturowanie" << std::endl;
        std::cout<< "5. rozmycie poziome" << std::endl;
        std::cout<< "6. rozmycie pionowe" << std::endl;
        std::cout<< "7. histogram" << std::endl;
        std::cout<< "0. powrot do poprzedniego menu" << std::endl;
        std::cout<< "Co chcesz zrobic?" << std::endl;
    }
    else if (typ_menu == Menu::Zaawansowane_filtry)
    {
        std::cout<< "Witaj w menu zaawansowanych filtrow.." << std::endl;
        std::cout<< "Opcje:" << std::endl;
        std::cout<< "1 : maska_usredniajaca " << std::endl;
        std::cout<< "2 : maska_usredniajaca_ze_wzmocnieniem " << std::endl;
        std::cout<< "3 : gradient_Robertsa " << std::endl;
        std::cout<< "4 : maska_Prewitta " << std::endl;
        std::cout<< "5 : maska_Sobela " << std::endl;
        std::cout<< "6 : maska_wykrywajaca_narozniki " << std::endl;
        std::cout<< "7 : laplasjany " << std::endl;
        std::cout<< "0. powrot do poprzedniego menu" << std::endl;
        std::cout<< "Co chcesz zrobic?" << std::endl;
    }
    else
    {
        // nieznane menu left blank here
    }
}

void proste_filtry(Obraz& obraz)
{
    int wybor;
    do{
        print_menu(Menu::Proste_filtry);
        std::cin>>wybor;
        switch (wybor)
        {
            case 1:{
               obraz = filter_runner.progowanie(obraz);
               break;}
            case 2:{
               obraz = filter_runner.zmiana_poziomow(obraz);
               break;}
            case 3:{
                obraz = filter_runner.korekcja_gamma(obraz);
                break;}
            case 4:{
                obraz = filter_runner.konturowanie(obraz);
                break;}
            case 5:{
                obraz = filter_runner.rozmycie_poziome(obraz);
                break;}
            case 6:{
                obraz = filter_runner.rozmycie_pionowe(obraz);
                break;}
            case 7:{
                obraz = filter_runner.rozciaganie_histogramu(obraz);
                break;}
            case 0:{
                std::cout<< "Powracam do poprzedniego menu" << std::endl;
                break;}
            default:{
                std::cout << "Nieznana opcja, jeszcze raz" << std::endl;
                break;}
        }

    } while (wybor != 0);
}

void zaawansowane_filtry(Obraz& obraz)
{
    int wybor;
    do{
        print_menu(Menu::Zaawansowane_filtry);
        std::cin>>wybor;
        switch (wybor)
        {
            case 1:{
               obraz = filter_runner.splot("maska_usredniajaca", obraz);
               break;}
            case 2:{
               obraz = filter_runner.splot("maska_usredniajaca_ze_wzmocnieniem", obraz);
               break;}
            case 3:{
                obraz = filter_runner.splot("gradient_Robertsa", obraz);
                break;}
            case 4:{
                obraz = filter_runner.splot("maska_Prewitta", obraz);
                break;}
            case 5:{
                obraz = filter_runner.splot("maska_Sobela", obraz);
                break;}
            case 6:{
                obraz = filter_runner.splot("maska_wykrywajaca_narozniki", obraz);
                break;}
            case 7:{
                obraz = filter_runner.splot("laplasjany", obraz);
                break;}
            case 0:{
                std::cout<< "Powracam do poprzedniego menu" << std::endl;
                break;}
            default:{
                std::cout << "Nieznana opcja, jeszcze raz" << std::endl;
                break;}
       }

    } while (wybor != 0);
}

Obraz wczytaj_obraz(FileManager& manager)
{
    std::string fileName;
    std::cout<< "Podaj nazwe pliku .." << std::endl;
    std::cin>>fileName;
    return manager.loadData(fileName);
}

void run()
{
    Obraz obraz;
    FileManager manager;

    int wybor;
    do{
        print_menu(Menu::Glowne);
        std::cin>>wybor;
        switch (wybor)
        {
            case 1:{
                obraz = wczytaj_obraz(manager);
                break;}
            case 2:{
                proste_filtry(obraz);
                break;}
            case 3:{
                zaawansowane_filtry(obraz);
                break;}
            case 4:{
                manager.saveData(obraz);
                break;}
            case 5:{
                manager.wyswietl(obraz);
                break;}
            case 0: {
                std::cout<< "Koniec pracy" << std::endl;
                break;}
            default: {
                std::cout << "Nieznana opcja, jeszcze raz" << std::endl;
                break;}
        }
    } while (wybor != 0);

}

}  // namespace prework
