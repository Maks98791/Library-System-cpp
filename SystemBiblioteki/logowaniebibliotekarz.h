#ifndef LOGOWANIEBIBLIOTEKARZ_H
#define LOGOWANIEBIBLIOTEKARZ_H
#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class LogowanieBibliotekarz;
}

class LogowanieBibliotekarz : public QDialog
{
    Q_OBJECT

public:
    explicit LogowanieBibliotekarz(QWidget *parent = 0);
    ~LogowanieBibliotekarz();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::LogowanieBibliotekarz *ui;
};

#endif // LOGOWANIEBIBLIOTEKARZ_H
