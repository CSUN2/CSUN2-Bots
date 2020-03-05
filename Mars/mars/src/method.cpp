#include "main.h"
#include "initialize.h"


//////////////////////////////////////////////////////////////////
//DRIVE METHODS /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

//extern void basic();
///////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
/////////////////DRIVE

void taredrive() //TARE MOTORS
{

  LDF.tare_position();
  LDM.tare_position();
  LDB.tare_position();
  RDF.tare_position();
  RDM.tare_position();
  RDB.tare_position();

}
void pumpout(int time)
{
  bool pneuSwitch = false;
  pneuSwitch = !pneuSwitch;
  sensor.set_value(pneuSwitch);
  pros::delay(time);

}
void pumpin(int time)
{
  bool pneuSwitch = true;
  pneuSwitch = !pneuSwitch;
  sensor.set_value(pneuSwitch);
  pros::delay(time);

}


int enavg(){ //get encoder value and average from left and right drive
  int LF = LDF.get_position();
  int LM = LDM.get_position();
  int LB = LDB.get_position();
  int RF = RDF.get_position();
  int RM = RDM.get_position();
  int RB = RDB.get_position();
  int Lavg = (LF + LM + LB)/3;
  int Ravg = (RF + RM + RB)/3;
  int avg = (Lavg + Ravg)/2;
  return avg;
}

int RTenavg(){ //get encoder value and average from left and right drive
  int LF = LDF.get_position();
  int LM = LDM.get_position();
  int LB = LDB.get_position();
  int RF = RDF.get_position();
  int RM = RDM.get_position();
  int RB = RDB.get_position();
  int Lavg = (LF + LM + LB)/3;
  int Ravg = (RF + RM + RB)/-3;
  int avg = (Lavg + Ravg)/2;
  return avg;
}

int LTenavg(){ //get encoder value and average from left and right drive
  int LF = LDF.get_position();
  int LM = LDM.get_position();
  int LB = LDB.get_position();
  int RF = RDF.get_position();
  int RM = RDM.get_position();
  int RB = RDB.get_position();
  int Lavg = (LF + LM + LB)/-3;
  int Ravg = (RF + RM + RB)/3;
  int avg = (Lavg + Ravg)/2;
  return avg;
}

void moveDeg(int degree,int speed) //move a set amount of degrees
{

  taredrive(); //TARE drive

  int Terror = degree + 8; //MAX error
  int Berror = degree - 8; // MIN error



  //moves certain degrees at a certain speed
  LDF.move_absolute(degree,speed);
  LDM.move_absolute(degree,speed);
  LDB.move_absolute(degree,speed);
  RDF.move_absolute(degree,speed);
  RDM.move_absolute(degree,speed);
  RDB.move_absolute(degree,speed);

  //Block other code till move above is complete
  while (!((enavg() < Terror) && (enavg() > Berror))) {
    pros::delay(2);
  }
}

void LmoveDeg(int degree,int speed) //move a set amount of degrees
{
    taredrive();//TARE drive


  int Terror = degree + 5; //MAX error
  int Berror = degree - 5; // MIN error



  //moves certain degrees at a certain speed
  LDF.move_absolute(-degree,speed);
  LDM.move_absolute(-degree,speed);
  LDB.move_absolute(-degree,speed);
  RDF.move_absolute(degree,speed);
  RDM.move_absolute(degree,speed);
  RDB.move_absolute(degree,speed);

  //Block other code till move above is complete
  while (!((LTenavg() < Terror) && (LTenavg() > Berror))) {
    pros::delay(4);
  }
}

void RmoveDeg(int degree,int speed) //move a set amount of degrees
{
  taredrive();//TARE drive

  int Terror = degree + 5; //MAX error
  int Berror = degree - 5; // MIN error



  //moves certain degrees at a certain speed
  LDF.move_absolute(degree,speed);
  LDM.move_absolute(degree,speed);
  LDB.move_absolute(degree,speed);
  RDF.move_absolute(-degree,speed);
  RDM.move_absolute(-degree,speed);
  RDB.move_absolute(-degree,speed);

  //Block other code till move above is complete
  while (!((RTenavg() < Terror) && (RTenavg() > Berror))) {
    pros::delay(4);
  }
}

