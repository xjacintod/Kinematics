#include "ethsocket.h"

ethsocket::ethsocket(QObject *parent) :
    QThread(parent)
{
}

QString ethsocket::connecting()
{
    struct sockaddr_in server;

        //Create socket
        socketStatus = socket(AF_INET , SOCK_STREAM , 0);
        if (socketStatus == -1)
        {
            QString msn = QString("Error: ") +  QString("No se pudo crear el socket");
            return msn;
        }
        server.sin_addr.s_addr = inet_addr("192.168.3.250");   //dirección IP del dispositivo pasivo
        server.sin_family = AF_INET;
        server.sin_port = htons( 80 );  //puerto de comunicación

        //Connect to remote server
        if (::connect(socketStatus , (struct sockaddr *)&server , sizeof(server)) < 0)
        {
            QString msn = QString("Error: ") + QString("Ethernet connection failed");
            return msn;
        }
        QString msn = QString("0");
        return msn;

}

void ethsocket::sending(int direccion, int dato)
{
    u_int16_t windex;
    u_int16_t wdata;
    u_int32_t dw = 0;

    windex = direccion;
    wdata = dato;

    dw = dw | windex*65536;
    dw = dw | wdata;

    if(send(socketStatus, &dw,4 ,0) < 0)
    {
        qDebug()<< "Eth: fallo al enviar";
    }
}

void ethsocket::run()
{
    while(1)
    {
        u_int32_t dr = 0;
        if(recv(socketStatus, &dr, 4, 0) < 0)
        {
            qDebug()<< "Eth: fallo al recibir";
            break;
        }
        else{

            u_int16_t rindex;
            u_int16_t rdata;
            rindex = rindex | dr/65536;
            rdata = rdata | dr;
            qDebug()<< "dir recibido: "<< rindex;
            qDebug()<< "dato recibido:  " << rdata;
        }

    }
}
