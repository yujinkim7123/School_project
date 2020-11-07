const int pinLM35 = 0;
int pinLED[3] = {7,6,5};
float val = 0;

void setup() { 
  Serial.begin(9600); 
  pinMode(pinLED[0],OUTPUT);
  pinMode(pinLED[1],OUTPUT);
  pinMode(pinLED[2],OUTPUT);
  
  }
void loop() {
  
val = analogRead(pinLM35);

 Serial.println(val * 5 * 100 / 1024.0);
 
 if((val * 5 * 100 / 1024.0)>30)
   { digitalWrite(pinLED[0],HIGH);
     digitalWrite(pinLED[2],LOW);}

     
  else{
    digitalWrite(pinLED[2],HIGH);
     digitalWrite(pinLED[0],LOW);
  }


}
