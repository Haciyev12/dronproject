#include <ps5Controller.h>

#include <SPI.h>
#include <ESP32Servo.h>

#ifndef functions_H
#define functions_H

extern byte address[6];
extern Servo esc[4];
extern int a[7];
extern int j[3];

void stopMotors();
void getvalue();
void getjiro();

#endif