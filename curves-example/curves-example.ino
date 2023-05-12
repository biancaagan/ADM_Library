/*

  This example code demonstrates how to use
  the curve functions.

  by Bianca Gan, 5/12/23

*/

#include "ADM.h"
#include "AccelStepper.h"
#include "MultiStepper.h"

AccelStepper stepper1(AccelStepper::FULL4WIRE, 3, 4, 5, 6);
AccelStepper stepper2(AccelStepper::FULL4WIRE, 8, 9, 10, 11);

MultiStepper steppers;


void setup() {
  Serial.being(9600);
}

void loop() {

  // Set the two angles:
  int r1 = -45;   // This sets the curves to go in a vertical direction
  int r2 = 135;   // This sets the curves to go in a vertical direction

  // First value is the diameter:
  curveUp(50, r1, r2);   
  step(-25, -25);   // Shifts to the right
  curveDown(50, r1, r2);

}
