#ifndef _CAR_H
#define _CAR_H
#include "vehicle.h"
#include <iostream>
using namespace std;

// class to hold the information about a car

class Car : public Vehicle {

private:
  double tankSize; // how many gallons the tank can hold
  int maxMPH;      // top speed car can go
  bool isRed;      // is the car red or not

public:
  // constructor
  Car();
  Car(int id, int age, double price, double ts, int mMph, bool iR);
  // accessors
  double getTankSize();
  int getMaxMPH();
  bool getIsRed();
  // mutators
  void setTankSize(double carTankSize);
  void setMaxMPH(int carMaxMPH);
  void setIsRed(bool carIsRed);
  void setModelNo(string modelName);

  // function to print out all features of the car
  string print();
};

#endif
