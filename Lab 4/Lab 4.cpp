#include <iostream>
#include "Math.h"

int main()
{
	Matrix matrix = Matrix();
	Matrix matrix2 = Matrix();
	matrix.MultiplicationObj(matrix, matrix2);
	matrix.Division(matrix, matrix2);
    return 0;

}

/*
double choice = -501;
	while (choice < -500 || choice > 500) {
		cout << "Enter x: ";
		cin >> choice;
	}
	x = choice;
	choice = -501;
	while (choice < -500 || choice > 500) {
		cout << "Enter y: ";
		cin >> choice;
	}
	y = choice;
	choice = -501;
	while (choice < -500 || choice > 500) {
		cout << "Enter z: ";
		cin >> choice;
	}
	z = choice;
*/

/*
int choice = 0;
	while (choice <= 0 || choice > 10) {
		cout << "Enter size of the polinom: ";
		cin >> choice;
	}
	size = choice;
	for (int i = 0; i < size; i++) {
		choice = -101;
		while (choice < -100 || choice > 100) {
			cout << "Enter coefficient" << i <<": ";
			cin >> choice;
		}
		polinom.push_back(choice);
	}
*/