#include <IRrecv.h>

// Define the IR receiver pin
const int irReceiverPin = 35;

// Create an IR receiver object using the defined pin
IRrecv irrecv(irReceiverPin);

// Variable to store decoded IR results
decode_results results;

void setup() {
  // Enable the IR receiver
  irrecv.enableIRIn();

  // Start serial communication for debugging
  Serial.begin(115200);
}

void loop() {
  // Check if there is a decoded IR signal
  if(irrecv.decode(&results)){
    // Print the hexadecimal value of the decoded IR signal
    Serial.println(results.value, HEX);

    // Pause for a short duration to avoid printing the same value repeatedly
    delay(1000);

    // Resume the IR receiver to listen for the next signal
    irrecv.resume();
  }
}
