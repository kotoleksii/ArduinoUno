const byte TRIG_PIN = 2;
const byte ECHO_PIN = 3;

const byte LED_1 = 5; // 1..100 cm
const byte LED_2 = 6; // 101..200 cm
const byte LED_3 = 7; // 201..300 cm
const byte LED_OUT = 4; // >334 cm or out of range

const unsigned long TIMEOUT_US = 30000UL;
const float US_TO_CM = 0.01715f;

unsigned long readEchoUs() {
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  return pulseIn(ECHO_PIN, HIGH, TIMEOUT_US);
}

float readDistanceCm() {
  unsigned long duration = readEchoUs();
  if (duration == 0) return -1; 

  return duration * US_TO_CM;
}

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED_1, OUTPUT); 
  pinMode(LED_2, OUTPUT); 
  pinMode(LED_3, OUTPUT); 
  pinMode(LED_OUT, OUTPUT);
}

void loop() {
  float distance = readDistanceCm();

  digitalWrite(LED_1, LOW); 
  digitalWrite(LED_2, LOW); 
  digitalWrite(LED_3, LOW); 
  digitalWrite(LED_OUT, LOW);

  if (distance < 0) {
    Serial.println("No Echo");
    digitalWrite(LED_OUT, HIGH);
  } 
  else {
    Serial.println(distance);

    if (distance >= 1 && distance <= 100) {
      digitalWrite(LED_1, HIGH);
    } else if (distance <= 200) {
      digitalWrite(LED_2, HIGH);
    } else if (distance <= 300) {
      digitalWrite(LED_3, HIGH);
    } else if (distance > 334) {
      Serial.println("Out of Range");
      digitalWrite(LED_OUT, HIGH);
    }
  }

  delay(20);
}
