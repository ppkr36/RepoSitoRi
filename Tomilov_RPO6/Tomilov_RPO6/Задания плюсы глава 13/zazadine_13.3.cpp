#include <iostream>
#include <fstream>
#include <string>
int main() {
	system("chcp 1251");
	std::string str;
	std::ifstream input("13_3.txt");
	std::getline(input, str, '\0');
	input.close();
	std::cout << str;
}