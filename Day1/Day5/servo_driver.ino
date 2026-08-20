#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

const int SDA_PIN = 8;
const int SCL_PIN = 9;
const int BUTTON_PIN = 4;

#define SERVOMIN 180
#define SERVOMAX 520

int currentAngle = 0;
int lastButtonState = HIGH;

int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Wire.begin(SDA_PIN, SCL_PIN);

  pwm.begin();
  pwm.setPWMFreq(50);

  pwm.setPWM(0, 0, angleToPulse(0));
  pwm.setPWM(1, 0, angleToPulse(0));

  Serial.println("Servos initialized!");
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
    Serial.println(" degrees");

    int pulse = angleToPulse(currentAngle);
    pwm.setPWM(0, 0, pulse);
    pwm.setPWM(1, 0, pulse);
  }

  lastButtonState = buttonState;
  delay(10);
}
