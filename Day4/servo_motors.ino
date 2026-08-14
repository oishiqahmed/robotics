#include <ESP32Servo.h>

Servo servo1;
Servo servo2;

const int SERVO_PIN1 = 18;
const int SERVO_PIN2 = 19;
const int BUTTON_PIN = 4;

int currentAngle = 0;
int lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  servo1.setPeriodHertz(50);
  servo2.setPeriodHertz(50);
  servo1.attach(SERVO_PIN1, 500, 2400);
  servo2.attach(SERVO_PIN2, 500, 2400);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  servo1.write(currentAngle);
  servo2.write(currentAngle);

  Serial.println("Servos initialized");
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {
    delay(100);

    if (currentAngle == 0) {
      currentAngle = 180;
    }
    else {
      currentAngle = 0;
    }
    
    Serial.print("Moving servos to...");
    Serial.print(currentAngle);
    Serial.println("degree");

    servo1.write(currentAngle);
    servo2.write(currentAngle);
  }

  lastButtonState = buttonState;
  delay(10);
}
