#include "main.h"
#include "initialize.h"
#include "method.h"


void Testmethod ()
{
  taredrive(); //tare drive
  tareintray(); //tare traydeg and intake
  traydeg(180, 100); //move tray forawrd to deploy
  pros::delay(2000);
  tareintray();
  traydeg(-360, 90); //move tray down to set into proper get_position
  eat(100);
  moveDeg(1100,45);//intake cubes and it moves forward
  pros::delay(1000);
  eat(0); //cease the intake.
  taredrive();//tare to prep for next move
  tareintray();

  ///////////////////////////////////////////////////////
  //next prepares and intakes next row
  /////////////////////////////////////////////////////
    moveDeg(-980, 45);
    LmoveDeg(240, 40);
    moveDeg(700, 40);
    RmoveDeg(225, 40);
    eat(100);
    moveDeg(1000, 45);
    pros::delay(500);
    eat(0);

    ///////////////////////////////////////////////////////////////
    //move toward bottom goalzone
    //////////////////////////////////////////////////////////////
      moveDeg(-1000, 45);
      RmoveDeg(240, 45);
      moveDeg(720, 45);
      RmoveDeg(180, 40);
      moveDeg(215, 40);

      //////////////////////////////////////////////////////////////
      //next drop off the cubes in zone
      //////////////////////////////////////////////////////////////
        traydeg(545, 14);
        //moveDeg(-100, 40);
        //traydeg(-30, 5);
        moveDeg(-180, 40);

  ////////////////////////////////////////////////////////////////
  pros::delay(20);
}
