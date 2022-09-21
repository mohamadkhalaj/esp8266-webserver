# ESP8266-webserver
ESP8266 AJAX webserver

# How to use?
Replace following variables with your own:
```
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
```

# How can i access to webserver?
There are two solutions for above question:
- Set static ip address for ESP in your router config
- Connect ESP's TX, RX to arduino and see ip address in arduino ide serial monitor

# How to program my ESP with arduino?
[ESP8622 programming guide](https://github.com/mohamadkhalaj/esp8266-programming-guide/blob/main/README.md)

# Where is schematic?
This project is so simple so i write it here without any images.
```
ESP VCC -> 3v3
ESP GND -> GND
ESP IO2 -> Your LED, servo motor or any other things that would be controlled via WIFI or global internet
```

## Screenshot
![Screenshot 2022-09-21 at 18-05-04 ESP web server](https://user-images.githubusercontent.com/62938359/191518216-8723569e-b27e-40c4-bb7f-744f081eec82.png)
