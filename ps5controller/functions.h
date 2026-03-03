#include <ps5Controller.h>

#include <SPI.h>
#include <ESP32Servo.h>

#ifndef functions_H
#define functions_H

extern float selfx;
extern float selfy;
extern byte address[6];
extern Servo esc[4];
extern int a[7];
extern int j[3];
extern int servoPin[4];
extern int jroPin[3];
extern int now[4];
extern int speed[4]; 
extern unsigned long lastTime;
extern unsigned long currentTime;

void progressDelay(unsigned long d);
void stopMotors(bool exit);
void printValues();
void getvalue();
void getjiro();
void servoWrite();

#endif