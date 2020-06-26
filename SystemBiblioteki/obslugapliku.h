#ifndef OBSLUGAPLIKU_H
#define OBSLUGAPLIKU_H
#include <fstream>
#include <vector>
#include "czytelnik.h"
#include "logowanieczytelnik2.h"

using namespace std;

class plik
{
public:
    fstream baza;
    vector<Czytelnik> lista;
    plik(vector<Czytelnik> &lista);
};

#endif // OBSLUGAPLIKU_H
