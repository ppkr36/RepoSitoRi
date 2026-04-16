#include <iostream>
#include <string>
#include <vector>
class Worker {
public:
	std::string name_;
	std::string surename_;
	std::string fathername_;
	std::string gender_;
	std::string position_;
	std::string departament_;
	int id_;
	int age_;
	Worker(int id) : name_{ "не указано" }, surename_{ "не указано" }, fathername_{ "не указано" }, gender_{ "не указано" }, position_{ "не указано" }, departament_{ "не указано" }, age_{ -1 } { id_ = id; }
	Worker(int id, std::string name) : Worker(id) { name_ = name; }
	Worker(int id, std::string name, std::string surename) : Worker(id, name) { surename_ = surename; }
	Worker(int id, std::string name, std::string surename, std::string fathername) : Worker(id, name, surename) { fathername_ = fathername; }
	Worker(int id, std::string name, std::string surename, std::string fathername, std::string gender) : Worker(id, name, surename, fathername) { gender_ = gender; }
	Worker(int id, std::string name, std::string surename, std::string fathername, std::string gender, std::string position) : Worker(id, name, surename, fathername, gender) { position_ = position; }
	Worker(int id, std::string name, std::string surename, std::string fathername, std::string gender, std::string position, std::string departament) : Worker(id, name, surename, fathername, gender, position) { departament_ = departament; }
	Worker(int id, std::string name, std::string surename, std::string fathername, std::string gender, std::string position, std::string departament, int age) : Worker(id, name, surename, fathername, gender, position, departament) { age_ = age; }
	~Worker() {
		std::cout << "\n" << "Работник с ID " << id_ << ", был ликвидирован\n";
	}
	void printWorkers() {
		std::cout << "\nID: " << id_ << "\n";
		std::cout << "Имя: " << name_ << "\n";
		std::cout << "Фамилия: " << surename_ << "\n";
		std::cout << "Отчество: " << fathername_ << "\n";
		std::cout << "Пол: " << gender_ << "\n";
		std::cout << "Возраст: " << age_ << "\n";
		std::cout << "Должность: " << position_ << "\n";
		std::cout << "Отдел: " << departament_ << "\n\n";
	}
};

int main() {
	system("chcp 1251");
	std::string name;
	std::string surename;
	std::string fathername;
	std::string gender;
	std::string position;
	std::string departament;
	int id;
	int age;
	std::vector<Worker> worksy{{2},{3},{4},{5},{55},{66},{241},{94},{6}};
	int cho = 99;
		while (cho != 0) {
			std::cout << "\n1.Вывести рабочих\n2.Редактировать рабочего\n3.Добавить рабочего\n4.Удалить рабочего\n0.Выход\n>_";
			std::cin >> cho;
			if (cho == 1) {
				if (worksy.size() != 0) {
					for (int i = 0; i < worksy.size(); i++) {
						std::cout << "\n" << i << '.';
						worksy.at(i).printWorkers();
					}
				}
				else std::cout << "\nРабочих нет\n";
			}
			if (cho == 2) {
				int index;
				std::cout << "Введите индекс рабочего: ";
				std::cin >> index;
				if (index <= worksy.size() && index > 0) {
					std::cin.ignore(1024, '\n');
					std::cout << "Имя: " << "\n";
					std::getline(std::cin, worksy.at(index).name_);
					std::cout << "Фамилия: " << "\n";
					std::getline(std::cin, worksy.at(index).surename_);
					std::cout << "Отчество: " << "\n";
					std::getline(std::cin, worksy.at(index).fathername_);
					std::cout << "Пол: " << "\n";
					std::getline(std::cin, worksy.at(index).gender_);
					std::cout << "Возраст: " << "\n";
					std::cin >> worksy.at(index).age_;
					std::cin.ignore(1024, '\n');
					std::cout << "Должность: " << "\n";
					std::getline(std::cin, worksy.at(index).position_);
					std::cout << "Отдел: " << "\n";
					std::getline(std::cin, worksy.at(index).departament_);
					system("cls");
				}
				else std::cout << "\nнекорректный индекс\n";
			}
			if (cho == 3) {
				std::cout << "ID: ";
				std::cin >> id;
				std::cin.ignore(1024, '\n');
				std::cout << "Имя: " << "\n";
				std::getline(std::cin, name);
				std::cout << "Фамилия: " << "\n";
				std::getline(std::cin, surename);
				std::cout << "Отчество: " << "\n";
				std::getline(std::cin, fathername);
				std::cout << "Пол: " << "\n";
				std::getline(std::cin, gender);
				std::cout << "Возраст: " << "\n";
				std::cin >> age;
				std::cin.ignore(1024, '\n');
				std::cout << "Должность: " << "\n";
				std::getline(std::cin, position);
				std::cout << "Отдел: " << "\n";
				std::getline(std::cin, departament);
				worksy.emplace_back(id, name, surename, fathername, gender, position, departament,  age);
				system("cls");
			}
			if (cho == 4) {
				int index;
				std::cout << "Введите индекс рабочего: ";
				std::cin >> index;
				if (index <= worksy.size() && index > 0) {
					worksy.erase(worksy.begin() + index);
				}
				else std::cout << "\nнекорректный индекс\n";
			}
			


	}
}