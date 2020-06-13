// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
#include <WS2812.h>
#include <BME280I2C.h>

RTC_DS1307 rtc;
#define outputPin 8  // Digital output pin command WS2812
#define LEDCount 60   // Number of LEDs WS2812
WS2812 LED(LEDCount);
cRGB value;

BME280I2C bme;

byte holdminute=99;
byte holdsecond=99;
int sensorPin = A0;   // input pin per photoresistor
int sensorValue = 0;  // variable to store the value coming from the sensor
int pot1Pin = A1;
int pot1Value = 0;
int pot2Pin = A2; 
int pot2Value = 0;
float lumMin = 0;
float lumMax = 1;
float lumDev = 0;
float lumValue = 1; // luminosità dei led
int hh = 0;
int hho = 0;
int oldhh = - 99;
int mm = 0;;
int ss = 0;
boolean mh = true;
int gg = 0;
int mmm = 0;
int gs = 0;
int yy = 0;
int q = 0;
int ledore = 11;
int leddata = 10;
int ledtempfl = 9;
int ledprehum = 6;
int capomese[]={11,12,1,2,3,4,5,6,7,8,9,10};
int patta[]={24,5,16,27,8,19,0,11,22,3,14,25,6,17,28,9,20,1,12,23,4,15,26,7,18,29,10,21,2,13,24,5,16,27,8,19,0,11,22,3,14};
int faselunare;
int aslm = 725;

unsigned long previousMillis = 0;
const long interval = 7000;

float temp(NAN), hum(NAN), pres(NAN);

void setup() {
  Serial.begin(9600);
  pinMode(ledore, OUTPUT);
  pinMode(leddata, OUTPUT);
  pinMode(ledtempfl, OUTPUT);
  pinMode(ledprehum, OUTPUT);
  LED.setOutput(outputPin);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
  }
    Wire.begin();

  while(!bme.begin())
  {
    Serial.println("Could not find BME280 sensor!");
    delay(1000);
  }

  // bme.chipID(); // Deprecated. See chipModel().
  switch(bme.chipModel()) {
     case BME280::ChipModel_BME280:
       Serial.println("Found BME280 sensor! Success.");
       break;
     case BME280::ChipModel_BMP280:
       Serial.println("Found BMP280 sensor! No Humidity available.");
       break;
     default:
       Serial.println("Found UNKNOWN sensor! Error!");
  }
  previousMillis = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();
  ss = now.second();
  if (holdsecond != ss) {
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);
    pot1Value =  analogRead(pot1Pin);
    pot2Value =  analogRead(pot2Pin);
    lumMin = pot1Value / 1024.00;
    lumMax = pot2Value / 1024.00;
    Serial.println(pot1Value);
    Serial.println(pot2Value);
    Serial.println(lumMin);
    Serial.println(lumMax);
    lumDev = lumMax - lumMin;
    lumValue = lumMin + sensorValue * lumDev / 1024;
    Serial.println(lumValue);
    mm = now.minute();
    hh = now.hour();
    hho = hh;
    gg = now.day();
    mmm = now.month();
    yy = now.year();
    gs = now.dayOfTheWeek();
    if (gs == 0) gs = 7;
    if (hh > 11) {
      hho = hh - 12;
    }
    hho = hho * 5 + mm / 12 + 0.5;
    holdsecond = ss;
    
    BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
    BME280::PresUnit presUnit(BME280::PresUnit_Pa);
    bme.read(pres, temp, hum, tempUnit, presUnit);
    pres = pres / 100;
    pres = pres + aslm / 29.27 * pres / (temp + 273.15);
    if (millis() - previousMillis >= interval) {
      previousMillis = millis();
      q = q + 1;
      if (q == 4) {
        q = 0;
      }
    }
    
    switch (q) {
      case 0:
        analogWrite(ledprehum, 0);
        analogWrite(ledore, 255 * lumValue);
        AccendiOre();
        break;
      case 1:
        analogWrite(ledore, 0);
        analogWrite(leddata, 255 * lumValue);
        AccendiData();
        break;
      case 2:
        analogWrite(leddata, 0);
        analogWrite(ledtempfl, 255 * lumValue);
        Accenditempfl();
        break;
      case 3:
        analogWrite(ledtempfl, 0);
        analogWrite(ledprehum, 255 * lumValue);
        Accendiprehum();
        break;
      }
  }
}


void AccendiData() {
  for (int i = 0; i < 60; i++) {
    value.b = 0; value.g = 4; value.r = 4;
    LED.set_crgb_at(i, value); // Set value at LED found at index 0
  }
  value.b = 0; value.g = 0; value.r = 255;
  LED.set_crgb_at(59 - gg, value); // Set value at LED found at index 0
  value.b = 0; value.g = 127; value.r = 255;
  LED.set_crgb_at(gs, value); // Set value at LED found at index 0
  value.b = 0; value.g = 127; value.r = 127;
  LED.set_crgb_at(mmm + 11, value); // Set value at LED found at index 0
  LED.sync(); // Sends the value to the LED
}


