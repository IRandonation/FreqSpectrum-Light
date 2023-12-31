#include <arduinoFFT.h>
#include <FastLED.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <time.h>
#include <Arduino.h>
#include "fftlight.h"

//internet clock
const char *ssid = "RANDOMPC4958";
const char *password = "syc71321";

const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 8*3600;
const int daylightOffset_sec = 0;

const int buttonPin = 4;
bool buttonPressed = false;
bool buttonReleased = false;
unsigned long buttonPressTime = 0;
int ButtonNumber = 0;

#define DATA_PIN 27

#define MATRIX_HEIGHT 8
#define MATRIX_WIDTH  16
// #define NUM_LED 128 //number of LED

#define First -8//clock position
#define Second 24
#define Third 64
#define Fourth 96

#define I2S_READ_LEN 2048
#define SAMPLE_BUFFER_SIZE 512



void NumberLEDShow(char Num, int i) {
    switch (Num)
    {
    case 48:
        leds[9+i] = CRGB(255,255,0);
        leds[10+i] = CRGB(255,255,0);
        leds[11+i] = CRGB(255,255,0);
        leds[12+i] = CRGB(255,255,0);
        leds[13+i] = CRGB(255,255,0);
        leds[14+i] = CRGB(255,255,0);
        leds[17+i] = CRGB(255,255,0);
        leds[22+i] = CRGB(255,255,0);
        leds[25+i] = CRGB(255,255,0);
        leds[26+i] = CRGB(255,255,0);
        leds[27+i] = CRGB(255,255,0);
        leds[28+i] = CRGB(255,255,0);
        leds[29+i] = CRGB(255,255,0);
        leds[30+i] = CRGB(255,255,0);
        break;

    case 49:
        leds[25+i] = CRGB(255,255,0);
        leds[26+i] = CRGB(255,255,0);
        leds[27+i] = CRGB(255,255,0);
        leds[28+i] = CRGB(255,255,0);
        leds[29+i] = CRGB(255,255,0);
        leds[30+i] = CRGB(255,255,0);
        break;

    case 50:
        leds[14+i] = CRGB(255,255,0);
        leds[22+i] = CRGB(255,255,0);
        leds[30+i] = CRGB(255,255,0);
        leds[29+i] = CRGB(255,255,0);
        leds[28+i] = CRGB(255,255,0);
        leds[11+i] = CRGB(255,255,0);
        leds[19+i] = CRGB(255,255,0);
        leds[27+i] = CRGB(255,255,0);
        leds[10+i] = CRGB(255,255,0);
        leds[9+i] = CRGB(255,255,0);
        leds[17+i] = CRGB(255,255,0);
        leds[25+i] = CRGB(255,255,0);
        break;

    case 51:
        leds[14+i] = CRGB(255,255,0);
        leds[22+i] = CRGB(255,255,0);
        leds[30+i] = CRGB(255,255,0);
        leds[29+i] = CRGB(255,255,0);
        leds[28+i] = CRGB(255,255,0);
        leds[11+i] = CRGB(255,255,0);
        leds[19+i] = CRGB(255,255,0);
        leds[27+i] = CRGB(255,255,0);
        leds[26+i] = CRGB(255,255,0);
        leds[9+i] = CRGB(255,255,0);
        leds[17+i] = CRGB(255,255,0);
        leds[25+i] = CRGB(255,255,0);
        break;

    case 52:
        leds[14+i] = CRGB(255,255,0);
        leds[13+i] = CRGB(255,255,0);
        leds[12+i] = CRGB(255,255,0);
        leds[11+i] = CRGB(255,255,0);
        leds[19+i] = CRGB(255,255,0);
        leds[25+i] = CRGB(255,255,0);
        leds[26+i] = CRGB(255,255,0);
        leds[27+i] = CRGB(255,255,0);
        leds[28+i] = CRGB(255,255,0);
        leds[29+i] = CRGB(255,255,0);
        leds[30+i] = CRGB(255,255,0);
        break;

    case 53:
        leds[14+i] = CRGB(255,255,0);
        leds[22+i] = CRGB(255,255,0);
        leds[30+i] = CRGB(255,255,0);
        leds[13+i] = CRGB(255,255,0);
        leds[12+i] = CRGB(255,255,0);
        leds[11+i] = CRGB(255,255,0);
        leds[19+i] = CRGB(255,255,0);
        leds[27+i] = CRGB(255,255,0);
        leds[26+i] = CRGB(255,255,0);
        leds[9+i] = CRGB(255,255,0);
        leds[17+i] = CRGB(255,255,0);
        leds[25+i] = CRGB(255,255,0);
        break;

    case 54:
        leds[14+i] = CRGB(255,255,0);
        leds[22+i] = CRGB(255,255,0);
        leds[30+i] = CRGB(255,255,0);
        leds[13+i] = CRGB(255,255,0);
        leds[12+i] = CRGB(255,255,0);
        leds[11+i] = CRGB(255,255,0);
        leds[19+i] = CRGB(255,255,0);
        leds[27+i] = CRGB(255,255,0);
        leds[26+i] = CRGB(255,255,0);
        leds[9+i] = CRGB(255,255,0);
        leds[17+i] = CRGB(255,255,0);
        leds[25+i] = CRGB(255,255,0);
        leds[10+i] = CRGB(255,255,0);
        break;

    case 55:
        leds[14+i] = CRGB(255,255,0);
        leds[22+i] = CRGB(255,255,0);
        leds[30+i] = CRGB(255,255,0);
        leds[29+i] = CRGB(255,255,0);
        leds[28+i] = CRGB(255,255,0);
        leds[27+i] = CRGB(255,255,0);
        leds[26+i] = CRGB(255,255,0);
        leds[25+i] = CRGB(255,255,0);
        break;

    case 56:
        leds[14+i] = CRGB(255,255,0);
        leds[22+i] = CRGB(255,255,0);
        leds[30+i] = CRGB(255,255,0);
        leds[13+i] = CRGB(255,255,0);
        leds[29+i] = CRGB(255,255,0);
        leds[12+i] = CRGB(255,255,0);
        leds[28+i] = CRGB(255,255,0);
        leds[11+i] = CRGB(255,255,0);
        leds[19+i] = CRGB(255,255,0);
        leds[27+i] = CRGB(255,255,0);
        leds[10+i] = CRGB(255,255,0);
        leds[26+i] = CRGB(255,255,0);
        leds[9+i] = CRGB(255,255,0);
        leds[17+i] = CRGB(255,255,0);
        leds[25+i] = CRGB(255,255,0);
        break;

    case 57:
        leds[14+i] = CRGB(255,255,0);
        leds[22+i] = CRGB(255,255,0);
        leds[30+i] = CRGB(255,255,0);
        leds[13+i] = CRGB(255,255,0);
        leds[29+i] = CRGB(255,255,0);
        leds[12+i] = CRGB(255,255,0);
        leds[28+i] = CRGB(255,255,0);
        leds[11+i] = CRGB(255,255,0);
        leds[19+i] = CRGB(255,255,0);
        leds[27+i] = CRGB(255,255,0);
        leds[26+i] = CRGB(255,255,0);
        leds[9+i] = CRGB(255,255,0);
        leds[17+i] = CRGB(255,255,0);
        leds[25+i] = CRGB(255,255,0);
        break;

    default:
        break;
    }
}

void TimeShow() {
    FastLED.clear();
    time_t now = time(nullptr);
    //Serial.print("time is ");
    char* time = ctime(&now);
    Serial.println(ctime(&now));
    int hour_1 = (int)time[11];
    int hour_2 = (int)time[12];
    int min_1 = (int)time[14];
    int min_2 = (int)time[15];

    NumberLEDShow(hour_1, First);
    NumberLEDShow(hour_2, Second);
    NumberLEDShow(min_1, Third);
    NumberLEDShow(min_2, Fourth);
    leds[61] = CRGB(255,255,0);
    leds[69] = CRGB(255,255,0);
    leds[58] = CRGB(255,255,0);
    leds[66] = CRGB(255,255,0);

    FastLED.show();
    delay(500);
    FastLED.clear();
    NumberLEDShow(hour_1, First);
    NumberLEDShow(hour_2, Second);
    NumberLEDShow(min_1, Third);
    NumberLEDShow(min_2, Fourth);
    leds[61] = CRGB(0,0,0);
    leds[69] = CRGB(0,0,0);
    leds[58] = CRGB(0,0,0);
    leds[66] = CRGB(0,0,0);
    FastLED.show();
    delay(500);
}


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
