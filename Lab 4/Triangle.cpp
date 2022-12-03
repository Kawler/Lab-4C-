#include "Geometry.h"

static float turn = 0;

Triangle::Triangle() {
	double temp = -51;
	cout << "Enter your triangle: " << endl;

	for (int i = 0; i < 3; i++) {
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
	side[2] = sqrt(pow((x[2] - x[0]), 2) + pow((y[2] - y[0]), 2));

}

void Triangle::moveObj()
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
			for (int i = 0; i <3;i++)
				x[i] += temp;
			temp = 0;
			break;
		case 2:
			while (temp <= 0 || temp > 50) {
				cout << "Enter value: ";
				cin >> temp;
			}
			for (int i = 0; i < 3; i++)
				y[i] += temp;
			temp = 0;
			break;
		}
	}
}

void Triangle::turnObj()
{
	float temp = 0;
	while (temp <= 0 || temp > 360) {
		cout << "Enter value: ";
		cin >> temp;
	}
	turn += temp;
}

void Triangle::area()
{
	double hp = (side[0] + side[1] + side[2]) / 2;
	double s = pow(hp * (hp - side[0]) * (hp - side[1]) * (hp - side[2]), 0.5);
	cout << "Area = " << s << endl;
}

void Triangle::perimetr()
{
	cout << "Perimetr = " << side[0] + side[1] + side[2] << endl;
}

void Triangle::draw()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Window");
	sf::ConvexShape convex;
	convex.setPointCount(3);
	convex.setPoint(0, sf::Vector2f(300+x[0]*10, 300 - y[0]*10));
	convex.setPoint(1, sf::Vector2f(300 + x[1] * 10, 300 - y[1] * 10));
	convex.setPoint(2, sf::Vector2f(300 + x[2] * 10, 300 - y[2] * 10));
	convex.setOrigin(300 + x[0] * 10, 300 - y[0] * 10);
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
		window.draw(line,2,sf::Lines);
		window.draw(line2, 2, sf::Lines);
		window.draw(convex);
		window.display();
	}
}
