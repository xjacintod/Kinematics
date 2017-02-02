#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    nsocket = new ethsocket(this);
    nsocket->start();

    ncontrolador = new controlador(this);
    ncontrolador->start();

    nkin = new Kinematics(this);

    //Puerto ethernet disponible
    QString msne = nsocket->connecting();
    if(msne != "0")
    {
         QMessageBox::StandardButton salida;
         salida = QMessageBox::critical(this, "Mensaje de Error", msne, QMessageBox::Ok);
         if(salida = QMessageBox::Ok)
         {
         }
   }

    connect(ui->pushButtonON,SIGNAL(clicked()), this, SLOT(ServoON()));
    connect(ui->pushButtonHA1, SIGNAL(clicked()), this, SLOT(HomeA1()));
    connect(ui->pushButtonHA2, SIGNAL(clicked()), this, SLOT(HomeA2()));
    connect(ui->pushButtonHA3, SIGNAL(clicked()), this, SLOT(HomeA3()));
    connect(ui->pushButtonStart, SIGNAL(clicked()), this, SLOT(Rutina()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Funcion()));

    connect(nsocket, SIGNAL(ReceivedFromPLC(int,int)), this, SLOT(ProcessData(int,int)));
    connect(ncontrolador, SIGNAL(Data2Write(int,int)), this, SLOT(Write2PLC(int,int)));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::ServoON()
{
    static bool toggleON = true;
    if(toggleON)
    {

        nsocket->sending(5951,1);
        nsocket->sending(5951, 1);
        ui->pushButtonON->setText("SERVO ON");
        toggleON = false;
    }
   else
    {
        nsocket->sending(5951,0);
        nsocket->sending(5951, 0);
        ui->pushButtonON->setText("SERVO OFF");
        toggleON = true;
    }
}

void Dialog::HomeA1()
{
    static bool toggleHA1 = true;
    if(toggleHA1 == true)
    {
         nsocket->sending(100,1);
         nsocket->sending(100, 1);
         toggleHA1 = false;
    }
    else
    {
        nsocket->sending(100,0);
        nsocket->sending(100, 0);
        toggleHA1 = true;
    }
}

void Dialog::HomeA2()
{

    static bool toggleHA2 = true;
    if(toggleHA2 == true)
    {
        nsocket->sending(100,2);
        nsocket->sending(100, 2);
        toggleHA2 = false;
    }
    else
    {
        nsocket->sending(100,0);
        nsocket->sending(100, 0);
        toggleHA2 = true;
    }
}
void Dialog::HomeA3()
{
    static bool toggleHA3 = true;
    if(toggleHA3 == true)
    {
         nsocket->sending(100, 4);
         toggleHA3 = false;
    }
    else
    {
        nsocket->sending(100, 0);
        toggleHA3 = true;
    }

}
void Dialog::Rutina()
{
    nsocket->sending(2, 0);
    nsocket->sending(3, 0);
    nsocket->sending(4,661);
    nsocket->sending(5, 0);
    nsocket->sending(6, 0);
    nsocket->sending(7, 800);
    nsocket->sending(8, 300);
    nsocket->sending(9, 1);
    nsocket->sending(10, 1);
}

void Dialog::ProcessData(int direccion, int dato)
{
    if(direccion == 5) //lee dato de % torque
    {

    }

    if(direccion == 7) //lee dato de corriente
    {

    }

    if(direccion == 10)  //cambia paso de ejecucion
    {
        ncontrolador->step = dato;
        ncontrolador->Ejecucion();

    }
}


void Dialog::Write2PLC(int direccion, int dato)
{

    nsocket->sending(direccion, dato);

}

void Dialog::Funcion()
{

}
