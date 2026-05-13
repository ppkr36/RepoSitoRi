#include <iostream>
class Array{
int* arr_ = new int[2];
public:
Array(){
    *(arr_) = 9;
    *(arr_ + 1) = 23;
    std::cout << "\nСработал конструктор по умолчанию \n";  
}
~Array(){
    std::cout << "\nСработал деструктор \n";
}
void printinfo(){
std::cout <<  "\nАдресс массива:" << arr_<< "\n";
std::cout <<  "\nАдресс первого элемента:" <<*(arr_+1)<< ": " << arr_[0] << "\n";
std::cout <<  "\nАдресс второго элемента "<<*(arr_+1) <<  ": " << arr_[1]<< "\n";
}
      
int main(){
    Array arr;
    arr.printinfo();
    return 0;
}
};