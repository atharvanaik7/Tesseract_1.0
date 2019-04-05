#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	while (true) {

		// int turn = pow(ch4, 2.2) / pow(127, 1.2);
		// printf("Sensor Reading %d \n", adi_analog_read_calibrated(2));
		driveOp();
		intakeOp();
		puncherOp();
		armOp();

		delay(10);
	}
}