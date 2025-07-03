#include <Servo.h>

Servo solarServo;

int ldrLeftPin = A0; // LDR on the left
int ldrRightPin = A1; // LDR on the right
int servoPin = 9;

int threshold = 10; // Small difference threshold to avoid unnecessary movements
int servoPos = 90; // Start with the servo in the middle position

void setup() {
  Serial.begin(9600);
  solarServo.attach(servoPin); // Attach the servo motor
  solarServo.write(servoPos);  // Move servo to initial position (90 degrees)
}

void loop() {
  int ldrLeftValue = analogRead(ldrLeftPin); // Read the left LDR value
  int ldrRightValue = analogRead(ldrRightPin); // Read the right LDR value

  int difference = ldrLeftValue - ldrRightValue; // Compare light intensity

  // If the difference is significant enough, adjust the servo position
  if (abs(difference) > threshold) {
    if (difference > 0 && servoPos > 0) {
      // Left is brighter, turn servo to the left
      servoPos--;
    } else if (difference < 0 && servoPos < 180) {
      // Right is brighter, turn servo to the right
      servoPos++;
    }
    solarServo.write(servoPos); // Update servo position
  }

  delay(100); // Small delay to allow time for movement and sensor reading
}