void AccendiOre () {
  for (int i = 0; i < 60; i++) {
    value.b = 5; value.g = 5; value.r = 0;
    LED.set_crgb_at(i, value); // Set value at LED found at index 0
  }
  int mp = mm - 1;
  int ms = mm + 1;
  if (mp < 0) mp = 59;
  if (ms == 60) ms = 0;
  value.b = 0; value.g = 16; value.r = 2;
  LED.set_crgb_at(mp, value); // Set value at LED found at index 0
  value.b = 0; value.g = 127; value.r = 16;
  LED.set_crgb_at(mm, value); // Set value at LED found at index 0
  value.b = 0; value.g = 16; value.r = 2;
  LED.set_crgb_at(ms, value); // Set value at LED found at index 0
  int hp = hho - 1;
  int hs = hho + 1;
  if (hp < 0) hp = 59;
  if (hs == 60) hs = 0;
  if (hp != mm) {
    value.b = 0; value.g = 0; value.r = 16;
    LED.set_crgb_at(hp, value); // Set value at LED found at index 0    
  }
  value.b = 0; value.g = 0; value.r = 255;
  LED.set_crgb_at(hho, value); // Set value at LED found at index 0ù
  if (hs != mm) {
    value.b = 0; value.g = 0; value.r = 16;
    LED.set_crgb_at(hs, value); // Set value at LED found at index 0
  }
  if (mm == hho && mh == true) {
    value.b = 0; value.g = 16; value.r = 2;
    LED.set_crgb_at(mp, value); // Set value at LED found at index 0
    value.b = 0; value.g = 127; value.r = 16;
    LED.set_crgb_at(mm, value); // Set value at LED found at index 0
    value.b = 0; value.g = 16; value.r = 2;
    LED.set_crgb_at(ms, value); // Set value at LED found at index 0
    mh = false;
  }
  else if (mm == hho && mh == false) {
    value.b = 0; value.g = 0; value.r =16;
    LED.set_crgb_at(hp, value); // Set value at LED found at index 0
    value.b = 0; value.g = 0; value.r =255;
    LED.set_crgb_at(hho, value); // Set value at LED found at index 0
    value.b = 0; value.g = 0; value.r =16;
    LED.set_crgb_at(hs, value); // Set value at LED found at index 0
    mh = true;
  }
  value.b = 255; value.g = 0; value.r = 0;
  LED.set_crgb_at(ss, value); // Set value at LED found at index 0
  LED.sync(); // Sends the value to the LED
}

void Accenditempfl() {
  for (int i = 0; i < 60; i++) {
    value.b = 1; value.g = 1; value.r = 1;
    LED.set_crgb_at(i, value); // Set value at LED found at index 0
  }
  temp = int(temp + 0.5);
  if (temp < 4) {
    value.b = 100; value.g = 0; value.r = 180;
  }
  if (temp >= 4 & temp < 12) {
    value.b = 80; value.g = 0; value.r = 200;
  }
  if (temp >= 12 & temp < 20) {
    value.b = 0; value.g = 127; value.r = 192; 
  }
  if (temp >= 20 & temp < 26) {
    value.b = 0; value.g = 255; value.r = 0;
  }
  if (temp >= 26 & temp < 32) {
    value.b = 127; value.g = 127; value.r = 0;
  }
  if (temp >= 32) {
    value.b = 0; value.g = 0; value.r = 255; 
  }
  if (temp / 2 != int(temp / 2)) {
    LED.set_crgb_at(temp / 2 + 4, value); // Set value at LED found at index 0
    LED.set_crgb_at(temp / 2 + 5, value); // Set value at LED found at index 0
  } else {
    LED.set_crgb_at(temp / 2 + 4, value); // Set value at LED found at index 0
  }
  Calcolafaselunare();
  Serial.println(temp);
  Serial.println(faselunare);
  value.b = 63; value.g = 63; value.r = 63; // RGB Value -> Blue
  LED.set_crgb_at(faselunare + 29, value); // Set value at LED found at index 0  LED.sync(); // Sends the value to the LED  
  LED.sync(); // Sends the value to the LED  
}

void Accendiprehum() {
  for (int i = 0; i < 60; i++) {
    value.b = 4; value.g = 2; value.r = 1;
    LED.set_crgb_at(i, value); // Set value at LED found at index 0
  }
  if (pres < 1000) {
    value.b = 0; value.g = 0; value.r = 255;
  }
  if (pres >= 1000 & pres < 1030) {
    value.b = 0; value.g = 127; value.r = 127; 
  }
  if (pres >= 1030) {
    value.b = 0; value.g = 255; value.r = 0;  
  }
  LED.set_crgb_at((pres - 960) / 5 + 2, value); // Set value at LED found at index 0
  if (hum < 36) {
    value.b = 0; value.g = 127; value.r = 192;
  }
  if (hum >= 36 & hum < 40) {
    value.b = 0; value.g = 92; value.r = 192;
  }
  if (hum >= 40 & hum <= 60) {
    value.b = 0; value.g = 255; value.r = 0;
  }
  if (hum > 60 & hum < 65) {
    value.b = 127; value.g = 127; value.r = 0;
  }
  if (hum > 65) {
    value.b = 255; value.g = 0; value.r = 0;
  }
  LED.set_crgb_at(58 - (hum - 20) / 2, value); // Set value at LED found at index 0
  Serial.println(pres);
  Serial.println(hum);  
  LED.sync(); // Sends the value to the LED  
}


void Calcolafaselunare () {
  faselunare = gg + capomese[mmm - 1] + patta[yy - 2000];
  if (mmm < 3) faselunare = gg + capomese[mmm - 1] + patta[yy - 2000 - 1];
  if (faselunare >= 30) faselunare = faselunare - 30;
}
