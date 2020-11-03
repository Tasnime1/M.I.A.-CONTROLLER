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


    emit move(movement);

    SDL_PollEvent(&event);

    if(SDL_JoystickGetButton(Joy,4)){qDebug()<<"You pressed Forward";
    movement="F";}

    if(SDL_JoystickGetButton(Joy,5)){qDebug()<<"You pressed Right";
    movement="R";}

    if(SDL_JoystickGetButton(Joy,6)){qDebug()<<"You pressed Back";
    movement="B";}

    if(SDL_JoystickGetButton(Joy,7)){qDebug()<<"You pressed Left";
    movement="L";}

    if(SDL_JoystickGetButton(Joy,12)){qDebug()<<"You pressed TRIANGLE";
    movement="U";
    }

    if(SDL_JoystickGetButton(Joy,13)){qDebug()<<"You pressed CIRCLE";
    movement="X";
    }

    if(SDL_JoystickGetButton(Joy,14)){qDebug()<<"You pressed X";
    movement="D";
    }

    if(SDL_JoystickGetButton(Joy,15)){qDebug()<<"You pressed SQUARE";
    movement="Y";
    }

    //CONFIGURE A BUTTON TO STOP!!
    if(SDL_JoystickGetButton(Joy,19)){qDebug()<<"You pressed SQUARE";
    movement="Y";
    }

}

