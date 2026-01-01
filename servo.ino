#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);
}

void loop() {
  int sensorValue = analogRead(A0);                 
  int angle = map(sensorValue, 0, 1023, 0, 180);    
  myServo.write(angle);                             
  delay(20);                                        
}
