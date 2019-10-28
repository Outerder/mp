#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "perso.h"
#include "Carte.h"
using namespace std;
using namespace sf;
class perso;

class Box
{
private:
	Vector2f v= Vector2f(62, 62);
	bool relationBoxPhantom;
	bool intersectBox ;
	float vitesse;

	//perso* p;

public:
	RectangleShape box = RectangleShape(v);
	RectangleShape phantomBox = RectangleShape(v);

	Box();
	void boxIntersect(vector <RectangleShape>);
	void boxDeplacement(int,float,vector<RectangleShape>,perso);
	void boxSetPosition(float, float);
	void draw(RenderTarget&);
};

