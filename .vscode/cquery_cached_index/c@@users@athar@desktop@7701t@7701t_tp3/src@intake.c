#include "main.h"

int _intake;

void intakeOp() {
  printf("%d\n", adi_analog_read(3));
  // printf("%d\n", adi_analog_read(4));
  if (controller_get_digital(MASTER, L2)) {
    if (adi_analog_read(3) < 2800 || adi_analog_read(4) < 2800) {
      _intake = -127;
    }
    else {
      _intake = -127;
    }
  } else if (controller_get_digital(MASTER, R2)) {
    _intake = 80;
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
    if(adi_analog_read_calibrated(2) < 0) {
      break;
      }
      delay(5);
  }
  motor_move_velocity(intake, 0);
}
