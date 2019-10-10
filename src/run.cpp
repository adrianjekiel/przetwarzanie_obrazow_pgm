/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include <iostream>
#include "run.hpp"
#include "FileManager.hpp"
#include "Liczby.hpp"

namespace prework
{

void run()
{
    std::string fileName{"liczby.txt"};
//    std::cout << "Please insert file name to process" << std::endl;
//    std::cin >> fileName;
    auto manager = prework::FileManager();
    auto data = manager.loadData(fileName);
    auto liczby = Liczby(data);
    std::string wynik_zad1 = liczby.zad1();
    std::string wynik_zad2 = liczby.zad2();
    std::string wynik_zad3 = liczby.zad3();
    std::vector<std::string> wyniki {wynik_zad1, wynik_zad2,wynik_zad3};

    std::cout << "Result will be saved to wyniki.txt file" << std::endl;
    manager.saveData("wyniki.txt", wyniki);
}

}  // namespace prework
