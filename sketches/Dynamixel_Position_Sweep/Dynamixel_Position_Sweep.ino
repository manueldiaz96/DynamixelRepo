#include <DynamixelSerial.h>

void setup() {
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(1000);
  pinMode(13, OUTPUT);
  Dynamixel.setMaxTorque(4, 1000);
  Dynamixel.setMaxTorque(6, 1000);
}

void loop() {
  Dynamixel.ledStatus(6, OFF);
  Dynamixel.ledStatus(4, OFF);
  for(int deg=0; deg<1024; deg++){
    Dynamixel.move(6, deg);
    Dynamixel.move(4, deg); 
    }
  for(int deg=1023; deg>0; deg--){
    Dynamixel.move(6, deg);
    Dynamixel.move(4, deg); 
    }
}
