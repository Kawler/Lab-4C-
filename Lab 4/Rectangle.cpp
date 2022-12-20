#include "Geometry.h"

static float turn = 0;

Rectangle::Rectangle()
{
	bool condition = false;
	double temp = -51;
	while (condition == false) {
		cout << "Enter your reactnagle: " << endl;

		for (int i = 0; i < 4; i++) {
			while (temp <= -50 || temp > 50) {
				cout << "Enter x" << i << ": ";
				cin >> temp;
			}
			x[i] = temp;
			temp = -51;
			while (temp <= -50 || temp > 50) {
				cout << "Enter y" << i << ": ";
				cin >> temp;
			}
			y[i] = temp;
			temp = -51;
		}

		side[0] = sqrt(pow((x[0] - x[1]), 2) + pow((y[0] - y[1]), 2));
		side[1] = sqrt(pow((x[1] - x[2]), 2) + pow((y[1] - y[2]), 2));
		side[2] = sqrt(pow((x[2] - x[3]), 2) + pow((y[2] - y[3]), 2));
		side[3] = sqrt(pow((x[3] - x[0]), 2) + pow((y[3] - y[0]), 2));

		if (side[0]==side[2]&&side[1]==side[3]&&side[0]*side[1]>0)
			condition = true;
	}
}

void Rectangle::moveObj()
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
			for (int i = 0; i < 4; i++)
				x[i] += temp;
			temp = 0;
			break;
		case 2:
			while (temp <= 0 || temp > 50) {
				cout << "Enter value: ";
				cin >> temp;
			}
			for (int i = 0; i < 4; i++)
				y[i] += temp;
			temp = 0;
			break;
		}
	}
}

void Rectangle::turnObj()
{
	float pi = 3.14159265359;
	float temp = 0;
	while (temp <= 0 || temp > 360) {
		cout << "Enter value: ";
		cin >> temp;
	}
	turn += temp;
	temp = turn * (pi / 180);
	cout << "New point x[1]" << (x[1] - x[0]) * cos(-temp) - (y[1] - y[0]) * sin(-temp) + x[0] << endl;
	cout << "New point y[1]" << (x[1] - x[0]) * sin(-temp) + (y[1] - y[0]) * cos(-temp) + x[0] << endl;
	cout << "New point x[2]" << (x[2] - x[0]) * cos(-temp) - (y[2] - y[0]) * sin(-temp) + x[0] << endl;
	cout << "New point y[2]" << (x[2] - x[0]) * sin(-temp) + (y[2] - y[0]) * cos(-temp) + x[0] << endl;
	cout << "New point x[3]" << (x[3] - x[0]) * cos(-temp) - (y[3] - y[0]) * sin(-temp) + x[0] << endl;
	cout << "New point y[3]" << (x[3] - x[0]) * sin(-temp) + (y[3] - y[0]) * cos(-temp) + x[0] << endl;
}

void Rectangle::area()
{
	cout << "Area = " << side[0]*side[1] << endl;
}

void Rectangle::perimetr()
{
	cout << "Perimetr = " << (side[0]+side[1]) * 2 << endl;
}

void Rectangle::draw()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Window");
	sf::ConvexShape convex;
	convex.setPointCount(5);
	convex.setPoint(0, sf::Vector2f(300 + x[0] * 10, 300 - y[0] * 10));
	convex.setPoint(1, sf::Vector2f(300 + x[1] * 10, 300 - y[1] * 10));
	convex.setPoint(2, sf::Vector2f(300 + x[2] * 10, 300 - y[2] * 10));
	convex.setPoint(3, sf::Vector2f(300 + x[3] * 10, 300 - y[3] * 10));
	convex.setPoint(4, sf::Vector2f(300 + x[3] * 10, 300 - y[3] * 10));
	convex.setOrigin(300, 300);
	convex.setPosition(300, 300);
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
