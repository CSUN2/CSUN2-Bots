#include "autonMethods.h"
#include "main.h"
#include "method.h"
#include "initialize.h"
#include "autoone.h"
#include "testMethod.h"
  autonMeth::autonMeth(int h){
    RDF.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    LDF.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    RDB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    LDB.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    LDM.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    RDM.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    Tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    Tray.tare_position();
  }

  void autonMeth::setDriveHold(){
    RDF.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    LDF.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    RDB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    LDB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }

  void autonMeth::resetDriveEncoders(){
    RDF.tare_position();
    LDF.tare_position();
    LDB.tare_position();
    RDB.tare_position();
  }

  void autonMeth::moveDriveMotors(int left, int right){ //Sets voltage to both sides of the drive motor
    RDF.move(right);
    RDB.move(right);

    LDF.move(left);
    LDB.move(left);
  }

  float autonMeth::averageEncoderValues(){
    return (RDF.get_position() + LDF.get_position() + RDB.get_position() + LDF.get_position())/4;
  }

  void autonMeth::moveDistancePID(int distance, int maxSpeed, int timeout){
    resetDriveEncoders();

    int kP = 4;
    int kI = 2000;//4500
    int kD = 10000;

    int totalError = 0;
    int lastError = averageEncoderValues();
    bool goneOver = false;

    while(true){
      float currValue = averageEncoderValues();
      float currError = currValue - distance;
      totalError += currError;
      int diffError = currError - lastError;

      int currSpeed = currError/kP + totalError/kI + diffError/kD;

      moveDriveMotors(-currSpeed-(5*gyroM.get_rotation()),
                      -currSpeed+(5*gyroM.get_rotation()));

      lastError = currError;
      if(currError<=3 && currError>=-3) {
        moveDriveMotors(0, 0);
        break;
      }
    //  if(!goneOver && abs(averageEncoderValues())> abs(distance)) {
        goneOver = true;
        totalError = 0;
      }
      pros::delay(10);
    }
