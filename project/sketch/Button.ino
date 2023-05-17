#include "Button.h"

void Button::loop() {
  btnState = digitalRead(btnPin);
  if (btnState == 1) {
    Serial.print("Button: ");
    Serial.print(btnPin);
    Serial.print(", State: ");
    Serial.print(btnState);
    Serial.print("\n");
  }


  if (btnState == 1) {
    pressed = true;
  } else {
    pressed = false;
  }
}