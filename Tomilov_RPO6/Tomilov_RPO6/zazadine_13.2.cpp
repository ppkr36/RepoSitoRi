#include <iostream>
#include <fstream>
#include <string>
int main() {
	system("chcp 1251");
	std::ofstream outp("13_2.txt");
	std::string vvod;
	std::getline(std::cin, vvod, '~');
	outp << vvod;
	outp.close();
	std::cout << vvod;

}