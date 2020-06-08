
// Test sketch
// For forum, to find a way to calculate
// runtime the sketch size for Arduino Mega

extern int _etext;
extern int _edata;
extern int __ctors_start;
extern int __ctors_end;
extern int __dtors_start;
extern int __dtors_end;
extern int __trampolines_start;
extern int __trampolines_end;
extern int __data_start;
extern int __data_end;
extern int __bss_start;
extern int __bss_end;
extern int __data_load_start;
extern int __data_load_end;
extern int __noinit_start;
extern int __noinit_end;
extern int __heap_start;
extern int __heap_end;
// extern int __eeprom_start;
extern int __eeprom_end;

volatile float vq;
#define Q  vq=Filler()
#define R  {Q;Q;Q;Q;Q;Q;Q;Q;}
#define S  {R;R;R;R;R;R;R;R;}
#define T  {S;S;S;S;S;S;S;S;}
#define U  {T;T;T;T;T;T;T;T;}
#define V  {U;U;U;U;U;U;U;U;}
#define W  {V;V;V;V;V;V;V;V;}
#define X  {W;W;W;W;W;W;W;W;}
#define Y  {X;X;X;X;X;X;X;X;}
#define Z  {Y;Y;Y;Y;Y;Y;Y;Y;}

void setup() {
  Serial.begin(9600);
  Serial.println(F("\nTest sketch"));
  Serial.print(F("_etext=0x"));
  Serial.println( (unsigned long) &_etext, HEX);
  Serial.print(F("_edata=0x"));
  Serial.println( (unsigned long) &_edata, HEX);
  Serial.print(F("__ctors_start=0x"));
  Serial.println( (unsigned long) &__ctors_start, HEX);
  Serial.print(F("__ctors_end=0x"));
  Serial.println( (unsigned long) &__ctors_end, HEX);
  Serial.print(F("__dtors_start=0x"));
  Serial.println( (unsigned long) &__dtors_start, HEX);
  Serial.print(F("__dtors_end=0x"));
  Serial.println( (unsigned long) &__dtors_end, HEX);
  Serial.print(F("__trampolines_start=0x"));
  Serial.println( (unsigned long) &__trampolines_start, HEX);
  Serial.print(F("__trampolines_end=0x"));
  Serial.println( (unsigned long) &__trampolines_end, HEX);
  Serial.print(F("__data_start=0x"));
  Serial.println( (unsigned long) &__data_start, HEX);
  Serial.print(F("__data_end=0x"));
  Serial.println( (unsigned long) &__data_end,HEX);
  Serial.print(F("__bss_start=0x"));
  Serial.println( (unsigned long) &__bss_start, HEX);
  Serial.print(F("__bss_end=0x"));
  Serial.println( (unsigned long) &__bss_end, HEX);
  Serial.print(F("__data_load_start=0x"));
  Serial.println( (unsigned long) &__data_load_start, HEX);
  Serial.print(F("__data_load_end=0x"));
  Serial.println( (unsigned long) &__data_load_end, HEX);
  Serial.print(F("__noinit_start=0x"));
  Serial.println( (unsigned long) &__noinit_start, HEX);
  Serial.print(F("__noinit_end=0x"));
  Serial.println( (unsigned long) &__noinit_end, HEX);
  Serial.print(F("__heap_start=0x"));
  Serial.println( (unsigned long) &__heap_start, HEX);
  Serial.print(F("__heap_end=0x"));
  Serial.println( (unsigned long) &__heap_end, HEX);
  // Serial.print(F("__eeprom_start=0x"));
  // Serial.println( (unsigned long) &__eeprom_start, HEX);
  Serial.print(F("__eeprom_end=0x"));
  Serial.println( (unsigned long) &__eeprom_end, HEX);
}

void loop() {
  // For Arduino 1.6.5:
  //    About 1210 byte per "S;"
  //    About 10kbyte per "T;"
  //    About 82kbyte per "U;"
  // Uncomment the appropriate line to fill the flash code.

  // Maximum for Arduino Uno
  // T;T; S;S;S;S;S;S;

  // Maximum for Arduino Leonardo
  // T;T; S;

  // Arduino Mega 2560, 0...32k
  // T;T;

   Arduino Mega 2560, 32...64k
   T;T;T;T;

   Arduino Mega 2560, 64...128k
   U;

   Arduino Mega 2560, 128...256k
   U;U;U;
}

float Filler( void)
{
  return( (float) random( 0, 100));
}
