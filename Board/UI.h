#pragma once

#define   BAUDRATE  9600
#define   Ser       Serial

struct UserInterface {
    void Init();
    void Handler();
    void splashScreen();
    int getSetPoint();
    bool getState();

    void set(uint8_t x, uint8_t y);
    void print(const char *txt);

  private:
    char cKey;
    char myTxt[10];
    bool state = false;
    uint16_t cursor = 10;
    void reset();
    uint8_t index = 0;
    bool check(char key);
    uint32_t uiTmr;
    uint32_t displayTmr;
};

extern UserInterface ui;
