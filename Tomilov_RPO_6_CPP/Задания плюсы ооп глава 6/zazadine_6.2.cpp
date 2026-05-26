#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
class Company
{
	std::string name_;
	const bool is_private_;
	int income_, expenses_, turnover_ = income_ + expenses_, net_profit_ = income_ - expenses_;

public:
	Company(std::string name, const bool is_private, int income, int expenses) : name_{name}, is_private_{is_private}, income_{income}, expenses_{expenses} {}

	Company &setName(std::string name)
	{
		if (name != "")
			name_ = name;

		return *this;
	}
	Company &setIncome(int income)
	{
		income_ = income;
		turnover_ = income_ + expenses_;
		net_profit_ = income_ - expenses_;
		return *this;
	}
	Company &setExpenses(int expenses)
	{
		if (expenses >= 0)
		{
			expenses_ = expenses;
			turnover_ = income_ + expenses_;
			net_profit_ = income_ - expenses_;
		}
		return *this;
	}
	std::string getName() const { return name_; }
	const bool getIsPrivate() const { return is_private_; }
	int getIncome() const
	{
		if (is_private_ == true && expenses_ >= 5000000)
			return income_;
		else if (is_private_ == false)
			throw std::runtime_error("� ��.�������� ������ �������� �����");
		else if (expenses_ < 5000000 && is_private_ == true)
			throw std::out_of_range("� ������� �������� � �������� ������ 5000000 ������ �������� �����");
	}
	int getExpenses() const
	{
		if (is_private_ == true && expenses_ >= 5000000)
			return expenses_;
		else if (is_private_ == false)
			throw std::runtime_error("� ���.�������� ������ �������� ������");
		else if (expenses_ < 5000000 && is_private_ == true)
			throw std::runtime_error("� ������� �������� � �������� ������ 5000000 ������ �������� ������");
	}
	int getTurnover() const
	{
		if (is_private_ == true && expenses_ >= 5000000)
			return turnover_;
		else if (is_private_ == false)
			return turnover_;
		else if (expenses_ < 5000000 && is_private_ == true)
			throw std::runtime_error("� ������� �������� � �������� ������ 5000000 ������ �������� ������");
	}
	int getNetProfit() const
	{
		if (is_private_ == true && expenses_ >= 5000000)
			return net_profit_;
		else if (is_private_ == false)
			throw std::runtime_error("� ���.�������� ������ �������� ������ �������");
		else if (expenses_ < 5000000 && is_private_ == true)
			throw std::runtime_error("� ������� �������� � �������� ������ 5000000 ������ �������� ������ �������");
	}
	void vivodCompany()
	{
		std::cout << "��� ��������: " << getName() << "\n";
		std::cout << "��� ��������: " << (getIsPrivate() == false) ? "���������������\n" : "�������\n";
		std::cout << "����� ��������: " << getIncome() << "\n";
		std::cout << "������ ��������: " << getExpenses() << "\n";
		std::cout << "������ ��������: " << getTurnover() << "\n";
		std::cout << "������ �������: " << getNetProfit() << "\n";
	}
};
int main()
{
	system("chcp 1251");
	std::vector<Company> companies{{"���������������", true, 10000000, 10000000}, {"��������������", false, 100000000, 400}, {"��� ���� �����", true, 1000000, 1000000}};
	int cho;
	do
	{
		std::cout << "\n1.������� ��� ��������\n2.������������� ��������\n3.�������� ��������\n4.������� ��������\n5.�����\n>_: ";
		std::cin >> cho;
		if (cho == 1)
		{

			companies.at(2).vivodCompany();
		}
	} while (cho != 5);
}
