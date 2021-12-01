#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN           10
#define NUMPIXELS     3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

long randomNumber;
long randomBrightness;
long randomDelay;

//const int ledPin = 13;   
const int ldrPin = A0;  


void setup() {

  Serial.begin(9600);
//  pinMode(ledPin, OUTPUT);  
  pinMode(ldrPin, INPUT);   
  pixels.begin();
}

void loop() {

  randomNumber = random(1,9);
  randomBrightness = random(0,256);
  randomDelay = random(100,400);

  int ldrStatus = analogRead(ldrPin);   

  //check if the LDR status is <= 300
  //if it is, the LED is HIGH

//   if (ldrStatus <= 300 ) {
//
//    digitalWrite(ledPin, LOW);   
//    Serial.println("LDR is DARK, LED is ON");
//    
//   }

    if (ldrStatus <= 300 && randomNumber==1)
  { 
    pixels.setPixelColor(0, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else if (ldrStatus <= 300 && randomNumber==2)
  {
    pixels.setPixelColor(1, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else if (ldrStatus <= 300 && randomNumber==3)
  {
    pixels.setPixelColor(2, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else if (ldrStatus <= 300 && randomNumber==4)
  {
    pixels.setPixelColor(0, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
    pixels.setPixelColor(1, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else if (ldrStatus <= 300 && randomNumber==5)
  {
    pixels.setPixelColor(0, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
    pixels.setPixelColor(2, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else if (ldrStatus <= 300 && randomNumber==6)
  {
    pixels.setPixelColor(1, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
    pixels.setPixelColor(2, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
 }
  
  else if (ldrStatus <= 300 && randomNumber==7)
  {
    pixels.setPixelColor(0, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
    pixels.setPixelColor(1, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
    pixels.setPixelColor(2, pixels.Color(randomBrightness,randomBrightness,randomBrightness));
  }
  
  else
  {
    pixels.setPixelColor(0, pixels.Color(0,0,0));
    pixels.setPixelColor(1, pixels.Color(0,0,0));
    pixels.setPixelColor(2, pixels.Color(0,0,0));
  }
  
 
  pixels.show();
 
  delay(randomDelay);

  pixels.setPixelColor(0, pixels.Color(0,0,0));
  pixels.setPixelColor(1, pixels.Color(0,0,0));
  pixels.setPixelColor(2, pixels.Color(0,0,0));
  pixels.show();

 
  Serial.println("---------------");
  }

  
