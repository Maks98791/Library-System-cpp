#ifndef BIBLIOTEKACZYTELNIK_H
#define BIBLIOTEKACZYTELNIK_H
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMessageBox>
#include <QApplication>
#include <QMainWindow>
#include <vector>

namespace Ui {
class BibliotekaCzytelnik;
}

class BibliotekaCzytelnik : public QMainWindow
{
    Q_OBJECT

public:
    explicit BibliotekaCzytelnik(QWidget *parent = 0);

    ~BibliotekaCzytelnik();

private slots:
    void on_actionPrzegl_daj_ksi_ki_triggered();

    void on_actionWyloguj_2_triggered();

    void on_actionDane_czytelnika_triggered();

    void on_actionWypo_yczone_ksi_ki_triggered();

    void on_actionO_programie_triggered();

private:
    Ui::BibliotekaCzytelnik *ui;
};

#endif // BIBLIOTEKACZYTELNIK_H
