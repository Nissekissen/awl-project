#ifndef LCDHANDLER_H
#define LCDHANDLER_H

class LCDHandler {
    // This class interprets two 16x1 (8x2) displays as one 16x2 display. Has the same basic functions as the LCD library
    public:
        print(String text);
        print(int text);
        clear();
        setCursor(int x, int y);
        begin(int x, int y);
    private:
        LiquidCrystal lcd1{42, 43, 44, 45, 46, 47};
        LiquidCrystal lcd2{50, 51, 52, 53, 4, 5};
        int currentDisplay = 0;
        int cursorX = 0;
        int cursorY = 0;
};



#endif