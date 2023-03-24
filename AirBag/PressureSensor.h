#ifndef MY_PRESSURE_SENSOR_H
#define MY_PRESSURE_SENSOR_H

#include <Arduino.h>

class PressureSensor{
  private:
    byte pin;
  public:
    PressureSensor(byte pin);

     void init();
     byte getPin();
     float update();
     void updatePressure();
     float ReadPressureFromVoltage(byte circuit);

}
