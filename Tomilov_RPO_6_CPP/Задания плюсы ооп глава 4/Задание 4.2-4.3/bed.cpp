#include <iostream>
#include <string>
#include <vector>
#include "bed.hpp"
Bed::Bed() {
	amount_m_ = "Односпальная";
	material_ = "Дерево";
	price = 10000;
	double_yar_ = false;
}

void Bed::redact() {
	std::cout << "Введите двуспальная ли кровать(0-нет/1-да): ";
	std::cin >> double_yar_;
	std::cin.ignore(1024, '\n');
	std::cout << "Введите кол-во спальных мест кровати: ";
	std::getline(std::cin, amount_m_);
	std::cout << "Введите материал кровати: ";
	std::getline(std::cin, material_);
	std::cout << "Введите цену: ";
	std::cin >> price;
	std::cout << '\n';
}

void Bed::output() {
	std::cout << (double_yar_ ? "Двуярусная" : "Одноярусная") << " кровать из " << material_ << ", расчитана на " << amount_m_ << " человек, стоимость: " << price;
}