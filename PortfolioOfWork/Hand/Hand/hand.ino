int analogPin0 = A0; 
int analogPin1 = A1; 
int analogPin2 = A2; 
int analogPin3 = A3; 
int analogPin4 = A4; 

int speakerPin = 8;    
 
int fsrReading1;   
int fsrReading2;
int fsrReading3;   
int fsrReading4;
int fsrReading5;   


int speakerMap1;
int speakerMap2;
int speakerMap3;
int speakerMap4;



int soundSpeed;

int frequency;


void setup() {
  Serial.begin(9600);  
}
 
void loop() {
  fsrReading1 = analogRead(analogPin0);
  fsrReading2 = analogRead(analogPin1);
  fsrReading3 = analogRead(analogPin2);
  fsrReading4 = analogRead(analogPin3);
  fsrReading5 = analogRead(analogPin4); 

  

//  int num=fsrReading/5;
//  Serial.print("Analog reading = ");

  Serial.print(fsrReading1);
  Serial.print("  ");
  Serial.print(fsrReading2);  
  Serial.print("  ");
  Serial.print(fsrReading3);    
  Serial.print("  ");
  Serial.print(fsrReading4);  
  Serial.print("  ");
  Serial.print(fsrReading5);
  Serial.print("  ");


 
  speakerMap1 = map(fsrReading1, 0, 1000, 100, 400);
  soundSpeed = map(fsrReading2, 0, 1000, 25, 500);
  speakerMap2 = map(fsrReading3, 0, 1000, 400, 800);
  speakerMap3 = map(fsrReading4, 0, 1000, 0, 1000); 
 speakerMap4 = map(fsrReading5, 0, 1000, 0, 1000);

  if (speakerMap3 >= 500){

    frequency = speakerMap3;
  } else {
    frequency = speakerMap1;
  }
  tone(speakerPin, frequency, soundSpeed);

  delay(soundSpeed*2);
  noTone(speakerPin);
  }
