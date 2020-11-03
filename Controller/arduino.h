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
    //void Recieve(QString);
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
    QString CommandP="HV";

    Joystick *joy;
    QTimer *myTimer;

public slots:
    void movementSlot(QString);
    void RecieveSlot();

};
#endif // ARDUINO_H
