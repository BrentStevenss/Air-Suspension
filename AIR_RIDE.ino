

/*
   -- Air ride --

   This source code of graphical user interface
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;

   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
*/
//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>

// RemoteXY connection settings
#define REMOTEXY_SERIAL Serial3
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 205 bytes
{ 255, 15, 0, 44, 0, 198, 0, 16, 8, 1, 67, 4, 3, 2, 20, 5, 165, 26, 11, 1,
  2, 8, 8, 9, 9, 165, 31, 0, 1, 2, 48, 8, 9, 9, 165, 31, 0, 1, 0, 25,
  7, 12, 12, 165, 31, 0, 67, 4, 42, 2, 20, 5, 165, 26, 11, 1, 2, 8, 18, 9,
  9, 165, 31, 0, 1, 2, 48, 18, 9, 9, 165, 31, 0, 1, 0, 25, 19, 12, 12, 165,
  31, 0, 1, 2, 7, 61, 10, 11, 165, 31, 0, 1, 2, 45, 61, 11, 11, 165, 31, 0,
  1, 2, 7, 74, 10, 11, 165, 31, 0, 1, 2, 45, 74, 11, 11, 165, 31, 0, 67, 4,
  3, 53, 20, 5, 165, 26, 11, 67, 4, 41, 53, 20, 5, 165, 26, 11, 1, 0, 26, 61,
  12, 12, 165, 31, 0, 1, 0, 26, 75, 12, 12, 165, 31, 0, 1, 1, 6, 35, 16, 12,
  164, 31, 80, 114, 101, 115, 101, 116, 32, 49, 0, 1, 1, 25, 35, 15, 12, 165, 31, 80,
  114, 101, 115, 101, 116, 32, 50, 0, 1, 1, 44, 35, 15, 12, 165, 31, 80, 114, 101, 115,
  101, 116, 32, 51, 0
};

// this structure defines all the variables and events of your control interface
struct {

  // input variables
  uint8_t FLUP; // =1 if button pressed, else =0
  uint8_t FRUP; // =1 if button pressed, else =0
  uint8_t FRONTUP; // =1 if button pressed, else =0
  uint8_t FLDOWN; // =1 if button pressed, else =0
  uint8_t FRDOWN; // =1 if button pressed, else =0
  uint8_t FRONTDOWN; // =1 if button pressed, else =0
  uint8_t RLUP; // =1 if button pressed, else =0
  uint8_t RRUP; // =1 if button pressed, else =0
  uint8_t RLDOWN; // =1 if button pressed, else =0
  uint8_t RRDOWN; // =1 if button pressed, else =0
  uint8_t REARUP; // =1 if button pressed, else =0
  uint8_t REARDOWN; // =1 if button pressed, else =0
  uint8_t preset1; // =1 if button pressed, else =0
  uint8_t preset2; // =1 if button pressed, else =0
  uint8_t preset3; // =1 if button pressed, else =0

  // output variables
  char FLPRESSURE[11];  // string UTF8 end zero
  char FRPRESSURE[11];  // string UTF8 end zero
  char RLPRESSURE[11];  // string UTF8 end zero
  char RRPRESSURE[11];  // string UTF8 end zero

  // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define FRVALVE_UP 52
#define FLVALVE_UP 50
#define RRVALVE_UP 48
#define RLVALVE_UP 46
#define FRVALVE_DWN 44
#define FLVALVE_DWN 42
#define RRVALVE_DWN 40
#define RLVALVE_DWN 38
#define FR_PRESSURE 4
#define FL_PRESSURE 3
#define RR_PRESSURE 2
#define RL_PRESSURE 1
unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 1000;

void setup()
{
  RemoteXY_Init ();


  // Front valves
  pinMode(FRVALVE_UP, OUTPUT);
  pinMode(FLVALVE_UP, OUTPUT);
  pinMode(FLVALVE_DWN, OUTPUT);
  pinMode(FRVALVE_DWN, OUTPUT);
  // Rear valves
  pinMode(RRVALVE_UP, OUTPUT);
  pinMode(RLVALVE_UP, OUTPUT);
  pinMode(RLVALVE_DWN, OUTPUT);
  pinMode(RRVALVE_DWN, OUTPUT);
  //Sensors
  pinMode(FR_PRESSURE, INPUT);
  pinMode(RR_PRESSURE, INPUT);
  pinMode(FL_PRESSURE, INPUT);
  pinMode(RL_PRESSURE, INPUT);
  startMillis = millis();

}

void loop()
{
  RemoteXY_Handler ();
  currentMillis = millis();
  if (currentMillis - startMillis >= period) {
    updatePressure();
  }


  if (RemoteXY.FLUP == 1) {
    digitalWrite(FLVALVE_UP, LOW);

  } else if (RemoteXY.FLUP == 0) {
    digitalWrite(FLVALVE_UP, HIGH);
  }
  if (RemoteXY.FRUP == 1) {
    digitalWrite(FRVALVE_UP, LOW);

  } else if (RemoteXY.FLUP == 0) {
    digitalWrite(FRVALVE_UP, HIGH);
  }
  if (RemoteXY.RLUP == 1) {
    digitalWrite(RLVALVE_UP, LOW);

  } else if (RemoteXY.RLUP == 0) {
    digitalWrite(RLVALVE_UP, HIGH);
  }
  if (RemoteXY.RRUP == 1) {
    digitalWrite(RRVALVE_UP, LOW);

  } else if (RemoteXY.RRUP == 0) {
    digitalWrite(RRVALVE_UP, HIGH);
  }
  //RL Down
  if (RemoteXY.RLDOWN == 1) {
    digitalWrite(RLVALVE_DWN, LOW);

  } else if (RemoteXY.RLDOWN == 0) {
    digitalWrite(RLVALVE_DWN, HIGH);
  }
  //FL Down
  if (RemoteXY.FLDOWN == 1) {
    digitalWrite(FLVALVE_DWN, LOW);

  } else if (RemoteXY.FLDOWN == 0) {
    digitalWrite(FLVALVE_DWN, HIGH);
  }
  if (RemoteXY.RRDOWN == 1) {
    digitalWrite(RRVALVE_DWN, LOW);

  } else if (RemoteXY.RRDOWN == 0) {
    digitalWrite(RRVALVE_DWN, HIGH);
  }
  if (RemoteXY.RRDOWN == 1) {
    digitalWrite(RRVALVE_DWN, LOW);

  } else if (RemoteXY.RRDOWN == 0) {
    digitalWrite(RRVALVE_DWN, HIGH);
  }

  if (RemoteXY.FRONTUP == 1 && RemoteXY.FRUP != 1 && RemoteXY.FLUP != 1) {
    digitalWrite(FRVALVE_UP, LOW);
    digitalWrite(FLVALVE_UP, LOW);
  } else if (RemoteXY.FRONTUP == 0 && RemoteXY.FRUP != 1 && RemoteXY.FLUP != 1) {
    digitalWrite(FRVALVE_UP, HIGH);
    digitalWrite(FLVALVE_UP, HIGH);
  }
  if (RemoteXY.FRONTDOWN == 1 && RemoteXY.FRDOWN != 1 && RemoteXY.FLDOWN != 1) {
    digitalWrite(FRVALVE_DWN, LOW);
    digitalWrite(FLVALVE_DWN, LOW);
  } else if (RemoteXY.FRONTDOWN == 0 && RemoteXY.FRDOWN != 1 && RemoteXY.FLDOWN != 1) {
    digitalWrite(FRVALVE_DWN, HIGH);
    digitalWrite(FLVALVE_DWN, HIGH);
  }
  if (RemoteXY.REARDOWN == 1 && RemoteXY.RRDOWN != 1 && RemoteXY.RLDOWN != 1) {
    digitalWrite(RRVALVE_DWN, LOW);
    digitalWrite(RLVALVE_DWN, LOW);
  } else if (RemoteXY.REARDOWN == 0 && RemoteXY.RRDOWN != 1 && RemoteXY.RLDOWN != 1) {
    digitalWrite(RRVALVE_DWN, HIGH);
    digitalWrite(RLVALVE_DWN, HIGH);
  }
  if (RemoteXY.REARUP == 1&& RemoteXY.RRUP != 1 && RemoteXY.RLUP != 1) {
    digitalWrite(RRVALVE_UP, LOW);
    digitalWrite(RLVALVE_UP, LOW);
  } else if (RemoteXY.REARUP == 0&& RemoteXY.RRUP != 1 && RemoteXY.RRDOWN != 1 ) {
    digitalWrite(RRVALVE_UP, HIGH);
    digitalWrite(RLVALVE_UP, HIGH);
  }

  if (RemoteXY.preset1 == 1) {
    AirToPreset("park");

  }
  if (RemoteXY.preset2 == 1) {
    AirToPreset("drive");
  }
  if (RemoteXY.preset3 == 1) {
    AirToPreset("maximum_height");
  }



}
float ReadPressureFromVoltage(float voltage) {

  float rate = (200 - 0) / (4.5 - 0.5);
  return (rate * (voltage - 0.5));
}
float ReadSensorVoltage(int circuit) {

  return (analogRead(circuit) * (5.0 / 1023.0));

}
void AirToPreset(char preset) {


  int frontPressure;
  int rearPressure;

  if (preset == "park") {
    frontPressure = 40;
    rearPressure = 0;
  }
  if (preset == "drive") {
    frontPressure = 115;
    rearPressure = 60;
  }

  if (preset == "maximum_height") {
    frontPressure = 130;
    rearPressure = 120;
  }
  int frbagpressure = (int)ReadPressureFromVoltage(FR_PRESSURE);
  int flbagpressure = (int)ReadPressureFromVoltage(FL_PRESSURE);
  int rrbagpressure = (int)ReadPressureFromVoltage(RR_PRESSURE);
  int rlbagpressure = (int)ReadPressureFromVoltage(RL_PRESSURE);
  while (!(frontPressure - 3 < flbagpressure < frontPressure + 3) &&
         !(frontPressure - 3 < frbagpressure < frontPressure + 3) &&
         !(rearPressure -3 < rlbagpressure < rearPressure +3) &&
         !(rearPressure - 3 < rrbagpressure < rearPressure + 3)) {

    // Adjust Front Left Pressure
    if (flbagpressure < frontPressure - 3) {
      digitalWrite(FLVALVE_UP, LOW);
      digitalWrite(FLVALVE_DWN, HIGH);
    }
    else if (flbagpressure > frontPressure + 3) {
      digitalWrite(FLVALVE_UP, HIGH);
      digitalWrite(FLVALVE_DWN, LOW);
    }
    else {
      digitalWrite(FLVALVE_UP, HIGH);
      digitalWrite(FLVALVE_DWN, HIGH);
    }

    // Adjust Front Right Pressure
    if (frbagpressure < frontPressure - 3) {
      digitalWrite(FRVALVE_UP, LOW);
      digitalWrite(FRVALVE_DWN, HIGH);
    }
    else if (frbagpressure > frontPressure + 3) {
      digitalWrite(FRVALVE_UP, HIGH);
      digitalWrite(FRVALVE_DWN, LOW);
    }
    else {
      digitalWrite(FRVALVE_UP, HIGH);
      digitalWrite(FRVALVE_DWN, HIGH);
    }

    // Adjust Rear Left Pressure
    if (rlbagpressure < rearPressure - 3) {
      digitalWrite(RLVALVE_UP, LOW);
      digitalWrite(RLVALVE_DWN, HIGH);
    }
    else if (rlbagpressure > rearPressure + 3) {
      digitalWrite(RLVALVE_UP, HIGH);
      digitalWrite(RLVALVE_DWN, LOW);
    }
    else {
      digitalWrite(RLVALVE_UP, HIGH);
      digitalWrite(RLVALVE_DWN, HIGH);
    }

    // Adjust Rear Right Pressure
    if (rrbagpressure < rearPressure - 3) {
      digitalWrite(RRVALVE_UP, LOW);
      digitalWrite(RRVALVE_DWN, HIGH);
    }
    else if (rrbagpressure > rearPressure + 3) {
      digitalWrite(RRVALVE_UP, HIGH);
      digitalWrite(RRVALVE_DWN, LOW);
    }
    else {
      digitalWrite(RRVALVE_UP, HIGH);
      digitalWrite(RRVALVE_DWN, HIGH);
    }
    frbagpressure = (int)ReadPressureFromVoltage(FR_PRESSURE);
    flbagpressure = (int)ReadPressureFromVoltage(FL_PRESSURE);
    rrbagpressure = (int)ReadPressureFromVoltage(RR_PRESSURE);
    rlbagpressure = (int)ReadPressureFromVoltage(RL_PRESSURE);

  }
}
  void updatePressure() {
    //update fr pressure
    dtostrf(ReadPressureFromVoltage(ReadSensorVoltage(FR_PRESSURE)), 0, 1, RemoteXY.FRPRESSURE);
    //update fl pressure
    dtostrf(ReadPressureFromVoltage(ReadSensorVoltage(FL_PRESSURE)), 0, 1, RemoteXY.FLPRESSURE);
    //update RR pressure
    dtostrf(ReadPressureFromVoltage(ReadSensorVoltage(RR_PRESSURE)), 0, 1, RemoteXY.RRPRESSURE);
    //update RL pressure
    dtostrf(ReadPressureFromVoltage(ReadSensorVoltage(RL_PRESSURE)), 0, 1, RemoteXY.RLPRESSURE);
  }
