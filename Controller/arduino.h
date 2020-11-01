#ifndef ARDUINO_H
#define ARDUINO_H

#include "joystick.h"
#include <QMainWindow>
#include <QSerialPort>

namespace Ui { class Arduino; }


class Arduino : public QMainWindow
{
    Q_OBJECT

public:
    Arduino(QWidget *parent = nullptr);
    ~Arduino();
    void SendRecieve(QString);
    void SendSensorReading(QString);

private:
    Ui::Arduino *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;

    QString Sensors="";
    QString Command;

    Joystick *joy;

public slots:
    void moveSlot(QString);

};
#endif // ARDUINO_H
