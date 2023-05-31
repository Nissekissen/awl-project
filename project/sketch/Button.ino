#include "Button.h"

void Button::loop() {
  btnState = digitalRead(btnPin);

  if (btnState == 1) {
    pressed = true;
  } else {
    pressed = false;
  }
}