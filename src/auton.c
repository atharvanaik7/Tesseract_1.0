#include "main.h"
///////////////////////// CLOSE RED 18 SWING //////////////////////////////////////////////////////

void close_red() {
  intakeAuto(5.8); // starts intake
  driveTask(160, 44.5, 50); // goes forward into cap and grabs the ball
  driveTask(160, -45.5, 50); // comes back hits the wall to re-align
  driveTask(100, 6, 50); // go foward a bit to have space to turn
  rotateTask(-90, 0); // turn towards the flags to shoot
  shoot(0.75); // shoot top flag
  checkBall();
  angle(middle_flag); // angle to shoot middle
  shoot(1.4); // shoot middle flag
  intakeAuto(15);
  fastTurn(-10, 0); // rotate so it is lined up with bottom flag
  driveTask(160, 50, 0); // drive into bottom flag
  driveTask(160, -24, 0); // back up so the robot is parallel with the cap
  rotateTask(90, 0); // turn towards the cap
  driveTask(80, -9, 50); // back up into wall to re-align
  flipAuto(200, 4); // start intake to flip cap
  slowTask(120, 34, 0);
  angle(middle_flag); // angle to shoot middle flag on the other side
  fastTurn(-18, 0); // rotate towards that flag
  intakeAuto(5); // intake to make sure ball is in puncher
  shoot(0.5); // shoot other side
  slewDrive(180, 18, 0, 1);
}

//////////////////////////////////// CLOSE BLUE 18 SWING /////////////////////////////////////////////////////
void close_blue(){
  intakeAuto(5.8); // starts intake
  driveTask(160, 44.5, 50); // goes forward into cap and grabs the ball
  driveTask(160, -45.5, 50); // comes back hits the wall to re-align
  driveTask(100, 6, 50); // go foward a bit to have space to turn
  rotateTask(80, 0); // turn towards the flags to shoot
  shoot(0.75); // shoot top flag
  checkBall();
  angle(middle_flag); // angle to shoot middle
  shoot(1.4); // shoot middle flag
  intakeAuto(15);
  fastTurn(10, 0); // rotate so it is lined up with bottom flag
  driveTask(160, 50, 0); // drive into bottom flag
  driveTask(160, -24, 0); // back up so the robot is parallel with the cap
  rotateTask(-90, 0); // turn towards the cap
  driveTask(80, -9, 50); // back up into wall to re-align
  flipAuto(200, 4); // start intake to flip cap
  slowTask(120, 34, 0);
  angle(middle_flag); // angle to shoot middle flag on the other side
  fastTurn(18, 0); // rotate towards that flag
  intakeAuto(5); // intake to make sure ball is in puncher
  shoot(0.5); // shoot other side
  slewDrive(180, 33, 0, 2);
}

//////////////////////////////////  BACK RED FAR FLAGS 15 SWING //////////////////////////////////////////

void backred() {
  driveTask(160, -52, 60);
  armAuto(80, 90);
  rotateTask(-30, 100);
  slowTask(100, 20, 100);
  rotateTask(-96, 0);
  coastMode();
  slowTask(80, 6, 0);
  armAuto(100, 190);
  delay(1000);
  brakeMode();
  slowTask(90, -14, 0);
  armAuto(180, 0);
  delay(600);
  driveTask(160, -19, 100);
  rotateTask(-90, 100);
  intakeAuto(3);
  driveTask(160, 15, 100);
  driveTask(160, -15, 50);
  rotateTask(-90, 100);
  slowTask(80, 8, 200);
  slowTask(80, -8, 100);
  rotateTask(60, 0);
  shoot(0.85);
  checkBall();
  angle(middle_flag);
  shoot(1.5);
  rotateTask(-60, 0);
  driveTask(160, 24, 0);
}

/////////////////////////////////// BACK BLUE FAR FLAGS 15 SWING ////////////////////////////////////////////////////

void backblue() {
  driveTask(160, -52, 60);
  armAuto(80, 90);
  rotateTask(30, 100);
  slowTask(100, 20, 100);
  rotateTask(96, 0);
  coastMode();
  slowTask(80, 6, 0);
  armAuto(100, 190);
  delay(1000);
  brakeMode();
  slowTask(90, -14, 0);
  armAuto(180, 0);
  delay(600);
  driveTask(160, -19, 100);
  rotateTask(90, 100);
  intakeAuto(3);
  driveTask(160, 15, 100);
  driveTask(160, -15, 50);
  rotateTask(90, 100);
  slowTask(80, 8, 200);
  slowTask(80, -8, 100);
  rotateTask(-60, 0);
  shoot(0.85);
  checkBall();
  angle(middle_flag);
  shoot(1.5);
  rotateTask(60, 0);
  driveTask(160, 24, 0);
}

