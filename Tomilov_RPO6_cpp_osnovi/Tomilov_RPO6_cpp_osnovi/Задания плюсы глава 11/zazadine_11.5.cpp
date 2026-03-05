#include <iostream>
#include <vector>
int main() {
	system("chcp 1251");
	srand(static_cast<int>(time(0)));
	std::vector<double>vect(7);
	double sum = 0;
	double avg = 0;
	for (int i = 0; i < vect.size(); i++) {
		vect.at(i) = (rand() % 101)/10.0;
		sum += vect.at(i);
		std::cout << vect.at(i) << " ";
	}
	avg = sum / vect.size();
	std::cout << "\n";
	for (int i = 0; i < vect.size(); i++) {
		vect.at(i) = avg;
		std::cout << vect.at(i) << " ";
	}
}