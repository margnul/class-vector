#pragma once
#include <span>
class vect {
private:
	
public:

	// �������������
	vect(int n);			// �� ���������� ���������

	template <typename T>
	vect(int n, T y);		// ������ �� ���������� ���������� ���������

	//template <typename T>
	//vect(span(T) t);		// ������ �� ������� �����, �������� � �.�.

	// ���������
	friend vect operator+(vect a, vect b);
	friend vect operator==(vect a, vect b);


	void print();
};