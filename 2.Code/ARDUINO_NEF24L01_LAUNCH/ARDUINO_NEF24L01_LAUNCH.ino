/*
        DIY Arduino based RC Transmitter
  Library: TMRh20/RF24, https://github.com/tmrh20/RF24/

            制作 Arduino RC 遥控器
               == 遥控器代码 ==
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

// 定义数字输入
#define jB1 1 // Joystick button 1
#define jB2 0 // Joystick button 2
#define t1 8  // 切换开关 1
#define t2 7  // 切换开关 2
#define b1 6  // Button 1
#define b2 5  // Button 2
#define b3 4  // Button 3
#define b4 3  // Button 4

RF24 radio(10, 9);                              // nRF24L01 (CE, CSN)
const byte address[6] = "00001"; // Address

// 此结构的最大大小为 32 字节 - NRF24L01 缓冲区限制
struct Data_Package
{
  byte j1PotX;
  byte j1PotY;
  byte j1Button;
  byte j2PotX;
  byte j2PotY;
  byte j2Button;
  byte pot1; //电位器
  byte pot2;
  byte tSwitch1; //切换开关
  byte tSwitch2;
  byte button1;
  byte button2;
  byte button3;
  byte button4;
};

Data_Package data; //使用上述结构创建变量

void setup()
{
  Serial.begin(9600);

  // 定义无线电通信
  radio.begin();
  radio.openWritingPipe(address);   //00001
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);

  // 激活 Arduino 内部上拉电阻器
  pinMode(jB1, INPUT);
  pinMode(jB2, INPUT);
  pinMode(t1, INPUT_PULLUP);
  pinMode(t2, INPUT_PULLUP);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);

  //设置初始默认值
  data.j1PotX = 129; // 值从 0 到 255。当操纵杆处于静止位置时，值位于中间或 127。我们实际上将锅值映射从 0 到 1023 到 0 到 255，因为这是一个 BYTE 值
  data.j1PotY = 126;
  data.j2PotX = 126;
  data.j2PotY = 129;
  data.j1Button = 0;
  data.j2Button = 0;
  data.pot1 = 255;
  data.pot2 = 255;
  data.tSwitch1 = 0;
  data.tSwitch2 = 0;
  data.button1 = 0;
  data.button2 = 0;
  data.button3 = 0;
  data.button4 = 0;


  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE); //开像素点发光
  display.clearDisplay();      //清屏

  display.setTextSize(2);
  display.setCursor(12, 5);
  display.println("RC Remote");
  display.setCursor(25, 25);
  display.println("Control");
  display.setTextSize(1);
  display.setCursor(0, 45);
  display.println("Switch Toggle Switch1");
  display.setCursor(25, 55);
  display.println("to manual mode");
  display.display();
  delay(3000);
}
void loop()
{
  display.clearDisplay();
  //读取所有模拟输入并将其映射到一个字节值
  data.j1PotX = map(analogRead(A0), 0, 1023, 0, 255);
  data.j1PotY = map(analogRead(A1), 0, 1023, 0, 255);
  data.j2PotX = map(analogRead(A2), 0, 1023, 0, 255);
  data.j2PotY = map(analogRead(A3), 0, 1023, 0, 255);
  data.pot1 = map(analogRead(A6), 0, 1023, 0, 255);
  data.pot2 = map(analogRead(A7), 0, 1023, 0, 255);
  // 读取所有数字输入
  data.j1Button = digitalRead(jB1);
  data.j2Button = digitalRead(jB2);
  data.tSwitch1 = digitalRead(t1);
  data.tSwitch2 = digitalRead(t2);
  data.button1 = digitalRead(b1);
  data.button2 = digitalRead(b2);
  data.button3 = digitalRead(b3);
  data.button4 = digitalRead(b4);
  // 将整个数据从结构发送到接收器

  radio.write(&data, sizeof(Data_Package));
  digitalWrite(2, HIGH);

  display.setCursor(0,10);display.print("Real-time Data:");

  display.setCursor(0,20);display.print("pot1:");
  display.setCursor(30,20);display.print(data.pot1);
  display.setCursor(55,20);display.print("pot2:");
  display.setCursor(95,20);display.print(data.pot2);

  display.setCursor(0,30);display.print("switch1:");
  display.setCursor(50,30);display.print(data.tSwitch1);
  display.setCursor(60,30);display.print("switch2:");
  display.setCursor(110,30);display.print(data.tSwitch2);

  display.setCursor(0,40);display.print("j1x :");
  display.setCursor(30,40);display.print(data.j1PotX);
  display.setCursor(65,40);display.print("j2x :");
  display.setCursor(95,40);display.print(data.j2PotX);

  display.setCursor(0,55);display.print("j1y :");
  display.setCursor(30,55);display.print(data.j1PotY);
  display.setCursor(65,55);display.print("j2y :");
  display.setCursor(95,55);display.print(data.j2PotY);
  display.display();
}