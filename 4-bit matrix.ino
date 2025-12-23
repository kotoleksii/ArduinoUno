#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_7segment matrix = Adafruit_7segment();

const int ledPin = 4;      

void setup() {
  pinMode(ledPin, OUTPUT);     
  digitalWrite(ledPin, LOW); 

  matrix.begin(0x70);         
  matrix.clear();              
  matrix.writeDisplay();      
}

void loop() {
  for (int i = 1; i <= 30; i++) {
    matrix.print(i);            
    matrix.writeDisplay();   

    if (i >= 10 && i <= 20) {
      digitalWrite(ledPin, HIGH);  
    } else {
      digitalWrite(ledPin, LOW); 
    }

    delay(200);
  }
}
