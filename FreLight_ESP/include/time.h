#include <FastLED.h>

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
