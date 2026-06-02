#include <iostream>
class Body {
  int height_, weigth_;

public:
  Body() : height_(0), weigth_(0) {}
  Body(int height, int weigth) : height_(height), weigth_(weigth) {}
  void printInfo() {
    std::cout << "высота: " << height_ << "\n" << "масса: " << weigth_ << "\n";
  }
};
class AreaBody : public Body {
  int x_, y_, z_;

public:
  AreaBody(int x, int y, int z) : x_(x), y_(y), z_(z) {}
};
int main() {
  Body bob(2000, 4000);
  bob.printInfo();
  AreaBody area_bob(-2204, 5000, 11);
  area_bob.printInfo();
}
