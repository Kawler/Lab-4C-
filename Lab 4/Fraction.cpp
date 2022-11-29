#include "Math.h"

Fraction::Fraction(float num, float num2)
{
	first = num;
	second = num2;
}

void Fraction::getData() {
	cout << "Data:" << first << "/" << second << endl;
}

void Fraction::Extraction(Fraction obj1, Fraction obj2)
{
	float temp, temp2, temp3, temp4 = 0;
	if (obj1.second != obj2.second){
		temp2 = obj1.second * obj2.second;
		temp = obj1.first * obj2.second;
		temp3 = obj1.second * obj2.first;
		temp4 = temp - temp3;
		cout << temp4 << "/" << temp2;
	}
	else {
		temp = obj1.first - obj2.first;
		cout << "Result:" << temp << "/" << obj1.second << endl;
	}
	
}

void Fraction::Addition(Fraction obj1, Fraction obj2)
{
	float temp, temp2, temp3, temp4 = 0;
	if (obj1.second != obj2.second) {
		temp2 = obj1.second * obj2.second;
		temp = obj1.first * obj2.second;
		temp3 = obj1.second * obj2.first;
		temp4 = temp + temp3;
		cout << temp4 << "/" << temp2;
	}
	else {
		temp = obj1.first + obj2.first;
		cout << "Result:" << temp << "/" << obj1.second << endl;
	}
}

void Fraction::Multiplication(Fraction obj1, float num)
{
	float temp = 0;
	temp = obj1.first * num;
	cout << "Result:" << temp << "/" << obj1.second << endl;
}

void Fraction::MultiplicationObj(Fraction obj1, Fraction obj2)
{
	float temp, temp2 = 0;
	temp = obj1.first * obj2.first;
	temp2 = obj1.second * obj2.second;
	cout << "Result:" << temp << "/" << temp2 << endl;
}

void Fraction::Division(Fraction obj1, Fraction obj2)
{
	float temp, temp2 = 0;
	temp = obj1.first * obj2.second;
	temp2 = obj1.second * obj2.first;
	cout << "Result:" << temp << "/" << temp2 << endl;
}
