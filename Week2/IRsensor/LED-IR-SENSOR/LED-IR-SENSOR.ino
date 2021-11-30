
int analog;
const int ldrPin = A4;
const int ledPin = 13;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  analog = analogRead(ldrPin);
  Serial.println(analog);
  if ( analog > 0 )   digitalWrite(LED_BUILTIN, HIGH);
  else  digitalWrite(LED_BUILTIN, LOW);
  delay(100);

}
