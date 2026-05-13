#include <iostream>
#include <vector>
#include <string>
class Planet {
	std::string atmospheric_composition_, name_;
	double mass_;
	int amount_sputniks_, davlenie_;
public:
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
	Planet(std::string atmospheric_composition, std::string name, double mass, int amount_sputniks, int davlenie) : atmospheric_composition_{ atmospheric_composition }, name_{ name }, mass_{ mass }, amount_sputniks_{ amount_sputniks }, davlenie_{ davlenie } {};
	void planetVivod() {
		std::cout << name_ << ":\n\t" << "Масса " << mass_ << " масс Земли\n\t" << "Состав атмосферы: " << atmospheric_composition_ << "\n\t" << "Давление у поверхности: " << davlenie_ << "\n\t" << "Количество спутников: " << amount_sputniks_ << "\n\n";
	}
	Planet& setAtmosphericComposition(std::string atmospheric_composition){ 
		if(atmospheric_composition != "") atmospheric_composition_ = atmospheric_composition;
		return *this;
	}
	Planet& setName(std::string name) {
		if (name != "")name_ = name;
		return *this;
	}
	Planet& setMass(double mass) {
		if (mass > 0) mass_ = mass;
		return *this;
	}
	Planet& setAmountSputniks(int amount_sputniks) {
		if (amount_sputniks >= 0) amount_sputniks_ = amount_sputniks;
		return *this;
	}
	Planet& setDavlenie(int davlenie) {
		if (davlenie >= 0) davlenie_ = davlenie;
		return *this;
	}
	std::string getAtmosphericComposition() const { return atmospheric_composition_; }
	std::string getName() const { return name_; }
	double getMass() const { return mass_; }
	int getAmountSputniks() const { return amount_sputniks_; }
	int getDavlenie() const { return davlenie_; }
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
	int cho = 0;
	int cho_kak = 0;
	std::cout << "Введите по какому полю, отсортировать планеты: \n1.По имени\n2.По составу атмосферы\n3.По массе\n4.По кол-ву спутников\n5.По давлению\n>_ ";
	std::cin >> cho;
	std::cout << "Введите как сортировать\n1.По возрастанию\n2.По убыванию";
	std::cin >> cho_kak;
	for (int i = 0; i < system_of_planets.size(); i++) {
		for (int j = 0; j < system_of_planets.size() - 1 - i; j++) {
			if (
				(cho == 1 && cho_kak == 1) && (system_of_planets.at(j).getName() > system_of_planets.at(j + 1).getName())
				||
				(cho == 1 && cho_kak == 2) && (system_of_planets.at(j).getName() < system_of_planets.at(j + 1).getName())
				||
				(cho == 2 && cho_kak == 1) && (system_of_planets.at(j).getAtmosphericComposition() > system_of_planets.at(j + 1).getAtmosphericComposition())
				||
				(cho == 2 && cho_kak == 2) && (system_of_planets.at(j).getAtmosphericComposition() < system_of_planets.at(j + 1).getAtmosphericComposition())
				||
				(cho == 3 && cho_kak == 1) && (system_of_planets.at(j).getMass() > system_of_planets.at(j + 1).getMass())
				||
				(cho == 3 && cho_kak == 2) && (system_of_planets.at(j).getMass() < system_of_planets.at(j + 1).getMass())
				||
				(cho == 4 && cho_kak == 1) && (system_of_planets.at(j).getAmountSputniks() > system_of_planets.at(j + 1).getAmountSputniks())
				||
				(cho == 4 && cho_kak == 2) && (system_of_planets.at(j).getAmountSputniks() < system_of_planets.at(j + 1).getAmountSputniks())
				||
				(cho == 5 && cho_kak == 1) && (system_of_planets.at(j).getDavlenie() > system_of_planets.at(j + 1).getDavlenie())
				||
				(cho == 5 && cho_kak == 2) && (system_of_planets.at(j).getDavlenie() < system_of_planets.at(j + 1).getDavlenie())
				) std::swap(system_of_planets.at(j), system_of_planets.at(j + 1));
		}
	}
	for (int i = 0; i < amount; i++) {
		system_of_planets.at(i).planetVivod();
	}
}