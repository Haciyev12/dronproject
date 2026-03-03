#include "functions.h"

// joystick
byte address[6] = "00001";
int a[7];

// motors
Servo esc[4];
int servoPin[4] = {25,26,27,14};
int now[4] = {1000 , 1000 , 1000 , 1000};
int speed[4] = {1000 , 1000 , 1000 , 1000};

// Time 
unsigned long lastTime = 0;
unsigned long currentTime = 0;

// jroskop
int j[3];
int jroPin[3] = {32, 35 , 34};
float selfx = 0;
float selfy = 0;