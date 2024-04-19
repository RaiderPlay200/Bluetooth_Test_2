#include <SoftwareSerial.h>

const byte rxPin = 0;
const byte txPin = 1;
SoftwareSerial BTSerial(rxPin, txPin); // RX TX

String messageBuffer = "";
String message = "";

void setup() {
// define pin modes for tx, rx:
pinMode(rxPin, INPUT);
pinMode(txPin, OUTPUT);
BTSerial.begin(9600);
Serial.begin(9600);
}



void loop() {

while (BTSerial.available() > 0) {
char data = (char) BTSerial.read();
messageBuffer += data;
Serial.print(messageBuffer);
if (data == ' '){
message = messageBuffer;
messageBuffer = "";
Serial.print(message); // send to serial monitor
message = "You sent " + message;
BTSerial.print(message); // send back to bluetooth terminal
}
}

}