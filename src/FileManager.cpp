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

std::vector<slowo_klucz> FileManager::loadData2(const std::string& fileName)
{
    std::vector<slowo_klucz> slowa_klucze;
    std::string temp_string;
    int temp_int;
    std::ifstream input(fileName);
    if(input.is_open())
    {
        while((input >> temp_string) and(input >> temp_int))
        {
            slowa_klucze.push_back(slowo_klucz{temp_int, temp_string});
        }
        input.close();
    }
    return slowa_klucze;
}
std::vector<slowo_szyfrogram> FileManager::loadData3(const std::string& fileName)
{
    std::vector<slowo_szyfrogram> slowa_szyfrogramy;
    std::string temp_slowo;
    std::string temp_szyfrogram;
    std::ifstream input(fileName);
    if(input.is_open())
    {
        while((input >> temp_slowo) and(input >> temp_szyfrogram))
        {
            slowa_szyfrogramy.push_back(slowo_szyfrogram{temp_slowo, temp_szyfrogram});
        }
        input.close();
    }
    return slowa_szyfrogramy;
}

void FileManager::saveData(const std::string& numer_zadania ,const std::vector<std::string>& vec)
{
    std::ofstream output("wyniki.txt", std::ios_base::out | std::ios_base::app);
    if(output.is_open())
    {
        output << numer_zadania << std::endl;
        for(const auto& elem : vec)
        {
            output << elem << std::endl;
        }
        output.close();
    }
}

}  // prework
