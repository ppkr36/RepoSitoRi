#ifndef BED_HPP
#define BED_HPP
#pragma once
#include <string>
class Bed {
public:
	std::string amount_m_, material_;
	int price;
	bool double_yar_;
	Bed();
	void redact();
	void output();
};
#endif