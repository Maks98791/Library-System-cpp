#include "logowaniebibliotekarz.h"
#include "bibliotekabibliotekarz.h"
#include "ui_logowaniebibliotekarz.h"
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMessageBox>
#include <QApplication>
#include <QLineEdit>

LogowanieBibliotekarz::LogowanieBibliotekarz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogowanieBibliotekarz)
{
    ui->setupUi(this);
}

LogowanieBibliotekarz::~LogowanieBibliotekarz()
{
    delete ui;
}

void LogowanieBibliotekarz::on_pushButton_clicked()
{

    if(ui->Admin_Login->text() == "admin" && ui->Admin_Haslo->text() == "admin" )
    {
        BibliotekaBibliotekarz *logBibl;
        logBibl = new BibliotekaBibliotekarz();

        hide();
        logBibl->show();
    }
    else
    {
        QMessageBox::information(this, "title2", "bledny login lub haslo");
    }

    //zatwierdzenie loginu i hasla dla bibliotekarza oraz sprawdzenie czy sa poprawne
    //login = admin, haslo = admin
}

void LogowanieBibliotekarz::on_pushButton_2_clicked()
{
    qApp->quit();
}

