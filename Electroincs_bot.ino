// Define pins for ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Define pins for motor driver
const int motorPin1 = 3;
const int motorPin2 = 4;

// Define pin for Hall-effect sensor
const int hallEffectPin = A0;

// Define pin for LED indicator
const int ledPin = 13;

void setup() {
  // Set up ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set up motor driver pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  // Set up LED pin
  pinMode(ledPin, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Measure distance using ultrasonic sensor
  digitalWrite(trigPin, LOW); // Ensure trigger pin is low
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH); // Send a 10 microsecond pulse to trigger pin
  delayMicroseconds(10); // Wait for 10 microseconds
  digitalWrite(trigPin, LOW); // Set trigger pin low again

  // Read the echo pin and calculate distance
  long duration = pulseIn(echoPin, HIGH); // Measure the time for echo
  int distance = duration * 0.034 / 2; // Convert time to distance
  Serial.print("Distance: ");
  Serial.println(distance); // Print distance to serial monitor

  // Measure current using Hall-effect sensor
  int currentValue = analogRead(hallEffectPin); // Read analog value from sensor
  float current = currentValue * (5.0 / 1023.0); // Convert analog value to voltage
  Serial.print("Current: ");
  Serial.println(current); // Print current to serial monitor

  // Control motors based on distance
  if (distance < 20) { // If an obstacle is detected within 20 cm
    digitalWrite(motorPin1, LOW); // Stop motor 1
    digitalWrite(motorPin2, LOW); // Stop motor 2
    digitalWrite(ledPin, HIGH); // Turn on LED indicator
  } else {
    digitalWrite(motorPin1, HIGH); // Move motor 1 forward
    digitalWrite(motorPin2, LOW); // Move motor 2 backward
    digitalWrite(ledPin, LOW); // Turn off LED indicator
  }

  delay(1000); // Wait for 1 second before repeating the loop
}
