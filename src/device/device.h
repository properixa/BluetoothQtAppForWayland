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

private:
    void setupUI();

    QBluetoothDeviceInfo device_info;
    QVBoxLayout *main_layout;
    QLabel *name_label;
};

#endif