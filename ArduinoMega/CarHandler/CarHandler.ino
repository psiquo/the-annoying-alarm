#include "Constants.h"

bool led = true;
int target;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  setup_dist();
  setup_motor();
  setup_serial();
  Serial.begin(115200);
}

void loop() {
  handle_serial();
  if (enabled){
    drive();
  } else {
     motor_stop();
  }
}

void drive() {
    update_dist();
    dist = distance[1];
    fw_pid.Compute();
    go();
        
    if ( distance[1] < FORWARD_DISTANCE  and min(distance[0], distance[2]) > FORWARD_DISTANCE){
      motor_stop();
      if (distance[0] > distance[2]){
        target = distance[0];
        left(ROTATION_SPEED);
      } else {
        target = distance[2];
        right(ROTATION_SPEED);
      }
      do {
        update_dist();
      }while(distance[1] < max(target,30));
  
      motor_stop();
    } else if (distance[0] < SIDE_DISTANCE) {
      right(ROTATION_SPEED);
      do {
        update_dist();
      }while(distance[0] < max(30,distance[1]));
  
      motor_stop();
    } else if (distance[2] < SIDE_DISTANCE) {
      left(ROTATION_SPEED);
      do {
        update_dist();
      }while(distance[2] < max(distance[1],30));
    }
  }
