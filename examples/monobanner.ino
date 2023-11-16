/*
 * Program name: banner.ino
 * Author: Álvaro R.
 * Date: 14th november 2023
 * Description: This program shows a message on the display
 * Board: MH ET Attiny88
 */

int segmentPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

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

const byte message[] = "ME LLAMO ALVARO ME GUSTAN LAS CALCULADORAS XYZ.";

const int numChar PROGMEM = 38;//Number of characters in the character set.
const byte characterSet[][numChar] PROGMEM = {//"Character set"
  
// 3  4  5  6  7  8  9  10 11 12 13 14 (Attiny pin)
// E  J  D  I  C  K  B  H  A  G  F     (Display segment)
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
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // ''
// E  J  D  I  C  K  B  H  A  G  F     (Display segment)
};

void setup() {
  for (int i = 0; i < 11; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  int i=0;
  int nextChar;
  while(message[i]!='.'){
      if(int(message[i])<65 || int(message[i])>90){ //If character is not a letter
        nextChar = 26; // blank space
      }
      else{ //If character is a letter
        nextChar = int(message[i]) - 65;
      }
      for (int j = 0; j<11; j ++){//Draw character
        digitalWrite(segmentPins[j], pgm_read_byte(&(characterSet[nextChar][j])));
      }
      delay(600);
      for (int j = 0; j<11; j ++){
        digitalWrite(segmentPins[j], 0);
      }
      delay(100);
      i++;
   };
   for (int j = 0; j<11; j ++){//Draw character
        digitalWrite(segmentPins[j], 0);
   }
   delay(1000);
}
