/*
 * Program name: pruebaSegmentos.ino
 * Author: Álvaro R.
 * Date: 14th november 2023
 * Description: rogram tests all segments in the display.
 */

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
