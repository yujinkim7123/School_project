const int pinBuzzer = 9; 
const int push1 = 13;
const int push2 = 12;
const int push3 = 11;
const int push4 = 10;
const int push5 = 8;
const int push6 = A5;
const int push7 = A4;
const int push8 = A3;

void setup()
{ 
  pinMode(pinBuzzer, OUTPUT); 
  pinMode(push1, INPUT); 
  pinMode(push2, INPUT); 
  pinMode(push3, INPUT); 
  pinMode(push4, INPUT); 
  pinMode(push5, INPUT); 
  pinMode(push6, INPUT); 
  pinMode(push7, INPUT); 
  pinMode(push8, INPUT); 
  }
void loop() { 
 
 if (digitalRead(push1) == HIGH) { tone(pinBuzzer, 261);  } 
else if (digitalRead(push2) == HIGH) { tone(pinBuzzer, 294);  }
else if (digitalRead(push3) == HIGH) { tone(pinBuzzer, 330); } 
else if (digitalRead(push4) == HIGH) { tone(pinBuzzer, 349); } 
else if (digitalRead(push5) == HIGH) { tone(pinBuzzer, 392); } 
else if (digitalRead(push6) == HIGH) { tone(pinBuzzer, 440); } 
else if (digitalRead(push7) == HIGH) { tone(pinBuzzer, 494); }
else if (digitalRead(push8) == HIGH) { tone(pinBuzzer, 523); }
else if (digitalRead(push1) == HIGH) { tone(pinBuzzer, 261); }
else {noTone(pinBuzzer);  } 



}
