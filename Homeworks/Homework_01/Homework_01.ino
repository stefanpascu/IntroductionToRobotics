const int ledPinRed = 9;
const int ledPinGreen = 10;
const int ledPinBlue = 11;

const int potPinRed = A0;
const int potPinGreen = A1;
const int potPinBlue = A2;

const int minVoltageValue = 0;
const double maxAnalogValue = 5.0;
const double maxVoltageValue = 1023.0;
const double maxLedVoltageValue = 255.0;
const double numarValori = 3.0;
int voltage = 0;

int brightnessRed = 0;
int brightnessGreen = 0;
int brightnessBlue = 0;

int potValueRed = 0;
int potValueGreen = 0;
int potValueBlue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  
  pinMode(potPinRed, INPUT);
  pinMode(potPinGreen, INPUT);
  pinMode(potPinBlue, INPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  potValueRed = analogRead(potPinRed);
  potValueGreen = analogRead(potPinGreen);
  potValueBlue = analogRead(potPinBlue);

  brightnessRed = map(potValueRed, minVoltageValue, maxVoltageValue, minVoltageValue, maxLedVoltageValue);
  brightnessGreen = map(potValueGreen, minVoltageValue, maxVoltageValue, minVoltageValue, maxLedVoltageValue);
  brightnessBlue = map(potValueBlue, minVoltageValue, maxVoltageValue, minVoltageValue, maxLedVoltageValue);
  
  analogWrite(ledPinRed, brightnessRed);
  analogWrite(ledPinGreen, brightnessGreen);
  analogWrite(ledPinBlue, brightnessBlue);

  // voltage helps testing if the potentiometers work
//  voltage = ((potValueRed + potValueGreen + potValueBlue) / numarValori) * maxAnalogValue / maxVoltageValue;
  Serial.println(potValueRed);

}
