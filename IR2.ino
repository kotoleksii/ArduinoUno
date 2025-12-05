#include <IRremote.h>

const int IR_RECEIVER_PIN = 4;

void setup()
{
  Serial.begin(9600);                 
  IrReceiver.begin(IR_RECEIVER_PIN);  
}

void loop()
{
  if (IrReceiver.decode()) {                               
    unsigned long signalCode = IrReceiver.decodedIRData.decodedRawData;

    if (signalCode != 0 && signalCode != 0xFFFFFFFF) {
      Serial.print("Decoded Data: ");
      Serial.println(signalCode, HEX);                      
    }

    IrReceiver.resume();
  }
}
