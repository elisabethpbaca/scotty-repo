#define echo 2 
#define trig 3 
#define wL+ 7 //wheels on the left forward
#define wR+ 5 //whells on the right forward
#define wL- 8
#define wR- 10
#define LEDPin 13 //onboard

int maxRange = 50;
int minRange = 10;
long duration, distance; // what does this do again?

void setup() (
  Serial.begin (9600); // computer to scotty chat speed yeah?
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(LEDpin, OUTPUT);
  pinMode(wL+, OUTPUT);
  pinMode(wR+, OUTPUT);
  pinMode(wL-, OUTPUT);
  pinMode(wR-, OUTPUT);
  )
  
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
 
 if (distance >= maxRange)(
     Serial.println(distance);
     digitalWrite(LEDPin, HIGH);
     digitalWrite(wR+, HIGH);
     digitalWrite(wL+, HIGH);
     digitalWrite(wR-, LOW);
     digitalWrite(wL-, LOW);
     )
     
 else if (distance<=minRange) {
     digitalWrite(wL-, HIGH); 
     digitalWrite(wR-, HIGH);
     digitalWrite(wL+, LOW );
     digitalWrite(wR+, LOW );  
     delay(1000);
 }    
 
 
   delay(5);
 )
