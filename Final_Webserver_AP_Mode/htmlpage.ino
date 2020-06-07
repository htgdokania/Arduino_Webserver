
String SendHTML(uint8_t led1stat,uint8_t led2stat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>Device Control</title>\n";
  ptr +="<style>html { font-family: Arial; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #343444;margin: 50px auto 30px;} h3 {color: #434444;margin-bottom: 50px;}\n";

  ptr +=".button {display: block;width: 100px;background-color: #1abc9c;border:none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 50%;}\n";
  ptr +=".button-on {background-color: #ff9900;}\n";
  ptr +=".button-on:active {background-color: #996633;}\n";
  ptr +=".button-off {background-color: #003399;}\n";
  ptr +=".button-off:active {background-color: #003366;}\n";
  
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP8266 based Arduino Web Server</h1>\n";
  
  if(led1stat)
      ptr +="<p>Device1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";
  else
      ptr +="<p>Device2 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";

  if(led2stat)
      ptr +="<p>LED2 Status: ON</p><a class=\"button button-off\" href=\"/led2off\">OFF</a>\n";
  else
      ptr +="<p>LED2 Status: OFF</p><a class=\"button button-on\" href=\"/led2on\">ON</a>\n";

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
