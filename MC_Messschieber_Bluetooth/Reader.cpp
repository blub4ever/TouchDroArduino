#include "Reader.h"
#include "Arduino.h"
#include "PinChangeInterrupt.h"


Reader::Reader(int intPin, int dataPin, int ledPin) {
  Reader::dataPin = dataPin;
  Reader::intPin = intPin;
  Reader::ledPin = ledPin;
}

void Reader::init(void (*userFunc)(void)) {
  attachPCINT(digitalPinToPCINT(Reader::intPin), userFunc, RISING);
  //attachInterrupt(interrupt, userFunc, RISING);
  pinMode(Reader::dataPin, INPUT);
  pinMode(Reader::ledPin, OUTPUT);

  Reader::wasAttached = false;
  Reader::cAttached = false;
  Reader::valueUpdate = true;
}


void Reader::update() {
  cli();
  long mill = millis();

  if (mill - Reader::time > 80) {

    if (Reader::pulseCount >= 23) {

      Reader::value = Reader::tmpValue;
      Reader::valueUpdate = true;
      Reader::tmpValue = 0;
      Reader::time = mill;
      Reader::pulseCount = 0;
    } else {

      int tmpRead = digitalRead(Reader::dataPin) ;
      if (tmpRead == HIGH) {
        if (Reader::pulseCount < 20)
          Reader::tmpValue |= 1L << Reader::pulseCount;
        else if (Reader::pulseCount == 20)
          Reader::tmpValue *= -1;
      }
      Reader::pulseCount++;
    }
  }
  sei();
}


boolean Reader::isAttached(int timeout) {
  long time = millis();
  long readerTime = Reader::time;
  if ( (time - readerTime) >= timeout) {
    Reader::cAttached = false;
    return false;
  } else {
    Reader::cAttached = true;
  }
  return true;
}

void Reader::led(boolean toggle) {
  if (toggle) {
    digitalWrite(Reader::ledPin, HIGH);
  } else {
    digitalWrite(Reader::ledPin, LOW);
  }
}

