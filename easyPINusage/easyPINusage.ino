//boolean rl[8] {HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW, LOW}; //State of relay
boolean rl[8] {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}; //State of relay
int relay[8] {A6, A8, A9, A10, A11, A12, A13, A15}; //Pin declaration
byte shortDelay = 250; //short delay between single switch actions, byte max: 255
unsigned long longDelay = 5000; //long delay after all relais are toggled

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); //Optical debug: built in led
  digitalWrite(LED_BUILTIN, HIGH); //LED on
  delay(5000); //delay before turn off
  digitalWrite(LED_BUILTIN, LOW); //LED off

  Serial.begin(115200); //Start Serial
  Serial.println("Setup finish"); //Serial debug
}

void loop() {
  RelayToggler(0); //toggle relays solo, this line toggle relay0
  RelayToggler(1);
  RelayToggler(2);
  RelayToggler(3);
  RelayToggler(4);
  RelayToggler(5);
  RelayToggler(6);
  RelayToggler(7);
  Serial.println("-----------------------------------------------------------");
  delay(longDelay);        //delay against flood serial

  RelayBlink(0, 150); //blink relay 0, pause before end Blink in ms: 100
  RelayBlink(1, 150);
  RelayBlink(2, 150);
  RelayBlink(3, 150);
  RelayBlink(4, 150);
  RelayBlink(5, 150);
  RelayBlink(6, 150);
  RelayBlink(7, 150);
  Serial.println("-----------------------------------------------------------");
  delay(longDelay);        //delay against flood serial

  RelayBlinkX(0, 150, 4); //blink relay 0, pause before end Blink in ms: 100, blink 4 times
  RelayBlinkX(1, 150, 1);
  RelayBlinkX(2, 150, 4);
  RelayBlinkX(3, 150, 1);
  RelayBlinkX(4, 150, 1);
  RelayBlinkX(5, 150, 4);
  RelayBlinkX(6, 150, 2);
  RelayBlinkX(7, 150, 1);
  Serial.println("-----------------------------------------------------------");
  delay(longDelay);        //delay against flood serial

  multiRelayToggler(0, 7); //toggler to switch a row of relay state start at 0 and end with 7
  Serial.println("-----------------------------------------------------------");
  delay(longDelay);        //delay against flood serial
}

int RelayToggler(int x) { //get startpoint and endpoint from loop
  rl[x] = !rl[x]; //booleanswitch, HIGH / LOW
  digitalWrite(relay[x], rl[x]); //write to PIN

  Serial.print("Relay Toggler:");
  Serial.print("\t\tToggle Relay: ");
  Serial.print(x);
  Serial.print("\t\tStatus: ");
  Serial.println(rl[x]);

  delay(shortDelay);
}

int RelayBlink(int x, int y) { //get startpoint and endpoint from loop
  Serial.print("Relay Blink:");
  Serial.print("\t\tBlink Relay: ");
  Serial.print(x);

  for (int i = 0; i < 2; i++) {
    rl[x] = !rl[x]; //booleanswitch, HIGH / LOW
    digitalWrite(relay[x], rl[x]); //write to PIN

    Serial.print("\t\tStatus: ");
    Serial.print(rl[x]);
    delay(y);
  }
  Serial.println("");
}

int RelayBlinkX(int x, int y, int z) { //get startpoint and endpoint from loop
  Serial.print("Relay BlinkX:");
  Serial.print("\t\tBlink Relay: ");
  Serial.print(x);

  for (int j = 0; j < z; j++) {
    for (int i = 0; i < 2; i++) {
      rl[x] = !rl[x]; //booleanswitch, HIGH / LOW
      digitalWrite(relay[x], rl[x]); //write to PIN

      Serial.print("\t\tStatus: ");
      Serial.print(rl[x]);
      delay(y);
    }
  }
  Serial.println("");
}

int multiRelayToggler(int x, int y) { //get startpoint and endpoint from loop
  for (int i = x; i <= y; i++) { //for loop, start at: 0 & redo until reaching endpoint: 7
    rl[i] = !rl[i]; //booleanswitch, HIGH / LOW
    digitalWrite(relay[i], rl[i]); //write to PIN

    Serial.print("multi Toggler:");
    Serial.print("\t\tToggle Relay: ");
    Serial.print(i);
    Serial.print("\t\tStatus: ");
    Serial.println(rl[x]);

    delay(shortDelay);
  }
}
