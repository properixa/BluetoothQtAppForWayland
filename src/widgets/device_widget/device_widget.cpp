#include "device_widget.h"
#include <QBluetoothDeviceInfo>
#include <QVBoxLayout>
#include <QLabel>

DeviceWidget::DeviceWidget(const QBluetoothDeviceInfo &info, QWidget *parent) : QWidget(parent), _device_info(info) {
    setupUI();
}

DeviceWidget::~DeviceWidget() {}

void DeviceWidget::setupUI() {
    main_layout = new QVBoxLayout(this);
    QString display_name = _device_info->name();
    if (display_name.isEmpty()) {
        display_name = "Unknown device";
    }
    name_label = new QLabel(display_name);
}

void DeviceWidget::update_info(const QBluetoothDeviceInfo &device) {
    
}