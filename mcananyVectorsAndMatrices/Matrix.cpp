#include "Matrix.h"



Matrix::Matrix()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			data[i * 4 + j] = (i == j);
}

// constructor with 4 vector parameters
Matrix::Matrix(const Vector & row0, const Vector & row1, const Vector & row2, const Vector & row3)
{
	for (int i = 0; i < 4; i++)
	{
		data[i] = row0.getData()[i];
	}
	for (int i = 4; i < 8; i++)
	{
		data[i] = row1.getData()[i - 4];
	}
	for (int i = 8; i < 12; i++)
	{
		data[i] = row2.getData()[i - 8];
	}
	for (int i = 12; i < 16; i++)
	{
		data[i] = row3.getData()[i - 12];
	}
}


Matrix::~Matrix()
{
}

//multiplies matrix by matrix and returns a matrix
Matrix Matrix::operator*(const Matrix & other) const
{
	return Matrix(Vector(row(0).dotProduct(other.col(0)), row(0).dotProduct(other.col(1)), row(0).dotProduct(other.col(2)), row(0).dotProduct(other.col(3))),
		Vector(row(1).dotProduct(other.col(0)), row(1).dotProduct(other.col(1)), row(1).dotProduct(other.col(2)), row(1).dotProduct(other.col(3))),
		Vector(row(2).dotProduct(other.col(0)), row(2).dotProduct(other.col(1)), row(2).dotProduct(other.col(2)), row(2).dotProduct(other.col(3))),
		Vector(row(3).dotProduct(other.col(0)), row(3).dotProduct(other.col(1)), row(3).dotProduct(other.col(2)), row(3).dotProduct(other.col(3))));
}

//multiplies matrix by vector and returns a vector
Vector Matrix::operator*(const Vector & other) const
{
	if (other.getDimensions() != 4)
	{
		return Vector();
	}
	return Vector(row(0).dotProduct(other),	row(1).dotProduct(other), row(2).dotProduct(other),	row(3).dotProduct(other));
}

//multiplies a matrix by a float and returns a matrix
Matrix Matrix::operator*(float c) const
{
	return Matrix(row(0)*c, row(1)*c, row(2)*c, row(3)*c);
}

//returns row vector
Vector Matrix::row(int i) const
{
	if (i == 0)
	{
		return Vector(data[0], data[1], data[2], data[3]);
	}
	if (i == 1)
	{
		return Vector(data[4], data[5], data[6], data[7]);
	}
	if (i == 2)
	{
		return Vector(data[8], data[9], data[10], data[11]);
	}
	else
	{
		return Vector(data[12], data[13], data[14], data[15]);
	}
}

//returns column vector
Vector Matrix::col(int j) const
{
	if (j == 0)
	{
		return Vector(data[0], data[4], data[8], data[12]);
	}
	if (j == 1)
	{
		return Vector(data[1], data[5], data[9], data[13]);
	}
	if (j == 2)
	{
		return Vector(data[2], data[6], data[10], data[14]);
	}
	else
	{
		return Vector(data[3], data[7], data[11], data[15]);
	}
}

//transpose the matrix
Matrix Matrix::transpose() const
{
	return Matrix(col(0), col(1), col(2), col(3));
}

//data getter
float * Matrix::getData()
{
	return data;
}

//output operator to print the data
std::ostream & operator<<(std::ostream & os, const Matrix & matrix)
{
	
	for (int i = 0; i < 4; i++)
		os << matrix.row(i) << std::endl;
	return os;
}
