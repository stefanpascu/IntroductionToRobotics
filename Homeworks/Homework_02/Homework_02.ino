const int buttonPin = 2;
const int buzzer = 3;

const int ledPinGreenPed = 11;
const int ledPinRedPed = 10;
const int ledPinGreenCar = 5;
const int ledPinYellowCar = 6;
const int ledPinRedCar = 7;

bool buzzerOnOff = LOW;
bool ledStateGreenPed = LOW;
bool ledStateRedPed = HIGH;
bool ledStateGreenCar = HIGH;
bool ledStateYellowCar = LOW;
bool ledStateRedCar = LOW;

bool contLedState = LOW;
bool reading = HIGH;
bool previousReading = HIGH;

const int oneSec = 1000;
const int numberOfSecondsGreen = 10;
const int numberOfSecondsBlinkingGreen = 5;
const int numberOfSecondsYellow = 3;
const int numberOfSecondsRed = 10;
const int buzzerTone = 100;
const int greenLightBuzzerDelay = 500;
const int blinkingGreenLightBuzzerDelay = 250;

double currentMillis; 
double timerBuzzerStartMillis;
double timerBuzzerCurrentMillis;
double timerLedGreenCurrentMillis;
double timerLedGreenStartMillis;
double timerStartMillis;
bool lastDebounceTime = HIGH;
int debounceDelay = 50;
bool buttonState = LOW;

void setup() {
  // put your setup code here, to run once: 
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPinGreenCar, OUTPUT);
  pinMode(ledPinYellowCar, OUTPUT);
  pinMode(ledPinRedCar, OUTPUT);
  pinMode(ledPinGreenPed, OUTPUT);
  pinMode(ledPinRedPed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
//   put your main code here, to run repeatedly:
  digitalWrite(ledPinRedPed, ledStateRedPed); 
  digitalWrite(ledPinGreenPed, ledStateGreenPed);
  digitalWrite(ledPinGreenCar, ledStateGreenCar);
  digitalWrite(ledPinYellowCar, ledStateYellowCar);
  digitalWrite(ledPinRedCar, ledStateRedCar);

  reading = digitalRead(buttonPin);
  if (reading != previousReading) {
    lastDebounceTime = millis();
  }
  
  currentMillis = millis();
  if (currentMillis - lastDebounceTime > debounceDelay) {
    if (previousReading != reading) {
      buttonState = reading;
      if (buttonState == LOW) {
        digitalWrite(ledPinRedPed, ledStateRedPed); 
        digitalWrite(ledPinGreenPed, ledStateGreenPed);
        currentMillis = millis();
        timerStartMillis = currentMillis / oneSec + numberOfSecondsGreen;
        while (true) {
          currentMillis = millis();
          if(currentMillis >= timerStartMillis * oneSec) {
            break;
          }
        }
        
        ledStateGreenCar = !ledStateGreenCar;
        ledStateYellowCar = !ledStateYellowCar;
        digitalWrite(ledPinGreenCar, ledStateGreenCar);
        digitalWrite(ledPinYellowCar, ledStateYellowCar);
        timerStartMillis = millis() / oneSec + numberOfSecondsYellow;
        while (true) {
          if(millis() >= timerStartMillis * oneSec) {
            break;
          }
        }
        
        ledStateYellowCar = !ledStateYellowCar;
        ledStateRedCar = !ledStateRedCar;
        ledStateRedPed = !ledStateRedPed;
        ledStateGreenPed = !ledStateGreenPed;
        digitalWrite(ledPinRedPed, ledStateRedPed); 
        digitalWrite(ledPinGreenPed, ledStateGreenPed);
        digitalWrite(ledPinYellowCar, ledStateYellowCar);
        digitalWrite(ledPinRedCar, ledStateRedCar);
        timerStartMillis = millis() / oneSec + numberOfSecondsRed;
        timerBuzzerStartMillis = millis();
        
        while (true) {
          timerBuzzerCurrentMillis = millis();
          if (timerBuzzerCurrentMillis - timerBuzzerStartMillis >= greenLightBuzzerDelay && buzzerOnOff == LOW) {
            tone(buzzer, buzzerTone);
            timerBuzzerStartMillis = timerBuzzerCurrentMillis;
            buzzerOnOff = !buzzerOnOff;
          }else if(timerBuzzerCurrentMillis - timerBuzzerStartMillis >= blinkingGreenLightBuzzerDelay && buzzerOnOff == HIGH) {
            noTone(buzzer);
            timerBuzzerStartMillis = timerBuzzerCurrentMillis;
            buzzerOnOff = !buzzerOnOff;
          }
          
          if(millis() >= timerStartMillis * oneSec) {
            break;
          }
        }
        
        noTone(buzzer);
        timerStartMillis = millis() / oneSec + numberOfSecondsBlinkingGreen;
        timerLedGreenStartMillis = millis();
        
        while (true) {
          timerLedGreenCurrentMillis = millis();
          if (timerLedGreenCurrentMillis - timerLedGreenStartMillis >= blinkingGreenLightBuzzerDelay) {
            if (buzzerOnOff == LOW) {
              tone(buzzer, buzzerTone);
              buzzerOnOff = !buzzerOnOff;
            } else {
              noTone(buzzer);
              buzzerOnOff = !buzzerOnOff;
            }
            
            ledStateGreenPed = !ledStateGreenPed;
            timerLedGreenStartMillis = timerLedGreenCurrentMillis;
          }
          
          digitalWrite(ledPinGreenPed, ledStateGreenPed);
          if(millis() >= timerStartMillis * oneSec) {
            break;
          }
        }
        
        noTone(buzzer);
        ledStateGreenPed = !ledStateGreenPed;
        ledStateRedPed = !ledStateRedPed;
        ledStateGreenCar = !ledStateGreenCar;
        ledStateRedCar = !ledStateRedCar;
      } 
    }
  }
  
  previousReading = reading;
}
