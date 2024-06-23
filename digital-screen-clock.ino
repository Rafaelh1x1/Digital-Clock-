#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimeLib.h>

// Set the LCD address to 0x27 for a 20 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 2);

void setup() {
  Serial.begin(9600);              // Start serial communication for debugging
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  
  // Set the initial time (e.g., 20:29:30 on June 21, 2024)
  setTime(20, 37, 30, 21, 6, 2024);
}

void loop() {
  // Get the current hour in 12-hour format
  int h = hour();
  int displayHour = h % 12;
  if (displayHour == 0) {
    displayHour = 12; // Adjust for 12 AM and 12 PM
  }
  
  // Determine AM or PM
  char* ampm = (h >= 12) ? "PM" : "AM";

  // Format the time as HH:MM AM/PM
  char timeBuffer[12];
  snprintf(timeBuffer, sizeof(timeBuffer), "%02d:%02d %s", displayHour, minute(), ampm);

  // Display the time on the LCD
  lcd.setCursor(0, 0);
  lcd.print(timeBuffer);

  // Format the date as DD/MM/YYYY
  char dateBuffer[12];
  snprintf(dateBuffer, sizeof(dateBuffer), "%02d/%02d/%04d", month(), day(), year());

  // Display the date on the LCD
  lcd.setCursor(0, 1);
  lcd.print(dateBuffer);

  // Print the date to the serial monitor for debugging
  Serial.print("Day: ");
  Serial.print(day());
  Serial.print(" Month: ");
  Serial.print(month());
  Serial.print(" Year: ");
  Serial.println(year());

  // Wait for a second before updating the display
  delay(1000);
}
