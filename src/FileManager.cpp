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
        while(input >> temp)
        {
            temp_vec.push_back(temp);
        }
        input.close();
    }
    return temp_vec;
}


void FileManager::saveData(const std::string& numer_zadania , const std::vector<std::string>& vec)
{
   std::ofstream output("Wyniki.txt", std::ios_base::out | std::ios_base::app);
   if(output.is_open())
   {
       output << numer_zadania << std::endl;
       for(auto & elem : vec)
       {
           output<< elem<< std::endl;
       }
       output.close();
   }
}

}  // prework
