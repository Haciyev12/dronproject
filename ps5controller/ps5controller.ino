#include "functions.h"


void setSpeed(){//a[2] = x a[3] = y
  
}


void setup() {
  Serial.begin(115200);
  ps5.begin("7C:66:EF:48:39:02");
  for(int i = 0; i < 4; i++){
    esc[i].attach(servoPin[i],1000,2000);
  }
  delay(3000);
  stopMotors(0);
}


void loop() {

  if (ps5.isConnected()) {

    getvalue();
    getjiro();
    
    printValues();
  }   
  else {
    delay(500);
  }
  
  servoWrite();

  progressDelay(10);
}