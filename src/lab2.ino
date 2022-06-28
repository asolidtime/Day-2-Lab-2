SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(AUTOMATIC);

int RED = D7;
int GREEN = D6;
int BLUE = D5;
bool redstate = false;
bool greenstate = false;
bool bluestate = false;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(A0, INPUT_PULLDOWN);
  pinMode(A1, INPUT_PULLDOWN);
  pinMode(A2, INPUT_PULLDOWN);
  pinMode(A3, INPUT_PULLDOWN);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
}

void updateStates() {
  digitalWrite(GREEN, greenstate);
  digitalWrite(RED, redstate);
  digitalWrite(BLUE, bluestate);
}


// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  //Serial.println(digitalRead(A0));
  if (digitalRead(A0)) {
    greenstate = !greenstate;
    updateStates();
    delay(150ms);
  }
  if (digitalRead(A1)) {
    bluestate = !bluestate;
    updateStates();
    delay(150ms);
  }
  if (digitalRead(A2)) {
    redstate = !redstate;
    updateStates();
    delay(150ms);
  }
  if (digitalRead(A3)) {
    if (!greenstate && !redstate && !bluestate) {
      redstate = true;
      bluestate = true;
      greenstate = true;
    } else {
      redstate = false;
      bluestate = false;
      greenstate = false;
    }
    updateStates();
    delay(150ms);
  }
}