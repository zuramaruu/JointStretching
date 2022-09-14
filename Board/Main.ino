#include "Main.h"
#include "Pins.h"
#include "Servo.h"

#define ON  180
#define OFF 0

MainSys sys;
Servo serv;

void MainSys::Init(void(*StartCallback)(void)) {
  serv.attach(PINSERV);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(INSERV, OUTPUT);
  Write(INSERV, HIGH);
  StartCallback();
}

void MainSys::Handler() {

  if (ui.getState()) {
    Write(LED_BUILTIN, 1);
    if (ui.getSetPoint() > sens.getValue()) serv.write(ON);
    else serv.write(OFF);
  }
  else {
    Write(LED_BUILTIN, 0);
    serv.write(OFF);
  }

}
