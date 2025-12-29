#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QMainWindow>
#include <QMap>
#include "../utils/device_scanner/device_scanner.h"
#include "../widgets/device_widget/device_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Bluetooth;
}
QT_END_NAMESPACE

class Bluetooth : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bluetooth(QWidget *parent = nullptr);
    ~Bluetooth();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_device_discovered(const QBluetoothDeviceInfo &device);

private:
    Ui::Bluetooth *ui;
    DeviceScanner *_device_scanner;
    QMap<QString, DeviceWidget*> _devices_list;
};

#endif