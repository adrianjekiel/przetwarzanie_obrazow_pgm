/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "Filtry.hpp"
#include <math.h>
#include "Maski.hpp"
#include <numeric>

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
   auto mi_max = min_max(obraz);
   auto min_pixels = mi_max.first;
   auto max_pixels = mi_max.second;
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
Obraz Filtry::splot(const std::string &maska, Obraz obraz)
{
    Maski maski;
    auto wspolczyniki = maski.get_mask(maska);
    if(wspolczyniki.empty())
    {
        std::cout<<"brak wspolczynikow"<<std::endl;
        return obraz;
    }
    auto &piksele = obraz.data();
    auto piksele_c = obraz.data();
    for(int wiersz = 1; wiersz<obraz.high()-1;wiersz++)
    {
        for(int kolumna = 1 ; kolumna<obraz.width()-1; kolumna++)
        {
            for(int color = 0; color<piksele[wiersz][kolumna].size(); color++)
            {
                piksele[wiersz][kolumna][color]=
                        piksele_c[wiersz-1][kolumna-1][color]*wspolczyniki[0]+
                        piksele_c[wiersz-1][kolumna][color]*wspolczyniki[1]+
                        piksele_c[wiersz-1][kolumna+1][color]*wspolczyniki[2]+
                        piksele_c[wiersz][kolumna-1][color]*wspolczyniki[3]+
                        piksele_c[wiersz][kolumna][color]*wspolczyniki[4]+
                        piksele_c[wiersz][kolumna+1][color]*wspolczyniki[5]+
                        piksele_c[wiersz+1][kolumna-1][color]*wspolczyniki[6]+
                        piksele_c[wiersz+1][kolumna][color]*wspolczyniki[7]+
                        piksele_c[wiersz+1][kolumna+1][color]*wspolczyniki[8];
            }
        }
    }
    if(are_negative_coefficients(wspolczyniki))
    {
        normalize_negative(obraz, wspolczyniki);
    }
    else
    {

        normalize_positive(obraz, wspolczyniki);
    }
    obraz.set_fileName(std::string("obraz_po_filtrze") + maska + std::string(".pgm"));
    return obraz;
}
    
void Filtry::normalize_positive(Obraz& obraz, const std::vector<int>& wspolczyniki)
{
    int suma = std::accumulate(wspolczyniki.begin(),wspolczyniki.end(),0);
    for(auto &wiersz : obraz.data())
    {
        for(auto &piksel : wiersz)
        {
            for( auto &color : piksel)
            {
              color=color/suma;
            }
        }
    }    
}
    
void Filtry::normalize_negative(Obraz& obraz, const std::vector<int>& wspolczyniki)
{
    auto mi_max = min_max(obraz);
    auto min_pixels = mi_max.first;
    auto max_pixels = mi_max.second;
    for(auto &wiersz : obraz.data())
    {
        for(auto &piksel : wiersz)
        {
            for(int color=0;color<piksel.size(); color++)
            {
              piksel[color]=((piksel[color]-min_pixels[color])*obraz.skala())/(max_pixels[color]-min_pixels[color]);
            }
        }
    } 
}
    
bool Filtry::are_negative_coefficients(const std::vector<int>& wspolczyniki)
{
    for(const auto& wspol: wspolczyniki)
    {
        if(wspol<0)
            return true;
    }
    return false;
}

std::pair<std::vector<int>, std::vector<int>> Filtry::min_max(const Obraz& obraz)
{
    std::vector<int> min_pixels = obraz.data()[0][0];
    std::vector<int> max_pixels = obraz.data()[0][0];
    for(const auto &wiersz : obraz.data())
    {
        for(const auto &piksel : wiersz)
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
    return std::make_pair(min_pixels,max_pixels);
}

}  // namespace prework
