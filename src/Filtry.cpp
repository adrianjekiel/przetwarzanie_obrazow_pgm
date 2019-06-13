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
            if(kolumna+1<obraz.width() and wiersz+1<obraz.high())
            {
                piksele[wiersz][kolumna]=abs(piksele[wiersz+1][kolumna] - piksele[wiersz][kolumna])+abs(piksele[wiersz][kolumna+1]-piksele[wiersz][kolumna]);
            }
        }
    }

    obraz.set_fileName("obraz_po_konturowaniu.pgm");
    return obraz;
}
Obraz Filtry::rozmycie_poz(Obraz obraz)
{
    double k = 0.33;
    auto &piksele = obraz.data();
    for(int wiersz = 0; wiersz<obraz.high();wiersz++)
    {
        for(int kolumna = 0 ; kolumna<obraz.width(); kolumna++)
        {
            if(wiersz<obraz.high() and kolumna+1<obraz.width())
            {
                piksele[wiersz][kolumna]=k*(double(piksele[wiersz][kolumna-1])+double(piksele[wiersz][kolumna])+double(piksele[wiersz][kolumna+1]));
            }
        }
    }

    obraz.set_fileName("obraz_po_rozmyciu_poziomym.pgm");
    return obraz;
}
Obraz Filtry::rozmycie_pio(Obraz obraz)
{
    double k = 0.33;
    auto &piksele = obraz.data();
    for(int wiersz = 0; wiersz<obraz.high();wiersz++)
    {
        for(int kolumna = 0 ; kolumna<obraz.width(); kolumna++)
        {
            if(wiersz+1<obraz.high() and wiersz>0)
            {
                piksele[wiersz][kolumna]=k*(double(piksele[wiersz-1][kolumna])+double(piksele[wiersz][kolumna])+double(piksele[wiersz+1][kolumna]));
            }
        }
    }

    obraz.set_fileName("obraz_po_rozmyciu_pionowym.pgm");
    return obraz;
}

}  // namespace prework
