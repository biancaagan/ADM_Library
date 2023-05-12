/*

  This example code utilizes input from p5
  over Serial, to use the alphabet functions.

  by Bianca Gan, 5/12/23

*/

#include "ADM.h"
#include "AccelStepper.h"
#include "MultiStepper.h"

int steps;
int count;

void loop() {
  long positions[2];

  char inByte;

  while(Serial.available()){
    inByte = Serial.read();
  }

  int s = 50;


  // newU(s);
  // delay(10000);
  // myNameIsADM(s);

  if(inByte == 'a'){
    alphA(s);
    count += 1;
  }

  if(inByte == 'b'){
    alphB(s);
    count += 1;
  }

  if(inByte == 'c'){
    alphC(s);
    count += 1;
  }

  if(inByte == 'd'){
    alphD(s);
    count += 1;
  }

  if(inByte == 'e'){
    alphE(s);
    count += 1;
  }

  if(inByte == 'f'){
    alphF(s);
    count += 1;
  }

  if(inByte == 'g'){
    alphG(s);
    count += 1;
  }

  if(inByte == 'h'){
    alphH(s);
    count += 1;
  }

  if(inByte == 'i'){
    alphI(s);
    count += 1;
  }

  if(inByte == 'j'){
    alphJ(s);
    count += 1;
  }

  if(inByte == 'k'){
    alphK(s);
    count += 1;
  }

  if(inByte == 'l'){
    alphL(s);
    count += 1;
  }

  if(inByte == 'm'){
    alphM(s);
    count += 1;
  }

  if(inByte == 'n'){
    alphN(s);
    count += 1;
  }

  if(inByte == 'o'){
    alphO(s);
    count += 1;
  }

  if(inByte == 'p'){
    alphP(s);
    count += 1;
  }

  if(inByte == 'q'){
    alphQ(s);
    count += 1;
  }

  if(inByte == 'r'){
    alphR(s);
    count += 1;
  }

  if(inByte == 's'){
    alphS(s);
    count += 1;
  }

  if(inByte == 't'){
    alphT(s);
    count += 1;
  }

  if(inByte == 'u'){
    alphU(s);
    count += 1;
  }

  if(inByte == 'v'){
    alphV(s);
    count += 1;
  }

  if(inByte == 'w'){
    alphW(s);
    count += 1;
  }

  if(inByte == 'x'){
    alphX(s);
    count += 1;
  }

  if(inByte == 'y'){
    alphY(s);
    count += 1;
  }

  if(inByte == 'z'){
    alphZ(s);
    count += 1;
  }

  if(inByte == ' '){
    space(s);
    count += 1;
  }

  if(inByte == 'E'){   // ENTER NEW LINE
    newLine(s, count);
    count = 0;
  }

  // Arrow keys functions to jog the pen:
  if(inByte == 'U'){    // UP
    up(s, 4);
  }

  if(inByte == 'D'){    // DOWN
    down(s, 4);
  }

  if(inByte == 'L'){    // LEFT
    left(s, 4);
  }

  if(inByte == 'R'){    // RIGHT
    right(s, 4);
  }


}
