/**
 * Made by Adrian Jekiel
 * Year 2019
 **/
#include <iostream>
#include "Binarne.hpp"
#include <fstream>
#include <algorithm>
namespace prework
{

void Binarne::zad1()
{
    std::vector<std::string> dane = menago_.loadData("liczby.txt");

    int slowa_zerami = 0;
    for(const auto& elem : dane)
    {
        int zero = 0;
        int jeden = 0;
        for(const auto& znak : elem)// petla po obiektach w stringu (znakach)
        {
            if(znak == '0')
                zero++;
            else
                jeden++;
        }
        if(zero>jeden)
        {
            slowa_zerami++;
        }
    }
    std::vector<std::string> to_save;
    std::string wynik = "ilosc linijek z wieksza iloscia zer = " + std::to_string(slowa_zerami);
    to_save.push_back(wynik);
    menago_.saveData("zadanie pierwsze" , to_save );
    //std::cout<<"ilosc linijek z wieksza iloscia zer = "<<slowa_zerami<<std::endl;
}
void Binarne::zad2()
{
    std::vector<std::string> dane = menago_.loadData("liczby.txt");
    int mod2 = 0;
    int mod8 = 0;
    for(const std::string& elem : dane)
    {
        auto iterator = elem.rbegin();
        if(*iterator == '0')
        {
            mod2++;
            iterator++;
            if(*iterator == '0')
            {
                iterator++;
                if(*iterator == '0')
                {
                    mod8++;
                }
            }
        }

    }
    std::vector<std::string> to_save;
    std::string wynik1 = "podzielne przez 2: " + std::to_string(mod2);
    std::string wynik2 = "podzielne przez 8: " + std::to_string(mod8);
    to_save.push_back(wynik1);
    to_save.push_back(wynik2);
    menago_.saveData("zadanie drugie " , to_save );
    //std::cout<<"podzielne przez 2: "<<mod2<<std::endl;
    //std::cout<<"podzielne przez 8: "<<mod8<<std::endl;
}
void Binarne::zad3()
{
    std::vector<std::string> to_save;
    std::vector<std::string> dane = menago_.loadData("liczby.txt");
    std::vector<std::string> najdluzsze;// robie vektor najduzszych
    std::vector<std::string> najkrotsze;//robie vektor najktorszych
    int najdluzszy = dane[0].size();// pierwszy wyraz jest najktortszym oraz najdluszum
    int najkrotszy = dane[0].size();
    for(const std::string& elem : dane)//petla po stringach w szukaniu najdluszego i najkrtesazefgo
    {
        if( elem.size() > najdluzszy)
        {
            najdluzszy = elem.size();
        }
        else if(elem.size() < najkrotszy)
        {
            najkrotszy = elem.size();
        }
    }
    for(const std::string& elem : dane)
    {
        if( elem.size() == najdluzszy)
        {
            najdluzsze.push_back(elem);
        }
        else if( elem.size() == najkrotszy)
        {
            najkrotsze.push_back(elem);
        }
    }
    sort(najdluzsze.begin(), najdluzsze.end());
    sort(najkrotsze.begin(), najkrotsze.end());
    //std::cout<<"najwieksza "<<najdluzsze.back()<<std::endl;
    //std::cout<<"najmniejsza "<<najkrotsze.front()<<std::endl;
    int wiersz = 0;
    for(const std::string& elem : dane)
    {
        wiersz++;
        if( elem == najdluzsze.back())
        {
           std::string wynik1 = "najwieksza wiersz " + std::to_string(wiersz);
           to_save.push_back(wynik1);
        }
        else if( elem == najkrotsze.front())
        {
           std::string wynik2 = "najmniejszy wiersz " + std::to_string(wiersz);
           to_save.push_back(wynik2);

        }
    }
    menago_.saveData("zadanie trzecie",to_save );

}


}  // prework
