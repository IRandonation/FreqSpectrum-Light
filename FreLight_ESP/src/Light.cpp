#include <arduinoFFT.h>
#include <FastLED.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <time.h>
#include <Arduino.h>
#include "fftlight.h"

//internet clock
const char *ssid = "xxxxxx";
const char *password = "xxxxxx";

const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 8*3600;
const int daylightOffset_sec = 0;

const int buttonPin = 4;
bool buttonPressed = false;
bool buttonReleased = false;
unsigned long buttonPressTime = 0;
int ButtonNumber = 0;

#define DATA_PIN 22

#define MATRIX_HEIGHT 8
#define MATRIX_WIDTH  16
// #define NUM_LED 128 //number of LED

#define First 8//clock position
#define Second 24
#define Third 64
#define Fourth 96

#define I2S_READ_LEN 2048
#define SAMPLE_BUFFER_SIZE 512

void setup() {
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LED);
    FastLED.setBrightness(50);  //0~255
    Serial.begin(115200);
    pinMode(audio_PIN,INPUT); //initialize sreial input
    pinMode(buttonPin, INPUT);
    // WiFi.begin(ssid, password);
    // while(WiFi.status() != WL_CONNECTED) {
    //     delay(500);
    //     Serial.print(".");
    // }
    // Serial.println("WiFi Connected");

    // configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    
    // while (!time(nullptr)) {
    //     delay(1000);
    //     Serial.println("Waiting for time sync...");
    // }
    // Serial.println("Time synced successfully");
}// end setup 

void loop() {
//     bool currentButtonState = digitalRead(buttonPin);

//   // 按钮按下
//     if (currentButtonState == LOW && !buttonPressed) {
//         buttonPressed = true;
//         buttonPressTime = millis();
//     }

//   // 按钮释放
//     if (currentButtonState == HIGH && buttonPressed) {
//         buttonPressed = false;
//         unsigned long buttonReleaseTime = millis();
//         unsigned long buttonDuration = buttonReleaseTime - buttonPressTime;

//     // 短按切换模式
//     if (buttonDuration < 1000) {
//         ButtonNumber = ButtonNumber + 1;
//         Serial.println(ButtonNumber);
//       // 执行切换模式的操作
//     }
//     // 长按复位
//     else {
//         esp_restart();
//       // 执行复位操作
//     }
//     }
    //TimeShow();
    light();
}
