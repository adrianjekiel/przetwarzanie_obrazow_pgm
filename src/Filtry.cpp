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
Obraz Filtry::kor_gamma(const double& wartosc, Obraz obraz)
{
    double d_skala = obraz.skala();
    for(auto &wiersz : obraz.data())
    {
        for(auto &piksel : wiersz)
        {
            piksel=(pow(double(piksel)/d_skala,1/wartosc))*d_skala;
        }
    }
    obraz.set_fileName("obraz_korekcja_gamma.pgm");
    return obraz;
}
Obraz Filtry::kontur(Obraz obraz)
{
    auto &piksele = obraz.data();
    for(int wiersz = 0; wiersz<obraz.high();wiersz++)
    {
        for(int kolumna = 0 ; kolumna<obraz.width(); kolumna++)
        {
            std::cout<<"dupa1"<<" "<<wiersz<<" "<<kolumna<<std::endl;
            if(kolumna+1<obraz.width() and wiersz+1<obraz.high())
            {
                auto curr_piksel = piksele[wiersz][kolumna];
                auto right_piksel = piksele[wiersz][kolumna+1];
                auto down_piksel = piksele[wiersz+1][kolumna];
                piksele[wiersz][kolumna]=abs(down_piksel - curr_piksel)+abs(right_piksel-curr_piksel);
            }
        }
    }
    obraz.set_fileName("obraz_po_konturowaniu.pgm");
    std::cout<<"dupa2";
    return obraz;
}


}  // namespace prework
