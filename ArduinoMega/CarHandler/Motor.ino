void setup_motor() {
   pinMode(REnab,OUTPUT);
  pinMode(LEnab,OUTPUT);
  pinMode(LIn1, OUTPUT);
  pinMode(LIn2, OUTPUT);
  pinMode(RIn1, OUTPUT);
  pinMode(RIn1, OUTPUT);

  fw_pid.SetOutputLimits(MIN_SPEED,MAX_SPEED);
  fw_pid.SetMode(AUTOMATIC);
  fw_pid.SetSampleTime(20);
  
}

void set_speed(double speed_val){
  Left.setSpeed(speed_val);
  Right.setSpeed(min(speed_val + 50,255));
}

void go() {
  set_speed(output_speed); 

  Left.forward();
  Right.forward();
}

void left(double speed_val){
   set_speed(speed_val);

   Left.backward();
   Right.forward();
}


void right(double speed_val){
   set_speed(speed_val);

   Left.forward();
   Right.backward();
}

void motor_stop(){
  Left.stop();
  Right.stop();
}
