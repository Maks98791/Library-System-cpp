#include "logowanieczytelnik.h"
#include "ui_logowanieczytelnik.h"
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMessageBox>
#include <QApplication>
#include <vector>
#include "czytelnik.h"
#include "logowanieczytelnik1.h"
#include "logowanieczytelnik2.h"

//okno wyboru pytajace czy czytelnik posiada konto czy nie

LogowanieCzytelnik::LogowanieCzytelnik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogowanieCzytelnik)
{
    ui->setupUi(this);
}

LogowanieCzytelnik::~LogowanieCzytelnik()
{
    delete ui;
}

void LogowanieCzytelnik::on_pushButton_clicked()
{
    LogowanieCzytelnik1 logow1;
    hide();
    logow1.setModal(true); //otworzenie okna logowania dla czytelnika posiadajacego konto
    logow1.exec();
}

void LogowanieCzytelnik::on_pushButton_2_clicked()
{
    LogowanieCzytelnik2 logow2;
    hide();
    logow2.setModal(true); //otworzenie okna logowania dla czytelnika NIE posiadajacego konta
    logow2.exec();
}
