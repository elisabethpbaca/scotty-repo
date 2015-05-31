#include "common.h"

void loop() {
  


  //github practice

  int leftDis=getLeftDistance();
  String leftText = "Left:";
  String lString = leftText + leftDis;
  Serial.println(lString);
  
  int rightDis=getRightDistance();
  String rightText = "Right:";
  String rString = rightText + rightDis;
  Serial.println(rString);
  
  int frontDis=getForwardDistance();
  String frontText = "Front:";
  String fString = frontText + frontDis;
  Serial.println(fString);

  
 forward();
delay (250); 
 left();
 delay (250);
 right();
 delay (250);
 backward();
 delay (250);
}   

   
