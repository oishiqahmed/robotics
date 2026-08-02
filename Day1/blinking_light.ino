#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4
#define LED_PIN 48

const float TEMPERATURE_THRESHOLD_C = 33.0;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  pinMode(ONE_WIRE_BUS, INPUT_PULLUP);

  pinMode(LED_PIN, OUTPUT);
  neopixelWrite(LED_PIN, 0, 0, 0);

  sensors.begin();
  Serial.println("Temperature sensor test");
}

void loop() {
  sensors.requestTemperatures();

  float tempC = sensors.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.println(tempC, 1);

  if (tempC >= TEMPERATURE_THRESHOLD_C) {
    Serial.println("[ALERT] TOO HOT! (not really but ok)");
    for (int i = 0; i < 3; i++) {
      neopixelWrite(LED_PIN, 100, 0, 100);
      delay(200);
      neopixelWrite(LED_PIN, 0, 0, 0);
      delay(200);
    }
  }
  else {
    Serial.println("Normal Temperature");
    neopixelWrite(LED_PIN, 0, 0, 0);
    delay(2000);
  }
}