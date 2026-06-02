#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Vehicle {
protected:
  std::string mark_;
  int runbeg_;

public:
  Vehicle(std::string mark, int runbeg) : runbeg_(runbeg), mark_(mark) {}
  virtual void print() = 0;
};
void Vehicle::print() { std::cout << mark_ << "\t" << runbeg_ << "km "; }
class Car : public Vehicle {
  bool is_active_;

public:
  Car(std::string mark, int runbeg, bool is_active)
      : is_active_(is_active), Vehicle(mark, runbeg) {}
  void print() {
    Vehicle::print();
    std::cout << (is_active_ ? " доступна" : " недоступна") << "\n";
  }
};
class Bus : public Vehicle {
  int capacity_;

public:
  Bus(std::string mark, int runbeg, int capacity)
      : capacity_(capacity), Vehicle(mark, runbeg) {}
  void print() {
    Vehicle::print();
    std::cout << " и вместимостью " << capacity_ << "\n";
  };
};
int main() {
  std::vector<std::unique_ptr<Vehicle>> garage;
  garage.emplace_back(std::make_unique<Car>("Машина", 2000, 1));
  garage.emplace_back(std::make_unique<Bus>("Автобус", 999999, 200));
  for (int i = 0; i < garage.size(); i++) {
    garage.at(i)->print();
  }
}
