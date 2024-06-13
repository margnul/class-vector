#pragma once
#include <span>
class vect {
private:
	
public:

	// инициализация
	vect(int n);			// по количеству элементов

	template <typename T>
	vect(int n, T y);		// вектор по количеству одинаковых элементов

	//template <typename T>
	//vect(span(T) t);		// вектор по массиву чисел, символов и т.д.

	// операторы
	friend vect operator+(vect a, vect b);
	friend vect operator==(vect a, vect b);


	void print();
};