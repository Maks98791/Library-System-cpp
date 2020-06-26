#include "bazaksiazek.h"
#include "ksiazka.h"
#include <iostream>
#include "przegladajksiazki.h"
#include "ui_przegladajksiazki.h"
#include <QWidget>

using namespace std;

BazaKsiazek::BazaKsiazek(vector <Ksiazka> &ksiazki)
{
    Ksiazka nowa;

    plikKsiazki.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\plikKsiazki.txt");

    if(plikKsiazki.good() == false)
    {
        qApp->quit();
    }

    int elementy = ksiazki.size();

    for(int i=0; i < elementy; i++)
    {
        plikKsiazki >> nowa.tytul >> nowa.autor >> nowa.status >> nowa.data_wyp >> nowa.data_zwrotu;
        ksiazki.push_back(nowa);
    }

    plikKsiazki.close();
}

/*
Ksiazka BazaKsiazek::przeszukaj(vector <Ksiazka> &ksiazki)
{
    vector <Ksiazka>::iterator it;

    for(it = ksiazki.begin(); it != ksiazki.end(); it++)
    {
        continue;
    }
    return ksiazki[5];
}*/
