// Aaron ALAI EMF Detector May 28th 2009 VERSION 1.1 (modified to use a seven-segment display and a buzzer)
// aaronalai1@gmail.com
// contains code for readingsSum sensor data

const int sample = 30;                                       //this is how many samples the device takes per reading
                                                          //more information for #define http://arduino.cc/en/Reference/Define
const int segSize = 8;
const int noOFDigits = 10;
const int minAverageValue = 0;
const int maxAverageValue = 100;
const int minDigitValue = 0;
const int maxDigitValue = 9;
const int minBuzzerTone = 0;
const int maxBuzzerTone = 300;
const int maxNoToneDigitValue = 1;
const int sevenDigitDisplayDelay = 70;
const int buzzer = 10;

int anthenaPin = 5;                                          //analog 5
const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;
const int pinDP = 9;

int buzzerTone;                                         //busserTone will change pitch resulting in higher sound is a magnetic field is closer
unsigned long readingsSum;                              //the program uses this variable to store the sum of each array it makes
float average;                                          //where to store info from analog 5
int digit = 0;
int index = 0;
long maxDigit = 0;                                      // maxDigit will be used for a more acurate seven-segment display
bool dpState = LOW;

int readings[sample];                                   //creates an array with number of elements equal to "sample"
                                                          //more information about arrays http://arduino.cc/en/Reference/Array

int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

bool digitMatrix[noOFDigits][segSize - 1] = {
// a, b, c, d, e, f, g  
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void displayNumber(byte digit, bool decimalPoint) {
  for(int i = 0; i < segSize - 1; i++) {
    digitalWrite(segments[i], digitMatrix[digit][i]);
  }
  digitalWrite(pinDP, decimalPoint);
}

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < segSize; i++) {
    pinMode(segments[i], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);
  pinMode(anthenaPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {  
  for(int i = 0; i < sample; i++){                    //this code tells the program to fill each element in the array we made with
     readings[i] = analogRead(anthenaPin);              //information from the anthena wire coming out of the Arduino
     readingsSum += readings[i];                      
  }                                                               
   
  average = readingsSum / sample;                     //here the program takes the sum of all numbers in readings, and divides by the number of elements "sample"
  
  average = constrain(average, minAverageValue, maxAverageValue);                                               
  digit = map(average, minAverageValue, maxAverageValue, minDigitValue, maxDigitValue);

  buzzerTone = map (average, minAverageValue, maxAverageValue, minBuzzerTone, maxBuzzerTone);
  
  if (digit <= maxNoToneDigitValue) {
    noTone(buzzer);
  } else {
    tone(buzzer, buzzerTone);
  }
  
  index++;
  
  if (digit > maxDigit) {
    maxDigit = digit;
  }
  
  if (index >= sevenDigitDisplayDelay) {
//    Serial.println(maxDigit);
    displayNumber(maxDigit, dpState);
    index = 0;
    maxDigit = 0;
  }
  
  readingsSum = 0;                                 //this line of code sets readingsSum back to zero so it can be used again
}
