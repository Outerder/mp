#include "Box.h"


Box::Box()
{
	
	relationBoxPhantom = false;
	intersectBox = false;
	vitesse = 0.05;
	box.setFillColor(Color::Yellow);
	box.setPosition(Vector2f(128, 128));

	phantomBox.setFillColor(Color::Cyan);
	phantomBox.setPosition(Vector2f(box.getPosition().x, box.getPosition().y));
}

void Box::boxIntersect(vector<RectangleShape>fond)
{
	for (int i = 0; i < fond.size(); i++)
	{
		if (phantomBox.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
			intersectBox = true;
			
		}
	}
}



void Box::boxDeplacement(int nb,float phantVit, vector<RectangleShape>fond,perso p)
{
	cout << box.getPosition().x << box.getPosition().y << endl;

	bool relationBoxPhantom = false;
	if (p.getPhantom().getGlobalBounds().intersects(box.getGlobalBounds()) && (nb == 1)) {
		cout << "il touche" << endl;
		
		phantomBox.setPosition((box.getPosition().x + 1), box.getPosition().y);//phantomBox position par rapport à box

		
		boxIntersect(fond);

		if (intersectBox == false) {

			box.setPosition((box.getPosition().x + 1), (box.getPosition().y));


			if (nb == 1 && p.getIntersect() == false) {
				
				p.setIntersect(true); 
			
			}
		}
		intersectBox = false;
	}
	if (p.getPhantom().getGlobalBounds().intersects(box.getGlobalBounds()) && (nb == 4)) {

		phantomBox.setPosition((box.getPosition().x), box.getPosition().y + 1);

		boxIntersect(fond);

		if (intersectBox == false) {
			box.setPosition((box.getPosition().x), (box.getPosition().y + 1));

		}
		intersectBox = false;

	}
	if (p.getPhantom().getGlobalBounds().intersects(box.getGlobalBounds()) && (nb == 2)) {

		phantomBox.setPosition((box.getPosition().x - 1), box.getPosition().y);

		boxIntersect(fond);

		if (intersectBox == false) {
			box.setPosition((box.getPosition().x - 1), (box.getPosition().y));

		}
		intersectBox = false;
	}
	if (p.getPhantom().getGlobalBounds().intersects(box.getGlobalBounds()) && (nb == 3)) {

		phantomBox.setPosition((box.getPosition().x), box.getPosition().y - 1);

		boxIntersect(fond);


		if (intersectBox == false) {
			box.setPosition((box.getPosition().x), (box.getPosition().y - 1));

		}
		intersectBox = false;
	}


}

void Box::boxSetPosition(float x,float y)
{
	box.setPosition(Vector2f(x,y));
	phantomBox.setPosition(Vector2f(box.getPosition().x, box.getPosition().y));
}

void Box::draw(RenderTarget&target)
{

target.draw(phantomBox);
target.draw(box);
}


