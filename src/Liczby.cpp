/**
 * Made by Adrian Jekiel
 * Year 2019
 **/
#include <iostream>
#include "Liczby.hpp"
#include <algorithm>
#include <sstream>
#include <vector>
namespace prework
{
Liczby::Liczby(const std::vector<int>& vecLiczby) :
    vecLiczby_(vecLiczby) //nabijanie
{}

std::string Liczby::zad1()
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
    std::string wynik1 = std::to_string(licznik);
    return std::string {wynik1 + "- ilosc liczb, ktore sa potega 3."};
}
std::string Liczby::zad2()
{
    for(auto elem : convertToString())//elem = string  convert to stering = vector
    {
        int liczba = oblicz_sume(elem);//suma sim
        int temp_liczba = std::stoi(elem);//z stringa w int
        if(temp_liczba==liczba)
        {
            return std::string {elem};
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

std::string Liczby::zad3()
{
    int nwdfinal;
    int nwdo =vecLiczby_[0];
    std::vector<int> temp_vec;
    std::vector<int> max_vec ;
    for(int i =0; i<vecLiczby_.size();i++)
    {
        nwdo = nwd(nwdo,vecLiczby_[i+1]);
        if(nwdo>1)
        {
            temp_vec.push_back(vecLiczby_[i]);
            nwdfinal = nwdo;
        }
        else
        {
            temp_vec.push_back(vecLiczby_[i]);
            if(temp_vec.size()>max_vec.size())
            {  
                max_vec = temp_vec;

            }
         temp_vec.clear();

         nwdo=vecLiczby_[i+1];
        }
    }
    std::string wynik1 = std::to_string(nwdfinal);
    std::string wynik2 = std::to_string(max_vec[0]);
    std::string wynik3 = std::to_string(max_vec.size());
//    std::cout<<nwdfinal<<std::endl;
//    std::cout<<max_vec[0]<<std::endl;
    //std::cout<<max_vec.size()<<std::endl; to w ogole nie potrzebne
    return std::string {wynik1 + " " + wynik2 + " " + wynik3};


}

int Liczby::nwd(int liczba_pierwsza, int liczba_druga)
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

