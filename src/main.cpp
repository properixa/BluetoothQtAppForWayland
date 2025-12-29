#include <QApplication>
#include <QStyleFactory>
#include "ui/bluetoothqt.h"
#include "utils/device_scanner/device_scanner.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    Bluetooth window;
    window.show();

    return app.exec();
}
