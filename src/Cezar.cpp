/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "Cezar.hpp"
#include <iostream>
namespace prework
{
void Cezar::zad1()
{
    std::vector<std::string> to_save;
    int k = 107%(26) ;
    auto dane = menago_.loadData("dane_6_1.txt");
    int i = 0;
    for(std::string& elem : dane)
    {
        for(char& a : elem)
        {
            if(a+k>90)//zawijamy
            {
                a=a+k-26;
            }
            else
            {
                a=a+k;
            }

        }
        to_save.push_back(elem);
    }
    menago_.saveData("ZADANIE PIERWSZE",to_save);

}
void Cezar::zad2()
{
    std::vector<std::string> to_save;
    auto dane = menago_.loadData2("dane_6_2.txt");
    for(slowo_klucz& elem : dane)
    {
        int klucz = elem.klucz%26;
        for(char& a : elem.slowo)
        {
            if(a-klucz<65)//zawijamy    c 68 k 5    a=63 a=68-5  63 + 26 = 89
            {
                a=a-klucz+26;
            }
            else
            {
                a=a-klucz;
            }
        }
        to_save.push_back(elem.slowo);
    }
    menago_.saveData("ZADANIE DRUGIE",to_save);
}
void Cezar::zad3()
{
    std::vector<std::string> to_save;
    auto dane = menago_.loadData3("dane_6_3.txt");
    for(slowo_szyfrogram& elem : dane)
    {
        int core_klucz = std::abs(elem.slowo[0]-elem.szyfrogram[0]);
        for(int i = 0; i<elem.slowo.size(); i++)
        {
          if(std::abs(elem.slowo[i]-elem.szyfrogram[i]) != core_klucz)
          {
            to_save.push_back(elem.slowo);
            break;
          }
        }
    }
    menago_.saveData("ZADANIE TRZECIE",to_save);
}

}  // prework
