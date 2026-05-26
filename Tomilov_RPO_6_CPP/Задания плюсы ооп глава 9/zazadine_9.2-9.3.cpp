#include <iostream>
#include <exception>
class MyArray{
int* arr_ptr_;
int size_;
public:
MyArray(): arr_ptr_{nullptr},size_(0){}
MyArray(int size){
    size_ = size;
    arr_ptr_ = new int[size_];
    for(int i = 0; i < size_; i++){
        arr_ptr_[i] = 0;
    }
}

int& operator[](int index){
if(index < size_ && index >= 0){
    return arr_ptr_[index];
}
else throw std::out_of_range("всё за пределы вышло");
}
MyArray& operator++(int){
    int* arr_copy = new int[size_+=1];
    arr_copy[size_-1] = 0;
    for(int i =0; i<size_;i++)  arr_copy[i] = arr_ptr_[i];
    delete[] arr_ptr_;
    arr_ptr_ = arr_copy;
    delete[] arr_copy;
    return *this;
}
MyArray& operator--(int){
        int* arr_copy = new int[size_-=1];
    for(int i =0; i<size_;i++)  arr_copy[i] = arr_ptr_[i];
    delete[] arr_ptr_;
    arr_ptr_ = arr_copy;
    delete[] arr_copy;
    return *this;
}
MyArray operator-() const{
    MyArray copy_arr(size_);
     for(int i =0; i<size_;i++){
        copy_arr.arr_ptr_[i] = -arr_ptr_[i];
    }
    return copy_arr;
}
operator int()const{
    return size_;
}
friend std::ostream& operator<<(std::ostream&,const MyArray&);
friend std::istream& operator>>(std::istream&,MyArray&);
friend MyArray operator+(MyArray&,MyArray&);
};

std::ostream& operator<<(std::ostream& out,const MyArray& obj){
    for(int i = 0; i < obj.size_; i++){
        out << obj.arr_ptr_[i] << " ";
    }
    return out;
}
std::istream& operator>>(std::istream& in,MyArray& obj){
    for(int i = 0; i < obj.size_; i++){
        in >> obj.arr_ptr_[i]; 
    }
    return in;
}
MyArray operator+(MyArray& left, MyArray& right){
MyArray plusarr(left.size_ + right.size_);
for(int i = 0; i < left.size_;i++){
    plusarr.arr_ptr_[i] = left.arr_ptr_[i];
}
for(int i = 0; i < right.size_; i++){
    plusarr.arr_ptr_[i+left.size_] = right.arr_ptr_[i];
}
return plusarr;

}
int main(){
MyArray arr(3);
std::cin >> arr;
std::cout << arr << '\n';
arr++;
std::cout << "размер массива: "  << (int)arr << "\n";
std::cout <<arr << '\n';
arr--;
std::cout << arr << '\n';
std::cout << -arr << '\n';
std::cout << "размер массива: "  << (int)arr << "\n";
std::cout << arr << '\n';
std::cout << arr + arr << '\n';
}