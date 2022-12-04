#include "Math.h"

Polinom::Polinom() {
	int choice = 0;
	while (choice <= 0 || choice > 10) {
		cout << "Enter size of the polinom: ";
		cin >> choice;
	}
	size = choice;
	for (int i = 0; i < size; i++) {
		choice = -101;
		while (choice < -100 || choice > 100) {
			cout << "Enter coefficient" << i << ": ";
			cin >> choice;
		}
		polinom.push_back(choice);
	}
}

void Polinom::getData() {
	cout << "Size: " << size << endl;
	cout << "Polinom coef: ";
	for (int i = 0; i < polinom.size(); i++) {
		cout << polinom[i];
	}
	cout << endl;
}

void Polinom::Extraction(Polinom a, Polinom b)
{
	vector<int> sum;
	for (int i = 0; i < a.size; i++)
		sum.push_back(a.polinom[i]);
	for (int i = 0; i < b.size && i < a.size; i++)
		sum[i] -= b.polinom[i];
	if (a.size > b.size) {
		for (int i = b.size; i < a.size; i++)
			sum.push_back(a.polinom[i]);
	}
	if (b.size > a.size) {
		for (int i = a.size; i < b.size; i++)
			sum.push_back(b.polinom[i]);
	}

	for (int i = 0; i < sum.size(); i++) {
		cout << sum[i];
		if (i != 0)
			cout << "x^" << i;
		if (i != sum.size() - 1)
			cout << " - ";
	}
	cout << endl;
}

void Polinom::Addition(Polinom a, Polinom b) {
	vector<int> sum;
	for (int i = 0; i < a.size; i++)
		sum.push_back(a.polinom[i]);
	for (int i = 0; i < b.size && i < a.size; i++)
		sum[i] += b.polinom[i];
	if (a.size > b.size) {
		for (int i = b.size; i < a.size; i++)
			sum.push_back(a.polinom[i]);
	}
	if (b.size > a.size) {
		for (int i = a.size; i < b.size; i++)
			sum.push_back(b.polinom[i]);
	}

	for (int i = 0; i < sum.size(); i++) {
		cout << sum[i];
		if (i != 0)
			cout << "x^" << i;
		if (i != sum.size() - 1)
			cout << " + ";
	}
	cout << endl;
}

void Polinom::Multiplication(Polinom a, float b)
{
	vector<int> sum;
	for (int i = 0; i < a.size; i++) {
		sum.push_back(a.polinom[i] * b);
	}

	for (int i = 0; i < sum.size(); i++) {
		cout << sum[i];
		if (i != 0)
			cout << "x^" << i;
		if (i != sum.size() - 1)
			cout << " + ";
	}
	cout << endl;
}

void Polinom::MultiplicationObj(Polinom a, Polinom b)
{
	vector<int> sum;
	for (int i = 0; i < a.size; i++) {
		for (int j = 0; j < b.size; j++) {
			sum.push_back(a.polinom[i] * b.polinom[j]);
		}
	}

	for (int i = 0; i < sum.size(); i++) {
		cout << sum[i];
		if (i != 0)
			cout << "x^" << i;
		if (i != sum.size() - 1)
			cout << " + ";
	}
	cout << endl;
}

void Polinom::Division(Polinom a, Polinom b)
{
	vector<int> sum;
	for (int i = 0; i < a.size; i++) {
		for (int j = 0; j < b.size; j++) {
			sum.push_back(b.polinom[i] / a.polinom[j]);
		}
	}

	for (int i = 0; i < sum.size(); i++) {
		cout << sum[i];
		if (i != 0)
			cout << "x^" << i;
		if (i != sum.size() - 1)
			cout << " + ";
	}
	cout << endl;
}
