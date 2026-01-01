const byte R = 11;
const byte G = 9;
const byte B = 10;
const byte BTN = 4;

int mode = 0;

void setColor(bool rOn, bool gOn, bool bOn) {
  digitalWrite(R, rOn);
  digitalWrite(G, gOn);
  digitalWrite(B, bOn);
}

void showMode(int m) {
  switch (m) {
    case 0: setColor(1,0,0); break; // Red
    case 1: setColor(0,1,0); break; // Green
    case 2: setColor(0,0,1); break; // Blue
    case 3: setColor(1,1,0); break; // Yellow
    case 4: setColor(1,0,1); break; // Magenta
    case 5: setColor(0,1,1); break; // Cyan
    case 6: setColor(1,1,1); break; // White
  }
}

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(BTN, INPUT); 

  showMode(mode); 
}

void loop() {
  if (digitalRead(BTN) == HIGH) {
    mode++;
    if (mode > 6) mode = 0;

    showMode(mode);

    delay(250);                 
    while (digitalRead(BTN)) {} 
    delay(50);
  }
}
