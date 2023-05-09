#include "Arduino.h"
#include "AccelStepper.h"
#include "MultiStepper.h"
#include "ADM.h"

AccelStepper stepper1(AccelStepper::FULL4WIRE, 3, 4, 5, 6);
AccelStepper stepper2(AccelStepper::FULL4WIRE, 8, 9, 10, 11);

MultiStepper steppers;

int aPos = stepper1.currentPosition();
int bPos = stepper2.currentPosition();

void setup() {
    Serial.begin(9600);
    
    // Set the speed of the motor:
    stepper1.setMaxSpeed(180);
    stepper2.setMaxSpeed(180);
    
    steppers.addStepper(stepper1);
    steppers.addStepper(stepper2);
    
}

/* ----------------------------- SIMPLE CURVES ----------------------------- */
void curveUp(int d, int r1, int r2){
    long positions[2];
    
    // These angles draw the curves vertically:
    // int r1 = -45;
    // int r2 = 135;
    
    // These angles draw the curves horizontally:
    // int r1 = 45;
    // int r2 = 225;
    
    // These angles draw at a 45º angle:
    // int r1 = 0;
    // int r2 = 180;
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    // First curve up --> clockwise
    // Sets new positions to be 0:
    stepper1.setCurrentPosition(d * cos(r1 * M_PI / 180));
    stepper2.setCurrentPosition(d * sin(r1 * M_PI / 180));
    // Resets the speed of the motor:
    stepper1.setMaxSpeed(180);
    stepper2.setMaxSpeed(180);
    
    for(int i = r1; i <= r2; i++){
        
        positions[0] = d * cos(i * M_PI / 180);
        positions[1] = d * sin(i * M_PI / 180);
        steppers.moveTo(positions);
        steppers.runSpeedToPosition();
        
    }
    
    // Second curve up --> counterclockwise
    // Sets new positions to be 0:
    stepper1.setCurrentPosition(-(d * cos(r2 * M_PI / 180)));
    stepper2.setCurrentPosition(-(d * sin(r2 * M_PI / 180)));
    // Resets the speed of the motor:
    stepper1.setMaxSpeed(180);
    stepper2.setMaxSpeed(180);
    
    for(int j = r2; j >= r1; j--){
        positions[0] = -(d * cos(j * M_PI / 180));
        positions[1] = -(d * sin(j * M_PI / 180));
        steppers.moveTo(positions);
        steppers.runSpeedToPosition();
    }
    
}


void curveDown(int d, int r1, int r2){
    long positions[2];
    
    // These angles draw the curves vertically:
    // int r1 = -45;
    // int r2 = 135;
    
    // These angles draw the curves horizontally:
    // int r1 = 45;
    // int r2 = 225;
    
    // These angles draw at a 45º angle:
    // int r1 = 0;
    // int r2 = 180;
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    // First curve down --> clockwise
    // Sets new positions to be 0:
    stepper1.setCurrentPosition(-d * cos(r1 * M_PI / 180));
    stepper2.setCurrentPosition(-d * sin(r1 * M_PI / 180));
    // Resets the speed of the motor:
    stepper1.setMaxSpeed(180);
    stepper2.setMaxSpeed(180);
    
    for(int i = r1; i <= r2; i++){
        
        positions[0] = -d * cos(i * M_PI / 180);
        positions[1] = -d * sin(i * M_PI / 180);
        steppers.moveTo(positions);
        steppers.runSpeedToPosition();
        
    }
    
    // Second curve down --> counterclockwise
    // Sets new positions to be 0:
    stepper1.setCurrentPosition((d * cos(r2 * M_PI / 180)));
    stepper2.setCurrentPosition((d * sin(r2 * M_PI / 180)));
    // Resets the speed of the motor:
    stepper1.setMaxSpeed(180);
    stepper2.setMaxSpeed(180);
    
    for(int j = r2; j >= r1; j--){
        positions[0] = (d * cos(j * M_PI / 180));
        positions[1] = (d * sin(j * M_PI / 180));
        steppers.moveTo(positions);
        steppers.runSpeedToPosition();
    }
    
    //--------------------------------------------------------
}
/* ---------------------- ---------------------- ---------------------- */




/* ----------------------------- ALPHABET ----------------------------- */

