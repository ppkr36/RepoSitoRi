#include <iostream>
#include <string>
#include <vector>
#include "bed.hpp"
Bed::Bed() {
	amount_m_ = "ќдноспальна€";
	material_ = "ƒерево";
	price = 10000;
	double_yar_ = false;
}

void Bed::redact() {
	std::cout << "¬ведите двуспальна€ ли кровать(0-нет/1-да): ";
	std::cin >> double_yar_;
	std::cin.ignore(1024, '\n');
	std::cout << "¬ведите кол-во спальных мест кровати: ";
	std::getline(std::cin, amount_m_);
	std::cout << "¬ведите материал кровати: ";
	std::getline(std::cin, material_);
	std::cout << "¬ведите цену: ";
	std::cin >> price;
	std::cout << '\n';
}

void Bed::output() {
	std::cout << (double_yar_ ? "ƒву€русна€" : "ќдно€русна€") << " кровать из " << material_ << ", расчитана на " << amount_m_ << " человек, стоимость: " << price;
}