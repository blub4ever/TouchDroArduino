#include "Reader.h"

#define cal_X_enable
#define cal_Y_enable
#define cal_Z_enable
#define cal_A_enable

#define cal_X_Int 4
#define cal_X_Val 5
#define cal_X_Led 18

#define cal_Y_Int 6
#define cal_Y_Val 7
#define cal_Y_Led 19

#define cal_Z_Int 14
#define cal_Z_Val 15
#define cal_Z_Led 8

#define cal_A_Int 16
#define cal_A_Val 17
#define cal_A_Led 9


#ifdef cal_X_enable
Reader readerX(cal_X_Int, cal_X_Val, cal_X_Led);
#endif

#ifdef cal_Y_enable
Reader readerY(cal_Y_Int, cal_Y_Val,cal_Y_Led);
#endif

#ifdef cal_Z_enable
Reader readerZ(cal_Z_Int, cal_Z_Val,cal_Z_Led);
#endif

#ifdef cal_A_enable
Reader readerA(cal_A_Int, cal_A_Val,cal_A_Led);
#endif

#ifdef cal_X_enable
void interX() {
  readerX.update();
}
#endif

#ifdef cal_Y_enable
void interY() {
  readerY.update();
}
#endif

#ifdef cal_Z_enable
void interZ() {
  readerZ.update();
}
#endif

#ifdef cal_A_enable
void interA() {
  readerA.update();
}
#endif


void setup() {
  Serial.begin(9600);
  Serial.println("Starte");


#ifdef cal_X_enable
  readerX.init(interX);
#endif

#ifdef cal_Y_enable
  readerY.init(interY);
#endif

#ifdef cal_Z_enable
  readerZ.init(interZ);
#endif

#ifdef cal_A_enable
  readerA.init(interA);
#endif
}

long loopTime = 0;

void loop() {
  // put your main code here, to run repeatedly:

#ifdef cal_X_enable
  if (readerX.valueUpdate) {
    Serial.print(F("X"));
    Serial.print((long)readerX.value);
    Serial.println(F(";"));
    readerX.valueUpdate = false;
  }
#endif

#ifdef cal_Y_enable
  if (readerY.valueUpdate) {
    Serial.print(F("Y"));
    Serial.print((long)readerY.value);
    Serial.println(F(";"));
    readerY.valueUpdate = false;
  }
#endif

#ifdef cal_Z_enable
  if (readerZ.valueUpdate) {
    Serial.print(F("Z"));
    Serial.print((long)readerZ.value);
    Serial.println(F(";"));
    readerZ.valueUpdate = false;
  }
#endif

#ifdef cal_A_enable
  if (readerA.valueUpdate) {
    Serial.print(F("A"));
    Serial.print((long)readerA.value);
    Serial.println(F(";"));
    readerA.valueUpdate = false;
  }
#endif


  if (loopTime - millis() > 1000) {
    loopTime = millis();
    
#ifdef cal_X_enable
    readerX.led(readerX.isAttached(1000));
#endif

#ifdef cal_Y_enable
    readerY.led(readerY.isAttached(1000));
#endif

#ifdef cal_Z_enable
    readerZ.led(readerZ.isAttached(1000));
#endif

#ifdef cal_A_enable
    readerA.led(readerA.isAttached(1000));
#endif
  }
  delay(10);
}