////////////////////////////////// SKILLS 26 ///////////////////////////////////////////////////////////////////

void skills_auton() {
  intakeAuto(6); // intake ball
  driveTask(140, 49, 200); // drive into cap with ball
  driveTask(140, -49.5, 200); // back up into wall
  driveTask(80, 6, 300);  // go forward for room to turn
  rotateTask(-92, 0); // turn towards flags
  driveTask(140, 48, 0); // go towards flags
  rotateTask(90, 0); // turn to line up with wall
  driveTask(80, -8, 200); // back up into wall
  driveTask(140, 4.5, 300); // drive forward for room to turn
  rotateTask(-82, 0); // turn to shoot flags
  shoot(0.5); // shoot top flag
  intakeAuto(20); // intake second ball
  delay(500); // delay
  angle(middle_flag); // angle to shoot middle flag
  shoot(1.5); // shoot middle flag
  angle(0); // angle back to down to 0
  rotateTask(-10.5, 0); // rotate to line up with bottom flag
  driveTask(140, 54, 300); // drive into bottom flag
  driveTask(140, -49, 0); // drive back so it is parallel with the cap on the right
  rotateTask(90, 0); // rotate towards cap
  driveTask(80, -9, 200); // back into wall
  intakeAuto(6); // start intake
  driveTask(140, 50, 250); // go towards ball
  driveTask(140, -4, 0); // back up so the cap does not interfere with turning
  rotateTask(-90, 100); // rotate towards middle column flags
  driveTask(80, -8, 200); // drive back into platform to center
  driveTask(80, 5, 0); // drive forward for room to turn
  rotateTask(20, 0); // rotate towards the middle column flags
  shoot(0.5); // shoot top flag
  intakeAuto(5); // intake second flag
  delay(600); // delay for the ball to get up
  angle(middle_flag); // angle to middle flag
  shoot(1.5); // shoot middle flag
  rotateTask(-8, 0); // turn towards bottom flag
  intakeAuto(10); // intake to grab ball
  driveTask(140, 38, 0); // drive into bottom flag
  rotateTask(-8, 0); // turn a bit more so it is perfectly aligned with wall
  driveTask(80, 19, 200); // drive into wall
  angle(0); // angle to high flag
  driveTask(140, -26, 0); // drive back to be parallel with cap
  rotateTask(90, 0); // rotate towards cap
  // flipAuto(150, 4); // turn on intake to flip cap
  // driveTask(140, 35, 300); // drive into cap
  // driveTask(80, -10, 0); // drive back to line up with bottom flag
  // intakeAuto(4);
  // rotateTask(-192, 0); // rotate towards bottom flag
  flipAuto(150, 20); // start intake to flip
  driveTask(140, 65, 200); // drive into cap to flip
  driveTask(80, -15, 0); // back up so cap does not get caught when turning
  rotateTask(-93, 0); // rotate towards bottom flag
  driveTask(140, 30, 250); // drive into bottom flag
  driveTask(140, -50, 0); // // drive back to be parallel with cap
  rotateTask(-95, 0); // rotate towards cap
  intakeAuto(3); // start intake to grab ball
  driveTask(140, 29, 200); // drive into cap and grab ball
  driveTask(140, -30, 100); // drive into wall
  // driveTask(140, 25, 100); // drive forward to be parallel with flags - +25
  rotateTask(90, 100); // rotate towards flags
  shoot(0.5); // shoot top
  angle(middle_flag); // angle to middle flag
  intakeAuto(5); // intake second ball
  delay(500); // delay
  shoot(1.5); // shoot middle
  rotateTask(-90, 0); // rotate to be parallel with wall
  driveTask(140, -15, 200); // drive back
  rotateTask(-90, 0); // rotate to get closer to platform
  driveTask(140, 26.5, 100); // drive to be parallel with platform
  rotateTask(90, 100); // rotate towards the platform
  // driveTask(80, -15, 300); // drive into wall
  intakeAuto(10); // start intake in case any ball are in the way
  driveTask(200, 90, 0); // drive onto platform
}

/////////////////////////// TESTING AUTON ////////////////////////////////////////////////////////

void test(){ // testing pid
  // coastMode();
  rotateTask(-90, 0);
  driveTask(160, 24, 0);
}












// AUTONS IN DEVELOPMENT / BACKUP AUTONS

///////////////// BACKRED FAR FLAGS //////////////////////////////////////////

