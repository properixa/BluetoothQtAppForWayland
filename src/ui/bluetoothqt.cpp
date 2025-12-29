#include "bluetoothqt.h"
#include "ui_bluetoothqt.h"
#include<QCloseEvent>

Bluetooth::Bluetooth(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bluetooth)
{
    ui->setupUi(this);
    _device_scanner = new DeviceScanner(this);
    connect(_device_scanner, &DeviceScanner::device_discovered,
            this, &Bluetooth::on_device_discovered);
}

Bluetooth::~Bluetooth()
{
    delete ui;
}

void Bluetooth::closeEvent(QCloseEvent *event) {
    event->accept();
    QApplication::exit();
}

void Bluetooth::on_device_discovered(const QBluetoothDeviceInfo &device) {
    QString device_address = device.address().toString();

    if (_devices_list.contains(device_address)) {
        
    }
}