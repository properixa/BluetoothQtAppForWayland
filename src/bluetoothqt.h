#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QMainWindow>

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

private:
    Ui::Bluetooth *ui;
};

#endif