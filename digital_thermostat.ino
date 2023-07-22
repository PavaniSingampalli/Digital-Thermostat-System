#include <LiquidCrystal.h>

// Define LCD display pins
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define buttons
const int upButton = A0;
const int downButton = A1;

// Temperature range
const int minTemperature = 0;
const int maxTemperature = 100;

// Control parameters
const int tolerance = 2; // Tolerance for temperature control
const int heatingThreshold = 2; // Degrees below setpoint to activate heating
const int coolingThreshold = 2; // Degrees above setpoint to activate cooling

// Variables
int desiredTemperature = 25; // Initial desired temperature
int currentTemperature = 25; // Initial current temperature


void setup() {
  lcd.begin(16, 2);
  lcd.print("Desired Temperature: ");
  lcd.setCursor(0, 1);
  lcd.print("Current Temperature: ");
}

void loop() {
  // Read buttons
  int upState = digitalRead(upButton);
  int downState = digitalRead(downButton);

  // Adjust desired temperature
  if (upState == HIGH) {
    desiredTemperature++;
    if (desiredTemperature > maxTemperature) {
      desiredTemperature = maxTemperature;
    }
    updateDisplay();
    delay(250); // Button debounce delay
  }
  if (downState == HIGH) {
    desiredTemperature--;
    if (desiredTemperature < minTemperature) {
      desiredTemperature = minTemperature;
    }
    updateDisplay();
    delay(250); // Button debounce delay
  }


  // Simulate temperature fluctuations (you can replace this with actual sensor readings)
  simulateTemperature();

  // Control algorithm
  if (currentTemperature < desiredTemperature - heatingThreshold) {
    // Activate heating
    lcd.setCursor(10, 0);
    lcd.print("ON ");
  } 
else if (currentTemperature > desiredTemperature + coolingThreshold) {
    // Activate cooling
    lcd.setCursor(10, 0);
    lcd.print("OFF");
  }

  // Update display
  updateDisplay();

  delay(1000); // Temperature update interval
}

void simulateTemperature() {
  // Simulate temperature changes by generating random values
  int randomValue = random(-2, 3); // Generate a random value between -2 and 2
  currentTemperature += randomValue;
}

void updateDisplay() {
  // Update desired temperature display
  lcd.setCursor(9, 0);
  lcd.print("   "); // Clear previous value
  lcd.setCursor(9, 0);
  lcd.print(desiredTemperature);

  // Update current temperature display
  lcd.setCursor(9, 1);
  lcd.print("   "); // Clear previous value
  lcd.setCursor(9, 1);
  lcd.print(currentTemperature);
}


