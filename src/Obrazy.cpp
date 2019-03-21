/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "FileManager.hpp"
#include "DummyData.hpp"
#include <fstream>
#include <sstream>
namespace prework
{

std::vector<std::vector<int>> FileManager::loadData(const std::string& fileName)
{
    std::string line;
    std::vector<std::vector<int>> temp;

    std::ifstream input(fileName);
    if(input.is_open())
    {
          while(std::getline(input,line))//idzie po enterach
          {
              std::vector<int> tymczasowy;//wiersz podzielny na liczby
              std::stringstream tline{line};//konwerujemy line na stream
              for(int i=0; i<320; i++)
              {
                  int x;
                  tline >> x;
                  tymczasowy.push_back(x);
              }
              temp.push_back(tymczasowy);
          }
    }
    return temp;
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
