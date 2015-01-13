/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8
 
 This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
 Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 And modified further by ScottC here: http://arduinobasics.blogspot.com.au/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 on 10 Nov 2012.
 */

# This is a change!!!

#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin
#define wheelLeftPos 7
#define wheelRightPos 5
#define wheelLeftNeg 8
#define wheelRightNeg 1
#define LEDPin 13 // Onboard LED


int maximumRange = 50; // Maximum range needed
int minimumRange = 10; // Minimum range needed
long duration, distance; // Duration used to calculate distance

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
 
 if (distance <= maximumRange && distance >= minimumRange){
   /* Send a negative number to computer and Turn LED ON 
   to indicate "in range" */
   
   Serial.println(distance);
   Serial.println("Forwards");
   digitalWrite(LEDPin, HIGH);
   digitalWrite(wheelLeftPos, HIGH); 
   digitalWrite(wheelRightPos, HIGH);
   digitalWrite(wheelLeftNeg, LOW );
   digitalWrite(wheelRightNeg, LOW );
 }
 else if (distance<=minimumRange) {
    Serial.println("backwards");
    digitalWrite(wheelLeftNeg, HIGH); 
    digitalWrite(wheelRightNeg, HIGH);
    digitalWrite(wheelLeftPos, LOW );
    digitalWrite(wheelRightPos, LOW );  
    delay(1000);
 }
 else {
    /* Send the distance to the computer using Serial protocol, and
    turn LED OFF to indicate successful reading. */
    Serial.println(distance);
    digitalWrite(LEDPin, LOW);
    digitalWrite(wheelLeftPos, LOW );
    digitalWrite(wheelRightPos, LOW );  
    digitalWrite(wheelLeftNeg, LOW );
    digitalWrite(wheelRightNeg, LOW );  
  }
 
 //Delay 50ms before next reading.
 delay(5);
}
