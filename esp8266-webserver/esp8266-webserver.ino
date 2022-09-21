#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#define LED 2

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
ESP8266WebServer server(80);

const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<header>
<title>ESP web server</title>
<style type="text/css">
body { font-family: Arial; text-align: center; margin:0px auto; padding-top: 30px;}
      .button {
        padding: 10px 20px;
        font-size: 24px;
        text-align: center;
        outline: none;
        color: #fff;
        background-color: #2f4468;
        border: none;
        border-radius: 5px;
        box-shadow: 0 6px #999;
        margin-bottom: 20px;
        cursor: pointer;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: rgba(0,0,0,0);
      }  
      .button:hover {background-color: #1f2e45}
      .button:active {
        background-color: #1f2e45;
        box-shadow: 0 4px #666;
        transform: translateY(2px);
      }
</style>
</header>
<body>
<center>
<div>
<h1>ESP web server</h1>
  <button class="button" onclick="send(1)">ON</button>
  <button class="button" onclick="send(0)">OFF</button><BR>
</div>
 <br>
<div><h2>
  State: <span id="state">NA</span>
</h2>
</div>
<script>
function send(led_sts) 
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("state").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "led_set?state="+led_sts, true);
  xhttp.send();
}
</script>
</center>
</body>
</html>
)=====";

void handleRoot() {
  
  String s = webpage;
  server.send(200, "text/html", s);
}

void led_control() {
  
  String state = "OFF";
  String act_state = server.arg("state");
  if(act_state == "1") {
    digitalWrite(LED,HIGH); //LED ON
    state = "ON";
  }
  else {
    digitalWrite(LED,LOW); //LED OFF
    state = "OFF";
  }
  server.send(200, "text/plane", state);
}

void setup(void) {
  
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
  pinMode(LED,OUTPUT); 
  
  while (WiFi.status() != WL_CONNECTED) {

    Serial.print("Connecting...");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/led_set", led_control);
  server.begin();
}

void loop(void) {

  server.handleClient();
}
