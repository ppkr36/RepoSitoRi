#include <iostream>
class Old {
public:
  virtual void print() { std::cout << "я Old" << "\n"; }
};
class Nouveau : public Old {
public:
  void print() { std::cout << "я Nouveau" << "\n"; }
};
int main() {
  Old old;
  Nouveau nouveau;
  old.print();
  nouveau.print();
  Old *old_ptr = new Old;
  old_ptr->print();
  Old *old_nouveau_ptr = new Nouveau;
  old_nouveau_ptr->print();
}
