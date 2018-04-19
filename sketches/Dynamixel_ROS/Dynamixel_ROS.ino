#include <DynamixelSerial3.h>
void setup() {
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(1000);

}

void loop() {
  Dynamixel.setEndless(1, OFF);
  Dynamixel.turn(1, RIGHT, 1023);

}
