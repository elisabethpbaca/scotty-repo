#include "common.h"

 void left() {
     Serial.println("left");
     digitalWrite(LEDPin, HIGH);
     digitalWrite(wheelLeftPos, LOW); 
     digitalWrite(wheelRightPos, HIGH);
     digitalWrite(wheelLeftNeg, HIGH );
     digitalWrite(wheelRightNeg, LOW ); 
 }
 
 void robotstop()  {
     Serial.println("stop");
     digitalWrite(LEDPin, HIGH);
     digitalWrite(wheelLeftPos, LOW); 
     digitalWrite(wheelRightPos, LOW);
     digitalWrite(wheelLeftNeg, LOW);
     digitalWrite(wheelRightNeg, LOW);
  }
  
  void forward()  {
     Serial.println("Forwards");
     digitalWrite(LEDPin, HIGH);
     digitalWrite(wheelLeftPos, HIGH); 
     digitalWrite(wheelRightPos, HIGH);
     digitalWrite(wheelLeftNeg, LOW );
     digitalWrite(wheelRightNeg, LOW );
  }
  
 void right()  {
     Serial.println("right");
     digitalWrite(LEDPin, HIGH);
     digitalWrite(wheelLeftPos,HIGH); 
     digitalWrite(wheelRightPos,LOW);
     digitalWrite(wheelLeftNeg,LOW);
     digitalWrite(wheelRightNeg,HIGH);
 }
 
 void backward() {
     Serial.println("backward");
     digitalWrite(LEDPin, HIGH);
     digitalWrite(wheelLeftPos, LOW); 
     digitalWrite(wheelRightPos, LOW);
     digitalWrite(wheelLeftNeg, HIGH );
     digitalWrite(wheelRightNeg, HIGH);
 }
