/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "FilterRunner.hpp"

namespace prework
{

Obraz FilterRunner::progowanie(Obraz obraz)
{
    int prog;
    std::cout<<"Progowanie. Podaj wspolczynik progowania.. (0-100%)"<<std::endl;
    std::cin>>prog;
    return filtry.progowanie(prog, obraz);
}

Obraz FilterRunner::zmiana_poziomow(Obraz obraz)
{
    int x,y;
    std::cout<<"Zmiana poziomow. Podaj nowa czern i biel (w %, czern < biel)"<<std::endl;
    std::cin>>x>>y;
    auto obraz_po_zmianie_poziomow = filtry.zmiana_poziomow(x,y, obraz);
    obraz = obraz_po_zmianie_poziomow;
}

Obraz FilterRunner::korekcja_gamma(Obraz obraz)
{
    double gamma;
    std::cout<<"Korekcja gamma. Podaj wspolczyniki gamma.. (mniej niz 1 przyciemnia, wiecej rozjasnia)"<<std::endl;
    std::cin>>gamma;
    return filtry.kor_gamma(gamma, obraz);
}

Obraz FilterRunner::konturowanie(Obraz obraz)
{
    std::cout<<"Konturowanie"<<std::endl;
    return filtry.kontur(obraz);
}

Obraz FilterRunner::rozmycie_pionowe(Obraz obraz)
{
    int r;
    std::cout<<"rozmycie pionowe. Podaj promien rozmycia.."<<std::endl;
    std::cin>>r;
    return filtry.rozmycie_pio(obraz, r);
}

Obraz FilterRunner::rozmycie_poziome(Obraz obraz)
{
    int r;
    std::cout<<"rozmycie poziome. Podaj promien rozmycia.."<<std::endl;
    std::cin>>r;
    return filtry.rozmycie_poz(obraz, r);
}

Obraz FilterRunner::rozciaganie_histogramu(Obraz obraz)
{
    std::cout<<"Rozciagniecie Histogramu"<<std::endl;
    return filtry.histogram(obraz);
}

Obraz FilterRunner::splot(const std::string& maska, Obraz obraz)
{
    std::cout<<"Splot z maska: " << maska <<std::endl;
    return filtry.splot(maska, obraz);
}

}  // namespace prework
