#include <iostream>
#include <string>
int main() {
	system("chcp 1251");
	std::string str;
	std::getline(std::cin, str);
	std::cout << str << "\n";
	str.erase(str.begin());
	std::cout << str << "\n";
	str.erase(0, 5);
	std::cout << str << "\n";
	std::cout << '\n' << "Какой элемент удалить?: ";
	int element;
	std::cin >> element;
	str.erase(str.begin() + element);
	std::cout << str << "\n";
	std::cout << "от какого удалить ";
	int start;
	std::cin >> start;
	std::cout << "до какого удалить ";
	int end;
	std::cin >> end;
	str.erase(str.begin() + start, str.begin() + end);
	std::cout << str;
}