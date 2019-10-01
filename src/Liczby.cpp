/**
 * Made by Adrian Jekiel
 * Year 2019
 **/
#include <iostream>
#include "Liczby.hpp"
#include <algorithm>
#include <sstream>
namespace prework
{
Liczby::Liczby(const std::vector<int>& vecLiczby) :
    vecLiczby_(vecLiczby) //nabijanie
{}

void Liczby::zad1()
{
    int licznik = 0;
    for(auto elem : vecLiczby_)
    {
        while(elem>1)
        {
            if(elem%3==0)
            {
                elem = elem/3;
            }
            else
            {
                break;
            }
        }
        if(elem==1)
        {
            licznik++;
        }

    }
    std::cout<<licznik<<" - ilosc liczb, ktore sa potega 3."<<std::endl;
}
void Liczby::zad2()
{
    for(auto elem : convertToString())//elem = string  convert to stering = vector
    {
        int liczba = oblicz_sume(elem);//suma sim
        int temp_liczba = std::stoi(elem);//z stringa w int
        if(temp_liczba==liczba)
        {
            std::cout<<elem<<std::endl;
        }
    }
}
int Liczby::silnia (int liczba)//tylko int
{
    if(liczba==0)
    {
        return 1;
    }
    else
    {
      return liczba* silnia(liczba-1);
    }

}

int Liczby::oblicz_sume (std::string liczba)
{
    int suma = 0;
    for(auto cyfra :liczba)//po charach w stringu
    {
        int int_liczba = std::stoi(std::string{cyfra});//{} bardzo wazne waste initializacja () castowanie do typu nie dziala
        suma += silnia(int_liczba);//suma silni tej liczby.
    }
    return suma;
}



std::vector<std::string> Liczby::convertToString ()
{
    std::vector<std::string> tempvec;
    for(auto elem: vecLiczby_)
    {
        tempvec.push_back(std::to_string(elem));
    }
    return tempvec;
}

void Liczby::zad3()
{
    int nwdo =vecLiczby_[0];
    int temp_dl=0;
    int max_dl=0;
    std::vector<int> temp_vec;
    std::vector<int> max_vec ;
    for(int liczba : vecLiczby_)
    {
        if(nwd(nwdo,liczba)>1)
        {
            temp_dl++;
            temp_vec.push_back(liczba);
        }
        else
        {
            if(temp_dl>max_dl)
            {
                max_dl = temp_dl;
                max_vec = temp_vec;
                temp_dl = 0;
                temp_vec.clear();
            }
         nwdo=liczba;
        }
    }
    std::cout<<max_vec[0]<<std::endl;
    std::cout<<max_vec.size()<<std::endl;
    std::sort(max_vec.begin(),max_vec.end());
    std::cout<<max_vec[max_vec.size()-1]<<std::endl;
}

int nwd(int liczba_pierwsza, int liczba_druga)
{
    int pom;
    while(liczba_druga!=0)
    {
        pom = liczba_druga;
        liczba_druga = liczba_pierwsza%liczba_druga;
        liczba_pierwsza = pom;
    }
    return liczba_pierwsza;
}

}  // prework

