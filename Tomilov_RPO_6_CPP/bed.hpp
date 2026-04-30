#pragma once
#ifndef BED_H
#define BED_H
#include <iostream>
#include <string>
#include <vector>
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