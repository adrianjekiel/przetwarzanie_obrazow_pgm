/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "FileManager.hpp"
#include "Obraz.hpp"
#include <stdlib.h>

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
                std::cout << "dupa"<<std::endl;
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
                std::cout << "dupa"<<std::endl;
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
            input.close();
            std::cout << fileName <<magic_number<<" "<<width<<" "<<high<<" "<<skala<< std::endl;
            return load;
        }

    }

    return {};
}
void FileManager::wyswietl(const std::string &fileName)
{
    std::string polecenie;
    polecenie = std::string("display ") + fileName + "&";
    system(polecenie.c_str());

}

void FileManager::saveData(const std::string& fileName, const Obraz& obraz_)
{
   std::ofstream output(fileName);
   if(output.is_open())
   {

       output << obraz_.magic_number() << std::endl;
       output << obraz_.width() << " " << obraz_.high() << std::endl;
       std::cout << obraz_.magic_number() << std::endl;
       std::cout << obraz_.width() << " " << obraz_.high() << std::endl;
       if(obraz_.magic_number() == "P2")
       {
           output << obraz_.skala() << std::endl;
           std::cout << obraz_.skala() << std::endl;
       }
       for(const auto& wiersz : obraz_.data())
       {
           for(const auto& piksel : wiersz)
           {
               output << piksel << " ";
               std::cout << piksel << " ";
           }
           output << std::endl;
       }
    output.close();
   }

}

}  // prework
