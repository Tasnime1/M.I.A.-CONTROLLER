#include "arduino.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Arduino w;
    w.setWindowTitle("Motor Control");
    w.show();
    return a.exec();
}
