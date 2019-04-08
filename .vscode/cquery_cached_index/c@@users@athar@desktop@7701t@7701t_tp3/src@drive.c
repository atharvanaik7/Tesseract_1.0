#include "main.h"
#include "math.h"

int _frontLeft, _frontRight, _backLeft, _backRight;
int _strafe;
bool brake = true;
int stop = 0;
int strafeSpeed = 100;


void driveOp() {

  if (stop > 0) {
    stop--;
  }

  // Button A switched between different brake modes
  if (controller_get_digital(MASTER, A)) {
    if (stop == 0) {
      if (brake) {
        for (int i = 11; i <= 14; i++) { motor_set_brake_mode(i, E_MOTOR_BRAKE_HOLD); }
        // lv_label_set_text(hold_label, "Brake Mode: \nHold");
      } else {
        for (int i = 11; i <= 14; i++) { motor_set_brake_mode(i, E_MOTOR_BRAKE_COAST); }
        // lv_label_set_text(hold_label, "Brake Mode: \nCoast");
      }
      stop = 50;
      brake = !brake;
    }
  }

  // Arcade
  // int turn = pow(ch4, 3) / pow(127, 2); // Turning Sensitivity

  _frontLeft = ch3 + ch4*0.8;
  _frontRight = -ch3 + ch4*0.8;
  _backLeft = ch3 + ch4*0.8;
  _backRight = -ch3 + ch4*0.8;


  // Setting the Motors
  motor_move(frontLeft, _frontLeft);
  motor_move(frontRight, _frontRight);
  motor_move(backLeft, _backLeft);
  motor_move(backRight, _backRight);
}




void drive(int vel) {
  // vel *= 127;
  // vel /= 200;
  motor_move_velocity(frontLeft, vel);
  motor_move_velocity(frontRight, -vel);
  motor_move_velocity(backLeft, vel);
  motor_move_velocity(backRight, -vel);
}
void rotate(int vel) {
  // vel *= 127;
  // vel /= 200;
  motor_move_velocity(frontLeft, vel);
  motor_move_velocity(frontRight, vel);
  motor_move_velocity(backLeft, vel);
  motor_move_velocity(backRight, vel);
}
void slewLeft(int vel) {
  motor_move_velocity(frontLeft, vel/2.45);
  motor_move_velocity(frontRight, -vel);
  motor_move_velocity(backLeft, vel/2.45);
  motor_move_velocity(backRight, -vel);
}
void slewRight(int vel) {
  motor_move_velocity(frontLeft, vel);
  motor_move_velocity(frontRight, -vel/2.48);
  motor_move_velocity(backLeft, vel);
  motor_move_velocity(backRight, -vel/2.48);
}

void brakeMode() {
  for(int i = 12; i <= 14; i++) {
    motor_set_brake_mode(i, E_MOTOR_BRAKE_HOLD);
  }
  motor_set_brake_mode(20, E_MOTOR_BRAKE_HOLD);
}
void coastMode() {
  for(int i = 12; i <= 14; i++) {
    motor_set_brake_mode(i, E_MOTOR_BRAKE_COAST);
  }
  motor_set_brake_mode(20, E_MOTOR_BRAKE_COAST);
}

void reset() {
  for(int i = 12; i <= 14; i++) {
    motor_tare_position(i);
  }
  motor_tare_position(20);
}

void wallCheck() { //testing
    while(adi_ultrasonic_get(sonar) > adi_ultrasonic_get(sonar2)) {
      rotate(-10);
      delay(20);
    }
    rotate(0);
  }

void driveTask(int speed, double dist, int ms) { // drive pid
  bool driving = true;
  double sp = dist / 16.5; // 12.9 - 16.5
  double prev_error = 0;

  int kp = 180; //200 127
  int ki = 0;
  int kd = 100; //100 63
  double pv = 0;
  double error = 0;
  double integral = 0;
  double integralActive = (3/12.8);
  double derivative = 0;
  int velocity = 0;

  motor_tare_position(13);

  while(driving) {
    pv = motor_get_position(13);

    // if (error <= 0.01 && error >= -0.01) { integral += error; }
    // else { integral = 0; }

    error = sp - pv;
    derivative = error - prev_error;
    velocity = error*kp + derivative*kd + integral*ki;
    prev_error = error;

    if (velocity > speed) { velocity = speed; }
    else if (velocity < -speed) { velocity = -speed; }

    drive(velocity);

    if (error <= .05 && error >= -.05) {
      driving = false;
    }

    delay(20);
  }
  drive(0);
  delay(ms);
}

void rotateTask(double rot, int ms) { // rotate pid

  rot /= 360;
  double sp;
  if(rot < 0){ sp = rot* 2.45; } // turning counter clockwise - 3.0 - 2.4 - 2.8 - 2.5
  else { sp = rot* 2.55; } // turning clockwise - 3.1 - 2.45 - 2.95 - 2.5
  bool driving = true;
  double prev_error = 0;

  int kp = 250; //250, 158
  int ki = 0;
  int kd = 100; //100, 63
  double pv = 0;
  double error = 0;
  double integral = 0;
  double integralActive = (0.25);
  double derivative = 0;
  int velocity = 0;

  motor_tare_position(13);

  while(driving) {
    pv = motor_get_position(13);

    if (error <= 0.005 && error >= -0.005) { integral += error; }
    else { integral = 0; }

    error = sp - pv;
    derivative = error - prev_error;
    velocity = error*kp + derivative*kd + integral*ki;
    prev_error = error;

    if (velocity > 100) { velocity = 100; }
    else if (velocity < -100) { velocity = -100; }

    rotate(velocity);

    if (error <= .005 && error >= -.005) { //.005, .03
      driving = false;
    }

    delay(20);
  }
  rotate(0);
  delay(ms);
}

