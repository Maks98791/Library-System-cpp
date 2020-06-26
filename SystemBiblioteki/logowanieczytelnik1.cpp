#include "logowanieczytelnik1.h"
#include "ui_logowanieczytelnik1.h"
#include "czytelnik.h"
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMessageBox>
#include <QApplication>
#include "logowanieczytelnik.h"
#include "czytelnik.h"
#include <fstream>
#include "logowanieczytelnik1.h"
#include "bibliotekaczytelnik.h"
#include "aktualnyczytelnik.h"
#include "bibliotekaczytelnik.h"

//okno logowania dla czytelnika posiadajacego konto

LogowanieCzytelnik1::LogowanieCzytelnik1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogowanieCzytelnik1)
{
    ui->setupUi(this);
}

LogowanieCzytelnik1::~LogowanieCzytelnik1()
{
    delete ui;
}

void LogowanieCzytelnik1::on_pushButton_clicked()
{
    BibliotekaCzytelnik *oknoCzytelnika;
    oknoCzytelnika = new BibliotekaCzytelnik();
    fstream osoba;
    string im, naz, log, has;

    osoba.open("E:\\Projekt\\build-SystemBiblioteki-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\baza.txt");

    if(osoba.good()==false)
    {
        qApp->quit();
    }

    while(!osoba.eof())
    {
        osoba >> im >> naz >> log >> has;

        if(ui->czyt_login->text().toStdString() == log && ui->czyt_haslo->text().toStdString() == has)
        {
            AktualnyCzytelnik(im, naz, log, has); //zapisane danych zalogowanego uzytkownika w pliku
            hide();
            oknoCzytelnika->show(); //zalogowanie sie czytelnika posiadajacego konto do bazy
            osoba.close();
        }
    }

    if(ui->czyt_login->text().toStdString() != log && ui->czyt_haslo->text().toStdString() != has)
    {
        osoba.close();
        QMessageBox::information(this, "Logowanie", "Błędny login lub hasło, sprawdz czy na"
                                                    "pewno posiadasz konto");
        LogowanieCzytelnik logowCzyt;
        hide();
        logowCzyt.setModal(true); //ponowne otworzenie konta po podanych blednym loginie lub haśle
        logowCzyt.exec();
    }
}

void LogowanieCzytelnik1::on_pushButton_2_clicked()
{
    qApp->quit();
}
