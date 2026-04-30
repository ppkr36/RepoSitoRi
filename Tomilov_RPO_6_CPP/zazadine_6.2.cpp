#include <iostream>
#include <vector>
#include <string>
class Company {
	std::string name_;
	const bool is_private_;
	int income_, expenses_, turnover_ = income_ + expenses_, net_profit_ = income_ - expenses_;
public:
	Company(std::string name, const bool is_private, int income, int expenses) : name_{ name }, is_private_{ is_private }, income_{ income }, expenses_{ expenses } {}

	Company& setName(std::string name) {
		if (name != "") name_ = name;

		return *this;
	}
	Company& setIncome(int income) {
		income_ = income;
		turnover_ = income_ + expenses_;
		net_profit_ = income_ - expenses_;
		return *this;
	}
	Company& setExpenses(int expenses) {
		if (expenses >= 0) {
			expenses_ = expenses;
			turnover_ = income_ + expenses_;
			net_profit_ = income_ - expenses_;
		}
		return *this;
	}
	std::string getName() const { return name_; }
	const bool getIsPrivate() const { return is_private_; }
	int getIncome() const {
		if (is_private_ == true && expenses_ >= 5000000) return income_;
		else if (is_private_ == false) throw std::exception("у гос.компаний нельзя получить доход");
		else if (expenses_ < 5000000 && is_private_ == true) throw std::exception("у частных компаний с оборотом меньше 5000000 нельзя получить доход");
	}
	int getExpenses() const {
		if (is_private_ == true && expenses_ >= 5000000) return expenses_;
		else if (is_private_ == false) throw std::exception("у гос.компаний нельзя получить расход");
		else if (expenses_ < 5000000 && is_private_ == true) throw std::exception("у частных компаний с оборотом меньше 5000000 нельзя получить расход");
	}
	int getTurnover() const {
		if (is_private_ == true && expenses_ >= 5000000) return turnover_;
		else if (is_private_ == false) return turnover_;
		else if (expenses_ < 5000000 && is_private_ == true) throw std::exception("у частных компаний с оборотом меньше 5000000 нельзя получить оборот");
	}
	int getNetProfit() const {
		if (is_private_ == true && expenses_ >= 5000000) return net_profit_;
		else if (is_private_ == false) throw std::exception("у гос.компаний нельзя получить чистую прибыль");
		else if (expenses_ < 5000000 && is_private_ == true) throw std::exception("у частных компаний с оборотом меньше 5000000 нельзя получить чистую прибыль");
	}
	void vivodCompany() {
		std::cout << "Имя компании: " << getName()<<"\n";
		std::cout << "Тип компании: " << (getIsPrivate() == false) ? "государственная\n" : "частная\n";
		std::cout << "Доход компании: " << getIncome() << "\n";
		std::cout << "Расход компании: " << getExpenses() << "\n";
		std::cout << "Оборот компании: " << getTurnover() << "\n";
		std::cout << "Чистая прибыль: " << getNetProfit() << "\n";
	}
};
	int main() {
		system("chcp 1251");
		std::vector<Company> companies{{"миржелтокаяяйцо", true, 10000000, 10000000},{"ГАЗНЕФТЬГАЗГАЗ", false, 100000000, 400},{"ООО тмыв денег", true, 1000000, 1000000} };
		int cho;
		do {
			std::cout << "\n1.Вывести все компании\n2.Редактировать компанию\n3.Добавить компанию\n4.Удалить компанию\n5.Выход\n>_: ";
			std::cin >> cho;
			if (cho == 1) {
				
					companies.at(2).vivodCompany();
				
				
			}
		} while (cho != 5);


	}
