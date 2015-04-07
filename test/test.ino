#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin
#define wheelLeftPos 7
#define wheelRightPos 5
#define wheelLeftNeg 8
#define wheelRightNeg 11
#define LEDPin 13 // Onboard LED


int maximumRange = 50; // Maximum range needed
int minimumRange = 10; // Minimum range needed
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
 if (distance<=10) {
   digitalWrite(wheelLeftPos, LOW); 
   digitalWrite(wheelRightPos, LOW);
   digitalWrite(wheelLeftNeg, LOW );
   digitalWrite(wheelRightNeg, LOW );
 } 
 else{
   digitalWrite(wheelLeftNeg, HIGH);
   digitalWrite(wheelLeftPos, LOW); 
   digitalWrite(wheelRightPos, LOW);
   digitalWrite(wheelRightNeg, HIGH);
 } 
}
