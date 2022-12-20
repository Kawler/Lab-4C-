
#pragma once
#include<string>
#include<vector> 
#include<iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;

class BasicFunctions {
protected:
	virtual void moveObj() = 0;
	virtual void turnObj() = 0;
	virtual void area() = 0;
	virtual void perimetr() = 0;
	virtual void draw() = 0;
};

class Triangle :
	public BasicFunctions
{
protected:
	double x[3], y[3];
	double side[3];
public:
	Triangle();
	virtual void moveObj() override;
	virtual void turnObj() override;
	virtual void area() override;
	virtual void perimetr() override;
	virtual void draw() override;
};

class Rectangle :
	public BasicFunctions
{
protected:
	double x[4], y[4];
	double side[4];
public:
	Rectangle();
	virtual void moveObj() override;
	virtual void turnObj() override;
	virtual void area() override;
	virtual void perimetr() override;
	virtual void draw() override;
};

class Rhombus :
	public BasicFunctions
{
protected:
	double x[4], y[4];
	double side[4];
	double angle = 0;
public:
	Rhombus();
	virtual void moveObj() override;
	virtual void turnObj() override;
	virtual void area() override;
	virtual void perimetr() override;
	virtual void draw() override;
};

class Ellipse :
	public BasicFunctions
{
protected:
	double sideA;
	double sideB;
	double ct[2];
public:
	Ellipse();
	virtual void moveObj() override;
	virtual void turnObj() override;
	virtual void area() override;
	virtual void perimetr() override;
	virtual void draw() override;
};

class Trapezoid :
	public BasicFunctions
{
protected:
	double x[4], y[4];
	double side[4];
public:
	Trapezoid();
	virtual void moveObj() override;
	virtual void turnObj() override;
	virtual void area() override;
	virtual void perimetr() override;
	virtual void draw() override;
};
