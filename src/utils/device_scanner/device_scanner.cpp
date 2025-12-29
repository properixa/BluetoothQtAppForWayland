#include "device_scanner.h"
#include <QTimer>

DeviceScanner::DeviceScanner(QObject *parent) : QObject(parent) {
    agent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(agent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &DeviceScanner::on_device_discovered);
}

DeviceScanner::~DeviceScanner() {
    if (agent && agent->isActive()) {
        agent->stop();
    }
}

void DeviceScanner::on_device_discovered(const QBluetoothDeviceInfo &device) {
    qDebug() << "Device with name " << device.name() << " discovered";
}

void DeviceScanner::start_device_discover() {
    if (agent->isActive()) {
        agent->stop();
    }

    QTimer::singleShot(10000, agent, &QBluetoothDeviceDiscoveryAgent::stop);

    agent->start();
    qDebug() << "DEVICE DISCOVERY STARTED";
    
}

