#include <QApplication>
#include <QStyleFactory>
#include "bluetoothqt.h"
#include "device/device.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    Bluetooth window;
    window.show();

    return app.exec();
}
