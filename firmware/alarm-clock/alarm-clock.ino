#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h> 
#include <WiFi.h>
#include <alarm.hpp>
#include <clock.hpp>

const char* ssid = "";
const char* password = "";

#define TFT_SCLK 0 // labeled SCL on the screen
#define TFT_MOSI 1 // labeled SDA on the screen
#define TFT_RST 2
#define TFT_DC 3
#define TFT_CS 4
#define TFT_BL 5

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
Clock myClock;
Alarm myAlarm;

void connect_to_wifi() {
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void setup() {
  Serial.begin(115200);

  tft.init(76, 284); // Our panel size (portrait)
  tft.invertDisplay(false); // Invert the colors (This display is flipped from normal)
  tft.setRotation(1); // Landscape, if it's upside down use 3!
  tft.fillScreen(ST77XX_BLACK); // clear the screen
  Serial.println("TFT Initialized!");
  tft.setCursor(0,0); // make the cursor at the top left

  connect_to_wifi();
}

void loop() {
    auto current_time = myClock.get_current_time();
    if (!current_time.has_value()) {
        delay(30000);
        return;
    }
    myAlarm.should_ring(current_time.value());

    delay(60000);
}
