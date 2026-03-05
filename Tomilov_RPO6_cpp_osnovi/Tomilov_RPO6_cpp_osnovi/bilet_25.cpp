#include <iostream>
#include <string>
int main() {
	std::string stri;
	int count_space=0, count_nums=0;
	std::getline(std::cin, stri);

	for (int i = 0; i < stri.length(); i++)
		if (isspace(stri.at(i)) == true) 
			count_space++;

	for (int i = 0; i < stri.length(); i++)
		if (isdigit(stri.at(i)) == true) 
			count_nums++;

	std::cout << stri.front() << " " << stri.back()<<" " << count_nums << " " << count_space;
}