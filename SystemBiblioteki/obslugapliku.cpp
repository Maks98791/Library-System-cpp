#include "obslugapliku.h"
#include <iostream>
#include <fstream>

using namespace std;

plik::plik(vector<Czytelnik> &lista)
{
    Czytelnik nowy;

    baza.open("E:\\Projekt\\SystemBiblioteki\\baza.txt");

    if(baza.good() == false)
    {
        qApp->quit();
    }

    int ile = lista.size();

    for(int i=0; i<ile; i++)
    {
        baza >> nowy.imie >> nowy.nazwisko >> nowy.login >> nowy.haslo;
        lista.push_back(nowy);
    }

    baza.close();
}

/*void plik::wprowadz_dane(vector<Czytelnik> &lista, string im, string naz, string log, string has)
{
    Czytelnik kolejny;

    baza.open("E:\\Projekt\\SystemBiblioteki\\baza.txt", ios::app);

    if(baza.good() == false)
    {
        qApp->quit();
    }

    kolejny.imie = im;
    kolejny.nazwisko = naz;
    kolejny.login = log;
    kolejny.haslo = has;

    baza << endl << kolejny.imie << " " << kolejny.nazwisko << " " << kolejny.login << " " << kolejny.haslo;

    lista.push_back(kolejny);

    baza.close();
}*/

