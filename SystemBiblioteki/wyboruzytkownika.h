#ifndef WYBORUZYTKOWNIKA_H
#define WYBORUZYTKOWNIKA_H
#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class WyborUzytkownika;
}

class WyborUzytkownika : public QDialog
{
    Q_OBJECT

public:
    explicit WyborUzytkownika(QWidget *parent = 0);
    ~WyborUzytkownika();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::WyborUzytkownika *ui;
};

#endif // WYBORUZYTKOWNIKA_H
