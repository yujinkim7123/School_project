const int led_pwm = 11;
const int led1 = 13;
const int led2 = 12;
const int led3 = 8;
unsigned long l3, l4, l1, l2, l6, l5;
unsigned long interval2 = 2000;
unsigned long interval1 = 1000;
unsigned long interval3 = 3000;
int fON1 = 0;
int fON2 = 0;
int fON3 = 0;
void setup(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  l3 = 0;
}

void loop(){     
   l2 = millis();
   if(l2 - l1 >= interval1){
    l1 = l2;
    if(!fON1){
      fON1 = HIGH; 
    }
    else{
      fON1 = LOW;
    }
    digitalWrite(led1, fON1);
   }
   
   l4 = millis();
   if(l4 - l3 >= interval2){
    l3 = l4;
    if(!fON2){
      fON2 = HIGH; 
    }
    else{
      fON2 = LOW;
    }
    digitalWrite(led2, fON2);
   }
   
    l6 = millis();
   if(l6 - l5 >= interval3){
    l5 = l6;
    if(!fON3){
      fON3 = HIGH; 
    }
    else{
      fON3 = LOW;
    }
    digitalWrite(led3, fON3);
   }
}
