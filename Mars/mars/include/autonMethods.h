#pragma once
#include "main.h"

class autonMeth{
  private:
    void resetDriveEncoders();
    float averageEncoderValues();
  public:
    autonMeth(int h);
    void moveDriveMotors(int left, int right); //sets motors to a voltage
    void setDriveHold();
    void moveDistancePID(int distance, int Maxspeed, int timeout);
    void turnGyroPID();
};
