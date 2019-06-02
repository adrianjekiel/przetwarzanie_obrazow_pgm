/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "Filtry.hpp"

namespace prework
{
Obraz Filtry::progowanie(const int &procent, Obraz obraz_do_progowania)
{
    int prog = (obraz_do_progowania.skala()*procent)/100;
    for(auto &wiersz : obraz_do_progowania.data())
    {
        for(auto &piksel : wiersz)
        {
            if(piksel>prog)
            {
                piksel=obraz_do_progowania.skala();
            }
            else
            {
                piksel=0;
            }
        }
    }
    std::cout<<obraz_do_progowania.magic_number()<<" "<<
               obraz_do_progowania.width()<<" "<<obraz_do_progowania.high()<<" "<<obraz_do_progowania.skala()<<std::endl;
    for(auto &wiersz : obraz_do_progowania.data())
    {
        for(auto &piksel : wiersz)
        {
            std::cout << piksel;
        }
    }
    return obraz_do_progowania;
}
Obraz Filtry::zmiana_poziomow(const int &czern_, const int &biel_, Obraz obraz_do_zmiany_poziomow)
{
    int czern = (obraz_.skala()*czern_)/100;
    int biel = (obraz_do_zmiany_poziomow.skala()*biel_)/100;
    for(auto &wiersz : obraz_do_zmiany_poziomow.data())
    {
        for(auto &piksel : wiersz)
        {
            if(piksel<=czern)
            {
                piksel=0;
            }
            else if(piksel >= biel)
            {
                piksel=obraz_do_zmiany_poziomow.skala();
            }
            else
            {
                piksel = ((piksel - czern)*obraz_do_zmiany_poziomow.skala())/(biel - czern);
            }
        }
    }
    return obraz_do_zmiany_poziomow;
}


}  // namespace prework
