#ifndef MY_AIRBAG_H
#define MY_AIRBAG_H

#include <Arduino.h>

class AirBag{
  private:
    byte bagPin;
    String pressure;
  public:
    AirBag(byte sensor, byte fill, byte dump);

     void init();
     void fillBag();
     void dumpbag();
     void updatePressure();
     float getPressure();
     void off();
}
