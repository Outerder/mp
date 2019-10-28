#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Carte.h"
#include "perso.h"
#include "Box.h"
using namespace sf;
using namespace std;




int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 960), "SFML works!");

	Carte map;
	perso man;
	Box b;

	while (window.isOpen())
	{
		b.boxIntersect(map.getFond());
		man.deplacement(map.getFond());
		b.boxDeplacement(man.GetNb(), man.GetPhantVit(), map.getFond(), man);













		window.clear();
		man.draw(window);

		//map.drawPhantomBox(window);
		map.draw(window);
		map.drawBox(window);

		cout << map.boxes.size() << endl;


		window.display();


	}

	return 0;
}
