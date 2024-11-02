#include <iostream>
#include "..//Solver/List.h"


/**
* @brief ����� ����� � ���������
* @return 0 � ������ ������
*/
int main()
{
	std::setlocale(NULL, "ru_RU.UTF-8");

	rut_miit::LinkedList<int> list{ 1, 2, 3, 4 };
	std::cout << "�������������� ������: " << list << std::endl;

	list.push_front(5);
	std::cout << "������ ����� push_front(5): " << list << std::endl;

	list.push_back(5);
	std::cout << "������ ����� push_back(5): " << list << std::endl;

	list.pop_front();
	std::cout << "������ ����� pop_front(): " << list << std::endl;

	list.pop_back();
	std::cout << "������ ����� pop_back(): " << list << std::endl;

	list.insert(3, 10);
	std::cout << "������ ����� insert " << list << std::endl;

	list.remove(0);
	std::cout << "������ ����� remove(3): " << list << std::endl;
	return 0;
}