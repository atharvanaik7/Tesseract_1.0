#include "main.h"

int _intake;

void intakeOp() {
  if (controller_get_digital(MASTER, R2)) {
    _intake = 80;
  } else if (controller_get_digital(MASTER, L2)) {
    _intake = -127;
  } else {
    _intake = 0;
  }

  motor_move(intake, _intake);
}


void intakeAuto(double rot) {
  motor_move_relative(intake, -rot, 200);
}


void flipAuto(int speed, double rot) {
  motor_move_relative(intake, rot, speed);
}
// checks if the ball is in the puncher
void checkBall() {
  motor_move_velocity(intake, -200);
  for(int i = 0; i < 150; i++){ // after 150 loops turn off intake if ball is not there
    if(adi_analog_read_calibrated(2) < 500) {
      break;
      }
      delay(20);
  }
  motor_move_velocity(intake, 0);
}
