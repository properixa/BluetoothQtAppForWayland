#include "bluetoothqt.h"
#include "ui_bluetoothqt.h"
#include<QCloseEvent>

Bluetooth::Bluetooth(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bluetooth)
{
    ui->setupUi(this);
    setup_scroll_window();

    _device_scanner = new DeviceScanner(this);
    connect(_device_scanner, &DeviceScanner::device_discovered,
            this, &Bluetooth::on_device_discovered);
    _device_scanner->start_device_discover();
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

    DeviceWidget *new_device = new DeviceWidget(device); 

    _devices_list.insert(device_address, new_device);
    _scroll_layout->addWidget(new_device);
}

void Bluetooth::setup_scroll_window() {
    QWidget *container = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(container);
    layout->setAlignment(Qt::AlignTop);
    layout->setSpacing(5);
    layout->setContentsMargins(1, 1, 1, 1);

    ui->ScrollDevices->setWidget(container);
    ui->ScrollDevices->setWidgetResizable(true);

    _scroll_layout = layout;
}

void Bluetooth::setup_already_discovered_devices() {
    
}
