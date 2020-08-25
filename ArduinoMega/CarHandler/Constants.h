// Distance Module
// --- Pins
const int trigPin = 23;
const int echo[] = {22,24,26};

// --- Values
const int sensors = 3;
const int default_d_value = 200;
long duration;
int distance[sensors];
int tempDist;
int oldDistance[sensors];
int measures = 3;

//Motor Module
//--Pins
const int enabMotor = 2;
const int LIn1 = 44;
const int LIn2 = 45;
const int RIn1 = 46;
const int RIn2 = 47;

//--Values
#define MAX_SPEED 255.
#define MIN_SPEED 0.

//Serial Module
//---Values
bool enabled = false;
