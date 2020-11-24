//Skuzzle Motorsport PWM temperature sensor - Nicholas Bailey - 24/11/2020
//Designed originally for the Miata Link ECU which uses a pwm inlet air temperature sensor which is no longer available.
//This code allows a generic thermistor style sensor to be used on a 5v line and outputs a conversion to PWM.
//Calibrate sensor by the thermistorDivision  //Calibrate expected PWM at ecu by pwmMultiply.

int pwmPin = 3; // the PWM pin
int thermistorPin = A2; // the thermistor input pin
int thermistorDivider = 10; //Divider
float pwmMultiply = 2.55; //Multiply

void setup()
{
  pinMode(pwmPin, OUTPUT); //Setup pins
  pinMode(thermistorPin, INPUT);
}

void loop()
{
  int pwmValue = analogRead(thermistorPin) / thermistorDivider; //Get snapshot value from thermistor pin
  if (pwmValue > 100) { pwmValue = 100; } //Sanity check max
  analogWrite(pwmPin, pwmValue * pwmMultiply); //Write PWM to the output pin
  delay(30);  //Dampens signal
}
