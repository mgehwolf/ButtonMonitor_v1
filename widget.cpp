#include "widget.h"
#include "gpio.h"
#include <wiringPi.h>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    wiringPiSetupGpio(); //Brodcom-Nummern
    pinMode(B1, INPUT);
    pinMode(B2, INPUT);
    pinMode(B3, INPUT);

    clock = new QTimer(this);
    connect(clock, SIGNAL(timeout()), SLOT(callup()));
    clock->start(100);

}

void Widget::callup(){
    QLabel *blockarray[3] = {ui->Button1, ui->Button2, ui->Button3};
    for (int x = 0; x < 3; x++){
        bool state = digitalRead(pinarray[x]);

        if (state == 1) blockarray[x]->setStyleSheet("background-color:red");
        else blockarray[x]->setStyleSheet("background-color:black");
    }
}
