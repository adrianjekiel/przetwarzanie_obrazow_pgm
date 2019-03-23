/**
 * Made by Adrian Jekiel
 * Year 2019
 **/
#include <iostream>
#include "Obrazy.hpp"
#include <algorithm>

namespace prework
{
Obrazy::Obrazy(const std::vector<std::vector<int>> &dane):
    dane_(dane)
{}

void Obrazy::zad1()
{
    int max=0;
    int min=255;
    for(auto elem : dane_)
    {
        auto tmax = std::max_element(elem.begin(),elem.end());
        auto tmin = std::min_element(elem.begin(),elem.end());
        if(max<*tmax)
            max=*tmax;
        if(min>*tmin)
            min=*tmin;
    }
    std::cout<<max<<" "<<min<<std::endl;
}
void Obrazy::zad2()
{
    int del = 0;
    for(auto elem : dane_)
    {
        int begin = 0;
        int end = elem.size()-1;
        for(int i = 0 ; i<=elem.size()/2 ; i++)
        {
            if(elem[begin+i]!=elem[end-i])
            {
                del++;
                break;
            }
        }
    }
    std::cout<<del<<std::endl;
}
void Obrazy::zad3()
{
    int counter = 0;
    for(int x = 0 ; x<dane_.size() ; x++)
    {
        for(int y = 0; y<dane_[x].size() ; y++)
        {
           if(x-1>=0 and diff(x,y,x-1,y))
           {
                   counter++;
           }
           else if(x+1<dane_.size() and diff(x,y,x+1,y))
           {
                   counter++;
           }
           else if(y-1>=0 and diff(x,y,x,y-1))
           {
                   counter++;
           }
           else if(y+1<dane_[x].size() and diff(x,y,x,y+1))
           {
                   counter++;
           }
        }   
    }
    std::cout<<counter<<std::endl;
}

void Obrazy::zad4()
{
    int max = 0;
    int x = 0;
    int counter;
    for(int y = 0 ; y<dane_[x].size() ; y++)
    {
        counter = 0;
        int core_piksel = dane_[0][y];
        for(x = 0; x<dane_.size() ; x++)
        {
            if(dane_[x][y] == core_piksel)
                counter++;
            else
                break;

        }
        if(max<counter)
            max=counter;
    }

    std::cout<<max<<std::endl;

}

bool Obrazy::diff(const int x1, const int y1, const int x2, const int y2)
{
    if(abs(dane_[x1][y1]-dane_[x2][y2])>128)
        return true;
    else
        return false;

}


}// prework
