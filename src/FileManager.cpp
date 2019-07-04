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
    std::string magic_number, temp_com;
    int width, high, pixel, skala;
    std::ifstream input(fileName);
    if(input.is_open())
    {
        input >> magic_number;

        while(temp_com.empty()) // jesli jakims cudem wczytalismy pusta linie to wczytujemy dopoki cos nie bedzie w temp_com
        {
            std::getline(input, temp_com); //uzywamy do tego getline, operator >> przekazuje tylko do spacji, nie cala linie, niestety :< to byl blad nasz
        }

        if(temp_com[0] != '#')
        {
            std::stringstream temp_stream(temp_com);
            temp_stream >> width >> high;
            if (magic_number != "P1") // jesli jest P2 lub P3 to jeszcze wczytaj skale
                temp_stream >> skala;
        }
        else
        {
            input >> width >> high;
            if (magic_number != "P1") // jesli jest P2 lub P3 to jeszcze wczytaj skale
                input >> skala;
        }

        Obraz obrazek(magic_number, width, high, skala); //inicjujemy obrazek, w sumie czy skala istnieje czy nie to bez roznicy, dla P1 bedzie skala = 0, (domyslnie int jest inicjalizowany zerem)
        if(obrazek.magic_number()=="P3")
        {
            for(int i = 0 ; i<high; i++)
            {
                std::vector<std::vector<int>> wiersz;
                for(int k =0; k<width ;k++)
                {
                    int r,g,b;
                    input >> r >> g >> b;
                    wiersz.push_back({r,g,b});
                }
                obrazek.data().push_back(wiersz);
            }
        }
        else
        {
            for(int i = 0 ; i<high; i++)
            {
                std::vector<std::vector<int>> wiersz;
                for(int k =0; k<width ;k++)
                {
                    input >> pixel;
                    wiersz.push_back({pixel});
                }
                obrazek.data().push_back(wiersz);
            }
        }

        obrazek.set_fileName(fileName); // ustaw nazwe wczytanego pliku
        input.close();
        return obrazek;
    }
    return {};
}

void FileManager::wyswietl(const Obraz& obraz)
{
    std::string polecenie;
    polecenie = std::string("display ") + obraz.fileName() + "&";
    system(polecenie.c_str());

}

// funkcja zapisuje obraz do pliku, fileName jest nabijane podczas stosowania filtru
// budujemy obrazek w ten sam sposob jak wczytywalismy czyli:
// numer_magiczny
// szerokosc wysokosc
// skala
// wartosci zabarwienia pikseli
void FileManager::saveData(const Obraz& obraz)
{
   std::ofstream output(obraz.fileName());
   if(output.is_open())
   {
       output << obraz.magic_number() << std::endl;
       output << obraz.width() << " " << obraz.high() << std::endl;
       if(obraz.magic_number() != "P1") //jesli P2 lub P3 to jeszcze zapisz skale
       {
           output << obraz.skala() << std::endl;
       }
       for(const auto& wiersz : obraz.data())
       {
           for(const auto& piksel : wiersz)
           {
               for(const auto& skladowa : piksel)
               {
                  output << skladowa << " ";
               }
           }
           output << std::endl;
       }
       output.close();
   }
}

}  // prework
