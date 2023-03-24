#include "AirBag.h"
#include "PressureSensor.h"

class Airbag {
  private:
    byte bagPin;
    String pressure;

  public:
    Airbag(byte sensor, byte fill, byte dump) {
      this -> pressureSensor = new PressureSensor(sensor);
      this -> fillRelay = new Relay(fill);
      this -> dumpRelay = new Relay(dump);
      init();
    }
    void init() {
      off;
      updatePressure()
    }
    void fillBag() {
      fillRelay.on();
    }
    void dumpBag() {
      dumpRelay.on();
    }
    void updatePressure() {
      this.pressure = pressureSensor.update();
    }
    float getPressure() {
      updatePressure();
      return pressure;
    }

    void off() {
      dumpRelay.off();
      fillRelay.off();
    }
};
