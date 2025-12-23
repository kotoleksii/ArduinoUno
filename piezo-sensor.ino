const int BUZZER_PIN = 8;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // S = ...
  tone(BUZZER_PIN, 900, 120); delay(200); noTone(BUZZER_PIN);
  tone(BUZZER_PIN, 900, 120); delay(200); noTone(BUZZER_PIN);
  tone(BUZZER_PIN, 900, 120); delay(400); noTone(BUZZER_PIN);

  // O = ---
  tone(BUZZER_PIN, 900, 360); delay(440); noTone(BUZZER_PIN);
  tone(BUZZER_PIN, 900, 360); delay(440); noTone(BUZZER_PIN);
  tone(BUZZER_PIN, 900, 360); delay(600); noTone(BUZZER_PIN);

  // S = ...
  tone(BUZZER_PIN, 900, 120); delay(200); noTone(BUZZER_PIN);
  tone(BUZZER_PIN, 900, 120); delay(200); noTone(BUZZER_PIN);
  tone(BUZZER_PIN, 900, 120); delay(1000); noTone(BUZZER_PIN);
}
