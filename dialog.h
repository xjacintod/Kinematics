#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <sockettcpip.h>
#include <controlador.h>
#include <QDialog>
#include <QString>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
     socketTCPIP *msocket;
     controlador *ncontrolador;

private:
    Ui::Dialog *ui;

public slots:
    void datoRecibido(int);
    void ServoON();
    void HomeA1();
    void HomeA2();
    void HomeA3();
    void PosSegura();
    void Rutina();
};

#endif // DIALOG_H
