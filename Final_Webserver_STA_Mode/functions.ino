void update_status(){
  server.send(200, "text/html", SendHTML(LED1,LED2));  // we send HTML page alng with updated LED status.
}
void OnConnect() {
  LED1 = LOW;
  LED2 = LOW;
  update_status();
}

void led1on() {
  LED1 = HIGH;
  update_status();
}

void led1off() {
  LED1 = LOW;
  update_status();
}

void led2on() {
  LED2 = HIGH;
  update_status();
}

void led2off() {
  LED2 = LOW;
  update_status();
}

void NotFound(){
  server.send(404, "text/plain", "Not found");
}
