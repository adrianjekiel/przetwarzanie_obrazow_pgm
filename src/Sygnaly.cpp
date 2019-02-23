/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "Sygnaly.hpp"

namespace prework
{
Sygnaly::Sygnaly(const std::vector<std::string>& vecSygnaly) :
    vecSygnaly_(vecSygnaly) //nabijanie
{}

void Sygnaly::zad1()
{
    std::string temp;
    for(int i=40 ; i<vecSygnaly_.size();i+=40)
    {
        temp.push_back(vecSygnaly_[i][10]);
    }
    std::cout<<temp<<std::endl;
}




}  // prework
