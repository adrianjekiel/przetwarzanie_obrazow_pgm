/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "FileManager.hpp"
#include "DummyData.hpp"
#include <fstream>
namespace prework
{

std::vector<std::string> FileManager::loadData(const std::string& fileName)
{
    std::vector<std::string> temp_vec;
    std::string temp;
    std::ifstream input(fileName);
    if(input.is_open())
    {
        while(std::getline(input, temp))
        {
            temp_vec.push_back(temp);
        }
        input.close();
    }
    return temp_vec;
}

bool FileManager::saveData(const std::string& fileName, const std::vector<DummyData>& dataVec)
{
    std::cout << fileName << std::endl;
    for(const auto& elem : dataVec)
    {
        std::cout << elem << std::endl;
    }
    return true;
}

}  // prework
