
/*Arduino Mecanum RC Car V1
*Taken from DIY Builder
*-----------------------------------
*Magtronica Team
*Universidad del Magdalena
*Version Mod
*/
#include <Arduino.h>

//include the library code:
#include<IBusBM.h>   
#include<AFMotor.h>

//Funciones de movimiento
void MoveForward();
void Stop();
void MoveBackward ();
void MoveLeft();
void MoveRight();
void MoveTopRight();
void MoveTopLeft();
void MoveBackRight();
void MoveBackLeft();
void RightTurn();
void LeftTurn();

IBusBM IBus;     //create IBus object:

//variables to store channel value:
int rcCH1 = 0;
int rcCH2 = 0;
int rcCH3 = 0;
int rcCH4 = 0;
int rcCH5 = 0;

//create motor objects
AF_DCMotor motor1 (1, MOTOR12_1KHZ);
AF_DCMotor motor2 (2, MOTOR12_1KHZ);
AF_DCMotor motor3 (3, MOTOR34_1KHZ);
AF_DCMotor motor4 (4, MOTOR34_1KHZ);

int motorSpeed = 0; //variable to store motor speed:


void setup() {
  IBus.begin(Serial); // iBUS connected to Serial0:
  Serial.begin(115200);
}

void loop() {
  //get the latest value from all channels and map them to one byte:
 rcCH1 = map(IBus.readChannel(0), 1000, 2000, 0, 255);
 rcCH2 = map(IBus.readChannel(1), 1000, 2000, 0, 255);
 rcCH3 = map(((int)(IBus.readChannel(2) - 988)), 0, 1024, 0, 255);
 rcCH4 = map(IBus.readChannel(3), 1000, 2000, 0, 255);
 rcCH5 = map(IBus.readChannel(4), 1000, 2000, 0, 255); // MODOS

//  // Evaluacion de valores de canales


 motorSpeed = rcCH3;   //store the rcCH3(Channel 3) data in motorSpeed variable:

 // Movimientos en los canales 1 y 2 == DONE
 if(rcCH1 > 127) {          //Check whether the channel1 value is greater than 150. If the condition is true then execute the below code:                         
   MoveRight();  
  }else if (rcCH1 < 127) {  //Check whether the channel1 value is less than 100. If the condition is true then execute the below Code:
   MoveLeft(); 
  }else if (rcCH2 > 127) {  //Check whether the channel2 value is greater than 150. If the condition is true then execute the below Code:
   MoveForward();  
  }else if (rcCH2 < 127) {  //Check whether the channel1 value is less than 100. If the condition is true then execute the below Code:
   MoveBackward();
  }else{                    //If the above conditions are false then execute the below Code:
   Stop();
  }

    //Check whether the channel6 value is 1. If the condition is true then execute the below code:
   //Corner Drive Mode:
  if ((rcCH1 > 127)&&(rcCH2 > 127)){
    MoveTopRight();
  }else if ((rcCH1 > 127)&&(rcCH2 < 127)){
    MoveBackRight();
  }else if ((rcCH1 < 127)&&(rcCH2 > 127)){
    MoveTopLeft();
  }else if ((rcCH1 < 127)&&(rcCH2 < 127)) {
    MoveBackLeft();
  }

 //If the above condition is false then execute the below Code:
 //Spin Mode:
  if (rcCH4 < 127){
    LeftTurn(); 
  }else if (rcCH4 > 127){
    RightTurn();
  }
}


void MoveForward() { //Move Forward:
 motor1.run(FORWARD);                      //Drive motor1 clockwise:
 motor1.setSpeed(motorSpeed);              //Define motor1 speed:
 motor2.run(FORWARD);                      //Drive motor2 clockwise:
 motor2.setSpeed(motorSpeed);              //Define motor2 speed:
 motor3.run(FORWARD);                      //Drive motor3 clockwise:
 motor3.setSpeed(motorSpeed);              //Define motor3 speed:
 motor4.run(FORWARD);                      //Drive motor4 clockwise:
 motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}

