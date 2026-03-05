#include <iostream>
int main() {
	system("chcp 1251");
	char name[30];
	char place[30];
	int day;
	int month;
	int year;
	std::cout << "¬ведите своЄ им€ >_:";
	std::cin >> name;
	std::cout << "\n" << "¬ведите день рождени€ >_:";
	std::cin >> day;
	std::cout << "\n" << "¬ведите мес€ц рождени€ >_:";
	std::cin >> month;
	std::cout << "\n" << "¬ведите год рождени€ >_:";
	std::cin >> year;
	std::cout << "\n" << "ќткуда вы? >_:";
	std::cin >> place;
	int age = 2026 - year;
	std::cout << " Hello, " << name << " from " << place << ' ' << day << '.' << month << '.' << year << '.' << " dob. " << "Your age is " << age;


}