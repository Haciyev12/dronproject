#include "functions.h"



void servoWrite(){
  for(int i = 0; i < 4; i++){
    esc[i].writeMicroseconds(now);
  }
}



void setup() {
  Serial.begin(115200);
  ps5.begin("7C:66:EF:48:39:02");
  for(int i = 0; i < 4; i++){
    esc[i].attach(pin[i],1000,2000);
  }
  delay(3000);
  stopMotors();
}




void loop() {

  if (ps5.isConnected()) {
    
    getvalue();
    getjiro();
    
    speed = map(a[6], 0, 255, 1100, 1300);

    
    if(speed > now){
      now += 20;
    }
    if(speed < now){
      now -= 1;
    }

    printValues();

  }   
  else {
    speed = 1100;
    delay(1000);
  }
  
  servoWrite();

  progressDelay(10);
}