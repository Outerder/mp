#include "Carte.h"
#include <stdlib.h>

Carte::Carte()
{
	v = Vector2f(62, 62);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++) {
			if (map[j][i] == 1) {

				RectangleShape carre(v);

				carre.setFillColor(sf::Color::White);
				carre.setPosition(Vector2f(i * 64, j * 64));
				fond.push_back(carre);
			}
			if (map[j][i] == 2) {

				Box* b = new Box;
				b->boxSetPosition(i * 64, j * 64);
				boxes.push_back(b);


				/*RectangleShape* phantomBox= new RectangleShape(v);
				phantomBox->setFillColor(Color::Yellow);
				phantomBox->setPosition(Vector2f(box->getPosition().x, box->getPosition().y));
				phantomBoxes.push_back(phantomBox);*/
			}
		}
	}



}

void Carte::draw(RenderTarget& target)
{

	for (int i = 0; i < fond.size(); i++) target.draw(fond[i]);

}

void Carte::drawBox(RenderTarget& target)
{
	for (int j = 0; j < boxes.size(); j++) {
		boxes[j]->draw(target);

	}
}

/*void Carte::drawPhantomBox(RenderTarget& target)
{
	for (int j = 0; j < phantomBoxes.size(); j++) target.draw(phantomBoxes[j]);
}*/

vector<RectangleShape> Carte::getFond()
{
	return fond;
}

/*vector<RectangleShape> Carte::getPhantomBox()
{
	return phantomBoxes;
}*/

/*vector<RectangleShape> Carte::getBox()
{
	return boxes;
}*/
