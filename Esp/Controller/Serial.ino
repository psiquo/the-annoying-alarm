void setup_serial() {
  s.begin(9600);
}

void handle_serial() {
  if(sendCom && (not comMsg.equals(""))){
    char tmp[100];
    String(comMsg + "\n").toCharArray(tmp,100);
    s.write(tmp);
    sendCom = false;
    mqtt_print("Sent message through serial " + comMsg);
  }
}
