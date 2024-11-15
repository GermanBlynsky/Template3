#include <iostream>
#include <string>
#include <sstream>
#include <initializer_list>
#pragma once

namespace rut_miit
{
	template <typename T> class LinkedList;

	/**
	* @brief - Оператор сдвига влево
	*/
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const rut_miit::LinkedList<T>& list);
	template <typename T>
	class LinkedList
	{
	private:
		/*
		*@brief структура узла
		*/
		struct Node
		{
			T data;
			Node* next;
			Node* prev;
			Node(T value) :data(value), next(nullptr), prev(nullptr) {}
		};

		/*
		*@brief узел головы дэка
		*/
		Node* head;

		/*
		*@brief узел хвоста дэка
		*/
		Node* tail;
	public:

		/**
		* @brief - Конструктор по умолчанию
		*/
		LinkedList();

		/**
		* @brief - Конструктор, создающий список по значениям, заданным пользователем
		*/
		LinkedList(std::initializer_list<T> initList);

		/**
		* @brief - Конструктор копирования
		* @param other - Название уже существующего списка
		*/
		LinkedList(const LinkedList& other);

		/**
		* @brief - Деструктор по умолчанию
		*/
		~LinkedList();

		/**
		* @brief - Конструктор перемещения
		*/
		LinkedList(LinkedList&& other) noexcept;

		/**
		* @brief - Оператор перемещения
		*/
		LinkedList& operator=(const LinkedList& other);

		/**
		* @brief - Проверка на пустой список
		*/
		bool IsEmpty() const;

		/**
		* @brief - Фунция преобразования в строку
		*/
		std::string to_string() const;

		/**
		* @brief - Функция вставки эллемента в конец списка
		*/
		void push_back(const T& value);

		/**
		* @brief - Функция вставки элемента в начало списка
		*/
		void push_front(const T& value);

		/**
		* @brief - Функция удаления элемента из конца списка
		*/
		void pop_back();

		/**
		* @brief - Функция удаление элемента из начала списка
		*/
		void pop_front();

		/**
		* @brief - Функция вставки эллемента по индексу
		*/
		void insert(size_t idx, T elem);

		/**
		* @brief - Функция удаления элемента по индексу
		*/
		void remove(size_t idx);

		/**
		* @brief - Функция, возвращающая первый элемент списка
		*/
		T get_head_value(); 

		/**
		* @brief - Функция, возвращающая последний элемент списка
		*/
		T get_tail_value();
	};


	template<typename T>
	std::ostream& operator<<(std::ostream& os, const rut_miit::LinkedList<T>& list)
	{
		os << list.to_string();
		return os;
	}
}
//ДАЛЬШЕ ИДЕТ РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА
template <typename T>
rut_miit::LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
rut_miit::LinkedList<T>::LinkedList(std::initializer_list<T> initList) : LinkedList()
{
	for (auto& value : initList)
	{
		push_back(value);
	}
}

template <typename T>
rut_miit::LinkedList<T>::LinkedList(const LinkedList& other) : LinkedList()
{
	Node* temp = other.head;
	while (temp != nullptr)
	{
		push_back(temp->data);
		temp = temp->next;
	}
}

template <typename T>
rut_miit::LinkedList<T>& rut_miit::LinkedList<T>::operator=(const LinkedList& other)
{
	LinkedList temp(other);
	std::swap(this->head, temp.head);
	std::swap(this->tail, temp.tail);
	return *this;
}

template <typename T>
rut_miit::LinkedList<T>::~LinkedList()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

template <typename T>
bool rut_miit::LinkedList<T>::IsEmpty() const
{
	return head == nullptr;
}

template <typename T>
std::string rut_miit::LinkedList<T>::to_string() const
{
	std::stringstream result;
	Node* temp = head;
	while (temp != nullptr)
	{
		result << temp->data << " ";
		temp = temp->next;
	}
	return result.str();
}

template <typename T>
void rut_miit::LinkedList<T>::push_back(const T& value)
{
	Node* newNode = new Node(value);
	newNode->prev = tail;
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		tail->next = newNode;
	}
	tail = newNode;
}

template <typename T>
void rut_miit::LinkedList<T>::push_front(const T& value)
{
	Node* newNode = new Node(value);
	newNode->next = head;
	if (head == nullptr)
	{
		tail = newNode;
	}
	else
	{
		head->prev = newNode;
	}
	head = newNode;
}

template <typename T>
void rut_miit::LinkedList<T>::pop_back()
{
	if (tail == nullptr)
	{
		return;
	}
	if (head->next == nullptr)
	{
		delete tail;
		head = nullptr;
		tail = nullptr;
		return;
	}
	Node* temp = tail;
	tail = tail->prev;
	delete temp;
	tail->next = nullptr;
}

template <typename T>
void rut_miit::LinkedList<T>::pop_front()
{
	if (head == nullptr)
	{
		return;
	}
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	head->prev = nullptr;
}

template <typename T>
void rut_miit::LinkedList<T>::insert(size_t idx, T elem)
{
	size_t index = idx;
	Node* current = head;
	size_t curr_index = 0;
	while (curr_index < index)
	{
		current = current->next;
		curr_index++;
	}
	if (current == nullptr) {
		push_back(elem);
	}
	else {
		Node* tmp_current = current;
		Node* tmp_prev = current->prev;
		current = new Node(elem);
		current->next = tmp_current;
		current->prev = tmp_prev;
		if (tmp_current != nullptr) {
			tmp_current->prev = current;
		}
		if (tmp_prev != nullptr) {
			tmp_prev->next = current;
		}
		else {
			head = current;
		}
	}
}

template <typename T>
void rut_miit::LinkedList<T>::remove(size_t idx)
{
	if (idx < 0) {
		throw std::invalid_argument("Wrong value index!");
	}
	if (idx == 0) {
		pop_front();
	}
	else {
		size_t index = idx;
		Node* current = head;
		size_t curr_index = 0;
		while (curr_index < index)
		{
			current = current->next;
			curr_index++;
		}
		Node* tmp_next = current->next;
		Node* tmp_prev = current->prev;
		delete current;
		if (tmp_next != nullptr) {
			tmp_next->prev = tmp_prev;
		}
		if (tmp_prev != nullptr) {
			tmp_prev->next = tmp_next;
		}
	}
}

template <typename T>
rut_miit::LinkedList<T>::LinkedList(LinkedList<T>&& other) noexcept
{
	head = other.head;
	tail = other.tail;
	other.head = nullptr;
	other.tail = nullptr;
}

template <typename T>
T rut_miit::LinkedList<T>::get_head_value()
{
	if (head) {
		return head->data;
	}
	throw std::out_of_range("Список пуст");
}

template <typename T>
T rut_miit::LinkedList<T>::get_tail_value()
{
	if (tail) {
		return tail->data;
	}
	throw std::out_of_range("Список пуст");
}