#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin
#define wheelLeftPos 7
#define wheelRightPos 5
#define wheelLeftNeg 8
#define wheelRightNeg 11
#define LEDPin 13 // Onboard LED

#define FWRange 12
#define BWRange 9
#define StopRange 4
long duration, distance; // Duration used to calculate distance\

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 pinMode(wheelLeftPos, OUTPUT);
 pinMode(wheelRightPos, OUTPUT);
 pinMode(wheelLeftNeg, OUTPUT);
 pinMode(wheelRightNeg, OUTPUT);
}

void loop() {
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); 
  
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10); 
   
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   Serial.println(distance);
   //Calculate the distance (in cm) based on the speed of sound.
   distance = duration/58.2;
   
   if (distance<=StopRange) {
     still();
   }
   else if (distance<BWRange) {
      backwards();
   } 
   else if (distance>BWRange && distance<FWRange)  {
     still();
   }
   else if (distance>FWRange) {
      forward(); 
   }
   else {
    still();
   }
}

void forward() {
   digitalWrite(wheelLeftNeg, LOW);
   digitalWrite(wheelLeftPos, HIGH); 
   digitalWrite(wheelRightPos, HIGH);
   digitalWrite(wheelRightNeg, LOW);
}

void backwards() {
   digitalWrite(wheelLeftNeg, HIGH);
   digitalWrite(wheelLeftPos, LOW); 
   digitalWrite(wheelRightPos, LOW);
   digitalWrite(wheelRightNeg, HIGH);
}

void still(){
   digitalWrite(wheelLeftNeg, LOW);
   digitalWrite(wheelLeftPos, LOW); 
   digitalWrite(wheelRightPos, LOW);
   digitalWrite(wheelRightNeg, LOW);
}
