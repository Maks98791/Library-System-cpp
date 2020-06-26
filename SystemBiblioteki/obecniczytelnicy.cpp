#include "obecniczytelnicy.h"
#include "ui_obecniczytelnicy.h"
#include <fstream>
#include <QListWidget>
#include "bibliotekabibliotekarz.h"

using namespace std;

ObecniCzytelnicy::ObecniCzytelnicy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObecniCzytelnicy)
{
    ui->setupUi(this);

    fstream baza_osob;

    baza_osob.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\baza.txt", ios::in);

    if(baza_osob.good() == false)
    {
        qApp->quit();
    }

    string imieCzyt, nazwiskoCzyt, a, b;

    while(!baza_osob.eof())
    {
        baza_osob >> imieCzyt >> nazwiskoCzyt >> a >> b;

        QString qimieCzyt = QString::fromStdString(imieCzyt);
        QString qnazwiskoCzyt = QString::fromStdString(nazwiskoCzyt);

        ui->listaObecnychCzytelnikow->addItem(qimieCzyt + " " + qnazwiskoCzyt);
    }

    baza_osob.close();
}

ObecniCzytelnicy::~ObecniCzytelnicy()
{
    delete ui;
}

void ObecniCzytelnicy::on_pushButton_clicked()
{
    hide();
}
