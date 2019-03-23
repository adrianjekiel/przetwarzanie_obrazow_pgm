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
    for(int x = 0 ; x<=200 ; x++)
    {
        for(int y = 0; y<=320 ; y++)
        {
            if(x>=1 and x<=199 and y>=1 and y<=319)
            {

                if(dane_[x][y]-dane_[x+1][y]>128 or dane_[x][y]-dane_[x][y+1]>128
                        or dane_[x][y]-dane_[x-1][y]>128 or dane_[x][y]-dane_[x][y-1]>128)
                {
                    counter++;
                }
            }
            else if(x==0)
            {
                if(y==0)
                {
                    if(dane_[x][y]-dane_[x+1][y]>128 or dane_[x][y]-dane_[x][y+1]>128)
                    {
                        counter++;
                    }
                }
                else if(y>0 and y<320)
                {
                    if(dane_[x][y]-dane_[x][y-1]>128 or dane_[x][y]-dane_[x+1][y]>128 or dane_[x][y]-dane_[x][y+1]>128)
                    {
                        counter++;
                    }
                }
                else if(y==320)
                {
                    if(dane_[x][y]-dane_[x+1][y]>128 or dane_[x][y]-dane_[x][y-1]>128)
                    {
                        counter++;
                    }
                }

            }
            else if(y==0 and x>0 and x<200)
            {
                if(dane_[x][y]-dane_[x-1][y]>128 or dane_[x][y]-dane_[x][y+1]>128 or dane_[x][y]-dane_[x+1][y]>128)
                {
                    counter++;
                }
            }
            else if(y==0 and x==200)
            {
                if(dane_[x][y]-dane_[x-1][y]>128 or dane_[x][y]-dane_[x][y+1]>128)
                {
                    counter++;
                }
            }
            else if(x==200)
            {
                if(y>0 and y<320)
                {
                    if(dane_[x][y]-dane_[x-1][y]>128 or dane_[x][y]-dane_[x][y+1]>128
                            or dane_[x][y]-dane_[x][y-1]>128)
                    {
                        counter++;
                    }
                }
                else if(y==320)
                {
                    if(dane_[x][y]-dane_[x-1][y]>128 or dane_[x][y]-dane_[x][y-1]>128)//prway dolny
                    {
                        counter++;
                    }
                }
            }
            else if(y==320 and x>0 and x<200)
            {
                if(dane_[x][y]-dane_[x-1][y]>128 or dane_[x][y]-dane_[x][y-1]>128 or dane_[x][y]-dane_[x+1][y]>128)//prway kw
                {
                    counter++;
                }
            }

        }

        std::cout<<counter<<std::endl;
    }

}

}// prework
