#include "perso.h"

perso::perso()
{
	vitesse = 0.05;
	phantVit = 2;

	pers.setSize(Vector2f(60.f, 60.f));
	pers.setFillColor(Color::Blue);
	pers.setPosition(Vector2f(64, 64));

	phantom.setSize(Vector2f(60.f, 60.f));
	phantom.setFillColor(Color::Green);
	phantom.setPosition(Vector2f(64, 64));
}

void perso::draw(RenderTarget& target)
{
	target.draw(phantom);
	target.draw(pers);
}

void perso::deplacement(vector <RectangleShape> fond)
{
	phantom.setPosition(Vector2f(pers.getPosition().x, pers.getPosition().y));
	nb = 0;
	if (Keyboard::isKeyPressed(Keyboard::Right))nb = 1;
	else if (Keyboard::isKeyPressed(Keyboard::Left))nb = 2;
	else if (Keyboard::isKeyPressed(Keyboard::Up))nb = 3;
	else if (Keyboard::isKeyPressed(Keyboard::Down))nb = 4;

	if (nb == 1) {



		phantom.setPosition(Vector2f(pers.getPosition().x + phantVit, pers.getPosition().y));


		for (int i = 0; i < fond.size(); i++)
		{
			if (phantom.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
				intersect = true;
				
			}

		}
		if (intersect == false)
		{
		
			pers.move(vitesse, 0);

		}

		intersect = false;
	};
	if (nb == 2) {

		phantom.setPosition(Vector2f(pers.getPosition().x - phantVit, pers.getPosition().y));


		for (int i = 0; i < fond.size(); i++)
		{
			if (phantom.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
				intersect = true;
			}
		}

		if (intersect == false)
		{
			pers.move(-vitesse, 0);
		}

		intersect = false;
	};
	if (nb == 3) {

		phantom.setPosition(Vector2f(pers.getPosition().x, pers.getPosition().y - phantVit));

		for (int i = 0; i <fond.size(); i++)
		{
			if (phantom.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
				intersect = true;
			}
		}
		if (intersect == false)
		{
			pers.move(0, -vitesse);

		}

		intersect = false;

	};
	if (nb == 4) {

		phantom.setPosition(Vector2f(pers.getPosition().x, pers.getPosition().y + phantVit));

		for (int i = 0; i < fond.size(); i++)
		{
			if (phantom.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
				intersect = true;
			}
		}
		if (intersect == false)
		{
			pers.move(0, vitesse);

		}

		intersect = false;


	};



}

int perso::GetNb()
{
	return nb;
}

float perso::GetPhantVit()
{
	return phantVit;
}

Vector2f perso::getPosition()
{
	return pers.getPosition();
}

RectangleShape perso::getPhantom()
{
	return phantom;
}

void perso::setPosition(float x, float y)
{
	pers.setPosition( x,y );
}

bool perso::getIntersect()
{
	return intersect;
}

void perso::setIntersect(bool n)
{
	intersect = n;
}



