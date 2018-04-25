#include <DynamixelSerial.h>

void setup() {
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(1000);
  pinMode(13, OUTPUT);
  Dynamixel.setMaxTorque(4, 1000);
  Dynamixel.setMaxTorque(6, 1000);
}

void loop() {
//  for (int ID = 0; ID < 255; ID++) {
//    digitalWrite(13, LOW);
//    Dynamixel.ledStatus(ID, OFF);
//    Dynamixel.move(ID, random(200, 800)); // Move the Servo radomly from 200 to 800
//    delay(1000);
//
//    Dynamixel.setTempLimit(ID, 80); // Set Max Temperature to 80 Celcius
//    Dynamixel.setVoltageLimit(ID, 65, 160); // Set Operating Voltage from 6.5v to 16v
//    Dynamixel.setMaxTorque(ID, 512);       // 50% of Torque
//    Dynamixel.setSRL(ID, 2);               // Set the SRL to Return All
//
//    Dynamixel.ledStatus(ID, ON);          // Turn ON the LED
//    digitalWrite(13, HIGH);
//    delay(1000);
//  }
Dynamixel.ledStatus(6, OFF);
Dynamixel.ledStatus(4, OFF);
delay(1000);
Dynamixel.ledStatus(6, ON);
Dynamixel.ledStatus(4, ON);
delay(1000);
Dynamixel.move(6, 0); 
Dynamixel.move(4, 0); 
delay(2500);
Dynamixel.move(6, 500); 
Dynamixel.move(4, 500); 
delay(2500);
Dynamixel.move(6, 1023);
Dynamixel.move(4, 1023);  
delay(2500);
}
