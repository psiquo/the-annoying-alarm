// Distance Module
//---Includes
#include <stdlib.h>
// --- Pins
const int trigPin = 23;
const int echo[] = {22,24,26};

// --- Values
const int sensors = 3;
const int default_d_value = 200;
long duration;
double distance[sensors];
int tempDist;
double oldDistance[sensors];
int measures = 4;

//Motor Module
//---Includes
#include "L298N.h"
#include <PID_v1.h>
//---Pins
const int LEnab = 2;
const int REnab = 3;
const int LIn1 = 44;
const int LIn2 = 45;
const int RIn1 = 46;
const int RIn2 = 47;

//---Values
#define MAX_SPEED 200
#define MIN_SPEED 90//130
#define ROTATION_SPEED 90

#define FORWARD_DISTANCE 20
#define SIDE_DISTANCE 20

#define Kp 1.6//2.
#define Ki 9.6
#define Kd 0.//02

double dist,setPoint_fw = 70, output_speed=0;

L298N Left(LEnab, LIn1, LIn2);
L298N Right(REnab,RIn1,RIn2);

PID fw_pid(&dist, &output_speed, &setPoint_fw, Kp,Ki,Kd,REVERSE);

//Serial Module
//---Values
bool enabled = false;
