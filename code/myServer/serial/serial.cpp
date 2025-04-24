#include "serial.h"
#include "ui_serial.h"

serial::serial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serial)
{
    ui->setupUi(this);
}

serial::~serial()
{
    delete ui;
}
