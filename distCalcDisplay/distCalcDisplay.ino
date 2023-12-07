#include <LiquidCrystal_I2C.h>

// Include the LiquidCrystal_I2C library for controlling the LCD display.

// Define I2C address......
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Create variables to store pin numbers for ultrasonic sensor
int trig = 2;
int echo = 3;

// Create variables to store duration and distance measurements
long duretion, distance;

void setup() {
  // Set the trig pin as OUTPUT and echo pin as INPUT
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // Initialize and clear the LCD display
  lcd.init();
  lcd.clear();
  lcd.backlight();

  // Set the cursor to the specified position and print messages
  lcd.setCursor(2, 0);
  lcd.print("Distance");

  lcd.setCursor(1, 1);
  lcd.print("UltraSonic");

  // Delay for 2000 milliseconds (2 seconds)
  delay(2000);

  // Clear the LCD display
  lcd.clear();
}

void loop() {
  // Send a short pulse to the trig pin to trigger the ultrasonic sensor
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);

  // Measure the duration of the pulse received by the echo pin
  duretion = pulseIn(echo, HIGH);

  // Calculate the distance based on the speed of sound (approx. 0.0346 cm/microsecond)
  distance = (duretion / 2) * 0.0346;

  // Set the cursor to the specified position and print the distance value
  lcd.setCursor(3, 0);
  lcd.print(distance);

  // Set the cursor to the specified position and print the unit "cm"
  lcd.setCursor(6, 0);
  lcd.print("cm");
}