///////////////////TIME-BASED MOVEMENT////////////////////
void day(int value, int time) //drive in axis Y(front and back) for set time
{

    LDF.move_velocity(value);
    LDM.move_velocity(value);
    LDB.move_velocity(value);
    RDF.move_velocity(value);
    RDM.move_velocity(value);
    RDB.move_velocity(value);

  pros::delay(time);

  LDF.move_velocity(0);
  LDM.move_velocity(0);
  LDB.move_velocity(0);
  RDF.move_velocity(0);
  RDM.move_velocity(0);
  RDB.move_velocity(0);

}




void turny(int value,int time)
{

  LDF.move_velocity(-value);
  LDM.move_velocity(-value);
  LDB.move_velocity(-value);
  RDF.move_velocity(value);
  RDM.move_velocity(value);
  RDB.move_velocity(value);

  pros::delay(time);

  LDF.move_velocity(0);
  LDM.move_velocity(0);
  LDB.move_velocity(0);
  RDF.move_velocity(0);
  RDM.move_velocity(0);
  RDB.move_velocity(0);

}
void turnyR(int value,int time)
{

  LDF.move_velocity(value);
  LDM.move_velocity(value);
  LDB.move_velocity(value);
  RDF.move_velocity(-value);
  RDM.move_velocity(-value);
  RDB.move_velocity(-value);

  pros::delay(time);

  LDF.move_velocity(0);
  LDM.move_velocity(0);
  LDB.move_velocity(0);
  RDF.move_velocity(0);
  RDM.move_velocity(0);
  RDB.move_velocity(0);
}

////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////Tray

void tareintray()
{
  Tray.tare_position();
  Lintake.tare_position();
  Rintake.tare_position();
}

void traydeg(int degree,int speed)
{
  int toperror = degree + 5; //MAX error
  int boterror = degree - 5; // MIN error

  Tray.move_absolute(degree, speed);

  while (!((Tray.get_position() < toperror) && (Tray.get_position() > boterror))) {
    pros::delay(2);
  }
}


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///////////////////INTAKE


int inavg()
{

  double Ravg = Rintake.get_position();
  double Lavg = Lintake.get_position();
  int intakeavg = (Lavg + Ravg)/2;
  return intakeavg;
}

void indeg(int degree,int speed)
{
  int Toperror = degree + 5; //MAX error
  int Boterror = degree - 5; // MIN error

  Rintake.move_absolute(degree, speed);
  Lintake.move_absolute(degree, speed);

  while (!((inavg() < Toperror) && (inavg() > Boterror))) {
    pros::delay(2);
  }
}

void eat(int value)// intake on for fixed duration
{

    Rintake.move_velocity(value);
    Lintake.move_velocity(value);


}
void ew(int degree, int speed)
{

  taredrive();//TARE drive


int Terror = degree + 5; //MAX error
int Berror = degree - 5; // MIN error



  Rintake.move_absolute(degree,speed);
  Lintake.move_absolute(degree,speed);


}
void outtaketray(int degree, int speed)
{

  taredrive();//TARE drive


int Terror = degree + 5; //MAX error
int Berror = degree - 5; // MIN error


  traydeg(-90,70);
  Rintake.move_absolute(degree,speed);
  Lintake.move_absolute(degree,speed);

  traydeg(-540,70);
}
void outtake(int degree, int speed)
{

  taredrive();//TARE drive

  Rintake.move_absolute(-degree,speed);
  Lintake.move_absolute(-degree,speed);

}
void release()
{
  taredrive();

  //int Terror = degree + 5; //MAX error
  //int Berror = degree - 5; // MIN error

  Tray.move_absolute(400, 23);
  pros::delay(3000);
  pumpout(1000);
  pros::delay(2000);
  //outtake(90, 50);
  //Tray.move_absolute(200, 10);
  Tray.move_velocity(10);
  while(true){
    if(Tray.get_actual_velocity()<10) break;
    pros::delay(20);
  }
  Tray.move_velocity(0);
  }
