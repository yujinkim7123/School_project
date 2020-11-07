unsigned long interval = 40;
unsigned long l1, l2;
int faed = 0;
int fDir = 0;
int counter = 0;
int x = 11;


void setup() {
l1 = 0;
}

void loop() {
l2 = millis();
if(l2 - l1 >= interval){
  l1 = l2;
  if(!fDir){
    faed += 5;
    if(faed >= 255){
      faed = 255; fDir = 1;
    }
  }
  else{
    faed -= 5;
    if(faed <= 0){
      faed = 0; fDir = 0;
      analogWrite(x,faed);
       if(x==11){
        counter = 0;
      }
      else if(x==9){
        counter = 1;
      }
      if(counter == 0) {
        x--;
      }
      else
        x++; 
    }
  }
  analogWrite(x,faed);
} 
}
