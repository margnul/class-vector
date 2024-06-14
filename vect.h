#pragma once
#include <span>
class vect {
private:
	void* vect_end;// = malloc(2);	// 2 ����� �� ��������� � n ���� �� ��� ������
public:

	// �������������
	vect(int n = 0);				// ������ �� ���������� ���������

	vect(const vect&v);				// ����������� �����

	template <typename T = int>
	vect(int n = 0, T y = 0);		// ������ �� ���������� ���������� ���������

	//template <typename T>
	//vect(span(T) t);				// ������ �� ������� �����, �������� � �.�.

	// ���������
	friend vect operator+(vect a, vect b);
	friend vect operator==(vect a, vect b);


	void print();
};