#include "Dialog.hpp"
#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
Dialog typist(lcd_1, 16, 2, 60, 800, 1000);

void setup() {
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.

  typist.write("Hello world!");
  typist.write("This is a really long text that is meant to test my library "
               "and what it can do.");
}

void loop() {
  // int a0volt = analogRead(A0);
  // lcd_1.clear();
  // lcd_1.setCursor(0, 1);
  // lcd_1.print(a0volt);
  // delay(500);
}