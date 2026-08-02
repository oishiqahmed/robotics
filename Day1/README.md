# Day 1

### Components:
- Dual-core ESP32-S3 WROOM-1 Microcontroller
- DS18B20 Waterproof Temperature Sensor
- Breadboard & Jumper wires
- USB-cable

### Description:
I've set up the Arduino IDE. I've learned to confugure a Microcontroller and troubleshooting connectivity and port settings.I've implemented breadboard mechnics for the first time and successfully identified and wires a waterproof digital temperature probe using its Red(3.3V Power), Black(Ground) and Yellow(GPIO 4 Data).
Since I didn't have an external resistor I had to use the inter resister of the microcontroller using ```pinMode(GPIO, INPUT_PULLUP)```.
I've written and uploaded C++ code using core Arduino blocks, installed and utilized externsl libraries (```OneWire``` and ```DallasTemperature```) to read real=world environmental data.
I've identified the onboard WS2812 NeoPixel LED on GPIO 48 and controlled RGB color spectrum mixing using ```neopixelWrite(pin, Red, Green, Blue)```

I've created a real-time smart alert system that evaluates temperature threshold and triggers an automated visual signal (Red light) if the temperature reaches the limit. It keeps printing current temperature every two secons on the Serial Monitor.