#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QTimer>

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QTimer>
#include <SDL.h>

class Joystick : public QTimer
{
   // Q_OBJECT

public:
    Joystick();
    void JoystickButtons();

private:
    SDL_Event event;
    SDL_Joystick *joystick=nullptr;

    QTimer *timer2;

public slots:
    void Timer2();


};

#endif // JOYSTICK_H
