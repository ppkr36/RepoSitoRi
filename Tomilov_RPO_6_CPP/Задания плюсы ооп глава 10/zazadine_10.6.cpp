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
  Dice(int weight, int x, int y, int z, float bounce)
      :num_(4), Body(weight, x, y, z, bounce) {}
  void printCoordinates() {
      std::cout << "x: " << x_ << " " << "y: " << y_ << " " << "z: " << z_ << "\n";
  }
  int droplt(int force) {
      int cuda_letit = 1 + rand() % 3;
      switch (cuda_letit) {
      case 1:
          if ((rand() % 2) == 1) {
              x_ += (force * (1 + rand() % 12)) / weight_;
          }
          else {
              x_ -= (force * (1 + rand() % 12)) / weight_;
          }
          break;
      case 2:
          if ((rand() % 2) == 1) {
              y_ += (force * (1 + rand() % 12)) / weight_;
          }
          else {
              y_ -= (force * (1 + rand() % 12)) / weight_;
          }
          break;
      case 3:
          if ((rand() % 2) == 1) {
              x_ += (force * (1 + rand() % 12)) / weight_;
              y_ += (force * (1 + rand() % 12)) / weight_;
          }
          else {
              y_ -= (force * (1 + rand() % 12)) / weight_;
              x_ -= (force * (1 + rand() % 12)) / weight_;
          }
          break;
      }
    unsigned int kak_letit = 0;
    if (x_ >= 0) kak_letit += x_;
    else kak_letit += (x_*-1);
    if (y_ >= 0) kak_letit += y_;
    else kak_letit += (y_ * -1);
    for (int i = 0; i < kak_letit; i++) {
        if (i == kak_letit - 1) {
            num_ = 1 + rand() % 6;
            std::cout << "\nПо итогу выпало число " << num_ << "\n";
            return num_;
        }
        std::cout << "Куб летит и на нём число " << 1+rand()%6 << "\n";
    }
  }

};
class Ball : public Body {
    float jump_height_;
public:
    Ball(int weight, int x, int y, int z, float bounce) : Body(weight, x, y, z, bounce) {}
    int droplt(int force) {
        jump_height_ = (z_ * (double(force) * bounce_)) + (weight_ / 10);
        double max = jump_height_;
            std::cout << "Мяч брошен с высоты " << z_ << " и он отскочил на: " << jump_height_ << "\n";
        for (int i = 0; i < z_; i++) {
            if (jump_height_ > 0.0001) {
                std::cout << "После " << i + 1 << " отскока мяч отскочил на: " << (jump_height_ *= bounce_) << "\n";
            }
            else {
                std::cout << "Мяч упал\n";
                return max;
            }
        }
    }
};
int main() { 
    system("chcp 65001");
    srand(static_cast<int>(time(0))); 
    Dice dice(2,2,2,2,2);
    int num_of_dice = dice.droplt(1);
    dice.printCoordinates();
    Ball ball(1,2,2,19,0.4);
    int ball_jump_jump=ball.droplt(4);

}
