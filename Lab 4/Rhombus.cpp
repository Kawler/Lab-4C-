#include "Geometry.h"

static float turn = -45;

Rhombus::Rhombus()
{
	double temp = 0;
	cout << "Enter your rectangle: " << endl;
	while (temp <= 0 || temp > 20) {
		cout << "Enter side a: ";
		cin >> temp;
	}
	sideA = temp;
	ct[0] = 0;
	ct[1] = 0;
}

void Rhombus::moveObj()
{
	float temp = 0;
	int choice = 0;

	while (choice != 3) {
		cout << "What to do" << endl;
		cout << "1 - x axis" << endl;
		cout << "2 - y axis" << endl;
		cout << "3 - exit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			while (temp <= 0 || temp > 50) {
				cout << "Enter value: ";
				cin >> temp;
			}
			ct[0] += temp;
			temp = 0;
			break;
		case 2:
			while (temp <= 0 || temp > 50) {
				cout << "Enter value: ";
				cin >> temp;
			}
			ct[1] += temp;
			temp = 0;
			break;
		}
	}
}

void Rhombus::turnObj()
{
	float temp = 0;
	while (temp <= 0 || temp > 360) {
		cout << "Enter value: ";
		cin >> temp;
	}
	turn += temp;
}

void Rhombus::area()
{
	cout << "Area = " << sideA * sideA << endl;
}

void Rhombus::perimetr()
{
	cout << "Perimetr = " << sideA * 4 << endl;
}

void Rhombus::draw()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Window");
	sf::RectangleShape convex(sf::Vector2f(sideA * 10, sideA * 10));
	convex.setPosition(300 + ct[0], 300 + ct[1]);
	convex.setRotation(turn);
	convex.setFillColor(sf::Color::Blue);
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(0, 300)),
		sf::Vertex(sf::Vector2f(600, 300))
	};
	sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f(300, 0)),
		sf::Vertex(sf::Vector2f(300, 600))
	};
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(line, 2, sf::Lines);
		window.draw(line2, 2, sf::Lines);
		window.draw(convex);
		window.display();
	}
}
