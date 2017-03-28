#pragma once
#include <iostream>
#include <cmath>
class Vector
{
private:
	int dimension;
	float* data;
	//deletes data
	void clear();
public:
	Vector();
	~Vector();
	Vector(const Vector& other);
	Vector(int dimension, float data[]);
	Vector(int dimension);
	int getDimensions() const;
	float* getData() const;
	//if between 1 and 16, copy value of dimension and allocate floats on the heap, save address in data
	void init(int dimension);
	//copy passed data into new array
	void copy(float data[]);

	//allocate floats on the heap and save address in data
	Vector(float x, float y);
	Vector(float x, float y, float z);
	Vector(float x, float y, float z, float w);

	//operator overloading
	Vector operator=(const Vector& other);
	float operator[](int i) const;
	float & operator[](int i);
	Vector operator+(const Vector& other) const;
	Vector operator-(const Vector& other) const;
	Vector operator*(float c) const;
	Vector operator/(float c) const;
	float dotProduct(const Vector& other) const;
	Vector crossProduct(const Vector& other) const;
	float magnitude() const;
	Vector direction() const;
};
// output operator to print the data
std::ostream& operator<<(std::ostream& os, const Vector& vector);