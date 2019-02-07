/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "FileManager.hpp"
#include "DummyData.hpp"

namespace prework
{

std::vector<DummyData> FileManager::loadData(const std::string& fileName)
{
    std::cout << fileName << std::endl;
    return {};
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
