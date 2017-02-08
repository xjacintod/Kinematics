#include "controlador.h"

controlador::controlador(QObject *parent) :
    QThread(parent)
{
}

void controlador::run()
{
       //for(int i=0; i< 10;i++)
       while(1)
       {
           qDebug()<<"No. movimiento: ";
       }
}
