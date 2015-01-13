#ifndef COMMON_H
#define COMMON_H

#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin
#define wheelLeftPos 7
#define wheelRightPos 5
#define wheelLeftNeg 8
#define wheelRightNeg 11
#define LEDPin 13 // Onboard LED

enum DirectionToMove {
  forwardDir,
  backwardDir,
  leftDir,
  rightDir,
  stopDir
};

#endif /*COMMON_H*/
