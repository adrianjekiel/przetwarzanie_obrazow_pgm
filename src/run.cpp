/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include <iostream>
#include "run.hpp"
#include "FileManager.hpp"
#include "Obraz.hpp"
#include "Filtry.hpp"
#include "Maski.hpp"

namespace prework
{


void wczytaj_obraz()
{
    auto manager = prework::FileManager();
    std::string fileName;
    std::cout<<"Podaj nazwe pliku .."<<std::endl;
    std::cin>>fileName;
    auto obraz = manager.loadData(fileName);
}

void zapisz_obraz (Obraz obraz)
{
    auto manager = prework::FileManager();
    manager.saveData(obraz);
}

void menu_numer_dwa(Obraz obraz)
{
    auto filtry = prework::Filtry();
    int wybor;
    do{
        std::cout<<"Podaj wybor dla drugiego menu.."<<std::endl;
        std::cin>>wybor;
        switch (wybor)
        {
        case 1: {

               int prog;
               std::cout<<"Progowanie. Podaj wspolczynik progowania.."<<std::endl;
               std::cin>>prog;
               auto obraz_po_progowaniu = filtry.progowanie(prog, obraz);
               obraz = obraz_po_progowaniu;
               break;
        }
        case 2: {
               int x,y;
               std::cout<<"Zmiana poziomow. Podaj wspolczyniki.."<<std::endl;
               std::cin>>x>>y;
               auto obraz_po_zmianie_poziomow = filtry.zmiana_poziomow(x,y, obraz);
               obraz = obraz_po_zmianie_poziomow;
               break;
        }
        case 3: {
                int z;
                std::cout<<"Zmiana poziomow. Podaj wspolczyniki.."<<std::endl;
                std::cin>>z;
                auto obraz_po_korekcji_gamma = filtry.kor_gamma(z, obraz);
                obraz = obraz_po_korekcji_gamma;
                break;
        }
        case 4: {
                std::cout<<"Konturowanie"<<std::endl;
                auto obraz_po_konturowaniu = filtry.kontur(obraz);
                obraz = obraz_po_konturowaniu;
                break;
        }
        case 5: {
                int poz;
                std::cout<<"rozmycie poziome. Podaj wspolczynik.."<<std::endl;
                std::cin>>poz;
                auto obraz_po_rozmyciu_poziomym = filtry.rozmycie_poz(obraz, poz);
                obraz = obraz_po_rozmyciu_poziomym;
                break;
        }
        case 6: {
                int pio;
                std::cout<<"rozmycie poziome. Podaj wspolczynik.."<<std::endl;
                std::cin>>pio;
                auto obraz_po_rozmyciu_pionowym = filtry.rozmycie_pio(obraz, pio);
                obraz = obraz_po_rozmyciu_pionowym;
                break;
        }
        case 7: {
                std::cout<<"Rozciagniecie Histogramu"<<std::endl;
                auto obraz_po_rozciagnieciu_histogramu = filtry.histogram(obraz);
                obraz = obraz_po_rozciagnieciu_histogramu;
                break;
        }
        case 0: {
                std::cout<<"Powracam do poprzedniego menu"<<std::endl;}
                break;
            }

    } while (wybor != 0);
}

void menu_numer_trzy(Obraz obraz)
{
    auto filtry = prework::Filtry();
    int wybor;
    do{
        std::cout<<"Podaj wybor dla trzeciego menu.."<<std::endl;

        std::cout<<"1 : maska_usredniajaca "<<std::endl;
        std::cout<<"2 : maska_usredniajaca_ze_wzmocnieniem "<<std::endl;
        std::cout<<"3 : gradient_Robertsa "<<std::endl;
        std::cout<<"4 : maska_Prewitta "<<std::endl;
        std::cout<<"5 : maska_Sobela "<<std::endl;
        std::cout<<"6 : maska_wykrywajaca_narozniki "<<std::endl;
        std::cout<<"7 : laplasjany "<<std::endl;
        std::cin>>wybor;
        switch (wybor)
        {
        case 1: {
                std::cout<<" maska_usredniajaca "<<std::endl;
                auto obraz_po_filtrze_usredniajacym = filtry.splot("maska_sredniajaca",obraz);
                obraz =obraz_po_filtrze_usredniajacym;}
        case 2:{
                std::cout<<" maska_usredniajaca_ze_wzmocnieiem "<<std::endl;
                auto obraz_po_filtrze_usredniajacym_ze_wzmocnieniem = filtry.splot("maska_sredniajaca_ze_wzmocnieniem",obraz);
                obraz =obraz_po_filtrze_usredniajacym_ze_wzmocnieniem;}
        case 3: {
                std::cout<<" gradient_Robertsa "<<std::endl;
                auto obraz_po_gradiencie_Robertsa = filtry.splot("gradient_Robertsa",obraz);
                obraz =obraz_po_gradiencie_Robertsa; }
        case 4: {
                std::cout<<" maska_Prewitta "<<std::endl;
                auto obraz_po_filtrze_prewitta = filtry.splot("maska_Prewitta",obraz);
                obraz =obraz_po_filtrze_prewitta; }
        case 5: {
                std::cout<<" maska_Sobela "<<std::endl;
                auto obraz_po_filtrze_Sobela = filtry.splot("maska_Sobela",obraz);
                obraz =obraz_po_filtrze_Sobela; }
        case 6: {
                std::cout<<" maska_wykrywajaca_narozniki "<<std::endl;
                auto obraz_po_filtrze_wykrywajacym_narozniki = filtry.splot("maska_wykrywajaca_narozniki",obraz);
                obraz =obraz_po_filtrze_wykrywajacym_narozniki; }
        case 7: {
                std::cout<<" laplasjany "<<std::endl;
                auto obraz_po_filtrze_laplasjany = filtry.splot("laplasjany",obraz);
                obraz =obraz_po_filtrze_laplasjany; }
        case 0: {
                std::cout<<"Powracam do poprzedniego menu"<<std::endl;}
       }
    } while (wybor != 0);
}


void run()
{
    Obraz obraz;
    auto manager = prework::FileManager();
    //auto filtry = prework::Filtry();

    int wybor;
    do{
        std::cout<<"Witaj w glownym menu"<<std::endl;
        std::cout<<"NAJLEPSZEGO PROGRAMU GRAFICZNEGO"<<std::endl<<std::endl;
        std::cout<<"MENU:"<<std::endl;
        std::cout<<"1 : WCZYTAJ OBRAZ "<<std::endl;
        std::cout<<"2 : MENU PROSTYCH FILTROW "<<std::endl;
        std::cout<<"3 : MENU TRUDNYCH FILTROW "<<std::endl;
        std::cout<<"4 : ZAPISZ OBRAZ "<<std::endl;
        std::cout<<"5 : WYSWIETL OBRAZ "<<std::endl;
        std::cin>>wybor;
        switch (wybor)
        {
        case 1:{
            wczytaj_obraz();
            break;}
        case 2:{
            menu_numer_dwa(obraz);
            break;}
        case 3:{
            menu_numer_trzy(obraz);
            break;}
        case 4:{
            zapisz_obraz(obraz);
            break;}
        case 5:{
            manager.wyswietl(obraz);
            break;}
        }
    } while (wybor != 0);



    // w celach testowych zahardkowana nazwa pliku
   // std::string fileName{"blackbuck.ascii.ppm"};

    // stworz klase odpowiedzialna za wczytywanie, zapisywanie i wyswietlanie pliku obrazka
    //auto manager = prework::FileManager();

    // stworz klase odpowiedzialna za nakladanie filtrow na obrazek
    //auto filtry = prework::Filtry();

    // wczytaj obrazek
    //auto obraz = manager.loadData(fileName);

    // wyswietl obrazek za pomoca programu display
   // manager.wyswietl(obraz);

    // naloz filtr progowanie
//auto obraz_po_progowaniu = filtry.progowanie(40, obraz);

    // zapisz obraz po progowaniu
  //manager.saveData(obraz_po_progowaniu);

//    // wyswietl obraz po progowaniu
//    manager.wyswietl(obraz_po_progowaniu);

//    // naloz filtr zmiana poziomow
 //auto obraz_po_zmianie_poziomow = filtry.zmiana_poziomow(10, 70, obraz);

//    // zapisz obraz po zmianie poziomow
//    manager.saveData(obraz_po_zmianie_poziomow);

//    // wyswietl obraz po zmianie poziomow
//    manager.wyswietl(obraz_po_zmianie_poziomow);

//    // naloz filtr korekcja gamma
 // auto obraz_po_korekcji_gamma = filtry.kor_gamma(1.5, obraz);

//    //zapisz obraz po korekcji gamma
//    manager.saveData(obraz_po_korekcji_gamma);

//    //wyswietl obraz po korekcji gamma
//    manager.wyswietl(obraz_po_korekcji_gamma);

//    // naloz filtr konturowanie
// auto obraz_po_konturowaniu = filtry.kontur(obraz);

//    //zapisz obraz po konturowaniu
//    manager.saveData(obraz_po_konturowaniu);

//    //wyswietl obraz po konturowaniu
//    manager.wyswietl(obraz_po_konturowaniu);

//    // naloz filtr rozmycie poziome
  //auto obraz_po_rozmyciu_poziomym = filtry.rozmycie_poz(obraz,10);

//    //zapisz obraz po rozmyciu poziomym
//    manager.saveData(obraz_po_rozmyciu_poziomym);

//    //wyswietl obraz po rozmyciu poziomym
//    manager.wyswietl(obraz_po_rozmyciu_poziomym);

 // auto obraz_po_rozmyciu_pionowym = filtry.rozmycie_pio(obraz,10);
//    manager.saveData(obraz_po_rozmyciu_pionowym);
//   manager.wyswietl(obraz_po_rozmyciu_pionowym);

  //auto obraz_po_rozciagnieciu_histogramu = filtry.histogram(obraz);
//    manager.saveData(obraz_po_rozciagnieciu_histogramu);
   //manager.wyswietl(obraz_po_rozciagnieciu_histogramu);

   // auto obraz_po_filtrze_prewitta = filtry.splot("maska_Prewitta",obraz);
   // manager.saveData(obraz_po_filtrze_prewitta);
   // manager.wyswietl(obraz_po_filtrze_prewitta);

}

}  // namespace prework
