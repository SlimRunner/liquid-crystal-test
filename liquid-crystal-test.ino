#include <LiquidCrystal.h>
#include "Dialog.hpp"

int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup() {
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.

  char msg[] = "hello world!";
  const int MSG_SIZE = sizeof(msg) / sizeof(msg[0]) - 1;
  for (int i = 0; i < MSG_SIZE; ++i) {
    lcd_1.setCursor(i, 0);
    lcd_1.print(msg[i]);
    delay(200);
  }
}

void loop() {
  int a0volt = analogRead(A0);
  lcd_1.clear();
  lcd_1.setCursor(0, 1);
  lcd_1.print(a0volt);
  delay(500);
}