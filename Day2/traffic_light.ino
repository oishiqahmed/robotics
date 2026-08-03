#define LED_PIN 48

void setup() {
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  pinMode(LED_PIN, OUTPUT);
  neopixelWrite(LED_PIN, 0, 0, 0);
}

void loop() {
  neopixelWrite(LED_PIN, 255, 0, 0);
  Serial.println("STOP!");
  delay(5000);
  neopixelWrite(LED_PIN, 255, 165, 0);
  Serial.println("WAIT!");
  delay(2000);
  neopixelWrite(LED_PIN, 0, 255, 0);
  Serial.println("GO!");
  delay(5000);
  neopixelWrite(LED_PIN, 255, 165, 0);
  Serial.println("WAIT!");
  delay(2000);
}