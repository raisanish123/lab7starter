#include "boat.h"
#include<sstream>
Boat::Boat() 
  : isYacht{false}, length{0}
{}
Boat::Boat(int id, int age, double price, int length, bool isYacht):Vehicle(id,age,price),length{length},isYacht{isYacht}{}

bool Boat::getIsYacht() {
  return isYacht;
}

int Boat::getLength() {
  return length;
}

void Boat::setIsYacht(bool boatIsYacht) {
    isYacht = boatIsYacht;
}

void Boat::setLength(int boatLength) {
  length = boatLength;
}
string Boat::print() {
  string carInfo;
  string isItYatch="is not yatch";
  if (isYacht == true) {
    isItYatch="is yatch";
    }
  ostringstream oss;
  oss<<"-------------------------------------"<<endl;
  oss<<"Model: "<<Vehicle::modelNo<<endl;
  oss<<Vehicle::print()<<endl;
  oss<<"Length:"<<length<< " Type: "<<isItYatch<<endl;
  return oss.str();
  //cout<<"-------------------------------------"<<endl;
}
void Boat::setModelNo(string modelName){
  modelNo=modelName+"_B"+to_string(getId());

}




