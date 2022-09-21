/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 211 bytes
  { 255,8,0,0,0,204,0,16,31,1,2,0,4,11,17,9,2,26,31,31,
  79,78,0,79,70,70,0,3,131,32,12,22,8,2,26,3,133,4,34,45,
  10,2,26,3,133,4,52,46,10,2,26,6,0,4,75,22,22,2,26,4,
  128,32,82,28,6,2,26,129,0,3,4,18,5,17,79,102,102,47,111,110,
  0,129,0,32,7,22,4,17,79,102,102,47,72,84,66,47,77,83,0,129,
  0,3,30,47,3,17,79,102,102,47,78,111,114,109,97,108,47,82,97,105,
  110,98,111,119,47,76,105,103,104,116,47,83,111,117,110,100,0,129,0,3,
  48,53,3,17,71,114,111,117,112,32,49,47,71,114,111,117,112,32,50,47,
  71,114,111,117,112,32,51,47,71,114,111,117,112,52,47,71,114,111,117,112,
  53,0,129,0,11,69,8,4,17,82,71,66,0,129,0,34,69,20,4,17,
  66,114,105,103,104,116,110,101,115,115,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t screenMode; // =0 if select position A, =1 if position B, =2 if position C, ... 
  uint8_t lightMode; // =0 if select position A, =1 if position B, =2 if position C, ... 
  uint8_t lightSet; // =0 if select position A, =1 if position B, =2 if position C, ... 
  uint8_t rgbColor_r; // =0..255 Red color value 
  uint8_t rgbColor_g; // =0..255 Green color value 
  uint8_t rgbColor_b; // =0..255 Blue color value 
  int8_t brightness; // =0..100 slider position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
#include <DHT.h>
#include <DHT_U.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <IRremote.hpp>
#include <EEPROM.h>
#define ModeAddr 0
#define OnOff 1 
#define DD 10                 // wandu 
#define lightSensorPin A0     // liangdu in the range of 0-1023
#define soundLevelPin A2      // shengyin

#include "FastLED.h"          //dengdai 
#define NUM_LEDS 20           //deng dai shu
#define LED_DT 9              // deng dai jie kou
#define LED_TYPE WS2812       
#define COLOR_ORDER GRB 
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32


// WS2812   
uint8_t max_bright = 128;       
CRGB leds[NUM_LEDS]; 
uint8_t beginHue;


//sound level
int soundReading;

//light sensor
int lightReading;
int roomBrightness; 

//temp and humid
DHT dht(DD,DHT11);
float h = 0.0;
float t = 0.0;

// SSD1306 display
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

//time
unsigned long previousTime = 0;
const unsigned long eventInterval = 30;

void setup() 
{
  Serial.begin(9600);
  RemoteXY_Init(); 
  
  //setup temp and humid
  dht.begin();

  //setup SSD1306
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  display.clearDisplay();

  //setup WS2812     
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);  
  FastLED.setBrightness(max_bright);
  
}

void loop() 
{ 
  
  RemoteXY_Handler ();
  
  //temp and humid reading
  h = dht.readHumidity();
  t = dht.readTemperature();
  
  //brightness
  lightReading = analogRead(lightSensorPin);
  soundReading = analogRead(soundLevelPin);
  //Serial.println((soundReading-150)*100);
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 
  


  if (RemoteXY.switch_1 == 1){
    startAction();
  }
  else{
    //turn off light
    FastLED.clear();  // clear all pixel data
    FastLED.show();
    //turn of screen
    display.clearDisplay();
    display.println("");
    display.display();
  }


}

void startAction(){
  screenAction();
  lightAction();
  
}

