/*
 * Program name: pruebaSegmentos.ino
 * Author: Álvaro R.
 * Date: 14th november 2023
 * Description: This program tests all segments in the display.
 * Board: MH ET Attiny88
 */


int segmentPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

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
//                            E  J  D  I  C  K

const int numChar PROGMEM = 38;//Number of characters in the character set.
const byte characterSet[38][numChar] PROGMEM = {//"Character set"
  
// 3  4  5  6  7  8  9  10 11 12 13 14 (Attiny pin)
// E  J  D  I  C  K  B  H  A  G  F     (Display segment)
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // ''
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}, // 'O'
  {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, // 'I'
  {0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0}, // '2'
  {0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0}, // '3'
  {0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0}, // '4'
  {0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0}, // 'S'
  {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1}, // '6'
  {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0}, // '7'
  {0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0}, // '8'
  {0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0}, // '9'
  {1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1}, // 'A'
  {1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1}, // 'B'
  {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1}, // 'C'
  {0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0}, // 'D'
  {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1}, // 'E'
  {1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1}, // 'F'
  {1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1}, // 'G'
  {1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1}, // 'H'
  {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, // 'I'
  {0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0}, // 'J'
  {1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1}, // 'K'
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1}, // 'L'
  {1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1}, // 'M'
  {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1}, // 'N'
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}, // 'O'
  {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1}, // 'P'
  {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1}, // 'Q'
  {1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1}, // 'R'
  {0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0}, // '5'
  {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, // 'T'
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1}, // 'U'
  {1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1}, // 'V'
  {1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1}, // 'W'
  {0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0}, // 'X'
  {0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0}, // 'Y'
  {0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0}, // '5'
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // '|8|.'
// E  J  D  I  C  K  B  H  A  G  F     (Display segment)
};

void setup() {
  for (int i = 0; i < 11; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
    for (int i = 0; i < numChar; i++) {//Iterate character
      for (int j = 0; j<11; j ++){//Draw character
        digitalWrite(segmentPins[j], pgm_read_byte(&(characterSet[i][j])));
      }
      delay(600);
    }
}
