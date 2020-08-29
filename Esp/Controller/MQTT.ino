int str2Int(String msg) {
  bool isInt = true;
  for(int i = 0; i < msg.length(); i++) {
    isInt &= isDigit(msg.charAt(i));
  }
  if(isInt){
    return msg.toInt();
  } else {
    return -1;
  }
}

void to_alarm(String msg) {
  int semi_pos = msg.indexOf(":");
  if(semi_pos == -1) {
    log_msg("ERROR: Invalid time format for " + msg + " HH:MM expected");
    return;
  }
  String alarm_hour = msg.substring(0,semi_pos);
  String alarm_minutes = msg.substring(semi_pos+1,msg.length());
  int alarm_hour_val = str2Int(alarm_hour);
  int alarm_minutes_val = str2Int(alarm_minutes);
  if (alarm_hour_val < 0 || alarm_minutes_val <0 || alarm_hour_val >= 24 || alarm_minutes_val >= 60 ) {
    log_msg(String("ERROR: Invalid time  (" + msg + ")"));
    return;
  } else {
    alarm[0] = alarm_hour_val;
    alarm[1] = alarm_minutes_val;
    send_update(alarm[0],alarm[1]);
    lock = false;
    char msg[100];
    snprintf(msg,100,"New alarm set to %2d:%2d",alarm_hour_val,alarm_minutes_val);
    log_msg(String(msg));
  }
}
void callback(char* topic, byte* payload, unsigned int length) {
  String msg = String((char*) payload).substring(0,length);
  log_msg("Message arrived [" + String((char *) topic) + "] " + msg);

  to_alarm(msg);
  
}

void setup_mqtt() {
  client_mqtt.setServer(mqtt_server,1883);
  client_mqtt.setCallback(callback);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client_mqtt.connected()) {
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client_mqtt.connect(clientId.c_str())) {
      client_mqtt.subscribe("SistEmbed/Davide/AnnoyingAlarm");
    } else {
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void mqtt_handle() {
    if (!client_mqtt.connected()) {
    reconnect();
  }
  client_mqtt.loop();
}

void mqtt_print(String msg) {
  msg.toCharArray(print_msg,200);
  client_mqtt.publish("SistEmbed/Davide/Debug",print_msg);
}
