#include <Servo.h>

// Constants won't change
const int TRIG_PIN  = 6;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN  = 7;  // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int SERVO_PIN = 9;  // Arduino pin connected to Servo Motor's pin
const int DISTANCE_THRESHOLD = 50;  // Distance threshold in centimeters

Servo servo;  // Create servo object to control a servo

// Variables will change:
float duration_us, distance_cm;

void setup() {
  Serial.begin(9600);        // Initialize serial port
  pinMode(TRIG_PIN, OUTPUT);  // Set Arduino pin to output mode for TRIG
  pinMode(ECHO_PIN, INPUT);   // Set Arduino pin to input mode for ECHO
  servo.attach(SERVO_PIN);    // Attaches the servo on pin 9 to the servo object
  servo.write(0);             // Set initial position of the servo to 0 degrees
}

void loop() {
  // Generate a 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance in centimeters
  distance_cm = 0.017 * duration_us;

  // Control the servo based on the measured distance
  if (distance_cm < DISTANCE_THRESHOLD)
    servo.write(90);  // Rotate servo motor to 90 degrees
  else
    servo.write(0);   // Rotate servo motor to 0 degrees

  // Print the distance value to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);  // Delay for stability and to reduce Serial Monitor output
}
