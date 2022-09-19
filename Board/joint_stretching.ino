#include "Main.h"
#include "UI.h"
#include "Sensor.h"
#include "Pins.h"

void Start() {
  ui.Init();
  ui.splashScreen();
  sens.setCalibrationVal(cfg::CalValue);
  sens.setStabilizingTime(cfg::Time);
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
