/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "Filtry.hpp"
#include <math.h>

namespace prework
{
Obraz Filtry::progowanie(const int &procent, Obraz obraz)
{
    int prog = (obraz.skala()*procent)/100;
    for(auto &wiersz : obraz.data())
    {
        for(auto &piksel : wiersz)
        {
            if(piksel>prog)
            {
                piksel=obraz.skala();
            }
            else
            {
                piksel=0;
            }
        }
    }
    obraz.set_fileName("obraz_progowanie.pgm");
    return obraz;
}
Obraz Filtry::zmiana_poziomow(const int& czern_procent, const int& biel_procent, Obraz obraz)
{
    int czern = (obraz.skala()*czern_procent)/100;
    int biel = (obraz.skala()*biel_procent)/100;
    for(auto &wiersz : obraz.data())
    {
        for(auto &piksel : wiersz)
        {
            if(piksel<=czern)
            {
                piksel=0;
            }
            else if(piksel >= biel)
            {
                piksel=obraz.skala();
            }
            else
            {
                piksel = ((piksel - czern)*obraz.skala())/(biel - czern);
            }
        }
    }
    obraz.set_fileName("obraz_zmiana_poziomow.pgm");
    return obraz;
}
Obraz Filtry::kor_gamma(const int& wartosc, Obraz obraz)
{
    for(auto &wiersz : obraz.data())
    {
        for(auto &piksel : wiersz)
        {
            piksel=(pow(piksel/obraz.skala(),1/wartosc))*obraz.skala();
        }
    }
    obraz.set_fileName("obraz_korekcja_gamma.pgm");
    return obraz;
}


}  // namespace prework
