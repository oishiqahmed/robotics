import speech_recognition as sr
import pyttsx3
import requests

ESP32_IP = "..."

def move_servo(servo_number, angle):
    angle = max(0, min(180, angle))

    url = f"http://{ESP32_IP}/servo{servo_number}"

    try:
        response = requests.get(
            url,
            params={"angle": angle},
            timeout=2
        )

        if response.ok:
            speak(f"Servo {servo_number} moved to {angle} degrees.")
        else:
            speak("The ESP32 returned an error.")

    except requests.RequestException:
        speak("I could not connect to the ESP32.")

def speak(text):
    print(f"Assistant: {text}")
    engine = pyttsx3.init()
    engine.setProperty("rate", 175)
    engine.say(text)
    engine.runAndWait()
    engine.stop()

def listen():
    recognizer = sr.Recognizer()

    with sr.Microphone() as source:
        print("\nListening...")
        recognizer.adjust_for_ambient_noise(source, duration=1.0)
        audio = recognizer.listen(source)

    try:
        command = recognizer.recognize_google(audio).lower()
        print(f"Command: {command}")
        return command

    except sr.UnknownValueError:
        print("Sorry, I didn't catch that.")
        return ""

    except sr.RequestError:
        print("Network connection error.")
        return ""

def run_assistant():
    speak("Voice assistant ready.")

    while True:
        command = listen()

        if "servo" in command and ("one" in command or "1" in command):
            if "zero" in command or "0" in command:
                move_servo(1, 0)

            elif ("forty" in command and "five" in command) or "45" in command:
                move_servo(1, 45)

            elif "ninety" in command or "90" in command:
                move_servo(1, 90)

            elif "one hundred eighty" in command or ("one" in command and "eighty" in command) or "180" in command:
                move_servo(1, 180)

        elif "servo" in command and ("two" in command or "2" in command):
            if "zero" in command or "0" in command:
                move_servo(2, 0)

            elif ("forty" in command and "five" in command) or "45" in command:
                move_servo(2, 45)

            elif "ninety" in command or "90" in command:
                move_servo(2, 90)

            elif "one hundred eighty" in command or ("one" in command and "eighty" in command) or "180" in command:
                move_servo(2, 180)

        elif "exit" in command:
            speak("Closing voice assist.")
            break

if __name__ == "__main__":
    run_assistant()
