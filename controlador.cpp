#include "controlador.h"

controlador::controlador(QObject *parent) :
    QThread(parent)
{
    kin = new  Kinematics(this);

    connect(kin, SIGNAL(NewData2Write(int,int)), this, SLOT(SendData2Write(int,int)));

}

void controlador::run()
{
    //while(1)
    //{
    //    kin->MoverLineal(0, 0, 600, 0, 0, 900, 300, step, 2, false);
    //    step=0;

    //}
}

void controlador::Ejecucion()
{
    kin->MoverLineal(0, 0, 800, 0, 0, 661, 300, step, 2, false);
    //kin->MoverLineal(0, 0, 661, 0, 0, 800, 300, step, 3, false);
}

void controlador::SendData2Write(int direccion, int dato)
{
    emit Data2Write(direccion, dato);
}


