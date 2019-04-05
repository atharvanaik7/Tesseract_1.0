#include "main.h"


void armOp() {


    if(controller_get_digital(MASTER, R1)) {
      motor_move_absolute(arm, 2.4, 200);
    }
    else {
      motor_move(arm, ch2);
    }
}

void armAuto(int speed, double rot) {
  rot /= 360;
  rot *= 5;

  motor_move_absolute(arm, rot, speed);
}
