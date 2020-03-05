#include "main.h"
#include "initialize.h"
#include "method.h"

void autoone()
{
  taredrive(); //tare drive
  //autonMeth joseMeth(1);
  //tareintray(); //tare traydeg and intake
  //pros::delay(2000);
  //moveDeg(-40,60);
  //taredrive();
  //moveDeg(-150,40);

  outtake(360, 100);
  pros::delay(1000);
  moveDeg(200,60);
  pros::delay(1000);
  traydeg(100,30);
  moveDeg(-200, 100);

  ///outtaketray(-1800,100);
  pros::delay(1000);;
  //moveDeg(150,60);
  //traydeg(-540, 60);
  //moveDeg(-20,60);

  pros::delay(1000);


  eat(100);
  traydeg(-50,30);
  moveDeg(1070,45);//intake cubes and it moves forward
  pros::delay(1000);
  eat(0); //cease the intake.
  taredrive();//tare to prep for next move
  //tareintray();
///////////////////////////////////////////////////////
//next prepares and intakes next row
/////////////////////////////////////////////////////
//blue side
/////////////////////////////////////////////////////
/*
  moveDeg(-900, 85);
  RmoveDeg(240, 40);
  moveDeg(700, 40);
  LmoveDeg(240, 40);
  eat(100);
  moveDeg(960, 45);
  pros::delay(500);
  eat(0);
*/
  //////////////////////////////////////////////////////
  //red side turn
  ///////////////////////////////////////////////////////

  moveDeg(-950, 45);
  LmoveDeg(240, 40);
  moveDeg(700, 40);
  RmoveDeg(240, 40);
  eat(100);
  moveDeg(960, 45);
  pros::delay(500);
  eat(0);

///////////////////////////////////////////////////////////////
//move toward bottom goalzone
//////////////////////////////////////////////////////////////
//blue side
//////////////////////////////////////////////////////////////
/*
  moveDeg(-1000, 45);
//  traydeg(200,15);
  LmoveDeg(240, 45);
//  traydeg(-200,15);
  moveDeg(900, 45);
  LmoveDeg(210, 40);
  moveDeg(130, 40);
*/
//////////////////////////////////////////////////////////////
//red side
//////////////////////////////////////////////////////////////

  moveDeg(-500, 45);
  pros::delay(1000);
//  traydeg(100,15);
  RmoveDeg(720, 45);
  pros::delay(1000);
  moveDeg(500, 45);
//  traydeg(-200,15);
  LmoveDeg(480,45);
  moveDeg(900, 45);
  RmoveDeg(210, 40);
  moveDeg(130, 40);

//////////////////////////////////////////////////////////////
//alt auton red
//////////////////////////////////////////////////////////////
/*
  moveDeg(-950, 45);
  RmoveDeg(240, 35);
  moveDeg(160, 45);
  RmoveDeg(140, 40);
  moveDeg(150,40);
*/
//////////////////////////////////////////////////////////////
//alt auton blue
//////////////////////////////////////////////////////////////
/*
  moveDeg(-950, 45);
  LmoveDeg(240, 35);
  moveDeg(160, 45);
  LmoveDeg(250, 40);
  moveDeg(150,40);
*/
//////////////////////////////////////////////////////////////
//next drop off the cubes in zone
//////////////////////////////////////////////////////////////
  release();
  pros::delay(3000);
  outtake(90,100);

  eat(-360);
  //moveDeg(-100, 40);
  //traydeg(-30, 5);
  moveDeg(-540, 70);
  eat(0);







}
