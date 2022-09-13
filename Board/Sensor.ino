#include "Sensor.h"
#include "Pins.h"
#include "HX711_ADC.h"
#include "EEPROM.h"
#include "UI.h"

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
  if (millis() - sensTmr >= 50 && LoadCell.update()) {
    LoadCellValue = LoadCell.getData();

    sensTmr = millis();
  }
}

float Sensor::getValue() {
  return this->LoadCellValue;
}

void Sensor::errMsg() {
  Ser.print("Check wiring and pin designations");
  while (1);
}
