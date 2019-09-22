/**
 * Made by Adrian Jekiel
 * Year 2019
 **/
#include <iostream>
#include "Liczby.hpp"
#include <algorithm>
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
        if(elem%3==0 or elem==1)
        {
            licznik++;
        }
    }
    std::cout<<licznik<<" - ilosc liczb, ktore sa potega 3."<<std::endl;
}
void Liczby::zad2()
{
    for(auto elem:convertToString())
    {

    }
}
int Liczby::silnia (int liczba)
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



std::vector<std::string> Liczby::convertToString ()
{
    std::vector<std::string> tempvec;
    for(auto elem: vecLiczby_)
    {
        tempvec.push_back(std::to_string(elem));
    }
    return tempvec;
}

}  // prework

