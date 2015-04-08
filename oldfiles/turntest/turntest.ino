#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin
#define wheelLeftPos 7
#define wheelRightPos 5
#define wheelLeftNeg 8
#define wheelRightNeg 11
#define LEDPin 13 // Onboard LED

#define FWRange 20
#define BWRange 19
#define StopRange 5
#define Turn 12

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
   
   
       digitalWrite(wheelLeftNeg, HIGH);
       digitalWrite(wheelLeftPos, LOW); 
       digitalWrite(wheelRightPos, LOW);
       digitalWrite(wheelRightNeg, LOW);
       
}
     
