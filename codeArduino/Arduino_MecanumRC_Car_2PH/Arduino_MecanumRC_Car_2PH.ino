/*Magtronica Team
*Universidad del Magdalena
*Version v1
*/
#include<Arduino.h>

#include<IBusBM.h> 

IBusBM IBus;     //create IBus object:

// Pines de configuracion salidas del arduino a los Puente H

int sPWM = 2;     // PWM velocidad de los motores (Para todos)

// Motores de Adelante
// Motor LD
int ENAp1 = sPWM;
int IN1D = 4;
int IN2D = 5;
// Motor RI
int ENBp1 = sPWM;
int IN3I = 6;
int IN4I = 7;

// Motores de Atras
// Motor RD
int ENAp2 = sPWM;
int IN1I = 8;
int IN2I = 9;
// Motor LI
int ENBp2 = sPWM;
int IN3D = 10;
int IN4D = 11;

//variables to store channel value:
int rcCH1 = 0;
int rcCH2 = 0;
int rcCH3 = 0;
int rcCH4 = 0;
int rcCH5 = 0;

int motorSpeed = 0; //variable to store motor speed:

// Movimientos del Robot - direcciones
void MoveForward();
void Stop();
void MoveBackward ();

void setup() {
  IBus.begin(Serial); // iBUS connected to Serial0:
  Serial.begin(115200);
  
  // Declaramos todos los pines como salidas PuenteH 1 Y PuenteH 2
  pinMode (sPWM, OUTPUT);         // Salida señal PWM para controlar la velocidad de los motores
  pinMode (IN1D, OUTPUT);         
  pinMode (IN2D, OUTPUT);
  pinMode (IN3I, OUTPUT);
  pinMode (IN4I, OUTPUT);
  pinMode (IN1I, OUTPUT);
  pinMode (IN2I, OUTPUT);
  pinMode (IN3D, OUTPUT);
  pinMode (IN4D, OUTPUT);
}

void loop() {
  //get the latest value from all channels and map them to one byte:
  rcCH1 = map(IBus.readChannel(0), 1000, 2000, 0, 255);
  rcCH2 = map(IBus.readChannel(1), 1000, 2000, 0, 255);
  rcCH3 = map(((int)(IBus.readChannel(2) - 988)), 0, 1024, 0, 255);
  rcCH4 = map(IBus.readChannel(3), 1000, 2000, 0, 255);
  rcCH5 = map(IBus.readChannel(4), 1000, 2000, 0, 255); 


  motorSpeed = rcCH3;   //store the rcCH3(Channel 3) data in motorSpeed variable:

}

void MoveForward() { //Move Forward:
  analogWrite (sPWM, motorSpeed); //Velocidad motores
  //Direccion motor LD - ADELANTE
  digitalWrite (IN1D, HIGH);
  digitalWrite (IN2D, LOW);
  //Direccion motor RI - ADELANTE
  digitalWrite (IN3I, HIGH);
  digitalWrite (IN4I, LOW);
  //Direccion motor LI - ADELANTE
  digitalWrite (IN1I, HIGH);
  digitalWrite (IN2I, LOW);
  //Direccion motor RD - ADELANTE
  digitalWrite (IN3D, HIGH);
  digitalWrite (IN4D, LOW);
}

void Stop() { //Stop:
  analogWrite (sPWM, 0); //Velocidad motores
  //Direccion motor LD
  digitalWrite (IN1D, LOW);
  digitalWrite (IN2D, LOW);
  //Direccion motor RI
  digitalWrite (IN3I, LOW);
  digitalWrite (IN4I, LOW);
  //Direccion motor LI
  digitalWrite (IN1I, LOW);
  digitalWrite (IN2I, LOW);
  //Direccion motor RD
  digitalWrite (IN3D, LOW);
  digitalWrite (IN4D, LOW);
}

void MoveBackward () { //Move Backward:
  analogWrite (sPWM, motorSpeed); //Velocidad motores
  //Direccion motor LD - ATRAS
  digitalWrite (IN1D, LOW);
  digitalWrite (IN2D, HIGH);
  //Direccion motor RI - ATRAS
  digitalWrite (IN3I, LOW);
  digitalWrite (IN4I, HIGH);
  //Direccion motor LI - ATRAS
  digitalWrite (IN1I, LOW);
  digitalWrite (IN2I, HIGH);
  //Direccion motor RD - ATRAS
  digitalWrite (IN3D, LOW);
  digitalWrite (IN4D, HIGH);
}

void MoveLeft() { //Move Left:
  analogWrite (sPWM, motorSpeed); //Velocidad motores
  // Direccion motor LD - ADELANTE
  digitalWrite (IN1D, HIGH);
  digitalWrite (IN2D, LOW);
  // Direccion motor RI - ATRAS
  digitalWrite (IN3I, LOW);
  digitalWrite (IN4I, HIGH);
  //Direccion motor LI - ADELANTE
  digitalWrite (IN1I, HIGH);
  digitalWrite (IN2I, LOW);
  //Direccion motor RD - ATRAS
  digitalWrite (IN3D, LOW);
  digitalWrite (IN4D, HIGH);
}

