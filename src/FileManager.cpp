/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "FileManager.hpp"
#include "DummyData.hpp"
#include <fstream>

namespace prework
{

std::vector<std::string> FileManager::loadData(const std::string& fileName) //file name nazwa istniejocego pliku
{
    std::vector<std::string> string_vec;
    std::string temp;
    std::ifstream input(fileName);
    if(input.is_open())
    {
        std::cout<<"could be opened"<<std::endl;
        while( std::getline(input, temp))
        {
           string_vec.push_back(temp);
        }
        input.close();
    }

    std::cout << fileName << std::endl;
    return string_vec;
}

bool FileManager::saveData(const std::string& fileName,const std::vector<std::string>& string_vec)
{
    std::cout << fileName << std::endl;
    std::ofstream output(fileName);
    if(output.is_open())
    {
        std::cout<<"could be opened"<<std::endl;
        for(const std::string& elem : string_vec)
        {
            output << elem << std::endl;
            if(not output.good())
            {
                std::cout << "we close file, because problem has occured" <<std::endl;
                break;
            }
        }
        output.close();
    }

    return true;
}

}  // prework
