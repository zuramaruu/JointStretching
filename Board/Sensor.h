#pragma once

struct Sensor {
    void Init();
    void Handler();
    void setCalibrationVal(float val);
    void setStabilizingTime(long val);
    void setTare(bool tare);
    float getValue();

  private:
    float LoadCellValue;
    float calibrationValue;
    long stabilizingTime;
    bool _tare;
    // const int calValeepromAddr = 0;
    uint32_t sensTmr;
    void errMsg();
};

extern Sensor sens;
