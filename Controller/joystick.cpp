#include "joystick.h"
#include "arduino.h"

#include <QDebug>

Joystick::Joystick(QObject *parent) : QObject(parent)
{

    SDL_Init(SDL_INIT_GAMECONTROLLER);
    Joy = nullptr;

    if(SDL_NumJoysticks()<1)
        qDebug() << "Error! No joystick connected!";
    else
        Joy = SDL_JoystickOpen(0);

    qDebug()<<"Controller name: "<< SDL_JoystickName(Joy);
    qDebug()<<"Number of axes: "<< SDL_JoystickNumAxes(Joy);
    qDebug()<<"Number of Buttons: "<< SDL_JoystickNumButtons(Joy);
    qDebug()<<"Number of Balls: "<< SDL_JoystickNumBalls(Joy);


    timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Joystickk()));
    timer->start(100);
}

void Joystick:: Joystickk(){

    //qDebug()<<"Im here";
    emit move(movement);

    SDL_PollEvent(&event);
    if(SDL_JoystickGetButton(Joy,0)){qDebug()<<"You pressed button 1";
    movement="F";}
    if(SDL_JoystickGetButton(Joy,1)){qDebug()<<"You pressed button 2";
    movement="R";}
    if(SDL_JoystickGetButton(Joy,2)){qDebug()<<"You pressed button 3";
    movement="B";}
    if(SDL_JoystickGetButton(Joy,3)){qDebug()<<"You pressed button 4";
    movement="L";}
    if(SDL_JoystickGetButton(Joy,4)){qDebug()<<"You pressed button 5";
    movement="Y";}
    if(SDL_JoystickGetButton(Joy,5)){qDebug()<<"You pressed button 6";
    movement="X";}
    if(SDL_JoystickGetButton(Joy,6)){qDebug()<<"You pressed button 7";
    movement="D";}
    if(SDL_JoystickGetButton(Joy,7)){qDebug()<<"You pressed button 8";
    movement="U";}
    if(SDL_JoystickGetButton(Joy,8)){qDebug()<<"You pressed button 9";} //9 on joystick
    if(SDL_JoystickGetButton(Joy,9)){qDebug()<<"You pressed button 10";} //10 on joystick

}

