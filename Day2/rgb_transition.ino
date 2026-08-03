#define LED_PIN 48

void setup() {
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  pinMode(LED_PIN, OUTPUT);
  neopixelWrite(LED_PIN, 0, 0, 0);
}

void loop() {
  for (int rgb = 0; rgb <= 255; rgb++) {
    neopixelWrite(LED_PIN, rgb, 0, 0);
    delay(10);
  }
  for (int rgb = 255; rgb >= 0; rgb--) {
    neopixelWrite(LED_PIN, rgb, 0, 0);
    delay(10);
  }
  for (int rgb = 0; rgb <= 255; rgb++) {
    neopixelWrite(LED_PIN, 0, rgb, 0);
    delay(10);
  }
  for (int rgb = 255; rgb >= 0; rgb--) {
    neopixelWrite(LED_PIN, 0, rgb, 0);
    delay(10);
  }
  for (int rgb = 0; rgb <= 255; rgb++) {
    neopixelWrite(LED_PIN, 0, 0, rgb);
    delay(10);
  }
  for (int rgb = 255; rgb >= 0; rgb--) {
    neopixelWrite(LED_PIN, 0, 0, rgb);
    delay(10);
  }
}