#include "Math.h"
ComplexNum::ComplexNum()
{
	double choice = -501;
	while (choice < - 500 || choice > 500) {
		cout << "Enter real part: ";
		cin >> choice;
	}
	real = choice;
	choice = -501;
	while (choice < -500 || choice > 500) {
		cout << "Enter imaginary part: ";
		cin >> choice;
	}
	imaginary = choice;
}

void ComplexNum::getData() {
	cout << "real: " << real << " imaginary: " << imaginary <<"i" << endl;
}

void ComplexNum::Extraction(ComplexNum obj1, ComplexNum obj2)
{
	double tempr;
	double tempi;
	tempr = obj1.real - obj2.real;
	tempi = obj2.imaginary - obj2.imaginary;
	cout << tempr << " + " << tempi << 'i' << endl;
}

void ComplexNum::Addition(ComplexNum obj1, ComplexNum obj2)
{
	double tempr;
	double tempi;
	tempr = obj1.real + obj2.real;
	tempi = obj2.imaginary + obj2.imaginary;
	cout << tempr << " + " << tempi << 'i' << endl;
}

void ComplexNum::Multiplication(ComplexNum obj1, float num)
{
	double tempr;
	double tempi;
	tempr = obj1.real * num;
	tempi = obj1.imaginary * num;
	cout << tempr << " + " << tempi << 'i' << endl;
}

void ComplexNum::MultiplicationObj(ComplexNum obj1, ComplexNum obj2)
{
	double tempr;
	double tempi;
	tempr = obj1.real*obj2.real - obj1.imaginary * obj2.imaginary;
	tempi = obj1.real * obj2.imaginary + obj1.real * obj2.imaginary;
	cout << tempr << " + " << tempi << 'i' << endl;
}

void ComplexNum::Division(ComplexNum obj1, ComplexNum obj2)
{
	double tempr;
	double tempi;
	tempr = (obj1.real * obj2.real + obj2.imaginary * obj2.imaginary)/(obj2.real*obj2.real + obj2.imaginary* obj2.imaginary);
	tempi = (obj2.real * obj1.imaginary + obj1.real * obj2.imaginary) / (obj2.real * obj2.real + obj2.imaginary * obj2.imaginary);
	cout << tempr << " + " << tempi << 'i' << endl;
}
