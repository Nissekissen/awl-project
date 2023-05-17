#ifndef BUTTON_H
#define BUTTON_H

class Button {
    public:
        bool isPressed() { return pressed; };
        int getBtnPin() { return btnPin; };
        void setBtnPin(int pin) { btnPin = pin; pinMode(pin, INPUT_PULLUP); };
        int getLampPin() { return lampPin; };
        void setLampPin(int pin) { lampPin = pin; };
        int setLamp(int val) { digitalWrite(lampPin, val); }
        void loop();
    private:
        bool pressed;
        int btnPin;
        int lampPin;
        int btnState;
};

#endif