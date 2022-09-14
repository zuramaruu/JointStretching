#include "UI.h"
#include "Pins.h"
#include "LiquidCrystal_I2C.h"
#include "Keypad_I2C.h"
#include "Keypad.h"

UserInterface ui;

LiquidCrystal_I2C lcd(LCDADDR, 16, 2);

Keypad_I2C thisKey( makeKeymap(pin::hq), pin::row, pin::col,
                    ROWS, COLS, KYPDADDR);

void UserInterface::Init() {
  Ser.begin(BAUDRATE);
  lcd.init();
  lcd.backlight();
  thisKey.begin();
}

void UserInterface::Handler() {
  if (millis() - uiTmr >= 30) {
    set(0, 0);
    print("SetPoint:");

    cKey = thisKey.getKey();

    if (!cKey) cKey = '\0';
    else {
      if (check(cKey)) {
        if (cursor == 16) reset();
        else {
          set(cursor, 0);
          lcd.print(cKey);
          myTxt[index] = cKey;

          cursor++;
          index++;

        }
      } else {
        if (cKey == 'C') reset();
      }
    }

    if (cKey == '#' and not state) state = 1;
    else if (cKey == '#' and state) state = 0;

    uiTmr = millis();
  }

  if (millis() - displayTmr >= 1000) {
    set(0, 1);
    print("ActualVal:");
    set(10, 1);
    lcd.print(String(sens.getValue()));

    displayTmr = millis();
  }
}

int UserInterface::getSetPoint() {
  return int(myTxt);
}

bool UserInterface::getState() {
  return state;
}

void UserInterface::reset() {
  lcd.clear();
  memset(myTxt, 0, sizeof(myTxt));
  index = 0;
  cursor = 10;
  state = false;
}

void UserInterface::set(uint8_t x, uint8_t y) {
  lcd.setCursor(x, y);
}

void UserInterface::print(const char *txt) {
  lcd.print(txt);
}

bool UserInterface::check(char key) {
  bool _state;
  if (isDigit(key)) _state = 1;
  else _state = 0;
  return _state;
}

void UserInterface::splashScreen() {
  set(3, 0);
  print("Si Ganteng");
  set(3, 1);
  print("SMK Soehat");

  delay(SPLSHTIME);
  lcd.clear();
}
