#include <DynamixelSerial.h>
int id1 = 1 , id2 = 14 , id3 = 15 , id4 = 16, id5 = 17 , id6 = 18;
void setup() {
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(1000);
  pinMode(13, OUTPUT);
  Dynamixel.setMaxTorque(4, 1000);
  Dynamixel.setMaxTorque(6, 1000);

}

void loop() {
  Dynamixel.setEndless(id1, ON);
  Dynamixel.turn(id1, 0, 1023);
  delay(2000);
  Dynamixel.setEndless(id2, ON);
  Dynamixel.turn(id2, 0, 1023);
  delay(2000);
  Dynamixel.setEndless(id3, ON);
  Dynamixel.turn(id3, 0, 1023);
  delay(2000);
  Dynamixel.setEndless(id4, ON);
  Dynamixel.turn(id4, 0, 1023);
  delay(2000);
  Dynamixel.setEndless(id5, ON);
  Dynamixel.turn(id5, 0, 1023);
  delay(2000);
  Dynamixel.setEndless(id6, ON);
  Dynamixel.turn(id6, 0, 1023);
  //  delay(1500);
  //  Dynamixel.move(6, 500);
  //  delay(1500);
  //  Dynamixel.move(6, 600);
  //  delay(1500);
}
