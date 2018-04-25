#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <ros.h>
#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/Int32MultiArray.h>
#include <DynamixelSerial3.h>

ros::NodeHandle  nh;

void dynamixel_cb( const std_msgs::Int32MultiArray::ConstPtr& array){
  int data[4]; 
  /*
  data = [id, funcType, arg1, arg2]

  id : motorID
  funcType : 0 for servo, 1 for continuous
  arg1 : Position or speed, 0 to 1023
  arg2 : Only for funcType=1: Left = 0, Right = 1

  */
  for(std::vector<int>::const_iterator it = array->data.begin(); it != array->data.end(); ++it)
  {
    data[i] = *it;
    i++;
  }
  if(data[1] == 0){
    Dynamixel.setEndless(data[0], OFF);
    Dynamixel.move(data[0], data[2]);
  }
  else if(data[1] == 1){
    Dynamixel.setEndless(data[0], ON);
    Dynamixel.turn(data[0], data[3], data[2]);
  }
}

ros::Subscriber<std_msgs::Int32MultiArray> sub("dynamixel", 100, dynamixel_cb);

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