void step(int s){
    // Shifts a step after writing each letter, in the form of a curve
    // ------------------ CURVE SHIFT ------------------
    long positions[2];
    int r1 = 45;
    int r2 = 225;
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    // First curve down --> clockwise
    // Sets new positions to be 0:
    stepper1.setCurrentPosition(s * cos(r1 * M_PI / 180));
    stepper2.setCurrentPosition(s * sin(r1 * M_PI / 180));
    // Resets the speed of the motor:
    stepper1.setMaxSpeed(180);
    stepper2.setMaxSpeed(180);
    
    for(int i = r1; i <= r2; i++){
        positions[0] = s * cos(i * M_PI / 180);
        positions[1] = s * sin(i * M_PI / 180);
        steppers.moveTo(positions);
        steppers.runSpeedToPosition();
    }
    
    delay(1000);
}

void up(int stpSize, int steps){
    long positions[2];
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    positions[0] = aPos - stpSize * steps;
    positions[1] = bPos + stpSize * steps;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    
    delay(500);
}

void down(int stpSize, int steps){
    long positions[2];
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    positions[0] = aPos + stpSize * steps;
    positions[1] = bPos - stpSize * steps;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    
    delay(500);
}

void right(int stpSize, int steps){
    long positions[2];
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    positions[0] = aPos - stpSize * steps;
    positions[1] = bPos - stpSize * steps;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    
    delay(500);
}

void left(int stpSize, int steps){
    long positions[2];
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    positions[0] = aPos + stpSize * steps;
    positions[1] = bPos + stpSize * steps;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    
    delay(500);
}

void space(int s){
    // Shifts a bigger step for space in between words
    long positions[2];
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    positions[0] = aPos - s * 3;
    positions[1] = bPos - s * 3;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    
    delay(500);
}

void newLine(int s, int n){
    // Where n is the number of steps/letters taken since new line
    down(s, 1);
    left(s, n * 3);
    down(s, 5);
    right(s, 1);
    delay(1000);
}

void diagNE(int s1, int s2){
    // s1 > s2
    long positions[2];
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    positions[0] = aPos - s1;
    positions[1] = bPos + s2;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    
    delay(500);
}

void diagSW(int s1, int s2){
    // s1 > s2
    long positions[2];
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    positions[0] = aPos + s1;
    positions[1] = bPos - s2;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    
    delay(500);
}

void diagNW(int s1, int s2){
    // s1 < s2
    long positions[2];
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    positions[0] = aPos - s1;
    positions[1] = bPos + s2;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    
    delay(500);
}

void diagSE(int s1, int s2){
    // s1 < s2
    long positions[2];
    
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    
    positions[0] = aPos + s1;
    positions[1] = bPos - s2;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    
    delay(500);
}

void alphA(int s){
    up(s, 4);
    right(s, 2);
    down(s, 1);
    left(s, 2);
    right(s, 2);
    down(s, 3);
    step(s);
}

void alphB(int s){
    up(s, 4);
    right(s, 1);
    down(s, 2);
    left(s, 1);
    right(s, 2);
    down(s, 2);
    left(s, 2);
    right(s, 2);
    step(s);
}

void alphC(int s){
    up(s, 4);
    right(s, 2);
    down(s, 1);
    up(s, 1);
    left(s, 2);
    down(s, 4);
    right(s, 2);
    up(s, 1);
    down(s, 1);
    step(s);
}

void alphD(int s){
    up(s, 4);
    long positions[2];
    int aPos = stepper1.currentPosition();
    int bPos = stepper2.currentPosition();
    int r1 = -45;
    int r2 = 135;
    stepper1.setCurrentPosition((-s*3) * cos(r1 * M_PI / 180));
    stepper2.setCurrentPosition((-s*3) * sin(r1 * M_PI / 180));
    
    // Resets the speed of the motor:
    stepper1.setMaxSpeed(180);
    stepper2.setMaxSpeed(180);
    
    for(int i = r1; i <= r2; i++){
        positions[0] = (-s*3) * cos(i * M_PI / 180);
        positions[1] = (-s*3) * sin(i * M_PI / 180);
        steppers.moveTo(positions);
        steppers.runSpeedToPosition();
    }
    
    delay(500);
    right(s, 2);
    step(s);
}

void alphE(int s){
    up(s, 4);
    right(s, 2);
    left(s, 2);
    down(s, 2);
    right(s, 1);
    left(s, 1);
    down(s, 2);
    right(s, 2);
    left(s, 2);
    right(s, 2);
    step(s);
}

