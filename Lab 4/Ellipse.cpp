#include "Geometry.h"

static float turn = 0;

Ellipse::Ellipse()
{
	double temp = 0;
	cout << "Enter your ellipse: " << endl;
	while (temp <= 0 || temp > 10) {
		cout << "Enter R: ";
		cin >> temp;
	}
	sideA = temp;
	temp = -51;
	while (temp <= 0 || temp > 3) {
		cout << "Enter relationship of r to R (3 for 3:1, 2 for 2:1) : ";
		cin >> temp;
	}
	sideB = temp;
	ct[0] = 0;
	ct[1] = 0;
}

void Ellipse::moveObj()
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

void Ellipse::turnObj()
{
	float temp = 0;
	while (temp <= 0 || temp > 360) {
		cout << "Enter value: ";
		cin >> temp;
	}
	turn += temp;
}

void Ellipse::area()
{
	cout << "Area = " << sideA * sideB <<"pi" << endl;
}

void Ellipse::perimetr()
{
	cout << "Perimetr = " << 4 * (sideA * sideB + (sideA - sideB)) / (sideA + sideB) << endl;
}

void Ellipse::draw()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Window");
	sf::CircleShape convex(sideA*5);
	convex.scale(sideB, 1);
	convex.setPosition(300 + ct[0], 300 - ct[1]);
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
