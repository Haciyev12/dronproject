#include <ps5Controller.h> // it is working (Hemise INsallah demek lazimdi)

#include <SPI.h>
#include <ESP32Servo.h>


unsigned long lastTime = 0;
const byte address[6] = "00001";
int a[7];
int j[3];
int now=1100;
//25 , 26, 27,14

Servo esc[4];

int pin[4]={25,26,27,14};

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
    Serial.println();
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







