/**
 * Made by Adrian Jekiel
 * Year 2019
 **/
#include <iostream>
#include "Sygnaly.hpp"
#include <algorithm>
namespace prework
{
Sygnaly::Sygnaly(const std::vector<std::string>& vecSygnaly) :
    vecSygnaly_(vecSygnaly) //nabijanie
{}

void Sygnaly::zad1()
{
    std::string temp;
    for(int i=39 ; i<vecSygnaly_.size();i+=40)
    {
        temp.push_back(vecSygnaly_[i][9]);
    }
    std::cout<<temp<<std::endl;
}

void Sygnaly::zad2()
{
    auto vec_copy = vecSygnaly_;
    int id = 0;
    std::string tempmax;
    tempmax = vec_copy[id];//pierwszy wyraz
    std::sort(tempmax.begin(),tempmax.end());//sortujemy
    tempmax.erase(std::unique(tempmax.begin(),tempmax.end()),tempmax.end());//usuwamy duplicaty
    for(int i = 1; i<vec_copy.size();i+=1)
    {
        std::sort(vec_copy[i].begin(),vec_copy[i].end());//sortujemy kolejny wyraz

        vec_copy[i].erase(std::unique(vec_copy[i].begin(),vec_copy[i].end()),vec_copy[i].end());

        //mamy juz gotowy kolejny wyraz do przyrownaniua
        if(vec_copy[i].size()>tempmax.size())
        {
            tempmax = vec_copy[i];//nowy wyraz wiekszy jest dotychczasowym najwieskzum tempmax
            id = i;
        }
    }
    //po tej petli mamy juz najwiekszy jako tempmax
    //przechodzimy do wypisywania
    std::cout<<vecSygnaly_[id]<<std::endl<<tempmax.size()<<std::endl;
}

void Sygnaly::zad3()
{
    int x=1;
    for(auto sygnal : vecSygnaly_)
    {
        if(diff_less_then_ten(sygnal))
        {
            std::cout<<x<<" "<<sygnal<<std::endl;
            x++;
        }
    }

}

bool Sygnaly::diff_less_then_ten(const std::string &sygnal)
{
    for(int temp = 0; temp<sygnal.size();temp++)
    {
        for(int i = 0; i<sygnal.size(); i++)//kazda z kazda xd
        {
            if(std::abs(sygnal[temp]-sygnal[i])>10)
                return false;
        }
    }
    return true;
}





}  // prework

