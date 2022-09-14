#include "UI.h"
#include "Pins.h"
#include "LiquidCrystal_I2C.h"
#include "Keypad_I2C.h"
#include "Keypad.h"

UserInterface ui;

LiquidCrystal_I2C lcd(LCDADDR, 16, 2);

Keypad_I2C cKey( makeKeymap(pin::hq), pin::row, pin::col,
                 ROWS, COLS, KYPDADDR);

void UserInterface::Init() {
  Ser.begin(BAUDRATE);
  lcd.init();
  lcd.backlight();
  cKey.begin();
}

void UserInterface::Handler() {
  if (millis() - uiTmr >= 30) {
    customKey = cKey.getKey();

    this->set(0, 0);
    this->print("SetPoint:");
    if (customKey) {
      this->set(this->cursor, 0);
      lcd.print(customKey);
      cursor++;

      if (cursor == 16) {
        lcd.clear();
        cursor = 10;
      }
      myTxt.concat(customKey);
      Ser.print(myTxt);
    } else customKey = '\0';


    uiTmr = millis();
  }
}

void UserInterface::set(uint8_t x, uint8_t y) {
  lcd.setCursor(x, y);
}

void UserInterface::print(const char *txt) {
  lcd.print(txt);
}

void UserInterface::splashScreen() {
  this->set(3, 0);
  this->print("Si Ganteng");
  this->set(3, 1);
  this->print("SMK Soehat");
  delay(3000);
  lcd.clear();
}
