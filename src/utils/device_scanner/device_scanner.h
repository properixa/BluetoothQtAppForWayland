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
    void stop_device_discover();
    bool is_scanning() const;

signals:
    void device_discovered(const QBluetoothDeviceInfo &device);
    void discover_started();
    void discover_stopped();
    void error_occurred(const QString &error_message);

private slots:
    void on_device_discovered(const QBluetoothDeviceInfo &device);
    void on_discover_finished();
    void on_error_occurred(QBluetoothDeviceDiscoveryAgent::Error error);

private:
    QBluetoothDeviceDiscoveryAgent *_agent;
    bool _is_scanning = false;
};

#endif