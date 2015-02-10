#include <common.h>

void setup() {
 Serial.begin (9600);
 pinMode(trigPinP, OUTPUT);
 pinMode(echoPinP, INPUT);
 pinMode(trigPinG, OUTPUT);
 pinMode(echoPinG,INPUT);
 pinMode(trigPinB, OUTPUT);
 pinMode(echoPinB, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 pinMode(wheelLeftPos, OUTPUT);
 pinMode(wheelRightPos, OUTPUT);
 pinMode(wheelLeftNeg, OUTPUT);
 pinMode(wheelRightNeg, OUTPUT);
}
