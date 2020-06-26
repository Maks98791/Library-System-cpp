#ifndef BIBLIOTEKABIBLIOTEKARZ_H
#define BIBLIOTEKABIBLIOTEKARZ_H

#include <QMainWindow>

namespace Ui {
class BibliotekaBibliotekarz;
}

class BibliotekaBibliotekarz : public QMainWindow
{
    Q_OBJECT

public:
    explicit BibliotekaBibliotekarz(QWidget *parent = 0);
    ~BibliotekaBibliotekarz();

private slots:
    void on_actionWyloguj_triggered();

    void on_actionPrzegl_daj_czytelnik_w_triggered();

    void on_actionPrzegl_daj_ksi_ki_2_triggered();

    void on_actionO_programie_triggered();

private:
    Ui::BibliotekaBibliotekarz *ui;
};

#endif // BIBLIOTEKABIBLIOTEKARZ_H
