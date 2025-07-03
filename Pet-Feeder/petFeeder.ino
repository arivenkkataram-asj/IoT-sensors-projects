#include <Servo.h>

Servo feederServo;

// Ultrasonic Sensor Pins
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

// Threshold for detecting pet (in cm)
const int petDistanceThreshold = 15; // Adjust based on your setup

void setup() {
  // Servo setup
  feederServo.attach(3); 
  feederServo.write(0); // Initial position of servo motor (closed)

  // Ultrasonic sensor setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Check if pet is within range
  if (distance < petDistanceThreshold) {
    Serial.println("Pet detected, dispensing food!");
    dispenseFood();
  } else {
    Serial.println("No pet detected.");
  }
  
  delay(1000); // Adjust delay as necessary
}

// Function to dispense food
void dispenseFood() {
  feederServo.write(90); // Rotate servo to 90 degrees (release food)
  delay(1000); // Wait for 1 second
  feederServo.write(0);  // Return to 0 degrees (stop dispensing)
}
