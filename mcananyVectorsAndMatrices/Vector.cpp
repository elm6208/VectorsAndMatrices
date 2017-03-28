#include "Vector.h"


Vector::Vector()
{
	dimension = 0;
	data = nullptr;
}


Vector::~Vector()
{
	clear();
}

Vector::Vector(const Vector & other)
	: Vector(other.dimension, other.data)
{
}

Vector::Vector(int dimension, float data[])
	: Vector(dimension)
{
	if (dimension > 0)
	{
		copy(data);
	}
}

Vector::Vector(int dimension)
{
	if (dimension > 0 && dimension < 17)
	{
		init(dimension);
	}
	else clear();
}

int Vector::getDimensions() const
{
	return dimension;
}

float* Vector::getData() const
{
	return data;
}

//if between 1 and 16, copy value of dimension and allocate floats on the heap, save address in data
void Vector::init(int dimension)
{

	this->dimension = dimension;
	this-> data = new float[this->dimension];
}

//copy passed data into new array
void Vector::copy(float data[])
{
	memcpy(this->data, data, dimension * sizeof(float));
}

Vector::Vector(float x, float y)
{
	init(2);
	data[0] = x;
	data[1] = y;
}

Vector::Vector(float x, float y, float z)
{
	init(3);
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

Vector::Vector(float x, float y, float z, float w)
{
	init(4);
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = w;
}

Vector Vector::operator=(const Vector & other)
{
	clear();
	init(other.dimension);
	copy(other.data);
	return *this;
}

float Vector::operator[](int i) const
{
	if (i < 0 || i >= dimension)
		return -FLT_MAX;
	return data[i];
}

float & Vector::operator[](int i)
{
	return data[i];
}

Vector Vector::operator+(const Vector & other) const
{
	if (this->dimension != other.dimension)
	{
		return Vector();
	}
	Vector sum = Vector(dimension);

	for (int i = 0; i < dimension; i++)
		sum[i] = data[i] + other[i];
	
	return sum;
}

Vector Vector::operator-(const Vector & other) const
{
	return *this + (other * -1.f);
}

Vector Vector::operator*(float c) const
{
	Vector product = Vector(dimension);

	for (int i = 0; i < dimension; i++)
		product[i] = data[i] * c;

	return product;
}

Vector Vector::operator/(float c) const
{
	return *this * (1.f / c);
}

float Vector::dotProduct(const Vector & other) const
{
	if (dimension != other.dimension)
	{
		return -FLT_MAX;
	}
	float answer = 0;
	for (int i = 0; i < dimension; i++)
	{
		answer += data[i] * other.data[i];
	}
	return answer;
}

Vector Vector::crossProduct(const Vector & other) const
{
	if (this->dimension != 3 || other.dimension != 3)
		return Vector();
	Vector product = Vector(3);

	for (int i = 0; i < 3; i++)
		product[i] = data[(i + 1) % 3] * other[(i + 2) % 3]
		- data[(i + 2) % 3] * other[(i + 1) % 3];

	return product;
}

float Vector::magnitude() const
{
	return sqrtf(this->dotProduct(*this));

}

Vector Vector::direction() const
{
	return *this / (this->magnitude());
}

//deletes data
void Vector::clear()
{
	if (data != nullptr)
	{
		delete[] data;
	}
	data = nullptr;
	this->dimension = 0;
}

std::ostream & operator<<(std::ostream & os, const Vector & vector)
{
	os << "<";

	if (vector.getDimensions() > 0)
		os << vector[0];
	for (int i = 1; i < vector.getDimensions(); i++)
		os << "," << vector[i];
	os << ">";
	return os;
}
