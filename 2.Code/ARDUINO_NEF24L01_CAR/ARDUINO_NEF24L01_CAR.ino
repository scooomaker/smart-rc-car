/*
        DIY Arduino based RC Transmitter Project
                  == Receiver Code ==、
                  
                  My 12 years old works
                  Use Arduino 1.8.13

      TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "DistanceSRF04.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "namespace_Car.h"
#include "Data_Package.h"

using namespace ocar;
using namespace Mecanum;

DistanceSRF04 DistGo;
DistanceSRF04 DistLeft;
DistanceSRF04 DistRight;
DistanceSRF04 DistBack;

#define echoGo 25
#define trigGo 24
#define echoLeft 3
#define trigLeft 2
#define echoRight 16
#define trigRight 17
#define echoBack A9
#define trigBack A10

RF24 radio(26, 27);              // nRF24L01 (CE, CSN)
const byte address[6] = "00001"; // Address

LiquidCrystal_I2C lcd(0x3f, 16, 2);

extern int IN1;
extern int IN2;
extern int IN3;
extern int IN4;
extern int IN5;
extern int IN6;
extern int IN7;
extern int IN8;

// Max size of this struct is 32 bytes - NRF24L01 buffer limit

Data_Package data;

unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  DistGo.begin(echoGo, trigGo);
  DistLeft.begin(echoLeft, trigLeft);
  DistRight.begin(echoRight, trigRight);
  DistBack.begin(echoBack, trigBack);

  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS); //将波长定位250kbps
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening(); // 设置为接收器

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Welcome using");
  lcd.setCursor(0, 1);
  lcd.print("the robot!  ");
  delay(3000);
  lcd.clear();

  resetData();
}

void loop()
{
  // 检查是否有要接收的数据
  if (radio.available())
  {
    radio.read(&data, sizeof(Data_Package));
    lastReceiveTime = millis();
  }
  currentTime = millis();
  if (currentTime - lastReceiveTime > 700)
  {
    resetData();
  }

  if (data.tSwitch1 == LOW)
  {
    if (rang(1) > 30)
    {
      runCar();
    }
    else
    {
      _backCar(5);
      stopCar();
      direction();
    }
  }
  else
  {
    if (data.j1PotY < 120)
    {
      runCar(data.pot1);
    }
    else if (data.j1PotY > 150)
    {
      backCar(data.pot1);
    }
    else if (data.j1PotX > 150)
    {
      rightLongCar();
    }
    else if (data.j1PotX < 120)
    {
      leftLongCar();
    }
    else if (data.j2PotX < 120 && data.j2PotY < 120)
    {
      autoLeft_front();
    }
    else if (data.j2PotX > 150 && data.j2PotY < 120)
    {
      autoRight_front();
    }
    else if (data.j2PotX < 120 && data.j2PotY > 150)
    {
      autoLeft_rear();
    }
    else if (data.j2PotX > 150 && data.j2PotY > 150)
    {
      autoRight_rear();
    }
    else if (data.j2PotX < 120)
    {
      autoLeft();
    }
    else if (data.j2PotX > 150)
    {
      autoRight();
    }
    else
    {
      stopCar();
    }
  }
}

void resetData()
{
  stopCar();
  data.j1PotX = 129;
  data.j1PotY = 126;
  data.j2PotX = 126;
  data.j2PotY = 129;
  data.j1Button = 0;
  data.j2Button = 0;
  data.pot1 = 255;
  data.pot2 = 255;
  data.tSwitch1 = 1;
  data.tSwitch2 = 1;
  data.button1 = 0;
  data.button2 = 0;
  data.button3 = 0;
  data.button4 = 0;
}

unsigned int rang(int op)
{
  unsigned int distance = 0;
  switch (op)
  {
  case 1:
    distance = DistGo.getDistanceCentimeter();
    break;
  case 2:
    distance = DistLeft.getDistanceCentimeter();
    break;
  case 3:
    distance = DistRight.getDistanceCentimeter();
    break;
  case 4:
    distance = DistBack.getDistanceCentimeter();
    break;
  }
  lcdPrint(distance);
  return distance;
}

void lcdPrint(unsigned int distance)
{
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
}

void direction()
{
  unsigned int L = rang(2);
  unsigned int R = rang(3);
  if (L > R && L > 25)
  {
    leftCar();
    runCar();
  }
  else if (R > L && R > 25)
  {
    rightCar();
    runCar();
  }
  else if (L < 25 && R < 25)
  {
    if (rang(4) > 25)
    {
      TurnAround();
      runCar();
    }
    else
    {
      stopCar();
    }
  }
}
