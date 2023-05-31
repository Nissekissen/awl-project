#include <LiquidCrystal.h>


#include "GameHandler.h"
#include "LCDHandler.h"

GameHandler gameHandler;

// LCDHandler lcd;

void setup() {
  
  Serial.begin(9600);
  // lcd.setCursor(15, 0);
}

void loop() {
  gameHandler.loop();
}