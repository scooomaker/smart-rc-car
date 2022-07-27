#include "namespace_Car.h"
#include "Data_Package.h"
#include <Arduino.h>
//int IN1 = 4;  
//int IN2 = 5;  
//int IN3 = 6;  
//int IN4 = 7;  
//int IN5 = 8;  
//int IN6 = 9;  
//int IN7 = 10; 
//int IN8 = 11; 

#define IN1 4  //Right-rear     forward
#define IN2 5  //Right-rear     back-off
#define IN3 6  //Right-front    forward
#define IN4 7  //Right-front    back-off
#define IN5 8  //Left-rear      forward
#define IN6 9  //Left-rear      back-off
#define IN7 10 //Left-front     forward
#define IN8 11 //Left-front     back-off

extern Data_Package data;
namespace ocar
{
    void runCar()
    {
        analogWrite(IN1, data.pot1);
        analogWrite(IN2, 0);
        analogWrite(IN3, data.pot1);
        analogWrite(IN4, 0);

        analogWrite(IN5, data.pot1);
        analogWrite(IN6, 0);
        analogWrite(IN7, data.pot1);
        analogWrite(IN8, 0);
    }

    void runCar(unsigned int speed)
    {
        analogWrite(IN1, speed);
        analogWrite(IN2, 0);
        analogWrite(IN3, speed);
        analogWrite(IN4, 0);

        analogWrite(IN5, speed);
        analogWrite(IN6, 0);
        analogWrite(IN7, speed);
        analogWrite(IN8, 0);
    }

    void _leftCar()
    {
        analogWrite(IN1, 200);
        analogWrite(IN2, 0);
        analogWrite(IN3, 200);
        analogWrite(IN4, 0);

        analogWrite(IN5, 0);
        analogWrite(IN6, 0);
        analogWrite(IN7, 0);
        analogWrite(IN8, 0);
    }

    void _rightCar()
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, 0);

        analogWrite(IN5, 200);
        analogWrite(IN6, 0);
        analogWrite(IN7, 200);
        analogWrite(IN8, 0);
    }

    void leftCar()
    {
        analogWrite(IN1, 200);
        analogWrite(IN2, 0);
        analogWrite(IN3, 200);
        analogWrite(IN4, 0);

        analogWrite(IN5, 0);
        analogWrite(IN6, 0);
        analogWrite(IN7, 0);
        analogWrite(IN8, 0);
        delay(600);
    }

    void rightCar()
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, 0);

        analogWrite(IN5, 200);
        analogWrite(IN6, 0);
        analogWrite(IN7, 200);
        analogWrite(IN8, 0);
        delay(600);
    }

    void TurnAround()
    {
        analogWrite(IN1, 200);
        analogWrite(IN2, 0);
        analogWrite(IN3, 200);
        analogWrite(IN4, 0);

        analogWrite(IN5, 0);
        analogWrite(IN6, 200);
        analogWrite(IN7, 0);
        analogWrite(IN8, 200);
        delay(1000);
    }

    void backCar(unsigned int time)
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, time);
        analogWrite(IN3, 0);
        analogWrite(IN4, time);

        analogWrite(IN5, 0);
        analogWrite(IN6, time);
        analogWrite(IN7, 0);
        analogWrite(IN8, time);
    }

    void backCar()
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, 200);
        analogWrite(IN3, 0);
        analogWrite(IN4, 200);

        analogWrite(IN5, 0);
        analogWrite(IN6, 200);
        analogWrite(IN7, 0);
        analogWrite(IN8, 200);
    }

    void _backCar(unsigned int time)
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, 200);
        analogWrite(IN3, 0);
        analogWrite(IN4, 200);

        analogWrite(IN5, 0);
        analogWrite(IN6, 200);
        analogWrite(IN7, 0);
        analogWrite(IN8, 200);
        delay(time * 100);
    }

    void stopCar()
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, 0);

        analogWrite(IN5, 0);
        analogWrite(IN6, 0);
        analogWrite(IN7, 0);
        analogWrite(IN8, 0);
    }

    void leftLongCar()
    {
        analogWrite(IN1, data.pot1);
        analogWrite(IN2, 0);
        analogWrite(IN3, data.pot1);
        analogWrite(IN4, 0);

        analogWrite(IN5, 0);
        analogWrite(IN6, data.pot1);
        analogWrite(IN7, 0);
        analogWrite(IN8, data.pot1);
    }

    void rightLongCar()
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, data.pot1);
        analogWrite(IN3, 0);
        analogWrite(IN4, data.pot1);

        analogWrite(IN5, data.pot1);
        analogWrite(IN6, 0);
        analogWrite(IN7, data.pot1);
        analogWrite(IN8, 0);
    }
} // namespace ocar

