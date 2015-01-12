#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin
#define wheelLeftPos 7
#define wheelRightPos 5
#define wheelLeftNeg 8
#define wheelRightNeg 11
#define LEDPin 13 // Onboard LED

#define FWRange 20
#define BWRange 19
#define StopRange 9

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
   
    if (distance==12)  {
       RTurn();
   }
   else if (distance>=FWRange) {
       forward();
   }
   
   else if (distance<=StopRange) {
         still();
   }
   
   else if (distance<=BWRange)  {
       backwards();
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
    
    void RTurn() {
       digitalWrite(wheelLeftNeg, LOW);
       digitalWrite(wheelLeftPos, HIGH); 
       digitalWrite(wheelRightPos, LOW);
       digitalWrite(wheelRightNeg, HIGH);
     }
     
     void LTurn() {
       digitalWrite(wheelLeftNeg, HIGH);
       digitalWrite(wheelLeftPos, LOW); 
       digitalWrite(wheelRightPos, HIGH);
       digitalWrite(wheelRightNeg, LOW);
       
     }
