/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include <iostream>
#include "run.hpp"
#include "FileManager.hpp"
#include "DummyData.hpp"

namespace prework
{

void run()
{
    std::string fileName;
    std::cout << "Please insert file name to process" << std::endl;
    std::cin >> fileName;
    auto manager = prework::FileManager();
    auto data = manager.loadData(fileName);

    std::cout << "Result will be saved to output.txt file" << std::endl;
    manager.saveData("output.txt", data);
}

}  // namespace prework
