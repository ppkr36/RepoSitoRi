#include <iostream>
#include <string>
#include <vector>
class Vehicle {
protected:
  std::string mark_;
  int runbeg_;

public:
  Vehicle(std::string mark, int runbeg) : runbeg_(runbeg), mark_(mark) {}
  virtual void print() {}
};
class Car : public Vehicle {
  bool is_active_;

public:
  Car(std::string mark, int runbeg, bool is_active)
      : is_active_(is_active), Vehicle(mark, runbeg) {}
  void print() {
    std::cout << "Машина " << mark_ << " с пробегом  " << runbeg_ << "km "
              << (is_active_ ? " доступна" : " недоступна") << "\n";
  }
};
class Bus : public Vehicle {
  int capacity_;

public:
  Bus(std::string mark, int runbeg, int capacity)
      : capacity_(capacity), Vehicle(mark, runbeg) {}
  void print() {
    std::cout << "Автобус " << mark_ << " с пробегом " << runbeg_ << "km "
              << " и вместимостью " << capacity_ << "\n";
  };
};
int main() {
  std::vector<Vehicle *> garage;
  garage.emplace_back(new Car("Машина", 2000, 1));
  garage.emplace_back(new Bus("Автобус", 999999, 200));
  for (int i = 0; i < garage.size(); i++) {
    garage.at(i)->print();
  }
  for (int i = 0; i < garage.size(); i++) {
    delete garage.at(i);
  }
}
