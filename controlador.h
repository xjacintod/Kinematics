#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QThread>
#include <QDebug>

class controlador : public QThread
{
    Q_OBJECT
public:
    explicit controlador(QObject *parent = 0);
    void run();

signals:


public slots:

};

#endif // CONTROLADOR_H
