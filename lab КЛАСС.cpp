

#include "pch.h"
#include <iostream>
#include <string>
#include "lab.h"

using namespace std;

class Ellipse
{
public:
	int Ox, Oy;
	int a, b;
	double S, pi;
	string name;
	Ellipse(int x, int y, string n)
	{
		Ox = x;
		Oy = y;
		name = n;
	}
	Ellipse();
	void move()
	{

		cout << name << endl;
	}
};


int main()
{
	Ellipse object1, object2, object2;
	object1.name = "";

	Ellipse.draw();


	return 0;
}

Ellipse::Ellipse()
{
}
