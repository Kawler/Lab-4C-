#pragma once
#include<string>
#include<vector> 
#include<iostream>


using namespace std;

class BasicFunction {
public:
	virtual void getData() = 0;
};

class Fraction: BasicFunction
{
protected:
	float first;
	float second;
public:
	Fraction(float num, float num2);
	void getData();
	void Extraction(Fraction obj1, Fraction obj2);
	void Addition(Fraction obj1, Fraction obj2);
	void Multiplication(Fraction obj1, float num);
	void MultiplicationObj(Fraction obj1, Fraction obj2);
	void Division(Fraction obj1, Fraction obj2);
};

class Matrix :
	public BasicFunction
{
protected:
	int size;
	vector<vector<double>> matrix;
public:
	Matrix();
	void getData();
	void Extraction(Matrix obj1, Matrix obj2);
	void Addition(Matrix obj1, Matrix obj2);
	void Multiplication(Matrix obj1, float num);
	void MultiplicationObj(Matrix obj1, Matrix obj2);
	void Division(Matrix obj1, Matrix obj2);
};

class Polinom :
	public BasicFunction
{
protected:
	int size;
	vector<int> polinom;
public:
	Polinom(int Size);
	void getData();
	void Extraction(Polinom obj1, Polinom obj2);
	void Addition(Polinom obj1, Polinom obj2);
	void Multiplication(Polinom obj1, float num);
	void MultiplicationObj(Polinom obj1, Polinom obj2);
	void Division(Polinom obj1, Polinom obj2);
};

class Vector :
	public BasicFunction
{
protected:
	double x;
	double y;
	double z;
public:
	Vector(double X, double Y, double Z);
	void getData();
	void Extraction(Vector obj1, Vector obj2);
	void Addition(Vector obj1, Vector obj2);
	void Multiplication(Vector obj1, float num);
	void MultiplicationObj(Vector obj1, Vector obj2);
	void Division(Vector obj1, float obj2);
};

class ComplexNum :
	public BasicFunction
{
protected:
	double real, imaginary;
public:
	ComplexNum();
	void getData();
	void Extraction(ComplexNum obj1, ComplexNum obj2);
	void Addition(ComplexNum obj1, ComplexNum obj2);
	void Multiplication(ComplexNum obj1, float num);
	void MultiplicationObj(ComplexNum obj1, ComplexNum obj2);
	void Division(ComplexNum obj1, ComplexNum obj2);
};


