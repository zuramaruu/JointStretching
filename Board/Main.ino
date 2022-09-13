#include "Main.h"
#include "Pins.h"

MainSys sys;

void MainSys::Init(void(*StartCallback)(void)) {
  StartCallback();
}

void MainSys::Handler() {
  
}
