const int pinVibM = 3; 
const int pinLEDR = 9; 
const int pinLEDG = 10; 
const int pinLEDB = 11;
byte count = 0;

void setup() { 
  pinMode(pinVibM, INPUT); 
  Serial.begin(9600); 
    pinMode(pinLEDR, OUTPUT);
    pinMode(pinLEDG, OUTPUT);
     pinMode(pinLEDB, OUTPUT);
  attachInterrupt(1, countVib, FALLING); 
  }
void loop() { 
  if (count != 0) { 
    count = 0; 
     digitalWrite(pinLEDR, HIGH); 
     digitalWrite(pinLEDG, HIGH); 
     digitalWrite(pinLEDB, HIGH);
     delay(100);
  }
    else { 
   digitalWrite(pinLEDR, LOW); 
   digitalWrite(pinLEDG, LOW); 
   digitalWrite(pinLEDB, LOW); 
    }
    }
void countVib() {
  count++; 
}
