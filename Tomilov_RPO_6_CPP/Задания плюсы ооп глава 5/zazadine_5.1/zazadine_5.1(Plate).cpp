#include <iostream>
#include <string>
#include <vector>
#include "zazadine_5.1(Plate).hpp"

Plate::Plate() : 
	material_{ "керамика" }, 
	proiz_{ "завод-китай-керамика" }, 
	price_{ 4000 }, 
	height_{ 100 }, 
	width_{ 100 }, 
	thickness_{ 1 }, 
	weight_{3000} {};

Plate::Plate(std::string material, std::string proiz, double price, int height, int width, int thickness, int weight) : 
	material_{ material }, 
	proiz_{ proiz }, 
	price_{ price }, 
	height_{ height }, 
	width_{ width }, 
	thickness_{ thickness },
	weight_{ weight } {};

void Plate::printPlitka() {
std::cout << "\nПлитка из " << material_ << "; размеры (в ш г) в мм.: " << height_ << ", " 
<< width_ << ", " << thickness_ << "; вес: " << weight_ << " грамм, " << "стоимость: " 
<< price_ << " рублей, " << "производитель: " << proiz_;
}