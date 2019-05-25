/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "FileManager.hpp"
#include "Obraz.hpp"

namespace prework
{

Obraz FileManager::loadData(const std::string& fileName)
{
    std::string magic_number;
    std::string temp_com;
    int width;
    int high;
    int pixel;
    int skala;
    std::ifstream input(fileName);
    if(input.is_open())
    {
        input >> magic_number;
        if(magic_number == "P1")
        {
            input >> temp_com;
            if(temp_com[0] != '#')
            {
                std::stringstream temp_stream(temp_com);
                temp_stream >> width >> high;
            }
            else
            {
                input >> width >> high;
            }
            Obraz load(magic_number, width, high);
            for(int i = 0 ; i<width; i++)
            {
                std::vector<int> wiersz;
                for(int k =0; k<high ;k++)
                {
                    input >> pixel;
                    wiersz.push_back(pixel);
                }
                load.data().push_back(wiersz);
            }
            return load;
        }
        else if(magic_number == "P2")
        {
            input >> temp_com;
            if(temp_com[0] != '#')
            {
                std::stringstream temp_stream(temp_com);
                temp_stream >> width >> high;
            }
            else
            {
                input >> width >> high >> skala;
            }
            Obraz load(magic_number, width, high, skala);
            for(int i = 0 ; i<width; i++)
            {
                std::vector<int> wiersz;
                for(int k =0; k<high ;k++)
                {
                    input >> pixel;
                    wiersz.push_back(pixel);
                }
                load.data().push_back(wiersz);
            }
            return load;
        }
    input.close();
    }
    std::cout << fileName << std::endl;
    return {};
}

//bool FileManager::saveData(const std::string& fileName, const std::vector<DummyData>& dataVec)
//{
//    std::cout << fileName << std::endl;
//    for(const auto& elem : dataVec)
//    {
//        std::cout << elem << std::endl;
//    }
//    return true;
//}

}  // prework
