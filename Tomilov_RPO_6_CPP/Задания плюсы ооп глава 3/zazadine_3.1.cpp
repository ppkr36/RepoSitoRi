#include <iostream>
#include <string>
#include <vector>
class MyCar
{
public:
	std::string mark_;
	std::string country_;
	int probeg_;
	int year_;
	int power_;
		 
		MyCar() {
		std::cout << "\nВведите марку: ";
		std::cin.ignore();
		std::getline(std::cin, mark_);
		std::cout << "Введите страну-производитель: ";
		std::cin >> country_;
		std::cout << "Введите пробег: ";
		std::cin >> probeg_;
		std::cout << "Введите год выпуска: ";
		std::cin >> year_;
		std::cout << "Введите мощь: ";
		std::cin >> power_;
		std::cout << '\n';
	}
		void vivod() {
			std::cout << "Машина:\n\t" << mark_ << "\n\tПроизводитель: " << country_ << "\n\tМощь: " << power_ << " л.с.\n\t" <<year_ << " года выпуска\n\tпробег: " <<probeg_<<'\n';
		}
};
int main() {
	system("chcp 1251");
	int count;
	std::cout << "Введите кол-во машин: ";
	std::cin >> count;
	std::vector<MyCar> cars(count);
	for (int i = 0; i < cars.size(); i++) {
		for (int j = 0; j < cars.size() - 1; j++) {
			if (cars.at(j).year_ > cars.at(j + 1).year_) {
				std::swap(cars.at(j), cars.at(j + 1));
			}
		}
	}

	for (int i = 0; i < cars.size(); i++) {
		cars.at(i).vivod();
	}
	
	
}