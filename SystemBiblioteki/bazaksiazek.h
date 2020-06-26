#ifndef BAZAKSIAZEK_H
#define BAZAKSIAZEK_H
#include <vector>
#include <fstream>
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMessageBox>
#include <QApplication>
#include "ksiazka.h"

using namespace std;

class BazaKsiazek
{
    fstream plikKsiazki;

public:
    BazaKsiazek(vector<Ksiazka> &ksiazki);
    //Ksiazka przeszukaj(vector <Ksiazka> &ksiazki);
};

#endif // BAZAKSIAZEK_H
