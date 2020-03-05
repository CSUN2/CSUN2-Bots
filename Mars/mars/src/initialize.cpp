#include "main.h"

pros::Motor Tray(15, pros::E_MOTOR_GEARSET_36, false,pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor Rintake(16, pros::E_MOTOR_GEARSET_36, false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Lintake(10, pros::E_MOTOR_GEARSET_36, true,pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor LDB(13, pros::E_MOTOR_GEARSET_18, false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor LDM(12, pros::E_MOTOR_GEARSET_18, false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor LDF(2, pros::E_MOTOR_GEARSET_18, false,pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor RDB(20, pros::E_MOTOR_GEARSET_18, true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor RDM(19, pros::E_MOTOR_GEARSET_18, true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor RDF(18, pros::E_MOTOR_GEARSET_18, true,pros::E_MOTOR_ENCODER_DEGREES);
pros::ADIDigitalOut sensor ('A', false);
pros::Imu gyroM(14);
