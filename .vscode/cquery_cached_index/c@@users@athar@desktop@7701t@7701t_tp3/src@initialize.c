#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
// int color = 0;

void initialize() {
	for (int i = 11; i <= 14; i++) {
		// Sets motor gearset on startup
		motor_set_gearing(i, E_MOTOR_GEARSET_18); // drive speed
		// Sets motor encoder units on startup
		motor_set_encoder_units(i, E_MOTOR_ENCODER_ROTATIONS);
	}
	for(int h = 15; h <= 17; h++) {
		// Sets motor gearing to speed for arm, intake, and puncher
		motor_set_gearing(h, E_MOTOR_GEARSET_18);
		// Sets motor encoder units to rotations
		motor_set_encoder_units(h, E_MOTOR_ENCODER_ROTATIONS);
	}
	motor_set_gearing(18, E_MOTOR_GEARSET_36); // angler torque
	motor_set_encoder_units(18, E_MOTOR_ENCODER_DEGREES);
	motor_set_brake_mode(15, E_MOTOR_BRAKE_HOLD);

	display();
	if(competition_is_disabled()) {
		while(auton_select == 0) {
			delay(5);
		}
	}
	simple_text();

	// adi_port_set_config(2, E_ADI_ANALOG_IN);
	// adi_port_set_config(3, E_ADI_ANALOG_IN);
	// adi_port_set_config(4, E_ADI_ANALOG_IN);

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {

}
