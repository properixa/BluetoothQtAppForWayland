#include "bluetoothqt.h"
#include "ui_bluetoothqt.h"

Bluetooth::Bluetooth(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bluetooth)
{
    ui->setupUi(this);
}

Bluetooth::~Bluetooth()
{
    delete ui;
}