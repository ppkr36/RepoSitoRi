#include <iostream>
#include <fstream>
#include <string>
int main() {
	system("chcp 1251");
	std::string str;
	std::getline(std::cin, str, '~');
	std::ofstream text("13_4.txt");
	text << str;
	text.close();
	
	
}