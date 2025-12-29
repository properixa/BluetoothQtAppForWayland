#ifndef DEVICE_SCANNER_H
#define DEVICE_SCANNER_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>

class DeviceScanner : public QObject {
    Q_OBJECT

public:
    explicit DeviceScanner(QObject *parent = nullptr);
    ~DeviceScanner();
    void start_device_discover();

private slots:
    void on_device_discovered(const QBluetoothDeviceInfo &device);

private:
    QBluetoothDeviceDiscoveryAgent *agent;
};

#endif