// intakeAuto(7); // start intake
// driveTask(150, 45, 200); // goes forward and grabs the ball
// driveTask(150, -4, 0); // back up so the cap doesnt get in the way
// rotateTask(-90, 0); // turn towards the alliance platform
// driveTask(100, 9, 400); // drive into the alliance platform for alignment
// driveTask(100, -8, 0); // drive back for space to turn
// rotateTask(30, 0); // turn towards far flags
// delay(5000); // wait 5 seconds for other team to shoot
// shoot(0.5); // shoot top flag
// intakeAuto(7); // intake second ball up to the puncher
// delay(400); // delay for ball to get up to the puncher
// angle(75); // angle to middle flag
// shoot(1.5); // shoot middle flag
// rotateTask(-32, 0); // rotate back towards the alliance platform
// driveTask(150, 32, 0); // park onto alliance platform

///////////////// BACK BLUE FAR FLAGS ////////////////////////////////////////

// intakeAuto(7); // start intake
// driveTask(150, 45, 200); // goes forward and grabs the ball
// driveTask(150, -4, 0); // back up so the cap doesnt get in the way
// rotateTask(90, 0); // turn towards the alliance platform
// driveTask(100, 9, 400); // drive into the alliance platform for alignment
// driveTask(100, -8, 0); // drive back for space to turn
// rotateTask(-33, 0); // turn towards far flags
// delay(5000); // wait 5 seconds for other team to shoot
// shoot(0.5); // shoot top flag
// intakeAuto(7); // intake second ball up to the puncher
// delay(400); // delay for ball to get up to the puncher
// angle(middle_flag); // angle to middle flag
// shoot(1.5); // shoot middle flag
// rotateTask(32, 0); // rotate back towards the alliance platform
// driveTask(150, 32, 0); // park onto alliance platform

///////////////// CLOSE RED 22 SWING /////////////////////////////////////////

// intakeAuto(6);
// driveTask(150, 43, 200);
// driveTask(150, -44, 150);
// driveTask(100, 6.5, 100);
// rotateTask(-87, 0);
// shoot(0.5);
// intakeAuto(20);
// delay(400);
// angle(95);
// shoot(1.5);
// rotateTask(-8, 0);
// driveTask(150, 53, 0);
// angle(0);
// driveTask(100,-15, 0);
// rotateTask(120, 100);
// intakeAuto(5);
// driveTask(50, 6, 300);
// driveTask(100, 30, 100);
// driveTask(100, -10, 0);
// rotateTask(-110, 0);
// shoot(0.5);
// intakeAuto(5);
// delay(400);
// angle(95);
// shoot(1.5);
// rotateTask(-30, 0);
// driveTask(150, 35, 0);

///////////////// SKILLS 28 //////////////////////////////////////////////////

