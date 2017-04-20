#ifndef _READER_H
#define _READER_H

#include "Arduino.h"



class Reader{
  public:
    Reader(int,int,int);
    /**
      declars ports
    **/
    void init(void (*userFunc)(void));
    /**
      Reads the measure values.
    **/
    void update();

    /**
      Checks if a time out occurs
    **/
    boolean isAttached(int);

        /**
     * turns the status led on or off
     */
    void led(boolean);

    /**
      True if caliper is attached
    **/
    boolean cAttached;

    /**
      True if caliper was attached
    **/
    boolean wasAttached;
    
    /**
      True if caliper value has changed
    **/
    boolean valueUpdate;

    /**
      Caliper value
    **/
     long value;
    
  private:
    /**
      Data pin
    **/
    int dataPin;

    /**
      Int pin
    **/
    int intPin;

    /**
      Int pin
    **/
    int ledPin;
    
    /**
    **/
    int pulseCount;
    
    /**
    **/
    long  tmpValue;
    
    /**
      Needed for getting caliper values
    **/
    long time;
};

#endif
