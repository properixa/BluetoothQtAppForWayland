#include <QApplication>
#include <QStyleFactory>
#include "ui/bluetoothqt.h"
#include "widgets/device_widget/device_widget.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    Bluetooth window;
    window.show();

    return app.exec();
}
