#include "car.h"
#include<sstream>
Car::Car()
  : tankSize{0.0}, maxMPH{0}, isRed{false}
{}
Car::Car(int id, int age, double price, double ts, int mMph, bool iR):
Vehicle(id,age,price),tankSize{ts},maxMPH{mMph},isRed{iR}{}

double Car::getTankSize() {
  return tankSize;
}

int Car::getMaxMPH() {
  return maxMPH;
}

bool Car::getIsRed() {
  return isRed;
}

void Car::setTankSize(double carTankSize) {
  tankSize = carTankSize;
}

void Car::setMaxMPH(int carMaxMPH) {
  maxMPH = carMaxMPH;
}

void Car::setIsRed(bool carIsRed) {
  isRed=carIsRed;
}

string Car::print() {
  string carInfo;
  string isRedorNo="is not red";
  if (isRed == true) {
    isRedorNo="is red";
    }
  ostringstream oss;
  oss<<"-------------------------------------"<<endl;
  oss<<"Model: "<<Vehicle::modelNo<<endl;
  oss<<Vehicle::print()<<endl;
  oss<<"Tank Size:"<<tankSize<<" Max_mph:"<<maxMPH<< " Color: "<<isRedorNo<<endl;
  return oss.str();
}
void Car::setModelNo(string modelName){
  modelNo=modelName+"_C"+to_string(getId());

}