void screenAction(){
  //display
  display.clearDisplay();
  if (RemoteXY.screenMode == 0){
    display.println("");
    display.display();
  }
  else if (RemoteXY.screenMode == 1){
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE); 
    display.setRotation(0);
    display.print("humid: ");
    display.println(h);
    display.print("temp: ");
    display.println(t);
    display.print("Room Brightness: ");
    display.println(lightReading);
    display.display();
  }
  else{
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE); 
    display.setRotation(0);
    display.print("Light Mode: ");
    uint8_t curMode = RemoteXY.lightMode;
    if (curMode == 0){
      display.println("Off");
    }
    else if (curMode == 1){
      display.println("Normal");
    }
    else if (curMode == 2){
      display.println("Rainbow");
    }
    else if (curMode == 3){
      display.println("Room Light");
    }
    else {
      display.println("Music");
    }
    display.print("Sound Level: ");
    display.println(soundReading);
    display.display();
  }
}

void lightAction(){
  if (RemoteXY.lightMode == 0){
    FastLED.clear();  // clear all pixel data
    FastLED.show();
  }
  else if (RemoteXY.lightMode == 1){
    changeColor(RemoteXY.lightSet);
    int bright = 255 * (RemoteXY.brightness/100);
    FastLED.setBrightness(bright);
    FastLED.show(); 
  }
  else if (RemoteXY.lightMode == 2){
    beginHue++;
    int bri = RemoteXY.brightness*0.01*255;
    FastLED.setBrightness(bri);
    fill_rainbow(leds, NUM_LEDS, beginHue, 9); 
    FastLED.show();  
  }
  else if (RemoteXY.lightMode == 3){
    fill_solid(leds, 20, CRGB::White);
    int minCondition = 700;
    int val = lightReading;
    if (lightReading < minCondition){
      val = 0;
      roomBrightness = 0;
    }
    else{
      roomBrightness = map(val, minCondition, 1023, 0, 255);
    }
    FastLED.setBrightness(roomBrightness);
    FastLED.show(); 
  }
  else {
    unsigned long currentTime = millis();
    if(currentTime - previousTime >= eventInterval){
      //extendFromEnd();
      //extendFromCenter();
      blinkFromCenter();
      previousTime = currentTime;
    }
  }

}

void changeColor(int n){
  for (int i = n*4; i <= 4*(n+1)-1; i++){
    leds[i] = leds[i].setRGB(RemoteXY.rgbColor_r, RemoteXY.rgbColor_g, RemoteXY.rgbColor_b);
  }
}

void blinkFromCenter(){
    int r=252;
    int g=0;
    int b=0;
    int s = (soundReading-545)*10;
    //Serial.println(s);
    if(s>=75)
    {
      leds[9]=CRGB (20, 135, 217);
      leds[10]=CRGB (20, 135, 217);
      //leds[10]=CRGB (20, 217, 30);
    }
    else
    {
      leds[9] = CRGB ( r,g,b);
      leds[10] = CRGB ( r,g,b);
    }
    for (int i = 0; i <= 8; i++) 
    {
      leds[i] = leds[i+1];
     leds[19-i] = leds[18-i];
     
    }
    FastLED.show();
  }

void extendFromCenter(){
  int s = (soundReading-545)*10;
  //Serial.println(s);
  if(s > 150)
  s = 150;

  if(s < 80)
  s = 80;
  int val = map(s, 80, 150, 0, 10);
  int hue = 10;
  for(int i = 0; i <= val; i++){
    leds[10 +i] = CHSV(hue += 1, 150, 200);
    leds[ 10 -i] = CHSV(hue += 1, 150, 200);
  }

  for(int i = val+1; i <= 10; i++){
    leds[10+i].nscale8(10);
    leds[10-i].nscale8(10);
  }
  FastLED.show();
  //delay(100);
}

void extendFromEnd(){
  int s = (soundReading-545)*10;
  //Serial.println(s);
  if(s > 150)
  s = 150;

  if(s < 80)
  s = 80;
  int val = map(s, 80, 150, 0, 19);
  int hue = 10;
  for(int i = 0; i <= val; i++){
    leds[i] = CHSV(hue += 1, 150, 200);
  }

  for(int i = val+1; i <= 19; i++){
    leds[i].nscale8(10);
  }
  FastLED.show();
  //delay(100);
}
