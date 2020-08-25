void setup_alarm() {
  pinMode(alarmPin, OUTPUT);
  pinMode(interruptPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin),handler,FALLING);
}

ICACHE_RAM_ATTR void handler() {
  alarm_active = false;
  lock = true;
  sendCom = true;
  comMsg = "dis";
}
void check_alarm() {
  update_time();
  if (!alarm_active) {
    bool temp = true;
    for (int i = 0; i < 2; i++)
      temp &= (alarm[i] == curTime[i]);
    alarm_active = not lock ? temp : alarm_active;
    if( not temp) {
      lock = false;
    }

    if(alarm_active) {
      sendCom = true;
      comMsg = "en";
    }
  }
}
