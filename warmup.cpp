#include "boat.h"
#include "car.h"
#include "hybridcar.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  // creates vectors of car and boat classes
  vector<Vehicle *> vehicle_list;
  // reads in from inventory.dat file
  ifstream fin("inventory.dat");
  // variable to hold information from inventory.dat file
  string info = "";
  // variable to determine what kind of vehicle each line of the file is
  // describing
  string vehicle = "";
  // variables for the information of the car and boat
  int id = 0;
  double price = 0.0;
  int age = 0;
  double tankSize = 0.0;
  int maxMPH = 0;
  bool isRed;
  string isYacht = "";
  int length = 0;

  // loop through each line of the file
  while (getline(fin, info)) {
    // split lines into individual words
    istringstream sin(info);
    sin >> vehicle;
    // if statements to find if vehicle is a car or boat
    if (vehicle == "car" || vehicle == "hybridcar") {
      double batteryRange;
      // puts each word in line into it's individual variable
      sin >> id >> price >> age >> tankSize >> maxMPH >> boolalpha >>
          isRed; // using boolalpha to set isRed value
      Vehicle *hc;
      if (vehicle == "hybridcar") {
        sin >> batteryRange;
        hc = new HybridCar(id, age, price, tankSize, maxMPH, isRed,
                           batteryRange);
      } else {
        hc = new Car{id, age, price, tankSize, maxMPH, isRed};
      }
      hc->setModelNo(vehicle);
      // puts object into class vector
      vehicle_list.push_back(hc);
    } else if (vehicle == "boat") {
      sin >> id >> price >> age >> isYacht >> length;
      bool isYachtBool = false;
      if (isYacht == "true")
        isYachtBool = true;
      Boat *boat = new Boat(id, age, price, length, isYachtBool);
      boat->setModelNo(vehicle);
      vehicle_list.push_back(boat);
    }
  }
  fin.close();

  // for loops using print function to print out information of each vehicle in
  // the vectors
  ofstream outfile("report.dat");
  for (int i = 0; i < vehicle_list.size(); ++i) {
    cout << vehicle_list.at(i)->print();
    outfile << vehicle_list.at(i)->print();
  }
  outfile.close();

  // Do something useful with this data, then delete the objects when
  // you're done
  for (int i = 0; i < vehicle_list.size(); ++i) {
    delete vehicle_list[i]; // Note that this is deleting object pointer
  }

  vehicle_list
      .clear(); // We will purge the contents so no one tries to delete them
}
