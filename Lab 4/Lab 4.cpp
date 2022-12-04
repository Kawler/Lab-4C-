#include "Math.h"
#include "Geometry.h"

template<typename S>
void mathGeomSub(S obj1) {
	int choice;
	float num = 0;
	choice = 0;
	while (choice != 6) {
		cout << "What to do" << endl;
		cout << "1 - move" << endl;
		cout << "2 - turn" << endl;
		cout << "3 - get area" << endl;
		cout << "4 - get perimetr" << endl;
		cout << "5 - draw" << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			obj1.moveObj();
			break;
		case 2:
			obj1.turnObj();
			break;
		case 3:
			obj1.area();
			break;
		case 4:
			obj1.perimetr();
			break;
		case 5:
			obj1.draw();
			break;
		}
	}
}

void menuGeom() {
	int choice;
	float num = 0;
	choice = 0;
	while (choice != 6) {
		cout << "What to do" << endl;
		cout << "1 - Ellipse" << endl;
		cout << "2 - Rectangle" << endl;
		cout << "3 - Rhombus" << endl;
		cout << "4 - Trapezoid" << endl;
		cout << "5 - Triangle" << endl;
		cout << "Your choice: ";
		cin >> choice;

		if (choice == 1) {
			Ellipse el = Ellipse();
			mathGeomSub(el);
		}
		if (choice == 2) {
			Rectangle el = Rectangle();
			mathGeomSub(el);
		}
		if (choice == 3) {
			Rhombus el = Rhombus();
			mathGeomSub(el);
		}
		if (choice == 4) {
			Trapezoid el = Trapezoid();
			mathGeomSub(el);
		}
		if (choice == 5) {
			Triangle el = Triangle();
			mathGeomSub(el);
		}
	}
}

template <typename T>
void mathChoice(T obj1, T obj2) {
	int choice;
	float num = 0;
	choice = 0;
	while (choice != 7) {
		cout << "What to do" << endl;
		cout << "1 - add" << endl;
		cout << "2 - extract" << endl;
		cout << "3 - multipNum" << endl;
		cout << "4 - multipObj" << endl;
		cout << "5 - division" << endl;
		cout << "6 - get data" << endl;
		cout << "7 - exit" << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			obj1.Addition(obj1, obj2);
				break;
		case 2:
			obj1.Extraction(obj1, obj2);
			break;
		case 3:
			num = 0;
			while (num == 0 || num > 100) {
				cout << "Number = ";
				cin >> num;
			}
			obj1.Multiplication(obj1, num);
			break;
		case 4:
			obj1.MultiplicationObj(obj1, obj2);
			break;
		case 5:
			obj1.Division(obj1, obj2);
			break;
		case 6:
			obj1.getData();
			break;
		}
	}
}

void mathChoiceFix(Vector obj1, Vector obj2) {
	int choice;
	float num = 0;
	choice = 0;
	while (choice != 7) {
		cout << "What to do" << endl;
		cout << "1 - add" << endl;
		cout << "2 - extract" << endl;
		cout << "3 - multipNum" << endl;
		cout << "4 - multipObj" << endl;
		cout << "5 - division" << endl;
		cout << "6 - get data" << endl;
		cout << "7 - exit" << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			obj1.Addition(obj1, obj2);
			break;
		case 2:
			obj1.Extraction(obj1, obj2);
			break;
		case 3:
			num = 0;
			while (num == 0 || num > 100) {
				cout << "enter number: ";
				cin >> num;
			}
			obj1.Multiplication(obj1, num);
			break;
		case 4:
			obj1.MultiplicationObj(obj1, obj2);
			break;
		case 5:
			num = 0;
			while (num == 0 || num > 100) {
				cout << "enter number: ";
				cin >> num;
			}
			obj1.Division(obj1, num);
			break;
		case 6:
			obj1.getData();
			break;
		}
	}
}

void menuMath(int k) {
	int frac=0;
	if (k == 1) {
		ComplexNum obj1 = ComplexNum();
		ComplexNum obj2 = ComplexNum();
		mathChoice(obj1, obj2);
	}
	if (k == 2) {
		int choice2 = -501;
		float x, y = 0;
		while (choice2 <= -500 || choice2 > 500) {
			cout << "Enter x: ";
			cin >> choice2;
		}
		x = choice2;
		choice2 = -501;
		while (choice2 < -500 || choice2 > 500 || choice2 == 0) {
			cout << "Enter y: ";
			cin >> choice2;
		}
		y = choice2;

		Fraction obj1 = Fraction(x, y);

		choice2 = -501;
		x, y = 0;
		while (choice2 <= -500 || choice2 > 500) {
			cout << "Enter x: ";
			cin >> choice2;
		}
		x = choice2;
		choice2 = -501;
		while (choice2 < -500 || choice2 > 500 || choice2 == 0) {
			cout << "Enter y: ";
			cin >> choice2;
		}
		y = choice2;

		Fraction obj2 = Fraction(x, y);
		mathChoice(obj1, obj2);
	}
	if (k == 3) {
		Matrix obj1 = Matrix();
		Matrix obj2 = Matrix();
		mathChoice(obj1, obj2);
	}
	if (k == 4) {
		Polinom obj1 = Polinom();
		Polinom obj2 = Polinom();
		mathChoice(obj1, obj2);
	}
	if (k == 5) {
		double x, y, z = 0;
		double choice2 = -501;
		while (choice2 < -500 || choice2 > 500) {
			cout << "Enter x: ";
			cin >> choice2;
		}
		x = choice2;
		choice2 = -501;
		while (choice2 < -500 || choice2 > 500) {
			cout << "Enter y: ";
			cin >> choice2;
		}
		y = choice2;
		choice2 = -501;
		while (choice2 < -500 || choice2 > 500) {
			cout << "Enter z: ";
			cin >> choice2;
		}
		z = choice2;
		Vector obj1 = Vector(x, y, z);

		x, y, z = 0;
		choice2 = -501;
		while (choice2 < -500 || choice2 > 500) {
			cout << "Enter x: ";
			cin >> choice2;
		}
		x = choice2;
		choice2 = -501;
		while (choice2 < -500 || choice2 > 500) {
			cout << "Enter y: ";
			cin >> choice2;
		}
		y = choice2;
		choice2 = -501;
		while (choice2 < -500 || choice2 > 500) {
			cout << "Enter z: ";
			cin >> choice2;
		}
		z = choice2;
		Vector obj2 = Vector(x, y, z);
		mathChoiceFix(obj1, obj2);
	}
}

void menuMain() {
	float temp = 0;
	int choice = 0;
	int choice2 = 0;

	while (choice != 3) {
		cout << "What to do" << endl;
		cout << "1 - math" << endl;
		cout << "2 - geometry" << endl;
		cout << "3 - exit" << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			while (choice2 != 6) {
				cout << "What to do" << endl;
				cout << "1 - Complex" << endl;
				cout << "2 - Fraction" << endl;
				cout << "3 - Matrix" << endl;
				cout << "4 - Polinom" << endl;
				cout << "5 - Vector" << endl;
				cout << "6 - exit" << endl;
				cout << "Your choice: ";
				cin >> choice2;

				switch (choice2) {
				case 1:
					menuMath(1);
					break;
				case 2:
					menuMath(2);
					break;
				case 3:
					menuMath(3);
					break;
				case 4:
					menuMath(4);
					break;
				case 5:
					menuMath(5);
					break;
				}
			}
			break;
		case 2:
			menuGeom();
			break;
		}
	}
}

int main()
{
	menuMain();
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