#include "functions.h"

void progressDelay(unsigned long d){
  currentTime = micros();
  
  long dt = (currentTime - lastTime) / 1000.0;
  
  lastTime = currentTime;
  
  long slip = (dt < 0) ? 0 : dt;
  
  delay(slip);  
}



void stopMotors(bool exit) {
  for(int i = 0; i < 4 ;i++){
    esc[i].writeMicroseconds(1000);
  }

  while(exit);
}

void getjiro(){
  int f[3];
  for(int i = 0; i < 3; i++){
    f[i] = analogRead(jroPin[i]);
  }
  for(int i = 0; i < 3; i++){
    j[i] = map(f[i], 1300, 2300, -1000, 1000) / 1000.0;
  }
}


void getvalue(){
  a[0] = ps5.LStickX();
  a[1] = ps5.LStickY();
  a[2] = ps5.RStickX();
  a[3] = ps5.RStickY();
  a[4] = ps5.Circle();
  a[5] = ps5.L1();
  a[6] = ps5.R2Value();
}

void printValues(){
  
  Serial.println("Speed : ");
  
  for(int i = 0; i < 4; i++){
    Serial.print(speed[i]);
    Serial.print(" ");
  }
  
  Serial.println("Playstation controller values : ");
  
  for(int i = 0; i < 7; i++){
    Serial.print(a[i]);
    Serial.print(" ");
  }

  Serial.println("Jiroskop values : ");
  
  for(int i = 0; i < 3; i++){
    Serial.print(j[i]);
    Serial.print(" ");
  }
  
}


void servoWrite(){
  for(int i = 0; i < 4; i++){
    esc[i].writeMicroseconds(now[i]);
  }
}