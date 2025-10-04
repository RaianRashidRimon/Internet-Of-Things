const int buttonPin = 2; // the number of the pushbutton pin
const int ledPin = 12; // the number of the LED pin
int buttonState = 0; // variable for reading the pushbutton status
void setup() {
pinMode(ledPin, OUTPUT); // initialize the LED pin as an output:
pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input:
}
void loop(){
buttonState = digitalRead(buttonPin);// read the state of the pushbutton
// check if the pushbutton is pressed. if it is, the buttonState is HIGH:
if (buttonState == HIGH) {
// turn LED on:
digitalWrite(ledPin, HIGH);
}
else {
// turn LED off:
digitalWrite(ledPin, LOW);
}
}