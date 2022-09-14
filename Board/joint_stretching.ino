#include "Main.h"
#include "UI.h"
#include "Sensor.h"
#include "Pins.h"

void Start() {
  ui.Init();
  ui.splashScreen();
  sens.setCalibrationVal(696.0);
  sens.setStabilizingTime(2000);
  sens.setTare(true);
  sens.Init();
}

void setup() {
  sys.Init(Start);
}

void loop() {
  sys.Handler();
  ui.Handler();
  sens.Handler();
}