void alphF(int s){
    up(s, 4);
    right(s, 2);
    left(s, 2);
    down(s, 1);
    right(s, 1);
    left(s, 1);
    down(s, 3);
    right(s, 2);
    step(s);
}

void alphG(int s){
    up(s, 4);
    right(s, 2);
    down(s, 1);
    up(s, 1);
    left(s, 2);
    down(s, 4);
    right(s, 2);
    up(s, 1);
    left(s, 1);
    right(s, 1);
    down(s, 1);
    step(s);
}

void alphH(int s){
    up(s, 4);
    down(s, 2);
    right(s, 2);
    up(s, 2);
    down(s, 4);
    step(s);
}

void alphI(int s){
    right(s, 1);
    up(s, 4);
    down(s, 4);
    right(s, 1);
    step(s);
}

void alphJ(int s){
    up(s, 1);
    down(s, 1);
    right(s, 2);
    up(s, 4);
    down(s, 4);
    step(s);
}

void alphK(int s){
    up(s, 4);
    down(s, 2);
    diagNE(s*4, s*0.5);
    diagSW(s*4, s*0.5);
    diagSE(s*0.5, s*4);
    step(s);
}

void alphL(int s){
    up(s, 4);
    down(s, 4);
    right(s, 2);
    left(s, 2);
    right(s, 2);
    step(s);
}

void alphM(int s){
    up(s, 4);
    diagSE(s, s*3);
    diagNE(s*3, s);
    down(s, 4);
    step(s);
}

void alphN(int s){
    up(s, 4);
    diagSE(s*2, s*6);
    up(s, 4);
    down(s, 4);
    step(s);
}

void alphO(int s){
    up(s, 4);
    right(s, 2);
    down(s, 4);
    left(s, 2);
    right(s, 2);
    step(s);
}

void alphP(int s){
    up(s, 4);
    right(s, 2);
    down(s, 2);
    left(s, 2);
    down(s, 2);
    right(s, 2);
    step(s);
}

void alphQ(int s){
    up(s, 4);
    right(s, 2);
    down(s, 4);
    left(s, 2);
    right(s, 2);
    diagNW(s*0.25, s*2);
    diagSE(s*0.25, s*2);
    step(s);
}

void alphR(int s){
    up(s, 4);
    right(s, 2);
    down(s, 2);
    left(s, 2);
    diagSE(s*0.5, s*4);
    step(s);
}

void alphS(int s){
    up(s, 1);
    down(s, 1);
    right(s, 2);
    up(s, 2);
    left(s, 2);
    up(s, 2);
    right(s, 2);
    down(s, 1);
    up(s, 1);
    left(s, 2);
    down(s, 2);
    right(s, 2);
    down(s, 2);
    step(s);
}

void alphT(int s){
    right(s, 1);
    up(s, 4);
    left(s, 1);
    right(s, 2);
    left(s, 1);
    down(s, 4);
    right(s, 1);
    step(s);
}

void alphU(int s){
    up(s, 4);
    down(s, 4);
    right(s, 2);
    up(s, 4);
    down(s, 4);
    step(s);
}

void alphV(int s){
    right(s, 1);
    diagNW(s*2.5, s*5);
    diagSE(s*2.5, s*5);
    diagNE(s*5, s*2.5);
    diagSW(s*5, s*2.5);
    right(s, 1);
    step(s);
}

void alphW(int s){
    up(s, 4);
    down(s, 4);
    diagNE(s*3, s);
    diagSE(s, s*3);
    up(s, 4);
    down(s, 4);
    step(s);
}

void alphX(int s){
    diagNE(s*6, s*2);
    diagSW(s*3, s);
    diagNW(s, s*3);
    diagSE(s*2, s*6);
    step(s);
}

void alphY(int s){
    right(s, 1);
    up(s, 2);
    diagNW(s, s*3);
    diagSE(s, s*3);
    diagNE(s*3, s);
    diagSW(s*3, s);
    down(s, 2);
    right(s, 1);
    step(s);
}

void alphZ(int s){
    diagNE(s*6, s*2);
    left(s, 2);
    right(s, 2);
    diagSW(s*6, s*2);
    right(s, 2);
    step(s);
}
/* ---------------------- ---------------------- ---------------------- */
