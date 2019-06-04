#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"
#include "gpio.h"
#include <QTimer>

class Widget : public QWidget, private Ui::Widget
{
    Q_OBJECT
    QTimer *clock;

public:
    explicit Widget(QWidget *parent = 0);
private:
       Ui::Widget *ui;
private slots:
    void callup();
};

#endif // WIDGET_H
