#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <QObject>
#include <QDebug>

class Kinematics : public QObject
{
    Q_OBJECT
public:
    static int PulseStep;

    explicit Kinematics(QObject *parent = 0);
    void MoverLineal(int x_inicial,
                     int y_inicial,
                     int z_inicial,
                     int x_final,
                     int y_final,
                     int z_final,
                     int velocidad,
                     int LineaActual,
                     int NumLinea,
                     bool UltimaLinea);

signals:
    void NewData2Write(int direccion, int dato);

public slots:


};

#endif // KINEMATICS_H
