#include <LiquidCrystal.h>
#include <Time.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 // 핀 설정 -> 적외선 리모컨 버튼 설정
const int buzzerPin = 10;
const int resetButtonPin = 6;
const int startStopButtonPin = 7;
const int downButtonPin = 8;
const int upButtonPin = 9;
const int setupButtonPin = 5;
 // 시간 관련 변수
int setupHours = 0;     // How many hours will count down when started
int setupMinutes = 0;   // How many minutes will count down when started
int setupSeconds = 0;   // How many seconds will count down when started
time_t setupTime = 0;
 
int currentHours = 0;
int currentMinutes = 0;
int currentSeconds = 0;
time_t currentTime = 0;
 
time_t startTime = 0;
time_t elapsedTime = 0;

 // 푸시버튼을 위한 상태 저장 알리려는 변수 -> 적외선 리모컨으로 조작해서 하도록 변수 전환
int resetButtonState = LOW;
long resetButtonLongPressCounter = 0;
int startStopButtonState = LOW;
int upButtonState = LOW;
int downButtonState = LOW;
int setupState = LOW;
int resetButtonPrevState = LOW;
int startStopButtonPrevState = LOW;
int setupPrevState = LOW;
int upButtonPrevState = LOW;
int downButtonPrevState = LOW;
bool setupButtonPressed = false;
bool resetButtonPressed = false;
bool startStopButtonPressed = false;
bool upButtonPressed = false;
bool downButtonPressed = false;
 // 대기 , 설정, 동작, 알람모드 종류
const int MODE_IDLE = 0;
const int MODE_SETUP = 1;
const int MODE_RUNNING = 2;
const int MODE_RINGING = 3;
 
int currentMode = MODE_IDLE; 
int dataSelection = 0;

void setup() {
  lcd.begin(16, 2);
  // 적외선으로 송수신 부분 설정
  pinMode(resetButtonPin, INPUT);
  pinMode(startStopButtonPin, INPUT);
  pinMode(upButtonPin, INPUT);
  pinMode(downButtonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(setupButtonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
// 초기화 모드 확인 -> 적외선 리모컨 입력시 확인해서 모드 확인
 resetButtonPressed = false;
 resetButtonState = digitalRead(resetButtonPin);
  if(resetButtonState != resetButtonPrevState) 
  {
    resetButtonPressed = resetButtonState == HIGH; 
    resetButtonPrevState = resetButtonState;
  }
// 설정모드 확인-> 적외선 리모컨 입력시 확인해서 모드 확인
    setupButtonPressed = false;
    setupState= digitalRead(setupButtonPin);
    if(setupState != setupPrevState)
  {
    
    setupPressed = setupState == HIGH;
    setupPrevState = setupState;
  }
    
 // 시작 확인 -> 적외선 리모컨 입력시 확인해서 모드 확인
  startStopButtonPressed = false;
  startStopButtonState = digitalRead(startStopButtonPin);
  if(startStopButtonState != startStopButtonPrevState)
  {
    startStopButtonPressed = startStopButtonState == HIGH;
    startStopButtonPrevState = startStopButtonState;
  }
// up 확인 -> 적외선 리모컨 입력시 확인해서 모드 확인
  upButtonPressed = false;
  upButtonState = digitalRead(upButtonPin);
  if(upButtonState != upButtonPrevState)
  {
    upButtonPressed = upButtonState == HIGH;
    upButtonPrevState = upButtonState;
  }
  //  down 확인 -> 적외선 리모컨 입력시 확인해서 모드 확인
   downButtonPressed = false;
  downButtonState = digitalRead(downButtonPin);
  if(downButtonState != downButtonPrevState)
  {
    downButtonPressed = downButtonState == HIGH;
    downButtonPrevState = downButtonState;
  }

switch(currentMode)
  {
    case MODE_IDLE:
      if(resetButtonPressed)
      {
        Reset();
      }
      if(setupButtonPressed)
      {
        currentMode = MODE_SETUP;
      }
      if(startStopButtonPressed)
      {
        currentMode = currentMode == MODE_IDLE ? MODE_RUNNING : MODE_IDLE;
        if(currentMode == MODE_RUNNING)
        {
          // STARTING TIMER!
          startTime = now(); 
        }
      }
      break;
    case:
   if(resetButtonLongPressed)
      {
        currentMode = MODE_SETUP;
      }
    case MODE_SETUP:
      if(resetButtonPressed)
      {
        // Exit setup mode
        setupTime = setupSeconds + (60 * setupMinutes) + (3600 * setupHours);
        currentHours = setupHours;
        currentMinutes = setupMinutes;
        currentSeconds = setupSeconds;
        dataSelection = 0;
        currentMode = MODE_IDLE;
      }
      if(startStopButtonPressed)
      {
        // Select next data to adjust
        dataSelection++;
        if(dataSelection == 3)
        {
          dataSelection = 0;
        }
      }
      if(downButtonPressed)
      {
        switch(dataSelection)
        {
          case 0: // hours
            setupHours--;
            if(setupHours == -1)
            {
              setupHours = 99;
            }
            break;
          case 1: // minutes
            setupMinutes--;
            if(setupMinutes == -1)
            {
              setupMinutes = 59;
            }
            break;
          case 2: // seconds
            setupSeconds--;
            if(setupSeconds == -1)
            {
              setupSeconds = 59;
            }
            break;
        }
      }
      if(upButtonPressed)
      {
        switch(dataSelection)
        {
          case 0: // hours
            setupHours++;
            if(setupHours == 100)
            {
              setupHours = 0;
            }
            break;
          case 1: // minutes
            setupMinutes++;
            if(setupMinutes == 60)
            {
              setupMinutes = 0;
            }
            break;
          case 2: // seconds
            setupSeconds++;
            if(setupSeconds == 60)
            {
              setupSeconds = 0;
            }
            break;
        }
      }
      break;
    
    case MODE_RUNNING:
      if(startStopButtonPressed)
      {
        currentMode = MODE_IDLE;
      }
      if(resetButtonPressed)
      {
        Reset();
        currentMode = MODE_IDLE;
      }
      break;
 
    case MODE_RINGING:
      if(resetButtonPressed || startStopButtonPressed || downButtonPressed || upButtonPressed)
      {
        currentMode = MODE_IDLE;
      }
      break;
  }
 



}
