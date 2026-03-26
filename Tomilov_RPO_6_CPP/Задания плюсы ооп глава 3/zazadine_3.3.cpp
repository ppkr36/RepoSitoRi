#include <iostream>
#include <vector>
#include <string>
class Planet {
public:
	std::string atmospheric_composition_, name_;
	double mass_;
	int amount_sputniks_, davlenie_;
	Planet() {
		std::cout << "Введите массу планеты: ";
		std::cin >> mass_;
		std::cin.ignore(1024, '\n');
		std::cout << "Введите название планеты: ";
		std::getline(std::cin, name_);
		std::cout << "Введите состав атмосферы: ";
		std::getline(std::cin, atmospheric_composition_);
		std::cout << "Введите кол-во спутников: ";
		std::cin >> amount_sputniks_;
		std::cout << "Введите давление: ";
		std::cin >> davlenie_;
		std::cout << "\n";
	}
	Planet(std::string& atmospheric_composition, std::string& name, double& mass, int& amount_sputniks,int& davlenie) {
		atmospheric_composition_ = atmospheric_composition;
		name_ = name;
		mass_ = mass;
		amount_sputniks_ = amount_sputniks;
		davlenie_ = davlenie;
	}
	void planetVivod() {
		std::cout << name_ << ":\n\t" << "Масса " << mass_ << " масс Земли\n\t" << "Состав атмосферы: " << atmospheric_composition_ << "\n\t" << "Давление у поверхности: " << davlenie_ << "\n\t" << "Количество спутников: " << amount_sputniks_ << "\n\n";
	}
};
int main() {
	system("chcp 1251");
	std::cout << "Введите кол-во планет в системе: ";
	int amount;
	std::cin >> amount;
	std::vector<Planet> solar_system;
	solar_system.emplace_back("Воздух", "Земля", 1, 1, 33);
	solar_system.emplace_back("Не воздух", "Марс", 1.12, 2, 4);
	std::vector<Planet> system_of_planets(amount);
	for (int i = 0; i < amount; i++) {
		system_of_planets.at(i).planetVivod();
	}
}