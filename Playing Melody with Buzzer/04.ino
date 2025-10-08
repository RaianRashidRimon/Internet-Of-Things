// Pin where the buzzer is connected
const int buzzerPin = 9;

// Number of notes in the melody
const int length = 15;

// Melody: "ccggaagffeeddc " (Twinkle, Twinkle, Little Star), space is a rest
char notes[] = "ccggaagffeeddc ";

// Beats for each note (1 = quarter note, 2 = half note, 4 = whole note)
int beats[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4};

// Tempo in milliseconds (controls speed of the melody)
int tempo = 300;

// Function to play a tone at a specific frequency for a duration
void playTone(int period, int duration) {
  // period is in microseconds (us), duration is in milliseconds (ms)
  long cycles = (duration * 1000L) / (period * 2); // Number of full cycles
  for (long i = 0; i < cycles; i++) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(period); // Half period high
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(period); // Half period low
  }
}

// Function to play a musical note
void playNote(char note, int duration) {
  // Note names and their corresponding periods in microseconds
  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'}; // 'C' is higher octave
  int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956}; // Periods (us)

  // Find and play the matching tone
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
}

void loop() {
  // Play the melody
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // Rest, no sound
    } else {
      playNote(notes[i], beats[i] * tempo); // Play the note
    }
    delay(tempo / 2); // Pause between notes for clarity
  }
  delay(2000); // Pause before repeating the melody
}