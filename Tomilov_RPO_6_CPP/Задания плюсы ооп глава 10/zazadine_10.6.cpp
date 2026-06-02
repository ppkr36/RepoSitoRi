#include <cstdlib>
#include <iostream>
class Body {
protected:
  int weight_, x_, y_, z_;
  float bounce_;

private:
  int id;
  static int amount;

public:
  virtual int droplt(int force) = 0;
  Body(int weight, int x, int y, int z, float bounce)
      : id(++amount), weight_(weight), x_(x), y_(y), z_(z), bounce_(bounce) {};
};
int Body::amount = 0;

class Dice : public Body {
  int num_;

public:
  Dice(int num, int weight, int x, int y, int z, float bounce)
      : num_(num), Body(weight, x, y, z, bounce) {}
  int droplt(int force) {
    int cuda_letit = 1 + rand() % 3;
    switch (cuda_letit) {
    case 1:
      if ((rand() % 2) == 1) {
        x_ += (force * (1 + rand() % 12)) / weight_;
      } else {
        x_ -= (force * (1 + rand() % 12)) / weight_;
      }
      break;
    case 2:
      if ((rand() % 2) == 1) {
        y_ += (force * (1 + rand() % 12)) / weight_;
      } else {
        y_ -= (force * (1 + rand() % 12)) / weight_;
      }
      break;
    case 3:
      if ((rand() % 2) == 1) {
        x_ += (force * (1 + rand() % 12)) / weight_;
        y_ += (force * (1 + rand() % 12)) / weight_;
      } else {
        y_ -= (force * (1 + rand() % 12)) / weight_;
        x_ -= (force * (1 + rand() % 12)) / weight_;
      }
      break;
    }
    if (x_ > 0)
  }
};
class Ball : public Body {};
int main() { srand(static_cast<int>(time(0))); }
