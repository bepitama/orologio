//Created by Giuseppe Tamanini 13/01/2021
//Licenza CC/SA

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
#define button1Pin 3 // crea la costante buttonPin con il numero del pin dove verrà collegato il pulsante1
#define button2Pin 4 // crea la costante buttonPin con il numero del pin dove verrà collegato il pulsante2
#define button3Pin 5 // crea la costante buttonPin con il numero del pin dove verrà collegato il pulsante3
int sensorPin = A0;   // input pin per photoresistor
int sensorValue = 0;  // variable to store the value coming from the sensor
int pot1Pin = A2;
int pot1Value = 0;
int pot2Pin = A1; 
int pot2Value = 0;
float lumMin = 0;
float lumMax = 1;
float lumDev = 0;
float lumValue = 1; // luminosità dei led
int hh = 0; // ore su 24
int hho = 0; // ore su 12
int oldhh = - 99;
int mm = 0; // minuti
int ss = 0; // secondi
boolean mh = true; // minuti e ore sovrapposte
int gg = 0; // giorni
int mmm = 0; // mesi
int gs = 0; // giorno della settimana
int yy = 0; // anno
int q = 0; // quadro visualizzazione
boolean modv = false; // modalità di visualizzazione
int ledore = 11; // pin led
int leddata = 10;
int ledtempfl = 9;
int ledprehum = 6;
int capomese[]={11,12,1,2,3,4,5,6,7,8,9,10};
int patta[]={24,5,16,27,8,19,0,11,22,3,14,25,6,17,28,9,20,1,12,23,4,15,26,7,18,29,10,21,2,13,24,5,16,27,8,19,0,11,22,3,14};
int faselunare;
int GMese[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // numero di giorni dei mesi
int giorniMese; // numero giorni del mese
int aslm = 750; // altezza sul livello del mare
boolean valbutton1; // condizione del pulsante di modifica data/ora
boolean valbutton2; // condizione del pulsante di incremento dato
boolean valbutton3; // condizione del pulsante che sposta la modifica al campo successivo
boolean oldvalbutton1; // vecchie condizioni
boolean oldvalbutton2;
boolean oldvalbutton3;
boolean cambiato1; // stato dell'azione del pulsante
boolean cambiato2;
boolean cambiato3;
int campo = 1; // numero che identifica quale dato stiamo impostando (1 anno, 2 mese, 3 giorno, 4 ora, 5 minuti, 6 altitudine)
static unsigned long myTime; // tempo di premuta pulsante modifica data/ora
static unsigned long myTime1; // tempo di premuta pulsante che incrementa il dato
static unsigned long myTime2; // tempo di premuta pulsante che sposta la modifica al campo successivo
static unsigned long myTime3; // tempo massimo di non utilizzo pulsanti previsto per l'uscita dalla modalità modifica

unsigned long previousMillis = 0;
const long interval = 7000;

float temp(NAN), hum(NAN), pres(NAN);

void setup() {
  Serial.begin(9600);
  pinMode(ledore, OUTPUT);
  pinMode(leddata, OUTPUT);
  pinMode(ledtempfl, OUTPUT);
  pinMode(ledprehum, OUTPUT);
  pinMode(button1Pin, INPUT); // setta il pin del pulsante1 come INPUT
  pinMode(button2Pin, INPUT); // setta il pin del pulsante2 come INPUT
  pinMode(button3Pin, INPUT); // setta il pin del pulsante3 come INPUT
  LED.setOutput(outputPin); // definisce qual è il pin che comanda i led WS2812
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
    //Serial.print("sensorValue=");
    //Serial.println(sensorValue);
    pot1Value =  analogRead(pot1Pin);
    pot2Value =  analogRead(pot2Pin);
    lumMin = pot1Value / 1024.00;
    lumMax = pot2Value / 1024.00;
    //Serial.print("lunMin=");
    //Serial.println(lumMin);
    //Serial.print("lunMax=");
    //Serial.println(lumMax);
    lumDev = (lumMax + 1 - lumMin) / 2;
    lumValue = lumMin * 0.5 + lumDev * sensorValue / 1024.00;
    //Serial.print("lumValue=");
    //Serial.println(lumValue);
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
    hum = hum * 1.25;
    pres = pres / 100;
    pres = pres + aslm / 29.27 * pres / (temp + 273.15);
    if (!modv) {
      if (millis() - previousMillis >= interval) {
        previousMillis = millis();
        q = q + 1;
        if (q == 4) {
          q = 0;
        }
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
  valbutton1 = digitalRead(button1Pin);
  if (valbutton1 && !oldvalbutton1) {
    myTime = millis();
    oldvalbutton1 = true; 
  } else if (valbutton1 == false && oldvalbutton1) {
    oldvalbutton1 = false;  // pone il vecchio stato del pulsante a falso
    cambiato1 = false; // lo stato dell'azione del pulsante1 è falsa 
  }
  if (valbutton1 && oldvalbutton1 && cambiato1 == false && millis() - myTime > 1000) {
    myTime3 = millis();
    while (valbutton1) { // ripete finché il pulsante1 è ancora premuto attendendone il rilascio
      valbutton1 = digitalRead(button1Pin);
    }
    oldvalbutton1 = false;
    modificadata(); // esegue la funzione modificadata
  }

  valbutton3 = digitalRead(button3Pin);
  if (valbutton3 && !oldvalbutton3) {
    myTime = millis();
    oldvalbutton3 = true; 
  } else if (valbutton3 == false && oldvalbutton3) {
    oldvalbutton3 = false;  // pone il vecchio stato del pulsante a falso
    cambiato3 = false; // lo stato dell'azione del pulsante1 è falsa 
  }
  if (valbutton3 && oldvalbutton3 && cambiato3 == false && millis() - myTime > 1000) {
    myTime3 = millis();
    while (valbutton3) { // ripete finché il pulsante1 è ancora premuto attendendone il rilascio
      valbutton3 = digitalRead(button3Pin);
    }
    oldvalbutton3 = false;
    modv = !modv; // cambia la modalità di visualizzazione
    q = 0; // quadro 0 (ore)
    previousMillis = millis();
  }

  valbutton2 = digitalRead(button2Pin);
  if (valbutton2 && !oldvalbutton2) {
    myTime = millis();
    oldvalbutton2 = true; 
  } else if (valbutton2 == false && oldvalbutton2) {
    oldvalbutton2 = false;  // pone il vecchio stato del pulsante a falso
    cambiato2 = false; // lo stato dell'azione del pulsante1 è falsa 
  }
  if (valbutton2 && oldvalbutton2 && cambiato2 == false && millis() - myTime > 10) {
    myTime3 = millis();
    while (valbutton2) { // ripete finché il pulsante1 è ancora premuto attendendone il rilascio
      valbutton2 = digitalRead(button2Pin);
    }
    oldvalbutton2 = false;
    q = q + 1; // cambia il quadro
    if (q == 4) q = 0;
  }

}


void AccendiData() {
  for (int i = 0; i < 60; i++) {
    value.b = 0; value.g = 4; value.r = 4;
    LED.set_crgb_at(i, value);
  }
  value.b = 0; value.g = 0; value.r = 255;
  LED.set_crgb_at(59 - gg, value);
  value.b = 0; value.g = 127; value.r = 255;
  LED.set_crgb_at(gs, value);
  value.b = 0; value.g = 127; value.r = 127;
  LED.set_crgb_at(mmm + 11, value);
  LED.sync(); // Sends the value to the LED
}


void AccendiOre () {
  for (int i = 0; i < 60; i++) {
    value.b = 5; value.g = 5; value.r = 0;
    LED.set_crgb_at(i, value);
  }
  int mp = mm - 1;
  int ms = mm + 1;
  if (mp < 0) mp = 59;
  if (ms == 60) ms = 0;
  value.b = 0; value.g = 16; value.r = 2;
  LED.set_crgb_at(mp, value);
  value.b = 0; value.g = 127; value.r = 16;
  LED.set_crgb_at(mm, value);
  value.b = 0; value.g = 16; value.r = 2;
  LED.set_crgb_at(ms, value);
  int hp = hho - 1;
  int hs = hho + 1;
  if (hp < 0) hp = 59;
  if (hs == 60) hs = 0;
  if (hp != mm) {
    value.b = 0; value.g = 0; value.r = 16;
    LED.set_crgb_at(hp, value);    
  }
  value.b = 0; value.g = 0; value.r = 255;
  LED.set_crgb_at(hho, value);
  if (hs != mm) {
    value.b = 0; value.g = 0; value.r = 16;
    LED.set_crgb_at(hs, value);
  }
  if (mm == hho && mh == true) {
    value.b = 0; value.g = 16; value.r = 2;
    LED.set_crgb_at(mp, value);
    value.b = 0; value.g = 127; value.r = 16;
    LED.set_crgb_at(mm, value);
    value.b = 0; value.g = 16; value.r = 2;
    LED.set_crgb_at(ms, value);
    mh = false;
  }
  else if (mm == hho && mh == false) {
    value.b = 0; value.g = 0; value.r =16;
    LED.set_crgb_at(hp, value);
    value.b = 0; value.g = 0; value.r =255;
    LED.set_crgb_at(hho, value);
    value.b = 0; value.g = 0; value.r =16;
    LED.set_crgb_at(hs, value);
    mh = true;
  }
  value.b = 255; value.g = 0; value.r = 0;
  LED.set_crgb_at(ss, value);
  LED.sync(); // Sends the value to the LED
}

void Accenditempfl() {
  for (int i = 0; i < 60; i++) {
    value.b = 1; value.g = 1; value.r = 1;
    LED.set_crgb_at(i, value);
  }
  temp = int(temp);
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
    LED.set_crgb_at(temp / 2 + 4, value);
    LED.set_crgb_at(temp / 2 + 5, value);
  } else {
    LED.set_crgb_at(temp / 2 + 4, value);
  }
  Calcolafaselunare();
  Serial.println(temp);
  Serial.println(faselunare);
  value.b = 63; value.g = 63; value.r = 63;
  LED.set_crgb_at(faselunare + 29, value);  
  LED.sync(); // Sends the value to the LED  
}

void Accendiprehum() {
  for (int i = 0; i < 60; i++) {
    value.b = 4; value.g = 2; value.r = 1;
    LED.set_crgb_at(i, value);
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
  LED.set_crgb_at((pres - 960) / 5 + 2, value);
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
  LED.set_crgb_at(58 - (hum - 20) / 2, value);
  LED.sync(); // Sends the value to the LED  
}


void Calcolafaselunare () {
  faselunare = gg + capomese[mmm - 1] + patta[yy - 2000];
  if (mmm < 3) faselunare = gg + capomese[mmm - 1] + patta[yy - 2000 - 1];
  if (faselunare >= 30) faselunare = faselunare - 30;
}

void modificadata() {
  analogWrite(ledore, 0);
  analogWrite(leddata, 0);
  analogWrite(ledtempfl, 0);
  analogWrite(ledprehum, 0);
  for (int i = 0; i < 60; i++) {
    value.b = 0; value.g = 0; value.r = 0;
    LED.set_crgb_at(i, value);
  }
  while (campo < 7) {
    value.b = 127; value.g = 127; value.r = 127;
    switch (campo) {
    case 1:
      LED.set_crgb_at(1, value);
      LED.set_crgb_at(59 - (yy - 2000), value);
      break;
    case 2:
      LED.set_crgb_at(2, value);
      LED.set_crgb_at(59 - mmm, value);
      break;
    case 3:
      LED.set_crgb_at(3, value);
      LED.set_crgb_at(59 - gg, value);
      break;
    case 4:
      LED.set_crgb_at(4, value);
      LED.set_crgb_at(59 - hh, value);
      break;
    case 5:
      LED.set_crgb_at(5, value);
      LED.set_crgb_at(59 - mm, value);
      break;
    case 6:
      LED.set_crgb_at(6, value);
      LED.set_crgb_at(59 - aslm / 50, value);
      break;
    }
    valbutton1 = digitalRead(button1Pin);
    if (valbutton1 && !oldvalbutton1) {
      myTime3 = millis();
      myTime = millis();
      oldvalbutton1 = true; 
    } else if (valbutton1 == false && oldvalbutton1) {
      oldvalbutton1 = false;  // pone il vecchio stato del pulsante2 a falso
      cambiato1 = false; // lo stato dell'azione del pulsante2 è falsa 
    }
    if (valbutton1 && oldvalbutton1 && cambiato1 == false && millis() - myTime > 10) {
      value.b = 0; value.g = 0; value.r = 0;
      switch (campo) {
      case 1:
        LED.set_crgb_at(59 - (yy - 2000), value);
        yy = yy - 1;
        giorniMese = GMese[mmm - 1]; // estrae dalla matrice il numero dei giorni del mese corrente
        if (yy / 4 == int(yy / 4) && mmm == 2) giorniMese = giorniMese + 1; // se l'anno è bisestile ed è febbraio aggiungi 1 al numero dei giorni del mese
        break;
      case 2:
        LED.set_crgb_at(59 - (yy - 2000), value);
        LED.set_crgb_at(59 - mmm, value);
        mmm = mmm - 1;
        if (mmm < 1) mmm = 12;
        break;
      case 3:
        LED.set_crgb_at(59 - mmm, value);
        LED.set_crgb_at(59 - gg, value);
        gg = gg - 1; // decrementa il numero dei giorni
        if (gg < 1) { // se il valore è minore di 1
          gg = giorniMese; // pone numDay uguale al numero dei giorni del mese corrente
        }
        break;
      case 4:
        LED.set_crgb_at(59 - gg, value);
        LED.set_crgb_at(59 - hh, value);
        hh = hh - 1;
        if (hh < 1) hh = 23;
        break;
      case 5:
        LED.set_crgb_at(59 - hh, value);
        LED.set_crgb_at(59 - mm, value);
        mm = mm - 1;
        if (mm < 1) mm = 59;
        break;
      case 6:
        LED.set_crgb_at(59 - mm, value);
        LED.set_crgb_at(59 - aslm / 50, value);
        if (aslm > 0) aslm = aslm - 50;
        break;
      }
      cambiato1 = true; // lo stato dell'azione del pulsante2 è vera
    }
    valbutton2 = digitalRead(button2Pin);
    if (valbutton2 && !oldvalbutton2) {
      myTime3 = millis();
      myTime1 = millis();
      oldvalbutton2 = true; 
    } else if (valbutton2 == false && oldvalbutton2) {
      oldvalbutton2 = false;  // pone il vecchio stato del pulsante2 a falso
      cambiato2 = false; // lo stato dell'azione del pulsante2 è falsa 
    }
    if (valbutton2 && oldvalbutton2 && cambiato2 == false && millis() - myTime1 > 10) {
      value.b = 0; value.g = 0; value.r = 0;
      switch (campo) {
      case 1:
        LED.set_crgb_at(59 - (yy - 2000), value);
        yy = yy + 1;
        giorniMese = GMese[mmm - 1];
        if (yy / 4 == int(yy / 4) && mmm == 2) giorniMese = giorniMese + 1; // se l'anno è bisestile ed è febbraio aggiungi 1 al numero dei giorni del mese
        if (gg > giorniMese) gg = 1;
        break;
      case 2:
        LED.set_crgb_at(59 - (yy - 2000), value);
        LED.set_crgb_at(59 - mmm, value);
        mmm = mmm + 1;
        if (mmm > 12) mmm = 1;
        break;
      case 3:
        LED.set_crgb_at(59 - mmm, value);
        LED.set_crgb_at(59 - gg, value);
        gg = gg + 1;
        break;
      case 4:
        LED.set_crgb_at(59 - gg, value);
        LED.set_crgb_at(59 - hh, value);
        hh = hh + 1;
        if (hh > 23) hh = 0;
        break;
      case 5:
        LED.set_crgb_at(59 - hh, value);
        LED.set_crgb_at(59 - mm, value);
        mm = mm + 1;
        if (mm > 59) mm = 0;
        break;
      case 6:
        LED.set_crgb_at(59 - mm, value);
        LED.set_crgb_at(59 - aslm / 50, value);
        if (aslm < 2000) aslm = aslm + 50;
        break;
      }
      cambiato2 = true; // lo stato dell'azione del pulsante2 è vera
    }
    valbutton3 = digitalRead(button3Pin);
    if (valbutton3 && !oldvalbutton3) {
      myTime3 = millis();
      myTime2 = millis();
      oldvalbutton3 = true; 
    } else if (valbutton3 == false && oldvalbutton3) {
      oldvalbutton3 = false;  // pone il vecchio stato del pulsante3 a falso
      cambiato3 = false; // lo stato dell'azione del pulsante3 è falsa 
    }
    if (valbutton3 && oldvalbutton3 && cambiato3 == false && millis() - myTime2 > 10) {
      for (int i = 0; i < 60; i++) {
        value.b = 0; value.g = 0; value.r = 0;
        LED.set_crgb_at(i, value);
      }
      campo = campo + 1;
      cambiato3 = true; // lo stato dell'azione del pulsante3 è vera
    }
    delay(50);
    if (millis() - myTime3 > 10000) {
      campo = 7;
    }
    LED.sync(); // Sends the value to the LED
  }
  if (cambiato3) {
    rtc.adjust(DateTime(yy, mmm, gg, hh, mm, ss));
  }
  campo = 1;
  previousMillis = millis();
  q = 0;
}
