#include "Sensor.h"
#include "Pins.h"
#include "HX711_ADC.h"
#include "EEPROM.h"
#include "UI.h"

#define S_SAMLPLING 0

Sensor sens;

HX711_ADC LoadCell(HXOUT, HXSCK);

void Sensor::Init() {
  LoadCell.begin();
  LoadCell.start(this->stabilizingTime, this->_tare);
  if (LoadCell.getTareTimeoutFlag()) errMsg();
  else LoadCell.setCalFactor(this->calibrationValue);
}

void Sensor::setCalibrationVal(float val) {
  this->calibrationValue = val;
}

void Sensor::setStabilizingTime(long val) {
  this->stabilizingTime = val;
}

void Sensor::setTare(bool tare) {
  this->_tare = tare;
}

void Sensor::Handler() {
  if (millis() - sensTmr >= S_SAMLPLING && LoadCell.update()) {
    LoadCellValue = LoadCell.getData();
    if (LoadCellValue < 0) LoadCellValue = 0;
    sensTmr = millis();
  }
}

float Sensor::getValue() {
  return this->LoadCellValue;
}

void Sensor::errMsg() {
  Ser.print("Check wiring and pin designations");
  ui.set(3, 0);
  ui.print("ERROR");
  while (1);
}
