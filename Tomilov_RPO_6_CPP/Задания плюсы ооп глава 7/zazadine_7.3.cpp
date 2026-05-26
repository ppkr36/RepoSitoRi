#include <vector>
#include <iostream>
class DynamicClass{
    public:
int* size_ = new int(2);
int* arr_ = new int[*size_];
DynamicClass(DynamicClass&& other) noexcept{
    std::cout << "\nСработал конструктор переноса из " << other.arr_ << " в " << arr_ << "\n";
    size_ = other.size_;
    arr_ = other.arr_;
    other.size_ = nullptr;
    other.arr_ = nullptr;
}
DynamicClass(){
std::cout << "\nСработал конструктор по умолчанию " <<arr_<< "\n";
    size_ = nullptr;
    arr_ = nullptr;
}
DynamicClass(int num, std::vector<int> vec_nums){
    *size_ = num;
    arr_ = new int[*size_];
    std::cout << "\nСработал конструктор с параметром и создал массив размером " << *size_ << " по адресу " << arr_ << "\n" ;
    for(int i = 0; i < *size_; i++){
    arr_[i] = vec_nums.at(i);
}
}
~DynamicClass(){
    std::cout << "\nСработал деструктор " << arr_<<" \n";
    delete[] arr_;
    delete size_;
}
};
int main(){
std::vector<DynamicClass>objects(2);
objects.push_back(DynamicClass(3, {1, 2, 3}));
}