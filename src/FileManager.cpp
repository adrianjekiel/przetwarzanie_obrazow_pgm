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

void FileManager::saveData(const std::string& fileName,const std::vector<std::string>& string_vec)
{
    std::ofstream output(fileName); //ofstream o - output , zapisywanie. ifstream i - input odczytywanie
    if(output.is_open())
    {
        for(auto s:string_vec)
        {
            output << s <<std::endl;
        }
        output.close();
    }

}

}  // prework
