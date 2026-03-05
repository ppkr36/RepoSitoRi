#include <iostream>
#include <fstream>
#include <string>
int main() {
	system("chcp 1251");
	std::string str;
	std::ifstream input("13_1.txt");
	input >> str;
	input.close();
	std::cout << str;
	
	
}