#ifndef AKTUALNYCZYTELNIK_H
#define AKTUALNYCZYTELNIK_H
#include <iostream>
#include <fstream>

using namespace std;

class AktualnyCzytelnik
{
public:
    string imie;
    string nazwisko;
    string login;
    string haslo;

    AktualnyCzytelnik(string im, string naz, string log, string has);
};

#endif // AKTUALNYCZYTELNIK_H
