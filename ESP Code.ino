#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Servo.h>
#include <DS3231.h>

// Replace with your Wi-Fi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Replace with your Blynk authentication token
const char* authToken = "YOUR_BLYNK_AUTH_TOKEN";

// Define pins
#define TRIG_PIN 12
#define ECHO_PIN 13
#define SERVO_PIN 5
#define BUZZER_PIN 6
#define RED_LED_PIN 7
#define GREEN_LED_PIN 8

// Initialize components
Servo feederServo;
DS3231 rtc;

// Thresholds for alerts
const int foodLevelThreshold = 10; // Minimum food level in cm

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize sensors and actuators
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  // Attach servo to pin
  feederServo.attach(SERVO_PIN);

  // Initialize RTC
  rtc.begin();

  // Turn off buzzer and LEDs initially
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH); // Green LED indicates normal condition

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wi-Fi connected");

  // Initialize Blynk
  Blynk.begin(authToken, ssid, password);
}

void loop() {
  // Get current time from RTC
  DateTime now = rtc.now();
  int hour = now.hour();
  int minute = now.minute();

  // Check if it's feeding time (e.g., 8:00 AM and 6:00 PM)
  if ((hour == 8 && minute == 0) || (hour == 18 && minute == 0)) {
    dispenseFood();
    sendNotification("Feeding time! Food has been dispensed.");
  }

  // Monitor food level
  int foodLevel = getFoodLevel();
  if (foodLevel < foodLevelThreshold) {
    Serial.println("Low food level detected!");
    digitalWrite(RED_LED_PIN, HIGH); // Turn on red LED
    digitalWrite(GREEN_LED_PIN, LOW); // Turn off green LED
    sendNotification("Warning: Food level is low!");
  } else {
    digitalWrite(RED_LED_PIN, LOW); // Turn off red LED
    digitalWrite(GREEN_LED_PIN, HIGH); // Turn on green LED
  }

  // Run Blynk
  Blynk.run();

  delay(1000); // Adjust loop speed
}

void dispenseFood() {
  // Rotate servo to dispense food
  feederServo.write(90); // Open the dispenser
  delay(1000);
  feederServo.write(0); // Close the dispenser

  // Activate buzzer to alert the pet
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
}

int getFoodLevel() {
  // Trigger ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo pin
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2; // Convert to cm

  return distance;
}

void sendNotification(String message) {
  // Send notification via Blynk
  Blynk.notify(message);
}
