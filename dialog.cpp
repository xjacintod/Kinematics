#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    msocket = new socketTCPIP(this);
    ncontrolador = new controlador(this);

    connect(msocket, SIGNAL(ReceivedData(int)), this, SLOT(datoRecibido(int)));
    connect(ui->pushButtonON,SIGNAL(clicked()), this, SLOT(ServoON()));
    connect(ui->pushButtonHomeA1, SIGNAL(clicked()), this, SLOT(HomeA1()));
    connect(ui->pushButtonHomeA2, SIGNAL(clicked()), this, SLOT(HomeA2()));
    connect(ui->pushButtonHomeA3, SIGNAL(clicked()), this, SLOT(HomeA3()));
    connect(ui->pushButtonRutina, SIGNAL(clicked()), this, SLOT(Rutina()));

    //Puerto ethernet disponible
   QString msne = msocket->Connecting();
   if(msne != "0")
   {
       QMessageBox::StandardButton salida;
       salida = QMessageBox::critical(this, "Mensaje de Error", msne, QMessageBox::Ok);
       if(salida = QMessageBox::Ok)
       {
       }
   }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::datoRecibido(int n)
{
    ui->label->setText(QString::number(n));
}

void Dialog::ServoON()
{  
    static bool toggleON = true;
    if(toggleON)
    {
        msocket->WriteData = 1;
        msocket->WriteIndex = 5951;
        msocket->start();

        ui->pushButtonON->setText("SERVO ON");
        toggleON = false;
    }
   else
    {
        msocket->WriteData = 0;
        msocket->WriteIndex = 5951;
        msocket->start();

        ui->pushButtonON->setText("SERVO OFF");
        toggleON = true;
    }
}

void Dialog::HomeA1()
{
    static bool toggleHA1 = true;
    if(toggleHA1 == true)
    {    msocket->WriteData = 1;
         msocket->WriteIndex = 100;
         toggleHA1 = false;
    }
    else
    {
        msocket->WriteData = 0;
        msocket->WriteIndex = 100;
        toggleHA1 = true;
    }

}
void Dialog::HomeA2()
{
    static bool toggleHA2 = true;
    if(toggleHA2 == true)
    {    msocket->WriteData = 2;
         msocket->WriteIndex = 100;
         toggleHA2 = false;
    }
    else
    {
        msocket->WriteData = 0;
        msocket->WriteIndex = 100;
        toggleHA2 = true;
    }
}
void Dialog::HomeA3()
{
    static bool toggleHA3 = true;
    if(toggleHA3 == true)
    {    msocket->WriteData = 4;
         msocket->WriteIndex = 100;
         toggleHA3 = false;
    }
    else
    {
        msocket->WriteData = 0;
        msocket->WriteIndex = 100;
        toggleHA3 = true;
    }

}

void Dialog::Rutina()
{
   ncontrolador->run();
}

void Dialog::PosSegura()
{

}
