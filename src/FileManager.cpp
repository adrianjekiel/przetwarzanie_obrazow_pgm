/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "FileManager.hpp"
#include <fstream>

namespace prework
{

std::vector<int> FileManager::loadData(const std::string& fileName) //file name nazwa istniejocego pliku
{
    std::vector<int> int_vec;
    std::ifstream input(fileName);
    if(input.is_open())
    {
        int temp;
        while(input >> temp)
        {
            int_vec.push_back(temp);
        }
        input.close();
    }
    return int_vec;
}

bool FileManager::saveData(const std::string& fileName,const std::vector<int>& string_vec)
{
    return true;
}

}  // prework
