#include "joystick.h"
#include <QDebug>
#include <SDL.h>

#include <QTimer>

Joystick::Joystick()
{
    if(SDL_NumJoysticks()<1)
        qDebug() << "Error! No joystick connected!";
    else
        joystick = SDL_JoystickOpen(0); //check if desired joystick is 0!!


    qDebug()<<"Controller name: "<< SDL_JoystickName(joystick);
    qDebug()<<"Number of axes: "<< SDL_JoystickNumAxes(joystick);
    qDebug()<<"Number of Buttons: "<< SDL_JoystickNumButtons(joystick);
    qDebug()<<"Number of Balls: "<< SDL_JoystickNumBalls(joystick);

    connect(timer2,SIGNAL(timeout()),this,SLOT(Timer2()));
    timer2->start(1000);
}

void Joystick::Timer2(){
    qDebug()<<"Timer executed";
    JoystickButtons();
}


void Joystick::JoystickButtons()
{
    qDebug()<<"I'm a button";

}
