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
    int k = 107%(26) ;
    auto dane = menago_.loadData("dane_6_1.txt");
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
        std::cout<<elem<<std::endl;
    }

}


}  // prework
