#include <SFML/Graphics.hpp>
#include "locale.h"
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

class Node {

public:
	string name;
    
	int x;
	int y;

	Node( int x, int y) 
	{
		this->x = x;
		this->y = y;
	}
};

int main()
{
	setlocale(LC_ALL, "russian");
	int n;
	cout << "Введите количество вершин графа\n";
	cin >> n ;

	vector <vector<int>> matrix;

	for (int i = 0; i < n; i++)
	{
		vector <int> help;
		for(int j = 0; j < n; j++)
		{
			help.push_back(0);
	    }
		matrix.push_back(help);
	}
	
	cout << "Введите матрицу инциндентности\n";
	string stroke;
	getline(cin, stroke, '\n');
	for (int k = 0; k < n; k++)
	{
		
		getline(cin, stroke, '\n');
		for (int h = 0; h < stroke.length(); h+=2)
		{
			matrix[k][h / 2] = (int)stroke[h] - 48;
		}
		
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix.at(i).at(j);
		}
		cout << "\n";
	}
	
	vector <Node> coord;
	for (int i = 0; i < n; i++)
	{
		Node help(rand() % (200 - 400 + 1) + 400 - 10, rand() % (200 - 400 + 1) + 200 - 10);
		coord.push_back(help);
	}
	
	RenderWindow window(VideoMode(1000, 1000), "Homework 2");
	
	while (window.isOpen())

	{
		

		Event event;

		while (window.pollEvent(event))

		{

			if (event.type == Event::Closed)

			window.close();

		}

		window.clear(Color(255,255,255));

		for (int i = 0; i < n; i++)
		{
			CircleShape name1(10);
			name1.setFillColor(Color::Red);
			name1.setPosition(coord[i].x, coord[i].y);
			window.draw(name1);
		}

		for (int i = 0; i < n ; i++)
		{
			for (int j = 0; j < n ; j++)
			{
				if (matrix[i][j] == 1)
				{
					Vertex newEdge[] =
					{
					  Vertex(Vector2f(coord[i].x +10, coord[i].y+10)),
					  Vertex(Vector2f(coord[j].x +10, coord[j].y+10))
					};
					newEdge[0].color = Color::Black;
					newEdge[1].color = Color::Black;
					window.draw(newEdge, 2, Lines);
				}
				else if (i == j)
				{

				}

			}
		}
		

		window.display();

	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 1)
				sum += 1;
		}
	}
	if (sum == (n - 1)*n)
	{
		cout << "Граф связанный\n";
	}
	else
		cout << "Граф несвязанный\n";
	
	system("pause");
	return 0;

}