#include "Main.h"
#include "UI.h"
#include "Sensor.h"
#include "Pins.h"

void Start() {
  ui.Init();
  ui.splashScreen();
  sens.Init();
  sens.setCalibrationVal(696.0);
  sens.setStabilizingTime(2000);
  sens.setTare(true);
}

void setup() {
  sys.Init(Start);
}

void loop() {
  ui.Handler();
  sens.Handler();
}
