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
    for(auto elem : convertToString())//elem = string  convert to stering = vector
    {
        int liczba = olbicz_sume(elem);//suma si;m
        int temp_liczba = std::to_int(elem);//z stringa w int
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
    for(auto cyfry : liczba)//po charach w stringu
    {
        int int_liczba = std::to_int(cyfry);//robimy z chara inta by obliczcyc silnie
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

}  // prework

