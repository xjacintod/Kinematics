#ifndef SOCKETTCPIP_H
#define SOCKETTCPIP_H

#include <QThread>
#include <QMutex>
#include <QDebug>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>

class socketTCPIP : public QThread
{
    Q_OBJECT
public:
    explicit socketTCPIP(QObject *parent = 0);

    void run();
    QString Connecting();
    bool Stop = false;
    int WriteIndex;
    int WriteData;
    int socketStatus;

signals:
    void ReceivedData(int);

public slots:

};

#endif // SOCKETTCPIP_H
