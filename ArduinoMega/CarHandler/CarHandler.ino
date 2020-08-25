#include "Constants.h"
#include <AutoPID.h>


bool led = true;
int target;
/*
#define KP 1
#define KI 0
#define KD 0
double dist ,setPoint, output;
AutoPID pid(&dist, &setPoint, &output, MIN_SPEED,MAX_SPEED,KP,KI,KD);
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  setup_dist();
  setup_motor();
  setup_serial();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly
  handle_serial();
  if (enabled){
    drive();
  } else {
    motor_stop();
  }
}

void drive() {
    update_dist();

     go(175);
    
    if ( distance[1] < 20  and min(distance[0], distance[2]) > 20){
      Serial.println("Stopped");
      motor_stop();
      if (distance[0] > distance[2]){
        target = distance[0];
        left(175);
      } else {
        target = distance[2];
        right(175);
      }
      do {
        update_dist();
        Serial.println("Rotating");
      }while(distance[1] < min(target,30));
  
      motor_stop();
    } else if (distance[0] < 20) {
      right(175);
      do {
        update_dist();
        Serial.println("Rotating");
      }while(distance[0] < min(30,distance[1]));
  
      motor_stop();
    } else if (distance[2] < 20) {
      left(175);
      do {
        update_dist();
        Serial.println("Rotating");
      }while(distance[2] < min(distance[1],30));
    }
  }
