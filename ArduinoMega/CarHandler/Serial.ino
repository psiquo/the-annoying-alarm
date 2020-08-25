void setup_serial() {
  Serial1.begin(9600);
}
void handle_serial() {
  if(Serial1.available()){
    String msg = Serial1.readStringUntil("\n");
    msg.trim();
    Serial.print("Received message: " + msg + "\n");
    enabled = msg.equals("en");
  } 
}
