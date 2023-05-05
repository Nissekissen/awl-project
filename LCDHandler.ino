#include "LCDHandler.h"


LCDHandler::setCursor(int x, int y) {
    currentDisplay = y;
    cursorX = x % 8;
    cursorY = floor(x / 8);
    Serial.print(cursorX);
    Serial.print(" ");
    Serial.print(cursorY);
    Serial.print("\n");
}

LCDHandler::print(String text) {
    for (int i = 0; i < text.length(); i++) {
        
        if (cursorX >= 8) {
            cursorX = 0;
            cursorY++;
            if (cursorY >= 2) {
                cursorY = 0;
                currentDisplay++;
            }
        }
        (currentDisplay == 0 ? lcd1 : lcd2).print(text[i]);
        cursorX++;
    }
}

LCDHandler::print(int text) {
    String str = String(text);
    for (int i = 0; i < str.length(); i++) {
        
        if (cursorX >= 8) {
            cursorX = 0;
            cursorY++;
            if (cursorY >= 2) {
                cursorY = 0;
                currentDisplay++;
            }
        }
        Serial.print(str[i]);
        Serial.print(" ");
        Serial.print(cursorX);
        Serial.print(" ");
        Serial.print(cursorY);
        Serial.print("\n");
        (currentDisplay == 0 ? lcd1 : lcd2).print(str[i]);
        cursorX++;
    }
}

LCDHandler::clear() {
    lcd1.clear();
    lcd2.clear();
    currentDisplay = 0;
    cursorX = 0;
    cursorY = 0;
}

LCDHandler::begin(int x, int y) {
    lcd1.begin(8, 2);
    lcd2.begin(8, 2);
}