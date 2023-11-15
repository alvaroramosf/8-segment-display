/*
 * Program name: pruebaSegmentos.ino
 * Author: Álvaro R.
 * Date: 14th november 2023
 * Description: Displays the alphabet on a single display
 */
// Definimos los pines para el display de 8 segmentos
int segmentPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

// Definimos los números del 1 al 6 en formato de 8 segmentos:

// Pines del display personalizado.
// 12 10 10 10 10 07               12 11 10 09 08 07
// 12 11       08 07               |  |  |  |  |  |
// 12 11       08 07              ******************
// 12    11 08    07              *       |8|.     *
// 01    02 04    05              *                *
// 01 02       04 05              ******************
// 01 02       04 05   **          |  |  |  |  |  |
// 01 03 03 03 03 05  *06*         01 02 03 04 05 06
//                     **

const byte numbers[38][11] PROGMEM = {
// Pin Attiny (Pin display +2)
// 3  4  5  6  7  8  9  10 11 12 13 14
// E  J  D  I  C  K  B  H  A  G  F
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
// E  J  D  I  C  K  B  H  A  G  F
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // '|8|.'
// E  J  D  I  C  K  B  H  A  G  F
};

void setup() {
  // Configuramos los pines del display como salida
  for (int i = 0; i < 11; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  // Configuramos el pin del botón como entrada
 //pinMode(2, INPUT_PULLUP);
}

void loop() {
  // Si se presiona el botón
  //if (digitalRead(2) == LOW) {
    // Generamos un número aleatorio del 1 al 6
    //int number = random(1, 7);
    //delay(1000);

    // Mostramos el número en el display
    for (int i = 0; i < 38; i++) {
      for (int j = 0; j<11; j ++){
        digitalWrite(segmentPins[j], pgm_read_byte(&(numbers[i][j])));
      }
      delay(300);
    }
    // Esperamos un segundo antes de apagar el display
    //delay(1000);
}
