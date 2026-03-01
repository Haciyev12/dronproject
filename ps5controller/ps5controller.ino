#include "functions.h"

byte address[6] = "00001";
Servo esc[4];
int a[7];
int j[3];


unsigned long lastTime = 0;
int pin[4] = {25,26,27,14};
int now=1100;




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
    

    int speed=map(a[6], 0, 255, 1100, 1300);
    
    if(speed > now){
      now += 4;
    }
    if(speed < now){
      now -= 2;
    }
    
    for(int i = 0; i < 4; i++){
      esc[i].writeMicroseconds(now);
    }
   
    Serial.println("T1 is equal to ");
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
  else {
    stopMotors();
    delay(1000);
  }

 /* unsigned long currentTime = micros();
  float dt = (currentTime - lastTime) / 1000.0; // Convert to seconds
  lastTime = currentTime;
  float slip = max(0.0,20.0 - dt);
  delay(slip);
  */

  delay(10);
}







