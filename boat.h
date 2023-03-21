#ifndef _BOAT_H
#define _BOAT_H
#include "vehicle.h"
#include <iostream>
using namespace std;

// class to hold the information about a boat
class Boat : public Vehicle {

private:
  bool isYacht; // is the boat a yacht or not
  int length;   // length of the boat in feet

public:
  // constructor
  Boat();
  Boat(int id, int age, double price, int length, bool isYacht);
  bool getIsYacht();
  int getLength();
  // mutators
  void setIsYacht(bool boatIsYacht);
  void setLength(int boatLength);
  // function to print out all features of the boat
  string print();
  void setModelNo(string modelName);
};

#endif
