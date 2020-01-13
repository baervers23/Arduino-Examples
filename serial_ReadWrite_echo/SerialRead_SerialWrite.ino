#define BAUD_rate 115200 			//Set baud rate for all Serials in this sketch
#define Serial_UART0 				  //RX0&TX0 serial Communication. Thats the normal Serial.begin USB. (Uno only have the UART0)
//#define Serial_UART1 				//RX1&TX1 serial Communication
//#define Serial_UART2 				//RX2&TX2 serial Communication
//#define Serial_UART3 				//RX3&TX3 serial Communication

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // set ledpin as output
  digitalWrite(LED_BUILTIN, HIGH); // reset indicator led on
  delay(5000); //wait before turn off
  digitalWrite(LED_BUILTIN, LOW);  // turn off

#ifdef Serial_UART0
  Serial.begin(BAUD_rate); //Serial initialize
  Serial.println("UART0 -> Setup finished");
#endif
#ifdef Serial_UART1
  Serial1.begin(BAUR_rate); //Serial initialize
  Serial1.println("UART1 -> Setup finished");
#endif
#ifdef Serial_UART2
  Serial2.begin(BAUR_rate); //Serial initialize
  Serial2.println("UART2 -> Setup finished");
#endif
#ifdef Serial_UART3
  Serial3.begin(BAUR_rate); //Serial initialize
  Serial3.println("UART3 -> Setup finished");
#endif
}

void loop() {
#ifdef Serial_UART0
  if (Serial.available() > 0) {
    String s1 = Serial.readStringUntil('\n');// s1 is String type variable.
    Serial.print("UART0->\N");
    Serial.println(s1);//display same received Data back in serial monitor.
  }
#endif
#ifdef Serial_UART1
  if (Serial1.available() > 0) {
    String s1 = Serial1.readStringUntil('\n');// s1 is String type variable.
    Serial1.print("UART1->\N"");
                  Serial1.println(s1);//display same received Data back in serial monitor.
                }
#endif
#ifdef Serial_UART2
                  if (Serial2.available() > 0) {
                  String s1 = Serial2.readStringUntil('\n');// s1 is String type variable.
                  Serial2.print("UART2->\N"");
    Serial2.println(s1);//display same received Data back in serial monitor.
  }
#endif
#ifdef Serial_UART3
  if (Serial3.available() > 0) {
    String s1 = Serial3.readStringUntil('\n');// s1 is String type variable.
    Serial3.print("UART3->\N");
    Serial3.println(s1);//display same received Data back in serial monitor.
  }
#endif
}
