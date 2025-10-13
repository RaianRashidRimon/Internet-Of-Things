#define WAIT 5000  // Define wait time (not used in loop)

const int IN1 = 4;  // Motor driver IN1 pin
const int IN2 = 7;  // Motor driver IN2 pin
const int EN1 = 5;  // Motor driver Enable1 pin

/* Motor Driver Connection:
   - Connect Arduino's 5V to the 7806 voltage regulator input.
   - Regulator output (6V) connects to VS of the L293D motor driver.
   - VSS of the motor driver connects to Arduino's VCC (5V).
*/

void setup() {
    pinMode(IN1, OUTPUT);  // Set IN1 as output
    pinMode(IN2, OUTPUT);  // Set IN2 as output
    pinMode(EN1, OUTPUT);  // Set Enable1 as output
}

void loop() {
    // Move Forward
    digitalWrite(IN1, HIGH);  // IN1 HIGH
    digitalWrite(IN2, LOW);   // IN2 LOW
    digitalWrite(EN1, HIGH);  // Enable motor
    delay(10000);  // Wait for 10 seconds

    // Move Backward
    digitalWrite(IN1, LOW);   // IN1 LOW
    digitalWrite(IN2, HIGH);  // IN2 HIGH
    digitalWrite(EN1, HIGH);  // Enable motor
    delay(3000);  // Wait for 3 seconds
}
