#pragma once
#include "Vector.h"
class Matrix
{
private:
	float data[16];
public:
	Matrix();
	//parameterized constructor
	Matrix(const Vector& row0, const Vector& row1, const Vector& row2, const Vector& row3);
	~Matrix();

	//overloaded multiplication operators
	Matrix operator*(const Matrix& other) const;
	Vector operator*(const Vector& other) const;
	Matrix operator*(float c) const;

	//returns row and column vectors
	Vector row(int i) const;
	Vector col(int j) const;

	//transpose the matrix
	Matrix transpose() const;

	//data getter
	float* getData();
};
// output operator to print the data
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);