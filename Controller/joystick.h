#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QTimer>
#include <QObject>
#include "SDL.h"
#undef main

class Joystick : public QObject
{
    Q_OBJECT
public:
    explicit Joystick(QObject *parent = nullptr);

private:
    SDL_Event event;
    SDL_Joystick *Joy;

    QTimer *timer;

    QString movement="";

signals:
    void move(QString);

public slots:
    void Joystickk();
};

#endif // JOYSTICK_H
