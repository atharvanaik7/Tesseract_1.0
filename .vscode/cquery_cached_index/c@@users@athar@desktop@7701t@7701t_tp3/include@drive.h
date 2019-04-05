#ifndef DRIVE_H_
#define DRIVE_H_

// Operator Control
void driveOp();

// Autonomous Functions
void drive(int vel);
void rotate(int vel);
void strafe(int vel);
void slewLeft(int vel);
void slewRight(int vel);
void setBrakeMode(int mode);

void driveTask(int speed, double dist, int ms);
void rotatePid(double rot, int ms);
void rotateTask(double rot, int ms);
void strafeTask(int speed, double dist, int ms);
void rotateCounterTask(double rot, int ms);
void slewDrive(int speed, double dist, int ms, int dir);
void slowTask(int speed, double dist, int ms);
void fastTurn(double rot, int ms);

#endif
