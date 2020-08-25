void setup_http() {
  send_update(00,00);
}
void send_update(int hh,int mm){

    String url = website + "?hours=" + String(hh) + "&minutes=" + String(mm);
  
    log_msg("Contacting " + url);
    
    http.begin(http_wifi, url);

    int httpCode = http.GET();

    log_msg("Response code: " + String(httpCode));
  
    http.end();
  }
