void setup_time() {
  timeClient.begin();
}

void update_time() {
  timeClient.update();
  time_t epochTime = CE.toLocal(timeClient.getEpochTime());
  curTime[0] = hour(epochTime);
  curTime[1] = minute(epochTime);
  curTime[2] = second(epochTime);
}
