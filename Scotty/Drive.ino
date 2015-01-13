#include "common.h"
int dutyCycle = 75;
DirectionToMove moveDirection = forwardDir;

void setDutyCycle(int dutyCycleParam) {
  dutyCycle = dutyCycleParam;
}

void setDirection(DirectionToMove dir) {
  moveDirection = dir;
}

void Drive() {
  int dutyCycleOnDuration = dutyCycle * 10;
  int dutyCycleOffDuration = 1000 - dutyCycleOnDuration;
  Serial.println("Moving");
  Serial.println(dutyCycleOnDuration);
  Move();
  delayMicroseconds(dutyCycleOnDuration);
  Serial.println("Stoping");
  Serial.println(dutyCycleOffDuration);
  robotStop();
  delayMicroseconds(10000);
}

void Move() {
  switch(moveDirection) {
    case forwardDir:
      forward();
      break;
    case backwardDir:
      backward();
      break;
    case leftDir:
      left();
      break;
    case rightDir:
      right();
      break;
    case stopDir:
      robotStop();
      break;
  }
}
