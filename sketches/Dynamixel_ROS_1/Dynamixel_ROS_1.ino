#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <DynamixelSerial3.h>

ros::NodeHandle  nh;

void dynamixel_cb( const std_msgs::UInt16& id){
  Dynamixel.setEndless(id.data, ON);
  Dynamixel.turn(id.data, 0, 1023);  
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}

ros::Subscriber<std_msgs::UInt16> sub("dynamixel", dynamixel_cb);

void setup(){
  pinMode(13, OUTPUT);
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  delay(1000);

  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
}

