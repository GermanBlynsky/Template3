#include <iostream>
#include "..//Solver/List.h"



/**
* @brief Точка входа в программу
* @return 0 в случае успеха
*/
int main()
{
	std::setlocale(NULL, "ru_RU.UTF-8");

	rut_miit::LinkedList<int> list{ 1, 2, 3, 4 };
	std::cout << "Первоначальный список: " << list << std::endl;

	list.push_front(5);
	std::cout << "Список после push_front(5): " << list << std::endl;

	list.push_back(5);
	std::cout << "Список после push_back(5): " << list << std::endl;

	list.pop_front();
	std::cout << "Список после pop_front(): " << list << std::endl;

	list.pop_back();
	std::cout << "Список после pop_back(): " << list << std::endl;

	list.insert(3, 10);
	std::cout << "Список после insert " << list << std::endl;

	list.remove(0);
	std::cout << "Список после remove(3): " << list << std::endl;
	return 0;
}