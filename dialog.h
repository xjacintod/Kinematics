#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <ethsocket.h>
#include <controlador.h>
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
    ethsocket *nsocket;
    controlador *ncontrolador;
    Kinematics *nkin;

private:
    Ui::Dialog *ui;

public slots:
    void ServoON();
    void HomeA1();
    void HomeA2();
    void HomeA3();
    void Rutina();
    void Funcion();

    void ProcessData(int direccion, int dato);
    void Write2PLC(int direccion, int dato);

};

#endif // DIALOG_H
