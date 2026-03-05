#include <iostream>
#include <vector>
int main() {
	system("chcp 1251");
	std::vector<int>sales;
	int cho = 0;
	int sale;
	int sum = 0;
	while (cho != 7) {
		std::cout << "\n1.Ввести продажу\n2.Вывести лист продаж\n3.Удалить последнюю продажу\n4.Вывести кол-во продаж и их сумму\n5.Минимум Максимум\n>_";
		std::cin >> cho;
		switch (cho) {
		case 1:
			std::cout << "Введите сумму: \n";
			std::cin >> sale;
			sales.push_back(sale);
			break;
		case 2:
			for (int i = 0; i < sales.size(); i++) std::cout << "\nПродажа № " << i + 1 << " -> Сумма продажи " << sales.at(i) << "\n";
			break;
		case 3:
			sales.pop_back();
			std::cout << "Продажа успешно удалена: \n";
			break;
		case 4:
			for (int i = 0; i < sales.size(); i++) sum += sales.at(i);
			std::cout << "Общее количество продаж: " << sales.size() << " Общая сумма продаж: " << sum << "\n";
			break;
		case 5:
			int max = sales.at(0), min = sales.at(0);
			for (int i = 0; i < sales.size(); i++) {
				if (sales.at(i) > max)max = sales.at(i);
				if (sales.at(i) < min)min = sales.at(i);
				std::cout << "Минимальная продажа " << min << " Максимальная продажа " << max;
			}
		}
		

		
	}
}