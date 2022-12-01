#include "Math.h"
Vector::Vector(double X, double Y, double Z)
{
	x = X;
	y = Y;
	z = Z;
}

void Vector::getData()
{
	cout << "x = " << x << " y = " << y << " z = " << z << endl;
}

void Vector::Extraction(Vector obj1, Vector obj2)
{
	Vector temp = Vector(0,0,0);
	temp.x = obj1.x - obj2.x;
	temp.y = obj1.y - obj2.y;
	temp.z = obj1.z - obj2.z;
	cout << "New vector: " << temp.x << "," << temp.y << "," << temp.z << endl;
}

void Vector::Addition(Vector obj1, Vector obj2)
{
	Vector temp = Vector(0, 0, 0);
	temp.x = obj1.x + obj2.x;
	temp.y = obj1.y + obj2.y;
	temp.z = obj1.z + obj2.z;
	cout << "New vector: " << temp.x << "," << temp.y << "," << temp.z << endl;
}

void Vector::Multiplication(Vector obj1, float num)
{
	Vector temp = Vector(0, 0, 0);
	temp.x = obj1.x * num;
	temp.y = obj1.y * num;
	temp.z = obj1.z * num;
	cout << "New vector: " << temp.x << "," << temp.y << "," << temp.z << endl;
}

void Vector::MultiplicationObj(Vector obj1, Vector obj2)
{
	Vector temp = Vector(0, 0, 0);
	temp.x = obj1.y * obj2.z - obj1.z * obj2.y;
	temp.y = obj1.z * obj2.x - obj1.x * obj2.z;
	temp.z = obj1.x * obj2.y - obj1.y * obj2.x;
	cout << "New vector: " << temp.x << "," << temp.y << "," << temp.z << endl;
}

void Vector::Division(Vector obj1, float obj2)
{
	Vector temp = Vector(0, 0, 0);
	temp.x = obj1.x / obj2;
	temp.y = obj1.y / obj2;
	temp.z = obj1.z / obj2;
	cout << "New vector: " << temp.x << "," << temp.y << "," << temp.z << endl;
}
