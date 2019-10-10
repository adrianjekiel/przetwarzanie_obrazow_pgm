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

// 1. wazna rzecz do zauwazenia, ostatni elemenst z poprzedniego ciagu, moze byc tez pierwszym z nastepnego,
// czyli 2,4,18,9,3 --> jeden ciag {2,4,18} -> nwd 2 i drugi ciag {18,9,3} -> nwd 3

std::string Liczby::zad3()
{
    // nwd_final to ostateczne nwd ktore szukamy, semi_fnal_nwd symbolizuje najwieksze nwd w zbiorze gdzie nwd > 1
    // ewentualnie je przypiszemy do nwd_final jesli dlugosc ciagu znalezionego bedzie dluzsza niz aktualnie przechowywanego

    int nwdfinal, semi_final_nwd;
    int current_nwd = vecLiczby_[0];

    // temp_vec sluzy do przechowywania aktualnych ciagow liczb, max_vec jest to najdluzszy znaleziony ciag
    std::vector<int> temp_vec, max_vec;

    for(int i = 0; i < vecLiczby_.size(); i++)
    {
        // warto zauwazyc ze w pierwszej iteracji szukamy nwd vecLiczby_[0] z vecLiczby_[0]
        current_nwd = nwd(current_nwd, vecLiczby_[i]);

        if(current_nwd>1) // jesli nwd liczb jest wieksze od 1
        {
            temp_vec.push_back(vecLiczby_[i]);
            semi_final_nwd = current_nwd;
        }
        else // znalezlismy koniec ciagu
        {
            if(temp_vec.size()>max_vec.size()) // znalezlismy dluzszy ciag
            {  
                max_vec.swap(temp_vec); // to swap
                nwdfinal = semi_final_nwd; // i przypisanie maxymalnego dzielnika
            }
            temp_vec.clear(); // i szyscimy temp vector

            // teraz czas na ten pokrecony warunek opisany nad funkcja
            // zauwaz ze tutaj current_nwd to najwiekszy wspolny dzielnik wczesniej wyliczony, jesli weszlismy w else to na poczatku jego wartosc to 1,
            // dlatego sprawdzamy z vecLiczby_[i-1] a nie current_nwd jak w lini 106
            current_nwd = nwd(vecLiczby_[i-1], vecLiczby_[i]);
            if (current_nwd > 1) // liczba konczaca poprzedni ciag ma wspolny dzielnik z kolejna z nia liczba --> nie myl z nwd poprzedniego ciagu, to dwie rozne liczby
            {
                temp_vec.push_back(vecLiczby_[i-1]); // to wrzucamy jeszcze ta poprzednia
                semi_final_nwd = current_nwd; // no i mamy nowy semi_final_nwd
            }
            else // no jesli nie maja wspolnego dzielnika, to jednak vecLiczby_[i] bedzie rozpoczynal kolejny ciag
            {
                current_nwd = vecLiczby_[i]; // aktualne nwd to jest vecLiczby_[i], bo od niej zaczynamy
            }
            temp_vec.push_back(vecLiczby_[i]); // i nasz nowy vector bedzie sie od tej liczby zaczynal
        }
    }
    std::string wynik1 = std::to_string(nwdfinal);
    std::string wynik2 = std::to_string(max_vec[0]);
    std::string wynik3 = std::to_string(max_vec.size());
    std::cout << "wyniki: " << std::endl;
    std::cout << "nwd: " << wynik1 << " \npierwsza liczba ze zbioru: " << wynik2 << "\ndlugosc zbioru : " << wynik3 << std::endl;
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

