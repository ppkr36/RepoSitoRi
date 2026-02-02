#include <iostream>
#include <fstream>
#include <string>
int main() {
	system("chcp 1251");
	std::string str,file,caesar_file,decrypt_file;
	std::cin >> file;
	std::fstream text(file);
	std::getline(text, str, '\0');
	text.close();
	std::cout << "Что делать? \n 1.шифровать 2.дешифровать \n";
	int choice, key = 3;
	std::cin >> choice;
	if (choice == 1) {
		for (int i = 0; i < str.size(); i++) {
			caesar_file.push_back(str.at(i) + key);

		}
		text.open(file);
		text << caesar_file;
		text.close();
		std::cout << "Зашифрован.";
	}
	if (choice == 2) {
		for (int i = 0; i < str.size(); i++) {
			decrypt_file.push_back(str.at(i) - key);
		}
		text.open(file);
		text << decrypt_file;
		text.close();
		std::cout << "Расшифрован.";
	}
}