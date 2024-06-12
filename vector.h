#pragma once
class vector {
private:

public:

	// инициализация
	vector();

	template <typename T>
	vector(int n, T y); // вектор по количеству одинаковых элементов

	template <typename T>
	vector(); // вектор по массиву чисел, символов и т.д.

	// операторы
	friend vector operator+(vector a, vector b);
	friend vector operator==(vector a, vector b);


	void print();
};