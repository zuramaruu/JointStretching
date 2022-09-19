#include "Main.h"
#include "Pins.h"
#include "Servo.h"

#define   ON      180
#define   OFF     90
#define   UTIME   0

#define   DEBUG

MainSys sys;
Servo serv;

void MainSys::Init(void(*StartCallback)(void)) {
  serv.attach(PINSERV);
  serv.write(OFF);

  pinMode(LED, OUTPUT);
  pinMode(INSERV, OUTPUT);

  //  attachInterrupt(digitalPinToInterrupt(INTERR), Rest, RISING);
  StartCallback();
}

void MainSys::Handler() {

  if (ui.getState()) {
    Write(LED, 1);
    if (sens.getValue() > ui.getSetPoint().toInt()) serv.write(ON);
    //    else serv.write(OFF);
  }
  else {
    Write(LED, 0);
    serv.write(OFF);
  }
  
  /*
    #ifdef DEBUG

    Ser.print("Sens = ");
    Ser.println(String(sens.getValue()));

    #endif
  */
}

/* void Rest() {
  ui.reset();
  } */
