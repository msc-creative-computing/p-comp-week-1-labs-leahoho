
#include "SD.h"
#define SD_ChipSelectPin 2
#include "TMRpcm.h"
#include "SPI.h"

int trigger_pin = 3;
int echo_pin = 4;


bool startPlaying = false;
bool isPlaying = false;


TMRpcm tmrpcm;

void setup()
{
pinMode (trigger_pin, OUTPUT);
pinMode (echo_pin, INPUT);

tmrpcm.speakerPin=9;

Serial.begin(9600);

if(!SD.begin(SD_ChipSelectPin))
{
  
  Serial.println("SD fail");
  return;
}

Serial.println("File Playing");

}

void loop() {
  
Serial.println("\n");

int duration;
int distance;

    digitalWrite (trigger_pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger_pin, LOW);
    duration = pulseIn (echo_pin, HIGH);
    distance = abs(duration/2)/29.1;  

    Serial.print("1st Sensor: ");
    Serial.print(distance); 
    Serial.print("cm  ");


  if (distance <= 10){
        if (!isPlaying){
          startPlaying = true;
          }
  }
  else if(distance >= 10){
        if(isPlaying){
          tmrpcm.stopPlayback();
          isPlaying = false;
        }
  } 

  if (startPlaying && !isPlaying){
    tmrpcm.play("1.wav");
    startPlaying = false;
    isPlaying = true;

    delay(1000);
  }
  
}
