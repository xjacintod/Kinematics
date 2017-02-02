#ifndef ETHSOCKET_H
#define ETHSOCKET_H

#include <QThread>
#include <QDebug>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <vector>

class ethsocket : public QThread
{
    Q_OBJECT
public:
    explicit ethsocket(QObject *parent = 0);
    void run();
    QString connecting();
    void sending(int direccion, int dato);
    int socketStatus;

signals:
    void ReceivedFromPLC(int direccion, int dato);

public slots:

};

#endif // ETHSOCKET_H
