#include <iostream>
#include <string>
struct Human
{
	std::string name, surename;
	int day, month, year;
};
void myHuman(Human& human) {
	std::cout << "Введите имя, фамилию, день, месяц, и год рождения: ";
	std::cin >> human.name >> human.surename >> human.day >> human.month >> human.year;
}
std::string myZodiak(Human& human) {
	std::string znak_zodiaka;
	if (human.month == 12 && human.day >= 22 || human.month == 1 && human.day >= 20) { znak_zodiaka = "Козерог"; }
	else if (human.month == 1 && human.day >= 21 || human.month == 2 && human.day <= 18) { znak_zodiaka = "Водолей"; }
	else if (human.month == 2 && human.day >= 19 || human.month == 3 && human.day <= 19) { znak_zodiaka = "Рыбы"; }
	else if (human.month == 3 && human.day >= 20 || human.month == 4 && human.day <= 19) { znak_zodiaka = "Овен"; }
	else if (human.month == 4 && human.day >= 20 || human.month == 5 && human.day <= 20) { znak_zodiaka = "Телец"; }
	else if (human.month == 5 && human.day >= 21 || human.month == 6 && human.day <= 20) { znak_zodiaka = "Близнецы"; }
	else if (human.month == 6 && human.day >= 21 || human.month == 7 && human.day <= 21) { znak_zodiaka = "Рак"; }
	else if (human.month == 7 && human.day >= 22 || human.month == 8 && human.day <= 22) { znak_zodiaka = "Лев"; }
	else if (human.month == 8 && human.day >= 23 || human.month == 9 && human.day <= 22) { znak_zodiaka = "Дева"; }
	else if (human.month == 9 && human.day >= 23 || human.month == 10 && human.day <= 22) { znak_zodiaka = "Весы"; }
	else if (human.month == 10 && human.day >= 23 || human.month == 11 && human.day <= 21) { znak_zodiaka = "Скорпион"; }
	else if (human.month == 11 && human.day >= 22 || human.month == 12 && human.day <= 21) { znak_zodiaka = "Стрелец"; }
	return znak_zodiaka;
}
void myVivod(Human& human){ std::string znak_zodiaka = myZodiak(human); std::cout << "Приветствую вас, " << human.surename << ' ' << human.name << ", " << human.day << '.' << human.day << '.' << human.year << " г.р., " << "вам сейчас примерно " << 2026 - human.year << " лет, ваш знак зодиака: " << znak_zodiaka;}
int main() {
	system("chcp 1251");
	Human chelovek;
	myHuman(chelovek);
	myVivod(chelovek);
}