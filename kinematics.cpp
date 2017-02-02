#include "kinematics.h"

Kinematics::Kinematics(QObject *parent) :
    QObject(parent)
{
}


void Kinematics::MoverLineal(int x_inicial,
                             int y_inicial,
                             int z_inicial,
                             int x_final,
                             int y_final,
                             int z_final,
                             int velocidad,
                             int LineaActual,
                             int NumLinea,
                             bool UltimaLinea)
{
    if (LineaActual== NumLinea)
    {
        emit NewData2Write(2, x_inicial);
        emit NewData2Write(3, y_inicial);
        emit NewData2Write(4, z_inicial);
        emit NewData2Write(5, x_final);
        emit NewData2Write(6, y_final);
        emit NewData2Write(7, z_final);
        emit NewData2Write(8, velocidad);
        emit NewData2Write(9, 1);//Tipo de Trayectoria: 1 Lineal
    }

}
