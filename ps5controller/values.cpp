#include "functions.h"

// joystick
byte address[6] = "00001";
int a[7];

// motors
Servo esc[4];
int pin[4] = {25,26,27,14};
int now = 1100;
int speed = 1100;


// Time 
unsigned long lastTime = 0;
unsigned long currentTime = 0;

// jroskop
int j[3];
