/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include <iostream>
#include "run.hpp"
#include "FileManager.hpp"
#include "DummyData.hpp"
#include "Obrazy.hpp"

namespace prework
{

void run()
{
    std::string fileName;
    std::cout << "Please insert file name to process" << std::endl;
    std::cin >> fileName;
    auto manager = prework::FileManager();
    auto data = manager.loadData(fileName);
    auto obrazy = prework::Obrazy(data);
    obrazy.zad1();
    obrazy.zad2();
    obrazy.zad3();
    obrazy.zad4();

    std::cout << "Result will be saved to output.txt file" << std::endl;
    //manager.saveData("output.txt", data);
}

}  // namespace prework
