#include <iostream>
#include <string>
#include <vector>
class Student {
public:
	std::string name_;
	std::string class_;
	int age_;
	int id_;
	Student() {
		std::cout << "Студент был создан!" << '\n';
		name_ = "unknown";
		class_ = "null";
		age_ = 0;
		id_ = 1;
	}
	~Student() {
		std::cout << "Студент " << name_ << "(#" << id_ << ") << был ликвидирован" << "\n";
	}
	void redactStudent() {
		std::cout << "Введите уникальный номер студента: ";
		std::cin >> id_;
		std::cout << "\nВведите имя студента >_:";
		std::cin.ignore();
		std::getline(std::cin, name_);
		std::cout << "\nВведите возраст студента >_:";
		std::cin >> age_;
		std::cout << "\nВведите класс обучения >_:";
		std::cin.ignore();
		std::getline(std::cin, class_);
	}
	void vivod() {
		std::cout << "Студент #-" << id_ << "\n\t" << name_ << "\n\t" << age_ << " лет\n\t" << class_<<'\n';
	}
};
int main() {
	system("chcp 1251");
	std::cout << "Введите кол-во студентов: ";
	int count, choice = 0,student_choice;
	std::cin >> count;
	if (count != 0 && count > 0) {
		std::vector<Student> students(count);
		while (choice != 2) {
			for (int i = 0; i < students.size(); i++) {
				std::cout << i << '.'; students.at(i).vivod();
			}
			std::cout << "Введите что хотите: ";
			std::cout << "\n1. Отредактировать студента\n2. Выход\n>_:";
			std::cin >> choice;
			if (choice == 1) {
				std::cout << "Введите порядковый номер студента: ";
				std::cin >> student_choice;
				if (student_choice <= students.size() && student_choice >= 0) {
					students.at(student_choice).redactStudent();
				}
			}
			system("cls");
		}
	}
}