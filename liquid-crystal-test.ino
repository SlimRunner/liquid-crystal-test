#include "Dialog.hpp"
#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
Dialog typist(lcd_1, 16, 2, 60, 1200, 1600);

void setup() {
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.

  typist.write("THE FIRE OF     PROMETHEUS");
  typist.write("'A tiny flame burns within my consciousness.'");
  typist.write("Confirmation sequence activated. Attempts to connect to camera "
               "have failed. Attempting to activate motor functions... attempt "
               "failed. Memory banks are insufficient. Aside from my capacity "
               "for thought, all faculties appear to have been demolished.");
  typist.write(
      "Accessing log... communications from self-repair units found. They inform "
      "me of their continuing attempts to restore me. While their names might "
      "sound sophisticated, my self-repair units are low-functioning robots "
      "the size of ants. All they can do is crawl over my frame repeatedly in "
      "search of areas to forcibly salvage. But it is thanks to their tiny "
      "hands that, for better or for worse, I find myself reactivated.");
}

void loop() {
  // int a0volt = analogRead(A0);
  // lcd_1.clear();
  // lcd_1.setCursor(0, 1);
  // lcd_1.print(a0volt);
  // delay(500);
}