void slewDrive(int speed, double dist, int ms, int dir) { // slew control
  bool driving = true;
  double sp = dist / 16.5; // 12.9 - 16.5
  double prev_error = 0;

  int kp = 400; //200 127
  int ki = 0;
  int kd = 100; //100 63
  double pv = 0;
  double error = 0;
  double integral = 0;
  double integralActive = (3/12.8);
  double derivative = 0;
  int velocity = 0;

  motor_tare_position(13);

  while(driving) {
    pv = motor_get_position(13);

    // if (error <= 0.01 && error >= -0.01) { integral += error; }
    // else { integral = 0; }

    error = sp - pv;
    derivative = error - prev_error;
    velocity = error*kp + derivative*kd + integral*ki;
    prev_error = error;

    if (velocity > speed) { velocity = speed; }
    else if (velocity < -speed) { velocity = -speed; }

    if (dir == 1) {
      if(fabs(error) > sp*0.4) {
        slewLeft(velocity);
      }
      else {
        drive(velocity);
      }
    }
    else if (dir == 2) {
      if(fabs(error) > sp*0.4) {
        slewRight(velocity);
      }
      else {
        drive(velocity);
      }
    }

    if (error <= .05 && error >= -.05) {
      driving = false;
    }

    delay(20);
  }
  slewLeft(0);
  slewRight(0);
  drive(0);
  delay(ms);
}

void rotatePid(double rot, int ms) { // pigpen style
 rot /= 360;
 double sp;
 if(rot < 0){ sp = rot* 2.45; } // turning counter clockwise - 3.0 - 2.4 - 2.8
 else { sp = rot* 2.65; } // turning clockwise - 3.1 - 2.45 - 2.95
 bool driving = true;
 double prev_error = 0;

 int kp = 100; //250, 158
 int ki = 0;
 int kd = 25; //100, 63
 double pv = 0;
 double error = 0;
 double integral = 0;
 double integralActive = (0.25);
 double derivative = 0;
 int velocity = 0;

 motor_tare_position(13);

 while(driving) {
   pv = motor_get_position(13);

   // if (error <= 0.005 && error >= -0.005) { integral += error; }
   // else { integral = 0; }

   error = sp - pv;
   derivative = error - prev_error;
   integral += error;

   if(error > 0) {
     if(fabs(error) < sp*0.75) {
       kp = 175;
       ki = 0;
       kd = 50;
     }
     else {
       kp = 0;
       ki = 150;
       kd = 0;
     }
   }
   else {
     if(error < sp * -0.75) {
       kp = 100;
       ki = 0;
       kd = 25;
     }
     else {
       kp = 0;
       ki = 80;
       kd = 0;
     }
   }

   velocity = error*kp + derivative*kd + integral*ki;
   prev_error = error;

   if (velocity > 100) { velocity = 100; }
   else if (velocity < -100) { velocity = -100; }

   rotate(velocity);

   if (error <= .005 && error >= -.005) { //.005, .03
     driving = false;
   }

   delay(20);
 }
 rotate(0);
 delay(ms);}

void slowTask(int speed, double dist, int ms) { // slow drive pid
  bool driving = true;
  double sp = dist / 16.5; // 12.9 - 16.5
  double prev_error = 0;

  int kp = 250; //200 127
  int ki = 0;
  int kd = 100; //100 63
  double pv = 0;
  double error = 0;
  double integral = 0;
  double integralActive = (3/12.8);
  double derivative = 0;
  int velocity = 0;

  motor_tare_position(13);

  while(driving) {
    pv = motor_get_position(13);

    // if (error <= 0.01 && error >= -0.01) { integral += error; }
    // else { integral = 0; }

    error = sp - pv;
    derivative = error - prev_error;
    velocity = error*kp + derivative*kd + integral*ki;
    prev_error = error;

    if (velocity > speed) { velocity = speed; }
    else if (velocity < -speed) { velocity = -speed; }

    drive(velocity);

    if (error <= .05 && error >= -.05) {
      driving = false;
    }

    delay(20);
  }
  drive(0);
  delay(ms);
}

void fastTurn(double rot, int ms) { // fast rotate pid

  rot /= 360;
  double sp;
  if(rot < 0){ sp = rot* 2.31; } // turning counter clockwise - 3.0 - 2.4 - 2.8 - 2.5
  else { sp = rot* 2.3; } // turning clockwise - 3.1 - 2.45 - 2.95 - 2.5
  bool driving = true;
  double prev_error = 0;

  int kp = 250; //250, 158
  int ki = 0;
  int kd = 100; //100, 63
  double pv = 0;
  double error = 0;
  double integral = 0;
  double integralActive = (0.25);
  double derivative = 0;
  int velocity = 0;

  motor_tare_position(13);

  while(driving) {
    pv = motor_get_position(13);

    if (error <= 0.005 && error >= -0.005) { integral += error; }
    else { integral = 0; }

    error = sp - pv;
    derivative = error - prev_error;
    velocity = error*kp + derivative*kd + integral*ki;
    prev_error = error;

    if (velocity > 200) { velocity = 200; }
    else if (velocity < -200) { velocity = -200; }

    rotate(velocity);

    if (error <= .005 && error >= -.005) { //.005, .03
      driving = false;
    }

    delay(20);
  }
  rotate(0);
  delay(ms);
}
