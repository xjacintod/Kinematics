#include "controlador.h"

controlador::controlador(QObject *parent) :
    QThread(parent)
{
}

void controlador::run()
{

    while(1)
    {
        //qDebug()<< "controlador";
    }
}
