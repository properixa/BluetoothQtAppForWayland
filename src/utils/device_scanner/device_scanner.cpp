#include "device_scanner.h"
#include "../../ui/bluetoothqt.h"
#include <QTimer>

DeviceScanner::DeviceScanner(QObject *parent) : QObject(parent) {
    _agent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(_agent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &DeviceScanner::on_device_discovered);

    connect(_agent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &DeviceScanner::on_discover_finished);

    connect(_agent, &QBluetoothDeviceDiscoveryAgent::errorOccurred,
            this, &DeviceScanner::on_error_occurred);
}

DeviceScanner::~DeviceScanner() {
    stop_device_discover();
}

void DeviceScanner::start_device_discover() {
    if (!_is_scanning) {
        _agent->start();
        _is_scanning = true;
        emit discover_started();
        qDebug() << "Bluetooth devices discover started";
    }
}

void DeviceScanner::stop_device_discover() {
    if (_is_scanning) {
        _agent->stop();
        _is_scanning = false;
        qDebug() << "Bluetooth devices discover stopped";
    }
}

bool DeviceScanner::is_scanning() const {
    return _is_scanning;
}

void DeviceScanner::on_device_discovered(const QBluetoothDeviceInfo &device) {
    if (device.serviceClasses() == QBluetoothDeviceInfo::NoService) {
        qDebug() << "Skipped device with no service (name: " << device.name() << ")";
        return;
    }
    emit device_discovered(device);
    qDebug() << "DISCOVERED NEW DEVICE";
}

void DeviceScanner::on_discover_finished() {
    _is_scanning = false;
    emit discover_stopped();
    qDebug() << "DISCOVER FINISHED";
}

void DeviceScanner::on_error_occurred(QBluetoothDeviceDiscoveryAgent::Error error) {
    QString error_msg;
    
    switch (error) {
        case QBluetoothDeviceDiscoveryAgent::PoweredOffError:
            error_msg = "Bluetooth adapter is powered off";
            break;
        case QBluetoothDeviceDiscoveryAgent::InputOutputError:
            error_msg = "Bluetooth I/O error";
            break;
        case QBluetoothDeviceDiscoveryAgent::InvalidBluetoothAdapterError:
            error_msg = "Invalid Bluetooth adapter";
            break;
        case QBluetoothDeviceDiscoveryAgent::UnsupportedPlatformError:
            error_msg = "Platform not supported";
            break;
        case QBluetoothDeviceDiscoveryAgent::UnsupportedDiscoveryMethod:
            error_msg = "Discovery method not supported";
            break;
        default:
            error_msg = "Unknown Bluetooth error";
    }
    
    qWarning() << "Bluetooth error:" << error_msg;
    emit error_occurred(error_msg);
}