#include "main.h"
#include "method.h"
#include "initialize.h"
#include "autoone.h"
#include "testMethod.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "FOCUS!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Breathe and Focus");

	pros::lcd::register_btn1_cb(on_center_button);
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
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous()
{

			autoone();//blue
			//Testmethod();//red
}

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

	pros::Controller master(pros::E_CONTROLLER_MASTER);

	int deadzone = 15; //sets the sensitivity of analog reaction
	bool pneuSwitch = false;
	while (true) {
		master.print(0,0,"Stay Calm");
//////////////////////////////////////////////////////////////
		//TANK DRIVE
		//left side drive
		if(abs(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y))>=deadzone)//makes sure of true movement
			{
				double volt = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
				LDF.move(volt);
				LDM.move(volt);
				LDB.move(volt);
			}
					else
					{
						LDF.move_velocity(0);
						LDM.move_velocity(0);
						LDB.move_velocity(0);
					}
					//right side drive
		if(abs(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y))>=deadzone)
			{
				double volt = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
				RDF.move(volt);
				RDM.move(volt);
				RDB.move(volt);
			}
					else
					{
						RDF.move_velocity(0);
						RDM.move_velocity(0);
						RDB.move_velocity(0);
					}
///////////////////////////////////////////////////////////////
					//INTAKE

				if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1)
				{
					Lintake.move_velocity(200);
					Rintake.move_velocity(200);

				}
				else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1)
				{
					Lintake.move_velocity(-200);
					Rintake.move_velocity(-200);
				}
				else
				{
					Lintake.move_velocity(0);
					Rintake.move_velocity(0);
				}
/////////////////////////////////////////////////////////////////////////
				//Tray
				if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1)
				{
					Tray.move_velocity(15);
				}
				else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1)
				{
					Tray.move_velocity(-100);
				}
				else
				{
					Tray.move_velocity(0);
				}
				if(master.get_digital(DIGITAL_A)==1)
				{
					pneuSwitch = !pneuSwitch;
					sensor.set_value(pneuSwitch);
					pros::delay(100);
					//put this on a different thread (threading)
				}
		pros::delay(20);
	}
}
