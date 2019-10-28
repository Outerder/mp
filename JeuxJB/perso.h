#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Carte.h"
using namespace sf;
using namespace std;

class perso
{
private:

	RectangleShape pers;
	RectangleShape phantom;
	float vitesse;
	float phantVit;
	bool intersect = false;
	bool intersectBox = false;
	int nb;

public:

	perso();
	void draw(RenderTarget& target);
	void deplacement(vector <RectangleShape>);
	int GetNb();
	float GetPhantVit();
	Vector2f getPosition();
	RectangleShape getPhantom();
	void setPosition(float,float);
	bool getIntersect();
	void setIntersect(bool);
};

