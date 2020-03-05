#include "main.h"
//////////////////////////////////////////////////////////////////
//DRIVE METHODS /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

//extern void basic();

extern void taredrive();
extern void tareintray();
extern void eat(int value);
extern void day(int value, int time);
extern int enavg();
extern void traydeg(int degree,int speed);
extern void negtraydeg(int degree,int speed);
extern void intakedeg(int degree,int speed);
extern void moveDeg(int degree,int speed); //move a set amount of degrees
extern void RmoveDeg(int degree,int speed);
extern void LmoveDeg(int degree,int speed);
extern void turny(int value,int time);
extern void turnyR (int value,int time);
extern void pumpout(int time);
extern void pumpin(int time);
extern void ew(int degree, int speed);
extern void outtaketray(int degree, int speed);
extern void release();
extern void outtake(int degree, int speed);
