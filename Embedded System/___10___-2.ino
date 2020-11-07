const int pinTrig = 2; 
const int pinEcho = 4; 
const int pinLEDR = 9; 
const int pinLEDG = 10; 
const int pinLEDB = 11; 
long T, L;

void setup() { 
  Serial.begin(9600); 
  pinMode(pinTrig, OUTPUT); 
  pinMode(pinEcho, INPUT); 
   pinMode(pinLEDR, OUTPUT);
    pinMode(pinLEDG, OUTPUT);
     pinMode(pinLEDB, OUTPUT);
  }
void loop() { 
  digitalWrite(pinTrig, LOW); 
  delayMicroseconds(2); 
  digitalWrite(pinTrig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(pinTrig, LOW);

T = pulseIn(pinEcho, HIGH);

L = T/58.82;

if (L > 0 && L < 10){
     digitalWrite(pinLEDR, HIGH); 
     digitalWrite(pinLEDG, LOW); 
     digitalWrite(pinLEDB, LOW);
     }
 else if (L >= 10 && L < 15) {
    digitalWrite(pinLEDR, LOW); 
    digitalWrite(pinLEDG, HIGH); 
    digitalWrite(pinLEDB, LOW);
   }
else if (L >= 15 && L < 30) {
     digitalWrite(pinLEDR, LOW); 
     digitalWrite(pinLEDG, LOW); 
     digitalWrite(pinLEDB, HIGH);
     }
else {
   digitalWrite(pinLEDR, LOW); 
   digitalWrite(pinLEDG, LOW); 
   digitalWrite(pinLEDB, LOW); 
   }

}
