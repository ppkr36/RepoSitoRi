#pragma once
#include <iostream>
#include <string>
#include <vector>
class Plate {
public:
	std::string material_, proiz_;
	double price_;
	int height_, width_, thickness_, weight_;
	Plate();
	Plate(std::string material, std::string proiz, double price, int height, int width, int thickness, int weight);
	void printPlitka();
};