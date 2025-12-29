#include "bluetoothqt.h"
#include "ui_bluetoothqt.h"
#include<QCloseEvent>

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

void Bluetooth::closeEvent(QCloseEvent *event) {
    event->accept();
    QApplication::exit();
}