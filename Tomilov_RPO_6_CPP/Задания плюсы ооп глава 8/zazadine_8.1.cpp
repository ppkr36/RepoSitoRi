#include <iostream>
#include <string>
#include <vector>
class Student{
    std::string name_;
    std::string gender_;
    std::string class_learning_;
    int age_;
    int id_;
    static int amount_students;
public:
    Student(){
        
    }         
    std::string getName() const{
        return name_;
    }
    std::string getGender() const{
        return gender_;
    }
    std::string getClassLearning() const{
        return class_learning_;
    }
    int getAge() const{
        return age_;
    }
    int getId() const{
        return id_;
    }
    static int getAmountStudents() {
        return amount_students;
    }
    int main(){
        Student stud;
    }
    Student& setName(std::string name){
        if(!name.empty()) name_ = name;
        return *this;
    }
    Student& setGender(std::string gender){
        if(!gender.empty()) gender_ = gender;
        return *this;
    }
    Student& setClassLearning(std::string class_learning){
        if(!class_learning.empty()) class_learning_ = class_learning;
        return *this;
    }
    Student& setAge(int age){
        if(age >=0) age_ = age;
        return *this;
    }
};