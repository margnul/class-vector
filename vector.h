#pragma once
class vector {
private:

public:

	// �������������
	vector();

	template <typename T>
	vector(int n, T y); // ������ �� ���������� ���������� ���������

	template <typename T>
	vector(); // ������ �� ������� �����, �������� � �.�.

	// ���������
	friend vector operator+(vector a, vector b);
	friend vector operator==(vector a, vector b);


	void print();
};