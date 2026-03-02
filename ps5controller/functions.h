#include <ps5Controller.h>

#include <SPI.h>
#include <ESP32Servo.h>

#ifndef functions_H
#define functions_H

extern byte address[6];
extern Servo esc[4];
extern int a[7];
extern int j[3];
extern int pin[4];
extern int now;
extern int speed; 
extern unsigned long lastTime;
extern unsigned long currentTime;

void printValues();
void progressDelay(unsigned long d);
void stopMotors();
void getvalue();
void getjiro();

#endif