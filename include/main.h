/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * Copyright (c) 2017-2018, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convienent for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h"
#include "drive.h"
#include "puncher.h"
#include "intake.h"
#include "arm.h"
#include "display.h"

#define frontLeft 20
#define frontRight 12
#define backLeft 13
#define backRight 14

#define arm 15

#define intake 16
#define puncher 17
#define angler 18

#define pi 3.14159265359

#define MASTER E_CONTROLLER_MASTER
#define PARTNER E_CONTROLLER_PARTNER
#define A E_CONTROLLER_DIGITAL_A
#define X E_CONTROLLER_DIGITAL_X
#define Y E_CONTROLLER_DIGITAL_Y
#define B E_CONTROLLER_DIGITAL_B
#define UP E_CONTROLLER_DIGITAL_UP
#define DOWN E_CONTROLLER_DIGITAL_DOWN
#define LEFT E_CONTROLLER_DIGITAL_LEFT
#define RIGHT E_CONTROLLER_DIGITAL_RIGHT
#define L2 E_CONTROLLER_DIGITAL_L2
#define L1 E_CONTROLLER_DIGITAL_L1
#define R2 E_CONTROLLER_DIGITAL_R2
#define R1 E_CONTROLLER_DIGITAL_R1

#define ch1 controller_get_analog(MASTER, ANALOG_RIGHT_X)
#define ch2 controller_get_analog(MASTER, ANALOG_RIGHT_Y)
#define ch3 controller_get_analog(MASTER, ANALOG_LEFT_Y)
#define ch4 controller_get_analog(MASTER, ANALOG_LEFT_X)

adi_ultrasonic_t sonar;
adi_ultrasonic_t sonar2;

#define high_flag 0
#define middle_flag 75

int auton_select;

lv_obj_t *hold_label;
lv_obj_t *line1;
lv_obj_t *line2;
lv_obj_t *tesseract_line1;
lv_obj_t *tesseract_line2;
lv_style_t *tesseract_line_style;
lv_style_t line_style;

// int auton_mode = 0;


#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
