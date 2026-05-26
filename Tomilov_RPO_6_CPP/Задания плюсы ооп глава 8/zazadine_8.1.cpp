#include <iostream>
#include <string>
#include <vector>
class Student{
    std::string name_;
    std::string gender_;
    std::string class_learning_;
    int age_;
    int id_;
    static int amount_students_;
public:
    Student(): name_("Не указано"), gender_("Не указан"),class_learning_("Не указан"),age_(-1),id_(amount_students_++){
    std::cout << "Студент создан " << "\n";    
    }
    Student(std::string name, std::string gender_, std::string class_learning, int age): name_(name),gender_(gender_),class_learning_(class_learning),age_(age),id_(amount_students_++)  {
        std::cout << "студент с ID: " << id_ << " был создан" << "\n"; 
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
        return amount_students_;
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
    void vivodStudents(){
        std::cout << "\n\t Имя: " << name_;
        std::cout << "\n\t Пол: " << gender_;
        std::cout << "\n\t Класс Обучения: " << class_learning_;
        std::cout << "\n\t Возраст: " << age_;
        std::cout << "\n\t ID: " << id_ << "\n";

    }
    ~Student(){
        std::cout << "\nСтудент был уничтожен" << "\n";
    }
};
int Student::amount_students_ = 0;
int main(){
    std::string name,gender,class_learning;
    int age;
    std::vector<Student> students{{},{"name","gender","5A",12},{"Антон","подлодка","7",42}};
    int cho, index, cho_kak;
    do{
        std::cout << "1.Добавление студента: \n2.Уничтожение студента\n3.Редактирование студента\n4.Вывод всех студентов(отсортированных по полю)\n>_: ";
        std::cin >> cho;
        if(cho == 1){
            std::cout << "В,ведите имя: ";
            std::cin >> name;
            std::cout << "\n";
            std::cout << "Введите пол: ";
            std::cin >> gender;
            std::cout << "\n";
            std::cout << "Ведите класс обучения: ";
            std::cin >> class_learning;
            std::cout << "\n";
            std::cout << "Введите возраст: ";
            std::cin >> age;
            std::cout << "\n";
            students.emplace_back(name,gender,class_learning,age);
        }
        if(cho == 2){
            std::cout << "Введите индекс студента которого уничтожить: ";
            std::cin >> index;
            if(index >= 0 && index < students.size()) students.erase(students.begin() + index);
        }
        if(cho == 3){
            std::cout << "Введите индекс студента которого редактировать: ";
            std::cin >> index;
            std::cout << "Введите имя: ";
            std::cin >> name;
            std::cout << "\n";
            std::cout << "Введите пол: ";
            std::cin >> gender;
            std::cout << "\n";
            std::cout << "Ведите класс обучения: ";
            std::cin >> class_learning;
            std::cout << "\n";
            std::cout << "Введите возраст: ";
            std::cin >> age;
            std::cout << "\n";
            students.at(index) = Student(name,gender,class_learning,age);
        }
        if(cho == 4){
            for(int i = 0; i < students.size(); i++){
                std::cout << "\n" << i;
                students.at(i).vivodStudents();
                
            }
            std::cout << "По какому полю сотировать?\n1.по имени\n2.по полу\n3.по классу обучения\n4.по возрасту\n5.по ID\n6565.Выход\n>_: ";
            std::cin >> cho;
            std::cout << "как сортировать?\n1.по возрастанию\n2.по убыванию\n>_: ";
            std::cin >> cho_kak;
            for (int i = 0; i < students.size(); i++) {
            for (int j = 0; j < students.size() - 1 - i; j++) {
			if (
				(cho == 1 && cho_kak == 1) && (students.at(j).getName() > students.at(j + 1).getName())
				||
				(cho == 1 && cho_kak == 2) && (students.at(j).getName() < students.at(j + 1).getName())
				||
				(cho == 2 && cho_kak == 1) && (students.at(j).getGender() > students.at(j + 1).getGender())
				||
				(cho == 2 && cho_kak == 2) && (students.at(j).getGender() < students.at(j + 1).getGender())
				||
				(cho == 3 && cho_kak == 1) && (students.at(j).getClassLearning() > students.at(j + 1).getClassLearning())
				||
				(cho == 3 && cho_kak == 2) && (students.at(j).getClassLearning() < students.at(j + 1).getClassLearning())
				||
				(cho == 4 && cho_kak == 1) && (students.at(j).getAge() > students.at(j + 1).getAge())
				||
				(cho == 4 && cho_kak == 2) && (students.at(j).getAge() < students.at(j + 1).getAge())
				||
				(cho == 5 && cho_kak == 1) && (students.at(j).getId() > students.at(j + 1).getId())
				||
				(cho == 5 && cho_kak == 2) && (students.at(j).getId() < students.at(j + 1).getId())
				) std::swap(students.at(j), students.at(j + 1));
            }
        }
            for(int i = 0; i < students.size(); i++){
                std::cout << "\n" << i;
                students.at(i).vivodStudents();
                
            }
        
    }

    }while(cho != 6565);
}