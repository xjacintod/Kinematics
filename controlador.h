#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QThread>
#include <QDebug>
#include <QString>
#include <kinematics.h>

class controlador : public QThread
{
    Q_OBJECT
public:
    explicit controlador(QObject *parent = 0);
    Kinematics *kin;
    void run();

    int step;

signals:
    void Data2Write(int direccion, int dato);

public slots:
    void Ejecucion();
    void SendData2Write(int direccion, int dato);

};

#endif // CONTROLADOR_H
