#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  delay(2000);                     // Wait for 2 seconds to ensure the LCD is ready
  // lcd.setCursor(0, 0);             // Move cursor to the first column, first row
  lcd.print("My name is Rafael");     // Print text on the first line
  lcd.setCursor(0, 1);             // Move cursor to the first column, second row
  lcd.print("I be coding n shit"); // Print text on the second line
  lcd.setCursor(0, 2);
  lcd.print("Someone hire me");
}

void loop() {
  // You can update the display content here if needed
  delay(1000);
}