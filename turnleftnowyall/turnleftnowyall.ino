#define echoPin 2 
#define trigPin 3 
#define wLeftPos 7 //wheels on the left forward
#define wRightPos 5 //whells on the right forward
#define wLeftNeg 10
#define wRightNeg 8
#define LEDPin 13 //onboard


int maximumRange = 200; // Maximum range needed
int minimumRange = 50; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 pinMode(wLeftPos, OUTPUT);
 pinMode(wRightPos, OUTPUT);
 pinMode(wLeftNeg, OUTPUT);
 pinMode(wRightNeg, OUTPUT);
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
  Serial.println(distance);

   
    //forward();
   backwards();
 }
 
 void forward() {
     
   digitalWrite(LEDPin, HIGH);
   digitalWrite(wLeftPos, HIGH);
   digitalWrite(wRightPos, HIGH);
   digitalWrite(wLeftNeg, LOW);
   digitalWrite(wRightNeg, LOW);

 }
 
 void backwards() {
   digitalWrite(LEDPin, LOW);
   digitalWrite(wLeftPos, LOW);
   digitalWrite(wRightPos, LOW);
   digitalWrite(wLeftNeg, HIGH);
   digitalWrite(wRightNeg, LOW);

 }
