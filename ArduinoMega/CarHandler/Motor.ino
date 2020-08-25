#include "L298N.h"

L298N Left(enabMotor, LIn1, LIn2);
L298N Right(enabMotor,RIn1,RIn2);

void setup_motor() {
  pinMode(enabMotor,OUTPUT);
  pinMode(LIn1, OUTPUT);
  pinMode(LIn2, OUTPUT);
  pinMode(RIn1, OUTPUT);
  pinMode(RIn1, OUTPUT);
}

void set_speed(int speed_val){
  Left.setSpeed(speed_val);
  Right.setSpeed(speed_val);
}

void go(int speed_val) {

  set_speed(speed_val); 

  Left.forward();
  Right.forward();
}

void left(int speed_val){
   set_speed(speed_val);

   Left.backward();
   Right.forward();
}


void right(int speed_val){
   set_speed(speed_val);

   Left.forward();
   Right.backward();
}

void motor_stop(){
  Left.stop();
  Right.stop();
}
