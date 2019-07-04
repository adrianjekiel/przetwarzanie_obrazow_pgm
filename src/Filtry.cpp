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
            for( auto &color : piksel)
            {
                if(color>prog)
                {
                    color=obraz.skala();
                }
                else
                {
                    color=0;
                }
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
            for( auto &color : piksel)
            {
                if(color<=czern)
                {
                    color=0;
                }
                else if(color >= biel)
                {
                    color=obraz.skala();
                }
                else
                {
                    color = ((color - czern)*obraz.skala())/(biel - czern);
                }
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
            for( auto &color : piksel)
            {
              color=(pow(double(color)/d_skala,1/wartosc))*d_skala;
            }
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
            for(int color = 0; color<piksele[wiersz][kolumna].size(); color++)
            {
                if(kolumna+1<obraz.width() and wiersz+1<obraz.high())
                {
                    piksele[wiersz][kolumna][color]=abs(piksele[wiersz+1][kolumna][color] - piksele[wiersz][kolumna][color])+abs(piksele[wiersz][kolumna+1][color]-piksele[wiersz][kolumna][color]);
                }
            }

        }
    }

    obraz.set_fileName("obraz_po_konturowaniu.pgm");
    return obraz;
}
Obraz Filtry::rozmycie_poz(Obraz obraz,const int r)
{
    double k = 0.33;
    auto &piksele = obraz.data();
    for(int wiersz = 0; wiersz<obraz.high();wiersz++)
    {
        for(int kolumna = 0 ; kolumna<obraz.width(); kolumna++)
        {
            for(int color = 0; color<piksele[wiersz][kolumna].size(); color++)
            {
                if(kolumna+r<obraz.width() and kolumna-r>=0)
                {
                    piksele[wiersz][kolumna][color]=k*(double(piksele[wiersz][kolumna-r][color])+double(piksele[wiersz][kolumna][color])+double(piksele[wiersz][kolumna+r][color]));
                }
            }

        }
    }

    obraz.set_fileName("obraz_po_rozmyciu_poziomym.pgm");
    return obraz;
}
Obraz Filtry::rozmycie_pio(Obraz obraz, const int r)
{
    double k = 0.33;
    auto &piksele = obraz.data();
    for(int wiersz = 0; wiersz<obraz.high();wiersz++)
    {
        for(int kolumna = 0 ; kolumna<obraz.width(); kolumna++)
        {
            for(int color = 0; color<piksele[wiersz][kolumna].size(); color++)
            {
                if(wiersz+r<obraz.high() and wiersz-r>=0)
                {
                    piksele[wiersz][kolumna][color]=k*(double(piksele[wiersz-r][kolumna][color])+double(piksele[wiersz][kolumna][color])+double(piksele[wiersz+r][kolumna][color]));
                }
            }
        }
    }

    obraz.set_fileName("obraz_po_rozmyciu_pionowym.pgm");
    return obraz;
}
Obraz Filtry::histogram(Obraz obraz)
{
    std::vector<int> min_pixels = obraz.data()[0][0];
    std::vector<int> max_pixels = obraz.data()[0][0];
    for(auto &wiersz : obraz.data())
    {
        for(auto &piksel : wiersz)
        {
            for(int color = 0; color<piksel.size(); color++)
            {
                if(min_pixels[color]>piksel[color])
                {
                    min_pixels[color]=piksel[color];
                }
                if(max_pixels[color]<piksel[color])
                {
                    max_pixels[color]=piksel[color];
                }
            }
        }
    }
    for(auto &wiersz : obraz.data())
    {
        for(auto &piksel : wiersz)
        {
            for(int color = 0; color<piksel.size(); color++)
            {
             piksel[color]=(piksel[color] - min_pixels[color])*(obraz.skala()/(max_pixels[color]-min_pixels[color]));
            }
        }
    }
    obraz.set_fileName("obraz_po_rozciagnieciu_histogramu.pgm");
    return obraz;
}

}  // namespace prework
