#include "sockettcpip.h"

socketTCPIP::socketTCPIP(QObject *parent) :
    QThread(parent)
{
}

void socketTCPIP::run()
{
    u_int16_t arrow = 3;
    u_int16_t windex;
    u_int16_t wdata;

    u_int16_t rindex;
    u_int16_t rdata;

    //for(int i = 0; i < 10; i++)
    while(1)
    {
        u_int32_t dato = 0;
        QMutex mutexStop;
        mutexStop.lock();
        if(this->Stop)
        {
            mutexStop.unlock();
            break;
        }

        windex = WriteIndex;
        wdata = WriteData;

        mutexStop.unlock();

        qDebug()<<"index: "<<windex;
        qDebug()<<"data: "<<wdata;
        //Send a data to the server

        dato = dato | windex*65536;
        dato = dato | wdata;
        qDebug()<< dato;

        if( send(socketStatus, &dato, 4, 0) < 0)
        {
            qDebug()<<"Eth: fallo al enviar";
            break;
        }
        //Recieve a reply from  the server
        //if(recv(socketStatus, rindex, 2000, 0) < 0)
        //{
        //    qDebug()<<"recv failed";
        //    break;
        //}
        //qDebug()<< rindex;
    }
}

QString socketTCPIP::Connecting()
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
