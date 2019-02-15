/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "FileManager.hpp"
#include "DummyData.hpp"
#include <fstream>

namespace prework
{

std::vector<DummyData> FileManager::loadData(std::vector<std::string>& string_vec)
{
    std::vector<std::string>> string_vec;
    std::string temp;
    std::ifstream input(fileName);
    if(input.is_open())
    {
        std::cout<<"could be opened";<<std::endl;
        while( std::getline(input, temp))
        {
           string_vec.push_back(temp);
        }
        input.close();
    }

    std::cout << fileName << std::endl;
    return string_vec;
}

bool FileManager::saveData(const std::string& fileName,std::vector<std::string>& string_vec)
{
    std::cout << fileName << std::endl;
    std::fstream inOut(fileName);
    if(inOut.is_open())
    {
        std::cout<<"could be opened";<<std::endl;
        for(const DummyData& elem : string_vec)
        {
            //inOut << elem << std::endl; nwm takie cos?
            std::cout << elem << std::endl;
        }
    }
    if(inOut.is_good())
    {
        std::cout<<" File is good";
    }

    return true;
}

}  // prework
