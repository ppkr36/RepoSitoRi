#include <iostream>
#include <istream>
#include <ostream>
class Squad {
  int archer_, spearman_, horseman_;

public:
  Squad() : archer_(0), spearman_(0), horseman_(0) {}
  Squad(int archer, int spearman, int horseman)
      : archer_(archer), spearman_(spearman), horseman_(horseman) {}
  int getSum() const { return (archer_ + spearman_ + horseman_); }
  void toNull() {
    this->archer_ = 0;
    this->spearman_ = 0;
    this->horseman_ = 0;
  }
  friend Squad operator+(Squad &left, Squad &right) {
    Squad mega_squad(left.archer_ + right.archer_,
                     left.spearman_ + right.spearman_,
                     left.horseman_ + right.horseman_);
    left.toNull();
    right.toNull();
    return mega_squad;
  }
  friend Squad &operator-(Squad &left, Squad &right) {
    if (left.getSum() > right.getSum()) {
      if (left.archer_ > right.archer_)
        left.archer_ -= right.archer_;
      else
        left.archer_ = 0;
      if (left.spearman_ > right.spearman_)
        left.spearman_ -= right.spearman_;
      else
        left.spearman_ = 0;
      if (left.horseman_ > right.horseman_)
        left.horseman_ -= right.horseman_;
      else
        left.horseman_ = 0;
      right.toNull();
      return left;
    }
    if (left.getSum() > right.getSum()) {
      if (right.archer_ > left.archer_)
        right.archer_ -= left.archer_;
      else
        right.archer_ = 0;
      if (right.spearman_ > left.spearman_)
        right.spearman_ -= left.spearman_;
      else
        right.spearman_ = 0;
      if (right.horseman_ > left.horseman_)
        right.horseman_ -= left.horseman_;
      else
        right.horseman_ = 0;
      left.toNull();
      return right;
    }
  }
  friend bool operator>(Squad &left, Squad &right) {
    return (left.getSum() > right.getSum());
  }
  friend bool operator<(Squad &left, Squad &right) {
    return (left.getSum() < right.getSum());
  }
  friend bool operator==(Squad &left, Squad &right) {
    return (left.getSum() == right.getSum());
  }
  friend std::istream &operator>>(std::istream &in, Squad &right) {
    in >> right.archer_;
    in >> right.spearman_;
    in >> right.horseman_;
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const Squad &right) {
    out << "Кол-во лучников " << right.archer_ << " " << "Кол-во копешеков "
        << right.spearman_ << " " << "Кол-во всадников " << right.horseman_;
    return out;
  }
};
int main() {
  Squad otryad1(3, 5, 2);
  Squad otryad2(3, 80, 6);
  std::cout << otryad1 << "\n";
  std::cout << otryad2 << "\n";
  std::cout << ((otryad1 > otryad2) ? "otryad1 больше" : "otryad2 больше")
            << "\n";
  std::cout << ((otryad1 < otryad2) ? "otryad2 больше" : "otryad2 больше")
            << "\n";
  std::cout << ((otryad1 == otryad2) ? "отряды равны" : "отряды не равны")
            << "\n";
  Squad otryad3 = otryad1 + otryad2;
  Squad otryad4(1, 1, 1);
  std::cout << otryad3 << "\n";
  std::cout << otryad1 << "\n";
  std::cout << otryad2 << "\n";
  std::cout << otryad4 << "\n";
  std::cout << otryad3 - otryad4 << "\n";
}
