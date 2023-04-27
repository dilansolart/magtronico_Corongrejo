#include <IBusBM.h>

IBusBM IBus;    // IBus object

void setup() {
  Serial.begin(115200); // open the serial port at 9600 bps:
  IBus.begin(Serial);    // iBUS object connected to serial0 RX pin
  Serial.println("Wait for receiver");
  while (IBus.cnt_rec==0){
    Serial.println("No Connected");
    delay(100);
  }
  Serial.println("Init done");
}

void loop() {
  Serial.print("JoyD <- -> = "); Serial.println((int) IBus.readChannel(0) - 1500);
  Serial.print("JoyD ¡ ! = "); Serial.println((int) IBus.readChannel(1) - 1500);
  Serial.print("JoyI Velocidad = "); Serial.println((int) IBus.readChannel(2) - 993);
  Serial.print("JoyI Timon = "); Serial.println((int) IBus.readChannel(3));
  Serial.print("canal 5 = "); Serial.println((int) IBus.readChannel(4));
  Serial.print("canal 6 = "); Serial.println((int) IBus.readChannel(5));
  Serial.print("canal 7 = "); Serial.println((int) IBus.readChannel(6));
  Serial.print("canal 8 = "); Serial.println((int) IBus.readChannel(7));
  delay(1000);
}
