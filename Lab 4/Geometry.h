#pragma once
#include<string>
#include<vector> 
#include<iostream>

using namespace std;

class BasicFunctions {
protected:
	virtual void moveObj() = 0;
	virtual void turnObj() = 0;
	virtual void area() = 0;
	virtual void perimetr() = 0;
	virtual void draw() = 0;
};