void Stop() { //Stop:
 motor1.run(RELEASE);                       //Stop motor1:
 motor1.setSpeed(0);                        //Define motor1 speed:
 motor2.run(RELEASE);                       //Stop motor2:
 motor2.setSpeed(0);                        //Define motor2 speed:
 motor3.run(RELEASE);                       //Stop motor3:
 motor3.setSpeed(0);                        //Define motor3 speed:
 motor4.run(RELEASE);                       //Stop motor4:
 motor4.setSpeed(0);                        //Define motor4:
}
void MoveBackward () { //Move Backward:
 motor1.run(BACKWARD);                      //Drive motor1 anti-clockwise:
 motor1.setSpeed(motorSpeed);               //Define motor1 speed:
 motor2.run(BACKWARD);                      //Drive motor2 anti-clockwise:
 motor2.setSpeed(motorSpeed);               //Define motor2 speed:
 motor3.run(BACKWARD);                      //Drive motor3 anti-clockwise:
 motor3.setSpeed(motorSpeed);               //Define motor3 speed:
 motor4.run(BACKWARD);                      //Drive motor4 anti-clockwise:
 motor4.setSpeed(motorSpeed);               //Define motor4 speed:
}
void MoveLeft() { //Move Right:
  motor1.run(FORWARD);                      //Drive motor1 clockwise:
  motor1.setSpeed(motorSpeed);              //Define moto1 speed:
  motor2.run(BACKWARD);                     //Drive motor2 anti-clockwise
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(FORWARD);                      //Drive motor3 clockwise:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(BACKWARD);                     //Drive motor4 anti-clockwise
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void MoveRight() { //Move Left:
  motor1.run(BACKWARD);                     //Drive motor1 anti-clockwise:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(FORWARD);                      //Drive motor2 clockwise:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(BACKWARD);                     //Drive motor3 anti-clockwise
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(FORWARD);                      //Drive motor4 clockwise:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void MoveTopRight() { //Move Top Right:
  motor1.run(FORWARD);                      //Drive motor1 clockwise:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed"
  motor2.run(RELEASE);                      //Stop motor2:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(FORWARD);                      //Drive motor3 clockwise:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(RELEASE);                      //Stop motor4:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void MoveTopLeft() { //MOve Top Left:
  motor1.run(RELEASE);                      //Stop motor1:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(FORWARD);                      //Drive motor2 clockwise:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(RELEASE);                      //Stop motor3:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(FORWARD);                      //Drive motor4 clockwise:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void MoveBackRight() { //Move Back Right:
  motor1.run(RELEASE);                      //Stop motor1:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(BACKWARD);                     //Drive motor2 anti-clockwise:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(RELEASE);                      //Stop motor3:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(BACKWARD);                     //Drive motor4 anti-clockwise:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void MoveBackLeft() { //Move Back Left: 
  motor1.run(BACKWARD);                     //Drive motor1 anti-clockwise:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(RELEASE);                      //Stop motor2:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(BACKWARD);                     //Drive motor3 anti-clockwise:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(RELEASE);                      //Stop motor4:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void RightTurn() { //Turn Right:
  motor1.run(FORWARD);                      //Drive motor1 clockwise:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(FORWARD);                      //Drive motor2 clockwise:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(BACKWARD);                     //Drive motor3 anti-clockwise:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed :
  motor4.run(BACKWARD);                     //Drive motor4 anti-clockwise:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
void LeftTurn() { //Turn Left:
  motor1.run(BACKWARD);                     //Drive motor1 anti-clockwise:
  motor1.setSpeed(motorSpeed);              //Define motor1 speed:
  motor2.run(BACKWARD);                     //Drive motor2 anti-clockwise:
  motor2.setSpeed(motorSpeed);              //Define motor2 speed:
  motor3.run(FORWARD);                      //Drive motor3 clockwise:
  motor3.setSpeed(motorSpeed);              //Define motor3 speed:
  motor4.run(FORWARD);                      //Drive motor4 clockwise:
  motor4.setSpeed(motorSpeed);              //Define motor4 speed:
}
