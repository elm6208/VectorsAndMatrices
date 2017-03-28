#include "Vector.h"
#include "Matrix.h"
int main()
{
	//testing the vector class
	Vector a = Vector(1, 0, 0);
	Vector b = Vector(0, 2, 0);

	Vector c = a - b;
	std::cout << c << std::endl;

	c = a.crossProduct(b);
	std::cout << c.magnitude() << ' ' << c.direction() << std::endl;

	float arr[16];
	for (int i = 0; i < 16; i++) arr[i] = i;
	c = Vector(16, arr);
	std::cout << c;

	//spacing
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;

	//testing the matrix class
	Matrix m = Matrix(Vector(1, 0, 0, 1),
		Vector(0, 1, 0, 2),
		Vector(0, 0, 1, 3),
		Vector(0, 0, 0, 1));

	Vector v = Vector(1, 0, -1);

	Vector u = m*v;
	std::cout << u << std::endl;

	v = Vector(1, 0, -1, 1);
	u = m*v;
	std::cout << u << std::endl;

	v = Vector(1, 0, -1, 0);
	u = m*v;
	std::cout << u << std::endl;
}