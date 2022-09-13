#pragma once

#define BAUDRATE 9600
#define Ser Serial

#define ROWS 4
#define COLS 4

struct UserInterface {
    void Init();
    void Handler();
    void splashScreen();
    void set(uint8_t x, uint8_t y);
    void print(const char *txt);

  private:
    char customKey;
    uint16_t cursor = 10;
    String myTxt = "";
    uint32_t uiTmr;
    uint32_t displayTmr;
    uint32_t keyTmr;
};

extern UserInterface ui;