void MoveRight() { //Move Right:
  analogWrite (sPWM, motorSpeed); //Velocidad motores
  //Direccion motor LD - ATRAS
  digitalWrite (IN1D, LOW);
  digitalWrite (IN2D, HIGH);
  //Direccion motor RI - ADELANTE
  digitalWrite (IN3I, HIGH);
  digitalWrite (IN4I, LOW);
  //Direccion motor LI - ATRAS
  digitalWrite (IN1I, LOW);
  digitalWrite (IN2I, HIGH);
  //Direccion motor RD - ADELANTE
  digitalWrite (IN3D, HIGH);
  digitalWrite (IN4D, LOW);
}

void MoveTopRight() { //Move Top Right:
  analogWrite (sPWM, motorSpeed); //Velocidad motores
  //Direccion motor LD - RELEASE
  digitalWrite (IN1D, LOW);
  digitalWrite (IN2D, LOW);
  //Direccion motor RI - ADELANTE
  digitalWrite (IN3I, HIGH);
  digitalWrite (IN4I, LOW);
  //Direccion motor LI - RELEASE
  digitalWrite (IN1I, LOW);
  digitalWrite (IN2I, LOW);
  //Direccion motor RD - ADELANTE
  digitalWrite (IN3D, HIGH);
  digitalWrite (IN4D, LOW);
}

void MoveTopLeft() { //MOve Top Left:
  analogWrite (sPWM, motorSpeed); //Velocidad motores
  // Direccion motor LD - ADELANTE
  digitalWrite (IN1D, HIGH);
  digitalWrite (IN2D, LOW);
  //Direccion motor RI - RELEASE
  digitalWrite (IN3I, LOW);
  digitalWrite (IN4I, LOW);
  //Direccion motor LI - ADELANTE
  digitalWrite (IN1I, HIGH);
  digitalWrite (IN2I, LOW);
  //Direccion motor RD - RELEASE
  digitalWrite (IN3D, LOW);
  digitalWrite (IN4D, LOW);
}

void MoveBackRight() { //Move Back Right:
  analogWrite (sPWM, motorSpeed); //Velocidad motores
  //Direccion motor LD - ATRAS
  digitalWrite (IN1D, LOW);
  digitalWrite (IN2D, HIGH);
  //Direccion motor RI - RELEASE
  digitalWrite (IN3I, LOW);
  digitalWrite (IN4I, LOW);
  //Direccion motor LI - ATRAS
  digitalWrite (IN1I, LOW);
  digitalWrite (IN2I, HIGH);
  //Direccion motor RD - RELEASE
  digitalWrite (IN3D, LOW);
  digitalWrite (IN4D, LOW);
}

void MoveBackLeft() { //Move Back Left: 
  analogWrite (sPWM, motorSpeed); //Velocidad motores
  // Direccion motor LD - RELEASE
  digitalWrite (IN1D, LOW);
  digitalWrite (IN2D, LOW);
  // Direccion motor RI - ATRAS
  digitalWrite (IN3I, LOW);
  digitalWrite (IN4I, HIGH);
  //Direccion motor LI - RELEASE
  digitalWrite (IN1I, LOW);
  digitalWrite (IN2I, LOW);
  //Direccion motor RD - ATRAS
  digitalWrite (IN3D, LOW);
  digitalWrite (IN4D, HIGH);
}

void RightTurn() { //Turn Right:
  analogWrite (sPWM, motorSpeed); //Velocidad motores
  // Direccion motor LD - ATRAS
  digitalWrite (IN1D, LOW);
  digitalWrite (IN2D, HIGH);
  //Direccion motor RI - ADELANTE
  digitalWrite (IN3I, HIGH);
  digitalWrite (IN4I, LOW);
  //Direccion motor LI - ADELANTE
  digitalWrite (IN1I, HIGH);
  digitalWrite (IN2I, LOW);
  //Direccion motor RD - ATRAS
  digitalWrite (IN3D, LOW);
  digitalWrite (IN4D, HIGH);
}

void LeftTurn() { //Turn Left:
  analogWrite (sPWM, motorSpeed); //Velocidad motores
  //Direccion motor LD - ADELANTE
  digitalWrite (IN1D, HIGH);
  digitalWrite (IN2D, LOW);
  // Direccion motor RI - ATRAS
  digitalWrite (IN3I, LOW);
  digitalWrite (IN4I, HIGH);
  //Direccion motor LI - ATRAS
  digitalWrite (IN1I, LOW);
  digitalWrite (IN2I, HIGH);
  //Direccion motor RD - ADELANTE
  digitalWrite (IN3D, HIGH);
  digitalWrite (IN4D, LOW);
}