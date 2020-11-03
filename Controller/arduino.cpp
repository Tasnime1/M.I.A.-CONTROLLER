#include "arduino.h"
#include "ui_arduino.h"

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

    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

    joy = new Joystick;

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




//    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
//        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
//            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
//                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
//                    arduino_port_name = serialPortInfo.portName();
//                    qDebug()<<serialPortInfo.portName();
//                    arduino_is_available = true;
//                }
//            }
//        }
//    }

//    if(arduino_is_available){
        // open and configure the serialport
        arduino->setPortName("COM6");
        arduino->open(QSerialPort::WriteOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);

//    }else{
//        // give error message if not available
//        QMessageBox::warning(this, "Port Error", "Couldn't find an Arduino!");


        connect(joy,SIGNAL(move(QString)),this,SLOT(movementSlot(QString)));

        myTimer= new QTimer();
        connect(myTimer,SIGNAL(timeout()),this,SLOT(RecieveSlot()));
        myTimer->start(100);

}
//}

Arduino::~Arduino()
{
    delete ui;

}

void Arduino::RecieveSlot()
{

    if(arduino->isReadable())
    {
        Sensors=arduino->readAll();
        qDebug()<<Sensors; //to check data is correct
        ui->label_4->setText(Sensors);
    }
//    else
//    {
//        qDebug()<<"Can't read data from Serial Port(Arduino)!";
//    }

}




void Arduino::movementSlot(QString(movement)){

    Command= movement + "H"+ ui->lineEdit2->text() +"V"+ ui->lineEdit1->text();

    if(CommandP!=Command){
        CommandP=Command;

    qDebug()<<"NEW COMMAND->"+Command;
    if(arduino->isWritable()){
        arduino->write(Command.toStdString().c_str());
        qDebug()<<"Sending to Arduino";
    }else{
        qDebug() << "Couldn't write to serial!";
    }
                          }
}
