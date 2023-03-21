#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
using namespace std;
class Vehicle {
private:
  int id;       // car id number
  int age;      // how old the car is
  double price; // car's MSRP price
protected:
  string modelNo;

public:
  Vehicle() : id{0}, age{0}, price{0.0} {}
  Vehicle(int id, int age, double price) : id{id}, age{age}, price{price} {}
  int getId() { return id; }
  int getAge() { return age; }
  double getPrice() { return price; }
  // mutators
  void setId(int id) { this->id = id; }
  void setAge(int age) { this->age = age; }
  void setPrice(double price) { this->price = price; }
  // Every vehicle will set a model no using id and their type
  virtual void setModelNo(string modelName) = 0;
  virtual string print() {
    string statement = "Id:" + to_string(id) + " Age: " + to_string(age) +
                       " Price:$" + to_string(price);
    return statement;
  }
  virtual ~Vehicle(){};


};
#endif