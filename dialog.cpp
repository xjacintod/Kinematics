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
        ui->pushButtonON->setText("SERVO ON");
        toggleON = false;
    }
   else
    {
        nsocket->sending(5951,0);
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
         toggleHA1 = false;
    }
    else
    {
        nsocket->sending(100,0);
        toggleHA1 = true;
    }
}

void Dialog::HomeA2()
{

    static bool toggleHA2 = true;
    if(toggleHA2 == true)
    {
         nsocket->sending(100,2);
         toggleHA2 = false;
    }
    else
    {
        nsocket->sending(100,0);
        toggleHA2 = true;
    }
}
void Dialog::HomeA3()
{
    static bool toggleHA3 = true;
    if(toggleHA3 == true)
    {
         nsocket->sending(100,4);
         toggleHA3 = false;
    }
    else
    {
        nsocket->sending(100,0);
        toggleHA3 = true;
    }

}
void Dialog::Rutina()
{
    nsocket->sending(2, 0);
    nsocket->sending(3, 0);
    nsocket->sending(4, 634);
    nsocket->sending(5, 0);
    nsocket->sending(6, 0);
    nsocket->sending(7, 900);
    nsocket->sending(8,1);

}
