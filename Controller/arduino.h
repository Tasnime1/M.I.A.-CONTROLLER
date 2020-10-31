#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>

#include <QMainWindow>

#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Arduino; }
QT_END_NAMESPACE

class Arduino : public QMainWindow
{
    Q_OBJECT

public:
    Arduino(QWidget *parent = nullptr);
    ~Arduino();
    void Send(QString);
    void Recieve();

public slots:
//    void Timer();

private:
    Ui::Arduino *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;

    QTimer *timer;

    QString Sensors;
};
#endif // ARDUINO_H
