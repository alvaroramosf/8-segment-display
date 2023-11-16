/*
 * Program name: pruebaSegmentos.ino
 * Author: Álvaro R.
 * Date: 14th november 2023
 * Description: rogram tests all segments in the display.
 * Board: MH-ET Live Attiny88
 */

// Pinout of the display
//                             F  G  A GND H  B
// F A A A A A B               12 11 10 09 08 07
// F G       H B               |  |  |  |  |  |
// F G       H B              ******************
// F    G H    B              *       |8|.     *
// E    J I    C              *                *
// E J       I C              ******************
// E J       I C               |  |  |  |  |  |
// E D D D D D C   K          01 02 03 04 05 06
//                             E  J  D  I  C  K


int segmentPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

void setup() {
  for (int i = 0; i < 12; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
    for (int i = 0; i < 12; i++) {
      digitalWrite(segmentPins[i], 1);
      delay(100);
    }
    delay(1500);
    for (int i = 0; i < 12; i++) {
      digitalWrite(segmentPins[i], 0);
      delay(100);
    }
}
