#include "main.h"

int _puncher;
int press = 0;
double pos = 0;
double total_rot = 0;
double needed_rot = 0.75;
double start_rot = 0.75;
bool auto_ratchet = false;
bool ratcheted = false;

void puncherOp() {
  if(controller_get_digital(MASTER, B) && press == 0) {
    auto_ratchet = true;
    needed_rot += 1;
    press = 45;
  }

  if (auto_ratchet) {
    pos = motor_get_position(puncher);
    if (ratcheted) {
      total_rot = needed_rot - pos;
      if (!(total_rot < 0.02 && total_rot > -0.02)) { _puncher = 127; }
      else { auto_ratchet = false; }
    }
    else {
      total_rot = start_rot - fmod(pos, 1);
      if (!(total_rot < 0.02 && total_rot > -0.02)) { _puncher = 127; }
      else {
        start_rot = 1;
        needed_rot = 0;
        motor_tare_position(puncher);
        ratcheted = true;
        auto_ratchet = false;
      }
    }
  }
  else if (controller_get_digital(MASTER, A)) {
    ratcheted = false;
    _puncher = 127;
  } else {
    _puncher = 0;
  }

  if (press > 0) {
    press--;
  }
  // autoRachet();

  if (controller_get_digital(MASTER, DOWN)) {
    while(controller_get_digital(MASTER, DOWN)) {
      motor_move_velocity(angler, -25);
      delay(10);
    }
    motor_move_velocity(angler, 0);
    motor_tare_position(angler);
  }

  // Angler
  if (controller_get_digital(MASTER, X)) { // X
    motor_move_absolute(angler, 0, 75); // FRONT TOP
  }
  if (controller_get_digital(MASTER, Y)) { // Y
    motor_move_absolute(angler, 80, 100); // FRONT MIDDLE
  }
  if(controller_get_digital(MASTER, UP)) { // UP
    motor_move_absolute(angler, 50, 75); // BACK TOP
  }
  if(controller_get_digital(MASTER, LEFT)) { // LEFT
    motor_move_absolute(angler, 180, 100); // BACK MIDDLE
  }

  motor_move(puncher, _puncher);
}

// void autoRachet() {
//   while(adi_analog_read_calibrated(8) > 161) {
//     motor_move_velocity(puncher, 100);
//   }
//   motor_move_velocity(puncher, 0);
// }


void shoot(double rot) {
  motor_move_relative(puncher, rot, 200);
  rot += motor_get_position(puncher);
  while (!(motor_get_position(puncher) > rot - 0.05 && motor_get_position(puncher) < rot + 0.05)) {
    delay(5);
  }
}

void shootfast(double rot) {
  motor_move_relative(puncher, rot, 200);
}


// #define high_flag 0
// #define middle_flag 32

void angle(int angle) {
  motor_move_absolute(angler, angle, 75);
}
