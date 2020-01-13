#include <EEPROM.h>
#define BAUD_rate 115200

byte noElem = 12; // number of bytes readed and written
unsigned int baseAddr = 900; //Nane has 512, Uno hat 1024, Mega has 4096
unsigned int n = 0; //temporary int for convert integer<->bytearray

byte testInt[12] = { 10, 11, 22, 33, 44, 55, 66, 77, 88, 99, 46, 23};
//byte testInt[12] = { -12.5, -10.00, -5.7, 0, 2.45, 2.90, 3.10, 4 , 5.6, 7.9, 5.5, 4};
//byte testInt[12] = {};

template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
  const byte* p = (const byte*)(const void*)&value;
  int i;
  for (i = 0; i < sizeof(value); i++)
    EEPROM.write(ee++, *p++);
  return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value)
{
  byte* p = (byte*)(void*)&value;
  int i;
  for (i = 0; i < sizeof(value); i++)
    *p++ = EEPROM.read(ee++);
  return i;
}

void setup() {
Serial.begin(115200);
  // write data to eeprom
  for (int i = 0; i <= noElem - 1; i++) {
    n = EEPROM_writeAnything( (i * 4) + baseAddr, testInt[i]);
  }

  // read data back
  for (int i = 0; i <= noElem - 1; i++) {
    double val;
    int addr = (i * 4) + baseAddr;
    n = EEPROM_readAnything( addr, val);
    Serial.println(val);
  }
}

void loop(){
}
