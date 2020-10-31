#include "arduino.h"
#include "ui_arduino.h"

#include "joystick.h"

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QDebug>
#include <QString>
#include <QtWidgets>

Arduino::Arduino(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Arduino)
{
    ui->setupUi(this);

    Joystick *joystick;
    //connect(joystick,SIGNAL(Command(QString)),this,SLOT(mySlot(QString)));

    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }

    if(arduino_is_available){
        // open and configure the serialport
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::WriteOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }else{
        // give error message if not available
        QMessageBox::warning(this, "Port Error", "Couldn't find an Arduino!");
    }
//    timer->start(1000);
//    connect(timer,SIGNAL(timeout()),this,SLOT(Timer()));

}

//void Arduino::Timer(){
//    qDebug()<<"Timer executed";
//}

Arduino::~Arduino()
{
    delete ui;
}

void Arduino::Send(QString(Command))
{
    if(arduino->isWritable()){
        arduino->write(Command.toStdString().c_str());
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}

void Arduino::Recieve()
{
    if(arduino->isReadable()){
        Sensors= arduino->readAll();
    }else{
        qDebug() << "Couldn't read from serial!";
    }
}
