#pragma once
#include <SFML/Graphics.hpp>
#include<string>
#include <iostream>
#include <vector>
using namespace sf;
using namespace std;

class Square
{

private:

	Vector2f v = Vector2f(62, 62);

	//Vector2f v(10.f, 10.f);
	//RectangleShape rect(v);

public:

	Square();
	void CreateSquare(int, int);


};

