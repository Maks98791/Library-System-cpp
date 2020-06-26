#include "wyboruzytkownika.h"
#include <QApplication>
#include <iostream>
#include "logowanieczytelnik.h"
#include "logowaniebibliotekarz.h"
#include "logowanieczytelnik1.h"
#include "logowanieczytelnik2.h"
#include "czytelnik.h"
#include "uzytkownik.h"
#include "obslugapliku.h"
#include "bazaksiazek.h"
#include "ksiazka.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector <Czytelnik> osoby;
    vector <Ksiazka> ksiazki;

    BazaKsiazek ksiazka(ksiazki);

    QApplication a(argc, argv);

    WyborUzytkownika w;

    plik d(osoby);

    w.show();

    return a.exec();
}
