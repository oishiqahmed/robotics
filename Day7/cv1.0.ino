#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char *ssid = "...";
const char *password = "...";

WebServer server(80);

Servo servo1;
Servo servo2;

const int servoPin1 = 18;
const int servoPin2 = 4;

int currentAngle1 = 90;
int currentAngle2 = 90;

void handleRoot()
{
    String page =
        "<!DOCTYPE html>"
        "<html>"
        "<head>"
        "<meta name='viewport' content='width=device-width, initial-scale=1'>"
        "</head>"
        "<body>"
        "<h2>ESP32 Servo Control</h2>"

        "<p>Servo 1</p>"
        "<input type='range' min='0' max='180' value='90' "
        "oninput='updateServo1(this.value)'>"

        "<p>Servo 2</p>"
        "<input type='range' min='0' max='180' value='90' "
        "oninput='updateServo2(this.value)'>"

        "<script>"
        "function updateServo1(angle){"
        "fetch('/servo1?angle=' + angle);"
        "}"

        "function updateServo2(angle){"
        "fetch('/servo2?angle=' + angle);"
        "}"
        "</script>"

        "</body>"
        "</html>";

    server.send(200, "text/html", page);
}

void handleServo1()
{
    if (server.hasArg("angle"))
    {
        currentAngle1 = constrain(server.arg("angle").toInt(), 0, 180);

        servo1.write(currentAngle1);

        server.send(200, "text/plain", "OK");
    }
}

void handleServo2()
{
    if (server.hasArg("angle"))
    {
        currentAngle2 = constrain(server.arg("angle").toInt(), 0, 180);

        servo2.write(currentAngle2);

        server.send(200, "text/plain", "OK");
    }
}

void setup()
{
    Serial.begin(115200);

    WiFi.begin(ssid, password);

    servo1.attach(servoPin1);
    servo2.attach(servoPin2);

    servo1.write(currentAngle1);
    servo2.write(currentAngle2);

    Serial.print("Connecting");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.print("Connected. IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);
    server.on("/servo1", handleServo1);
    server.on("/servo2", handleServo2);

    server.begin();
}

void loop()
{
    server.handleClient();
}