namespace Mecanum
{
    void autoLeft()
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, data.pot1);
        analogWrite(IN3, data.pot1);
        analogWrite(IN4, 0);

        analogWrite(IN5, data.pot1);
        analogWrite(IN6, 0);
        analogWrite(IN7, 0);
        analogWrite(IN8, data.pot1);
    }

    void autoRight()
    {
        analogWrite(IN1, data.pot1);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, data.pot1);

        analogWrite(IN5, 0);
        analogWrite(IN6, data.pot1);
        analogWrite(IN7, data.pot1);
        analogWrite(IN8, 0);
    }

    void autoLeft_front()
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, 0);
        analogWrite(IN3, data.pot1);
        analogWrite(IN4, 0);

        analogWrite(IN5, data.pot1);
        analogWrite(IN6, 0);
        analogWrite(IN7, 0);
        analogWrite(IN8, 0);
    }

    void autoRight_front()
    {
        analogWrite(IN1, data.pot1);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, 0);

        analogWrite(IN5, 0);
        analogWrite(IN6, 0);
        analogWrite(IN7, data.pot1);
        analogWrite(IN8, 0);
    }

    void autoLeft_rear()
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, data.pot1);
        analogWrite(IN3, 0);
        analogWrite(IN4, 0);

        analogWrite(IN5, 0);
        analogWrite(IN6, 0);
        analogWrite(IN7, 0);
        analogWrite(IN8, data.pot1);
    }

    void autoRight_rear()
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, data.pot1);

        analogWrite(IN5, 0);
        analogWrite(IN6, data.pot1);
        analogWrite(IN7, 0);
        analogWrite(IN8, 0);
    }

    void autoLeftLongCar()
    {
        analogWrite(IN1, data.pot1);
        analogWrite(IN2, 0);
        analogWrite(IN3, data.pot1);
        analogWrite(IN4, 0);

        analogWrite(IN5, 0);
        analogWrite(IN6, data.pot1);
        analogWrite(IN7, 0);
        analogWrite(IN8, data.pot1);
    }

    void autoRightLongCar()
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, data.pot1);
        analogWrite(IN3, 0);
        analogWrite(IN4, data.pot1);

        analogWrite(IN5, data.pot1);
        analogWrite(IN6, 0);
        analogWrite(IN7, data.pot1);
        analogWrite(IN8, 0);
    }

    void autoLeft(unsigned int time)
    {
        analogWrite(IN1, 0);
        analogWrite(IN2, data.pot1);
        analogWrite(IN3, data.pot1);
        analogWrite(IN4, 0);

        analogWrite(IN5, data.pot1);
        analogWrite(IN6, 0);
        analogWrite(IN7, 0);
        analogWrite(IN8, data.pot1);
        delay(time * 100);
    }
    void autoRight(unsigned int time)
    {
        analogWrite(IN1, data.pot1);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, data.pot1);

        analogWrite(IN5, 0);
        analogWrite(IN6, data.pot1);
        analogWrite(IN7, data.pot1);
        analogWrite(IN8, 0);
        delay(time * 100);
    }

} // namespace Mecanum
