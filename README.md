# Automatic Pet Feeder with Real-Time Notifications Using ESP32

This repository contains the Arduino code, configuration, and assembly instructions for building an automatic pet feeder using the ESP32 microcontroller. The system automates feeding schedules and sends real-time notifications to a mobile app when feeding occurs <button class="citation-flag" data-index="1">. This project is ideal for pet owners who want to ensure their pets are fed on time, even when they are not at home.

---

## Table of Contents
1. [Overview](#overview)
2. [Components Used](#components-used)
3. [System Dimensions](#system-dimensions)
4. [Assembly Instructions](#assembly-instructions)
5. [Arduino Code Explanation](#arduino-code-explanation)
6. [Contributing](#contributing)
7. [License](#license)

---

## Overview
The automatic pet feeder uses the ESP32 to control a servo motor that dispenses food at scheduled times. It also monitors food levels using an ultrasonic sensor and sends real-time notifications to a mobile app like Blynk <button class="citation-flag" data-index="4">. If the food level is low, the system alerts the user via notifications. This project ensures pets are fed on time and helps users monitor food levels remotely.

---

## Components Used
To build this automatic pet feeder, you will need the following components:
- **ESP32 Development Board**
- **Micro Servo (e.g., SG90)**
- **HC-SR04 Ultrasonic Sensor**
- **DS3231 RTC Module**
- **Active Buzzer**
- **Red LED**
- **Green LED**
- **Jumper Wires**
- **Breadboard (Optional)**

---

## System Dimensions
For an ideal automatic pet feeder:
- **Height**: 20–25 cm
- **Width**: 15–20 cm
- **Length**: 15–20 cm

These dimensions ensure that the system is compact yet spacious enough to house all components and store sufficient food.

---

## Assembly Instructions
Follow these detailed steps to assemble your automatic pet feeder:
1. Attach the servo motor to a rotating disk or flap for dispensing food.
2. Connect the ultrasonic sensor to monitor food levels.
3. Connect the RTC module for accurate scheduling.
4. Connect the buzzer and LEDs for alerts and status indicators.
5. Power the system using a USB cable.
6. Secure all components inside a protective enclosure.

---

## Arduino Code Explanation
The provided Arduino code schedules feeding times using the RTC module and controls the servo motor to dispense food. The ultrasonic sensor monitors food levels, and notifications are sent to a mobile app like Blynk when feeding occurs or when food levels are low <button class="citation-flag" data-index="1">. The system also includes visual and audible alerts for the pet.

---

## Contributing
Feel free to fork this repository and contribute improvements or new features. If you have suggestions or find bugs, please open an issue.

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

By following this guide, you should be able to build and test your own automatic pet feeder using the ESP32. Happy tinkering! 🚀
