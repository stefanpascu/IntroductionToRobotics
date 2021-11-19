#include <EEPROM.h>

const int dataPin = 12;
const int latchPin = 11;
const int clockPin = 10;

const int pinX = A0;
const int pinY = A1;
const int pinSW = 3;

const int segD1 = 7;
const int segD3 = 6;
const int segD2 = 5;
const int segD4 = 4;

volatile bool flagButton = LOW;

const int segmentDigits[] = {
  segD1, segD2, segD3, segD4
};

const int digitArrayLength = 17;
const int noOFDigits = 10;
const int segmentsCount = 4;
const int debounceDelay = 50;
const int pointSwStateDelay = 20;
const int generalDelayValue = 4;

int numbersDigitsArray[] = {
  0, 0, 0, 0
};

//int noOfZeros;
int numbersDigitMultiplyingFactor;
int currentDigitIndex = 0;
bool pointState = LOW;
int pointSwStateCounter = 0;
int number = 0; 
bool dpState = LOW;
bool state = HIGH;
int xValue = 0;
int yValue = 0;
int swState = HIGH;
int previousSwState = HIGH;
const int minTreshold = 300;
const int maxTreshold = 750;
bool joyMoved = false;
bool lastDebounceTime = HIGH;
bool readFromEeprom = HIGH;

int digitArray[digitArrayLength] = {
//A B C D E F G DP 
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
  B11101110, // A
  B00111110, // b
  B10011100, // C
  B01111010, // d
  B10011110, // E
  B10001110, // F
  B00000001  // .
};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(pinSW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinSW), isrFunction, CHANGE);
  for( int i = 0; i < segmentsCount; i++) {
    pinMode(segmentDigits[i], OUTPUT);
    digitalWrite(segmentDigits[i], LOW);
  }
  Serial.begin(9600);
}


void loop() {
  
  if (readFromEeprom) {                                                                               // the first time the code is ran, the display will show
    for ( int eepromReadAddress = 0; eepromReadAddress < segmentsCount; eepromReadAddress++) {               // the variables stored in eeprom
      numbersDigitsArray[eepromReadAddress] = EEPROM.read(eepromReadAddress);
    } 
    readFromEeprom = LOW;
  }
  
  
  swState = digitalRead(pinSW);  
  
  if (swState != previousSwState) {
    lastDebounceTime = millis();
  }
  
  if (millis() - lastDebounceTime > debounceDelay && previousSwState != swState && flagButton) {
    if (swState == LOW){
      dpState = !dpState;
      pointState = HIGH;
    } 
  }

  previousSwState = swState;

  if (pointState == HIGH) {
    writePoint(currentDigitIndex);
  }
  
  if (dpState == LOW) {
    flagButton = LOW;
    pointSwStateCounter++;
    if (pointSwStateCounter >= pointSwStateDelay) {
      pointSwStateCounter = 0;
      
      pointState = !pointState;
    }
    
    numbersDigitMultiplyingFactor = 1000;                          // corresponds to the thousands unit in the beginning and decreases for each unit
    number = 0;
    for ( int i = segmentsCount - 1; i >= 0; i--) {
      number += (numbersDigitsArray[i] * numbersDigitMultiplyingFactor);
      numbersDigitMultiplyingFactor /= 10;
    }

    writeNumberWithZeros(number);
    
    yValue = analogRead(pinY);
    if (yValue > maxTreshold && joyMoved == false) {
      currentDigitIndex++;
      joyMoved = true;
    }
    if (yValue < minTreshold && joyMoved == false) {
      currentDigitIndex--;
      joyMoved = true;
    }
    if (yValue < maxTreshold && yValue > minTreshold) {
      joyMoved = false;  
    }
    if (currentDigitIndex >= segmentsCount) {
      currentDigitIndex = 0;
    }
    if (currentDigitIndex < 0) {
      currentDigitIndex = segmentsCount - 1;
    }
    
  } else {
    xValue = analogRead(pinX);
  
    if (xValue > maxTreshold && joyMoved == false) {
      numbersDigitsArray[currentDigitIndex]--;
      joyMoved = true;
    }
    if (xValue < minTreshold && joyMoved == false) {
      numbersDigitsArray[currentDigitIndex]++;
      joyMoved = true;
    }
    if (xValue < maxTreshold && xValue > minTreshold) {
      joyMoved = false;  
    }
    if (numbersDigitsArray[currentDigitIndex] >= noOFDigits) {
      numbersDigitsArray[currentDigitIndex] = 0;
    }
    if (numbersDigitsArray[currentDigitIndex] < 0) {
      numbersDigitsArray[currentDigitIndex] = noOFDigits - 1;
    }

    numbersDigitMultiplyingFactor = 1000;                          // corresponds to the thousands unit in the beginning and decreases for each unit
    number = 0;
    for ( int i = segmentsCount - 1; i >= 0; i--) {
      number += (numbersDigitsArray[i] * numbersDigitMultiplyingFactor);
      numbersDigitMultiplyingFactor /= 10;
    }
    
    for( int eepromUpdateAddress = 0; eepromUpdateAddress < segmentsCount; eepromUpdateAddress++) {
      EEPROM.update(eepromUpdateAddress, numbersDigitsArray[eepromUpdateAddress]);
      Serial.println(numbersDigitsArray[eepromUpdateAddress]);
      Serial.print(" ");
      Serial.print(eepromUpdateAddress);
    }

    writeNumberWithZeros(number);
    
  }
  
}

void isrFunction() {
  flagButton = HIGH;
}

void writeNumberWithZeros(int number) {
  int noOfZeros;
  if (number == 0) {
    noOfZeros = 4;
  } else if (number / 10 == 0) {
    noOfZeros = 3;
  } else if (number / 100 == 0) {
    noOfZeros = 2;
  } else if (number / 1000 == 0) {
    noOfZeros = 1;
  } else {
    noOfZeros = 0;
  }
  writeNumber(noOfZeros, number);
}

void writeNumber(int zeros, int number) {
  int currentNumber = number;
  int lastDigit;
  int displayDigit = 0;
  if (zeros == 0) {
    while (currentNumber > 0) {
      lastDigit = currentNumber % 10;
      
      writeReg(digitArray[lastDigit]);
      showDigit(displayDigit);
      displayDigit++;
      currentNumber /= 10;
      delay(generalDelayValue);
    } 
  } else if (zeros > 0 && zeros <= segmentsCount) {
      while (currentNumber > 0) {
        lastDigit = currentNumber % 10;
        
        writeReg(digitArray[lastDigit]);
        showDigit(displayDigit);
        displayDigit++;
        currentNumber /= 10;
        delay(generalDelayValue);
      } 
      
      for ( int i = 0; i < zeros; i++) {
        lastDigit = 0;
        showDigit(displayDigit);
        writeReg(digitArray[lastDigit]);
        displayDigit++;
        delay(generalDelayValue);
      }
  }
}

void writePoint(int col) {
  showDigit(col);
  writeReg(digitArray[digitArrayLength - 1]);
  delay(generalDelayValue);  
}

void showDigit(int digitNumber) {
  for( int i = 0; i < segmentsCount; i++) {
    digitalWrite(segmentDigits[i], HIGH);
  }
  digitalWrite(segmentDigits[digitNumber], LOW);
}

void writeReg(int digit) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  digitalWrite(latchPin, HIGH);
}
