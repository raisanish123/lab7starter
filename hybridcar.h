#ifndef _HYBRIDCAR_H
#define _HYBRIDCAR_H
#include "car.h"
#include <sstream>
class HybridCar:public Car{
  private:
    double batteryRange;
  public:
       HybridCar(int id, int age, double price, double ts, int mMph, bool iR,double bR):Car{id,age,price,ts,mMph,iR},batteryRange{bR}{}
void setBatteryRange(double br){
  batteryRange=br;
}  
string print(){
  ostringstream oss;
  oss<<  Car::print();
    oss<<"Battery Range: " <<batteryRange<<endl;
  return oss.str();
  }
};
#endif