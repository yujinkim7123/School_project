const int pinTilt = 2;
int pinLED[3] = {7,6,5};
int val = 0;
int val2 = 0;
void setup() { 
  pinMode(pinTilt, INPUT); 
  pinMode(pinLED[0],OUTPUT);
  pinMode(pinLED[1],OUTPUT);
  pinMode(pinLED[2],OUTPUT);
  Serial.begin(9600); 
 

  }
void loop() {
val = digitalRead(pinTilt);
if(val  == 0)
   {
    digitalWrite(pinLED[0],HIGH);
    digitalWrite(pinLED[1],HIGH);
    digitalWrite(pinLED[2],HIGH);
    delay(100);
   }
else{
  digitalWrite(pinLED[0],LOW);
  digitalWrite(pinLED[1],LOW);
  digitalWrite(pinLED[2],LOW);
}
 
Serial.println(val);

delay(100);

}
