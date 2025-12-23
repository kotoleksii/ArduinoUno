const int BUZZER_PIN = 10;
const int LED_PIN = 8; 

void beep(int freq, int toneMs, int totalMs) {
  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN, freq, toneMs);
  delay(toneMs);

  noTone(BUZZER_PIN);
  digitalWrite(LED_PIN, LOW);

  int rest = totalMs - toneMs;
  if (rest > 0) delay(rest);
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // S = ...
  beep(900, 120, 200);
  beep(900, 120, 200);
  beep(900, 120, 400);

  // O = ---
  beep(900, 360, 440);
  beep(900, 360, 440);
  beep(900, 360, 600);

  // S = ...
  beep(900, 120, 200);
  beep(900, 120, 200);
  beep(900, 120, 1000);
}
