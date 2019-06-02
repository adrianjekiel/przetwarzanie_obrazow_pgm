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
    std::string fileName;
    std::cout << "Please insert file name to process" << std::endl;
    std::cin >> fileName;
    auto manager = prework::FileManager();
    auto obraz = manager.loadData(fileName);
    manager.wyswietl(fileName);
    auto filtry = prework::Filtry();
    auto obraz_po_progowaniu = filtry.progowanie(40, obraz);
    std::cout << "Result will be saved to output.txt file" << std::endl;
    manager.saveData("obraz_po_progowaniu.pgm", obraz_po_progowaniu);
}

}  // namespace prework
