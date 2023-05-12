/*

  Serial communication p5 to Arduino.
  
  Keyboard / alphabet function.
  
  ABCs, new line, jogging up/down/left/right
  
  
  by Bianca Gan 4/9/23

  
*/



let serial;
let portName = '/dev/tty.usbmodem14201';    // Change for your USB port
let inData;
let outByte = 0;

let mX;
let mY;

let prevY;
let prevX;

let dX;
let dY;



function setup(){
  createCanvas(450, 400);
  
  serial = new p5.SerialPort();
  serial.on('open', startSerial);
  serial.on('data', serialEvent);
  serial.open(portName);
}


function draw(){
  background(220);
  
  fill(0);
  textAlign(CENTER);
  textSize(25);
  text('Use the keyboard to type with ADM!', width/2, height/2);
  
}
  
  
function startSerial(){
  serial.write('1');
  console.log('serial port opened');
}

function serialEvent() {
  // // read from port until new line:
  // let message = serial.readStringUntil('\n');

  inData = serial.read();
  console.log(inData);  // Arduino writes motor position
      
  // if (message != null){
  //     serial.write('x');
  // }
}

function keyTyped(){
  if(key === 'a'){
    serial.write('a');
    console.log('a');
  }
  
  if(key === 'b'){
    serial.write('b');
    console.log('b');
  }
  
  if(key === 'c'){
    serial.write('c');
    console.log('c');
  }
  
  if(key === 'd'){
    serial.write('d');
    console.log('d');
  }
  
  if(key === 'e'){
    serial.write('e');
    console.log('e');
  }
  
  if(key === 'f'){
    serial.write('f');
    console.log('f');
  }
  
  if(key === 'g'){
    serial.write('g');
    console.log('g');
  }
  
  if(key === 'h'){
    serial.write('h');
    console.log('h');
  }
  
  if(key === 'i'){
    serial.write('i');
    console.log('i');
  }
  
  if(key === 'j'){
    serial.write('j');
    console.log('j');
  }
  
  if(key === 'k'){
    serial.write('k');
    console.log('k');
  }
  
  if(key === 'l'){
    serial.write('l');
    console.log('l');
  }
  
  if(key === 'm'){
    serial.write('m');
    console.log('m');
  }
  
  if(key === 'n'){
    serial.write('n');
    console.log('n');
  }
  
  if(key === 'o'){
    serial.write('o');
    console.log('o');
  }
  
  if(key === 'p'){
    serial.write('p');
    console.log('p');
  }
  
  if(key === 'q'){
    serial.write('q');
    console.log('q');
  }
  
  if(key === 'r'){
    serial.write('r');
    console.log('r');
  }
  
  if(key === 's'){
    serial.write('s');
    console.log('s');
  }
  
  if(key === 't'){
    serial.write('t');
    console.log('t');
  }
  
  if(key === 'u'){
    serial.write('u');
    console.log('u');
  }
  
  if(key === 'v'){
    serial.write('v');
    console.log('v');
  }
  
  if(key === 'w'){
    serial.write('w');
    console.log('w');
  }
  
  if(key === 'x'){
    serial.write('x');
    console.log('x');
  }
  
  if(key === 'y'){
    serial.write('y');
    console.log('y');
  }
  
  if(key === 'z'){
    serial.write('z');
    console.log('z');
  }
  
  if(key === ' '){
    serial.write(' ');
    console.log('space');
  }
  
  if(keyCode === ENTER){
    serial.write('E');
    console.log('new line');
  }
}

function keyPressed(){  
  if(keyCode === UP_ARROW){
    //outByte = 1;
    serial.write('U')
    console.log('up');
  }
  
  if(keyCode === DOWN_ARROW){
    //outByte = 1;
    serial.write('D')
    console.log('down');
  }
  
  if(keyCode === LEFT_ARROW){
    //outByte = 1;
    serial.write('L')
    console.log('left');
  }
  
  if(keyCode === RIGHT_ARROW){
    //outByte = 1;
    serial.write('R')
    console.log('right');
  }
}  
  
  
