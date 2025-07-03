# 🔧 Embedded IoT Projects Collection

Welcome to the **Embedded IoT Projects Collection** — a curated set of mini-projects that combine embedded systems and IoT principles using a variety of sensors, actuators, and communication protocols.

Each project is developed using microcontrollers like **ESP32**, **RP2040**, and focuses on solving real-world problems in a modular and efficient way.

---

## 📁 Projects Overview

### 🐾 1. Pet Feeder using Servo Motor
- Automatically dispenses food using a servo motor
- Timer-based or sensor-activated system
- Potential integration with MQTT for remote control

### 🚶‍♂️ 2. Animal/PIR Sensor-Based Motion Detector
- Detects motion using a PIR sensor
- Activates buzzer or LED upon movement
- Useful for intruder alert or pet monitoring systems

### 🔥 3. Flame Sensor Fire Detection
- Detects flame or high temperature conditions
- Activates alert (buzzer/LED)
- Can send MQTT alert for real-time notification

### 🌡️ 4. Temperature & Humidity Monitoring (DHT11)
- Uses DHT11 to read environmental data
- Data can be displayed on LCD or sent via MQTT
- Logs values periodically

### ☀️ 5. Solar Panel Tracking System (LDR-Based)
- Dual LDRs track sunlight and rotate solar panel using servo
- Maximizes solar efficiency
- Can run autonomously using battery power

### 💬 6. MQTT Communication Test
- Basic implementation of MQTT protocol
- Publishes sensor data and receives control commands
- Broker: HiveMQ or Mosquitto

---

## 🛠️ Tech Stack

- **MCUs**: ESP32, RP2040, RP2350
- **Protocols**: MQTT, I2C, PWM, GPIO
- **Sensors**: DHT11, PIR, Flame Sensor, LDR
- **Actuators**: Servo Motor, Buzzer, LEDs
- **Power Systems**: Battery, Solar + LDO
- **Tools**: Arduino IDE, PlatformIO, KiCAD (PCB design)

---
