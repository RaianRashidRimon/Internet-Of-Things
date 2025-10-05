const int analogInPin = A0; // Analog input pin that the LDR is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to
int sensorValue = 0; // value read from the pot
int outputValue = 0; // value output to the PWM (analog out)
void setup() 
{
    Serial.begin(9600); // initialize serial communications at 9600 bps:
}
void loop() 
{
    sensorValue = analogRead(analogInPin); // read the analog in value:
    outputValue = map(sensorValue, 0, 1023, 0, 255); // map it to the range of the analog out:
    analogWrite(analogOutPin, outputValue); // change the analog out value:
    Serial.print("sensor = " ); // print the results to the serial monitor:
    Serial.print(sensorValue);
    Serial.print("\t output = ");
    Serial.println(outputValue);
    delay(1000);
}
