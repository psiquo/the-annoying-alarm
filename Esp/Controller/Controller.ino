#include "Constants.h"

void log_msg(String msg) {
  Serial.println(msg);
  mqtt_print(msg);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setup_wifi();
  setup_time();
  setup_alarm();
  setup_mqtt();
  setup_serial();
  setup_http();
}

void loop() {
  // put your main code here, to run repeatedly:
  mqtt_handle();
  check_alarm();
  handle_serial();
  if(alarm_active) {
    digitalWrite(alarmPin,HIGH);
  } else {    
    digitalWrite(alarmPin,LOW);
  }
  delay(1000);
}
