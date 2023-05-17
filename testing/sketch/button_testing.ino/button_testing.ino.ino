

#define PIN 22

int btnState = 0;
bool _continue = true;

void setup() {
  pinMode(PIN, INPUT);
  Serial.begin(9600);

}

void loop() {
  if (!_continue) {
    return;
  }
  Serial.println("Plug in the button.");
  for (int i = 0; i < 50; i++) {
    btnState = digitalRead(PIN);
    if (btnState == HIGH) {
      _continue = false;
      Serial.println("Test failed.");
      break;
    }
    delay(100);
  }
  if (!_continue) {
    return;
  }

  Serial.println("Press down on the button.");
  delay(3000);
  for (int i = 0; i < 10; i++) {
    btnState = digitalRead(PIN);
    if (btnState == LOW) {
      _continue = false;
      Serial.println("Test failed.");
      break;
    }
    delay(100);
  }

  if (!_continue) {
    return;
  }

  Serial.println("Release the button.");
  delay(3000);
  for (int i = 0; i < 10; i++) {
    btnState = digitalRead(PIN);
    if (btnState == HIGH) {
      _continue = false;
      Serial.println("Test failed.");
      break;
    }
    delay(100);
  }
  if (!_continue) {
    return;
  }

  Serial.println("Test passed");

  delay(10000);

}



