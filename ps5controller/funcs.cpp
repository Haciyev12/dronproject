#include "functions.h"

void progressDelay(unsigned long d){
  currentTime = micros();
  
  long dt = (currentTime - lastTime) / 1000.0;
  
  lastTime = currentTime;
  
  long slip = (dt < 0) ? 0 : dt;
  
  delay(slip);  
}



void stopMotors() {
  for(int i = 0; i < 4 ;i++){
    esc[i].writeMicroseconds(1000);
  }
}

void getjiro(){
  int f[3];
  f[0] = analogRead(32);
  f[1] = analogRead(35);
  f[2] = analogRead(34);

  j[0] = f[0];
  j[1] = f[1];
  j[2] = f[2];
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
  Serial.println(speed);
  
  Serial.println("Playstation controller values : ");
  for(int i = 0; i < 7; i++){
    Serial.print(a[i]);
    Serial.print(" ");
  }
  Serial.println(" ");
  Serial.println("Jiroskop values : ");
  
  for(int i = 0; i < 3; i++){
    Serial.print(j[i]);
    Serial.print(" ");
  }
}


