#include <arduinoFFT.h>
#include <math.h>
#include <FastLED.h>

#define SAMPLES 512 //number of sample
#define SAMPLING_FREQUENCY 10240 //frequncy of sampel
#define NUM_LED 128 //number of LED
#define audio_PIN 25

arduinoFFT FFT = arduinoFFT(); //creat a fft project

int gain = 7; //adjust it to fit the volume

static double vReal[SAMPLES];
static double vImag[SAMPLES];
double fft_bin[SAMPLES];
double fft_data[16];
int fft_result[16]; //there are 16 column leds in total

double fft_freq_boost[16] = {1.02,1.04,1.08,1.10,1.12,1.15,1.17,1.20,1.30,2.11,0.95,0.52,0.82,0.52,0.53,0.82};//adjust single frequency curves.

uint8_t bar_height[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t prev_fft_value[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

CRGB leds[NUM_LED];

double fft_add(int from, int to) {
    int i = from;
    double result = 0;
    while(i <= to) {
        result += fft_bin[i++];
    }
    return result;
}

void light() {
    static uint32_t tStart = 0;
    for(int i = 0; i < SAMPLES; i++) {
        vReal[i] = abs(analogRead(audio_PIN));
        vImag[i] = 0;
        //Serial.println(vReal[i]);
        delayMicroseconds(500000 / SAMPLING_FREQUENCY);
    }

    FFT.DCRemoval();
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);

    for(int i = 0; i < SAMPLES; i++){
            double t = 0.0;
            t = abs(vReal[i]);
            t = t / 16.0;
            fft_bin[i] =t;
        }
    
    fft_data[0]  =  (fft_add(3,5))/3;        //60-120hz
    fft_data[1]  =  (fft_add(5,7))/3;        //100-160hz
    fft_data[2]  =  (fft_add(7,9))/3;        //140-200hz
    fft_data[3]  =  (fft_add(9,11))/3;       //180-240hz
    fft_data[4]  =  (fft_add(11,13))/3;      //220-280hz
    fft_data[5]  =  (fft_add(13,16))/4;      //260-240hz
    fft_data[6]  =  (fft_add(16,20))/5;      //320-420hz
    fft_data[7]  =  (fft_add(20,28))/9;      //400-580hz
    fft_data[8]  =  (fft_add(28,36))/9;      //560-740hz
    fft_data[9]  =  (fft_add(36,48))/13;     //720-980hz
    fft_data[10] =  (fft_add(48,64))/17;     //960-1300hz
    fft_data[11] =  (fft_add(64,84))/21;     //1280-1700hz
    fft_data[12] =  (fft_add(84,110))/27;    //1680-1960hz
    fft_data[13] =  (fft_add(110,146))/37;   //2200-2940hz
    fft_data[14] =  (fft_add(146,194))/49;   //2920-3900hz
    fft_data[15] =  (fft_add(194,255))/62;   //3880-5120hz
    for(int i = 0; i < 16; i++) {
        fft_data[i] = fft_data[i] * fft_freq_boost[i];
        //Serial.println(fft_data[i]);
    }
    for(int i = 0; i < 16; i++) {
        fft_data[i] = fft_data[i] * gain / 50;
    }
    for(int i = 0; i < 16; i++) {
        fft_result[i] = constrain((int)fft_data[i],0,225);
        bar_height[i] = map(fft_result[i], 0, 225, 0, 8);
    }
   

     for(int i = 0; i < 16; i++) {
        for(int j = 0; j < bar_height[i]; j++){
            switch (j)
            {
            case 7/* constant-expression */:
                leds[i*8+j] = CRGB(255,0,0);/* code */
                break;

            case 6:
                leds[i*8+j] = CRGB(223,0,32);
                break;

            case 5:
                leds[i*8+j] = CRGB(191,0,64);
                break;

            case 4:
                leds[i*8+j] = CRGB(159,0,96);
                break;

            case 3:
                leds[i*8+j] = CRGB(127,0,128);
                break;

            case 2:
                leds[i*8+j] = CRGB(95,0,160);
                break;

            case 1:
                leds[i*8+j] = CRGB(63,0,192);
                break;

            case 0:
                leds[i*8+j] = CRGB(0,0,255);
                break;
            
            default:
                break;
            }
        }
    }
    FastLED.show();
    FastLED.clear();
    
}
   