// shoot(1.5);
// rotateTask(90, 0);
// driveTask(100, -10, 200);
// intakeAuto(12); // intake ball
// driveTask(150, 43.5, 1000); // drive into cap with ball
// flipAuto(120, 5);
// driveTask(100, 6, 100);
// driveTask(100, - 15, 0);
// rotateTask(49, 0);
// flipAuto(120, 5);
// driveTask(100, 20, 200);
// driveTask(100, -20, 0);
// rotateTask(-49, 0);
// driveTask(150, -39, 200); // back up into wall
// driveTask(100, 6, 300);  // go forward for room to turn
// rotateTask(-90, 0); // turn towards flags
// angle(95);
// driveTask(150, 51, 0); // go towards flags
// rotateTask(90, 0); // turn to line up with wall
// driveTask(100, -11, 200); // back up into wall
// driveTask(100, 6, 300); // drive forward for room to turn
// rotateTask(-85, 0); // turn to shoot flags
// shoot(0.5); // shoot top flag
// intakeAuto(20); // intake second ball
// angle(0); // set angle down to 0
// rotateTask(-8, 0); // rotate to line up with bottom flag
// driveTask(150, 53, 300); // drive into bottom flag
// driveTask(150, -49, 0); // drive back so it is parallel with the cap on the right
// rotateTask(90, 0); // rotate towards cap
// driveTask(100, -9, 200); // back into wall
// intakeAuto(6.5); // start intake
// driveTask(150, 50, 250); // go towards ball
// driveTask(150, -6, 0); // back up so the cap does not interfere with turning
// rotateTask(-90, 200); // rotate towards middle column flags
// driveTask(100, -8, 200); // drive back into platform to center
// driveTask(100, 5, 0); // drive forward for room to turn
// rotateTask(18, 0); // rotate towards the middle column flags
// shoot(0.5); // shoot top flag
// intakeAuto(5); // intake second flag
// delay(600); // delay for the ball to get up
// angle(95); // angle to middle flag
// shoot(1.5); // shoot middle flag
// rotateTask(-5, 0); // turn towards bottom flag
// intakeAuto(10); // intake to grab ball
// driveTask(150, 45, 0); // drive into bottom flag
// rotateTask(-5, 0);
// driveTask(100, 8, 200);
// angle(0); // angle to high flag
// driveTask(150, -26, 0); // drive back to be parallel with cap
// rotateTask(-90, 0); // rotate towards cap
// flipAuto(120, 6); // turn on intake to flip cap
// driveTask(150, 35, 350); // drive into cap
// driveTask(100, -10, 0); // drive back to line up with bottom flag
// rotateTask(-187, 0); // rotate towards bottom flag
// flipAuto(120, 22);
// driveTask(150, 78, 200);
// driveTask(100, -9, 0);
// rotateTask(-93, 0);
// driveTask(150, 35, 400); // drive into bottom flag
// driveTask(150, -50, 0); // // drive back to be parallel with cap
// shoot(1.5);
// rotateTask(-90, 0); // rotate towards cap
// intakeAuto(7);
// driveTask(150, 19, 1000); // drive into ball
// angle(95);
// flipAuto(120, 4);
// driveTask(100, 6, 100);
// driveTask(150, -46, 100);
// driveTask(150, 26, 100);
// rotateTask(90, 200); // rotate towards flags
// shoot(1.5); // shoot middle
// rotateTask(-90, 0); // rotate to be parallel with wall
// driveTask(150, -15, 200); // drive into wall
// rotateTask(-90, 0); // rotate to get the last ball
// driveTask(150, 48, 0); // drive to be parallel with platform
// rotateTask(90, 0); // rotate to be towards platform
// driveTask(100, -12, 300); // drive into wall
// flipAuto(120, 6);
// driveTask(150, 43, 150);
// driveTask(100, -10, 0);
// rotateTask(-49, 0);
// flipAuto(120, 6);
// driveTask(100, 12, 200);
// driveTask(100, -12, 0);
// rotateTask(49, 0);
// driveTask(150, -30, 0);
// rotateTask(90, 0);
// driveTask(150, 26, 0);
// rotateTask(-90, 0);
// driveTask(100, -15, 300);
// driveTask(150, 83, 0); // drive onto platform

//////////////// CAP ON RED /////////////////////////////////////

// intakeAuto(6.5);
// driveTask(150, 45.5, 200);
// driveTask(150, -13, 0);
// rotateTask(-115, 0);
// driveTask(100, -21.5, 0);
// delay(200);
// armAuto(50, 120);
// delay(500);
// driveTask(150, 15, 200);
// rotateTask(-45, 300);
// driveTask(150, 46.5, 0);
// driveTask(150, -5, 0);
// armAuto(120, 245);
// delay(700);
// armAuto(100, 0);
// driveTask(150, -10, 0);
// rotateTask(90, 0);
// driveTask(150, 26, 0);
// rotateTask(90, 0);
// driveTask(150, -10 , 100);
// driveTask(150, 8, 0);
// rotateTask(-40, 0);
// shoot(0.5);
// intakeAuto(5);
// delay(200);
// angle(95);
// shoot(1.5);
// rotateTask(40, 0);
// driveTask(150, 50, 0);

// /////////////////////// BACK RED MIDDLE FLAGS 7 ///////////////////////////////////////////////
//
// void backred_mid_7(){
//   intakeAuto(6);
//   driveTask(175, 38, 0);
//   driveTask(150, -6, 0);
//   rotateTask(-65, 0);
//   angle(20);
//   delay(6000);
//   shoot(0.25);
//   intakeAuto(7);
//   delay(200);
//   angle(33);
//   delay(500);
//   shoot(1);
//   rotateTask(-25, 0);
//   driveTask(200, 35, 0);
// }
//
// ////////////////////////////// BACK BLUE MIDDLE FLAGS 7 ///////////////////////////////////////////
//
// void backblue_mid_7() {
//   intakeAuto(6);
//   driveTask(175, 38, 0);
//   driveTask(150, -6, 0);
//   rotateTask(65, 0);
//   angle(20);
//   delay(6000);
//   shoot(0.25);
//   intakeAuto(7);
//   delay(200);
//   angle(33);
//   delay(500);
//   shoot(1);
//   rotateTask(25, 0);
//   driveTask(200, 38, 0);
// }
