#pragma once
#include <span>
class vect {
private:
	void* vect_end;// = malloc(2);	// 2 байта на указатель и n байт на тип данных
public:

	// инициализация
	vect(int n = 0);				// массив по количеству элементов

	vect(const vect&v);				// конструктор копии

	template <typename T = int>
	vect(int n = 0, T y = 0);		// вектор по количеству одинаковых элементов

	//template <typename T>
	//vect(span(T) t);				// вектор по массиву чисел, символов и т.д.

	// операторы
	friend vect operator+(vect a, vect b);
	friend vect operator==(vect a, vect b);


	void print();
};