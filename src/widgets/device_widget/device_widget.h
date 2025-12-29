#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <QWidget>
#include <QBluetoothDeviceInfo>
#include <QBluetoothAddress>

class QVBoxLayout;
class QLabel;

class DeviceWidget : public QWidget {
    Q_OBJECT

public: 
    explicit DeviceWidget(const QBluetoothDeviceInfo &device_info, QWidget *parent = nullptr);
    ~DeviceWidget();

    void update_info(const QBluetoothDeviceInfo &device);

private:
    void setupUI();

    QBluetoothDeviceInfo _device_info;
    QVBoxLayout *_main_layout;
    QLabel *_name_label;
};

#endif