/*

  This example code demonstrates how to use
  the curve functions.

  by Bianca Gan, 5/12/23

*/

#include "ADM.h"
#include "AccelStepper.h"
#include "MultiStepper.h"

// AccelStepper stepper1(AccelStepper::FULL4WIRE, 3, 4, 5, 6);
// AccelStepper stepper2(AccelStepper::FULL4WIRE, 8, 9, 10, 11);

// MultiStepper steppers;


void loop() {

  // Set the two angles:
  // Experiment with different values to see what happens.
  int r1 = -45;   // This sets the curves to go in a vertical direction
  int r2 = 135;   // This sets the curves to go in a vertical direction

  // int r1 = 45;   // This sets the curves to go in a horizontal direction
  // int r2 = 225;  // This sets the curves to go in a horizontal direction

  // int r1 = 0;    // This sets the cerves in a 45º angle
  // int r2 = 180;  // This sets the cerves in a 45º angle

  // First value is the diameter:
  // Each curve call draws two curves that make a slight 'S' shape
  curveUp(50, r1, r2);   

  delay(500);

  shift(-25, -25);   // Shifts to the right

  delay(500);

  curveDown(50, r1, r2);

  delay(500);

  shift(-25, -25);   // Shifts to the right

  delay(500);

}





