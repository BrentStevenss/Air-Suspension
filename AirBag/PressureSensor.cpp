#include "PressureSensor.h"

class PressureSensor(){
 private:
  byte pin; 
}
public:
  PressureSensor(byte pin){
    this -> pin = pin;
    init();
  }
  void PressureSensor::init(){
    pinMode(pin, INPUT);
  }
  byte PressureSensor::getPin(){
    return pin;
  }
  float PressureSensor::update(){
    return ReadPressureFromVoltage(getPin());
  }
float PressureSensor::ReadPressureFromVoltage(byte circuit) {
  float voltage = (analogRead(circuit) * (5.0 / 103.0));
  float rate = (200 - 0) / (4.5 - 0.5);
  return (rate * (voltage - 0.5));
}

  
