#include <SFML/Graphics.hpp>
using namespace sf;
#include <vector>
#include <iostream>
using namespace std;

int mmain()
{
	sf::RenderWindow window(sf::VideoMode(960, 960), "SFML works!");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);


	Vector2f v(62.f, 62.f);



	int map[15][15] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

	};


	vector <RectangleShape> fond;
	vector <RectangleShape> boxes;
	vector <RectangleShape> phantomBoxes;

	RectangleShape perso(v);
	perso.setFillColor(Color::Blue);
	perso.setPosition(Vector2f(64, 64));

	//RectangleShape box(v);
	//box.setFillColor(Color::Yellow);
	//box.setPosition(Vector2f(128, 128));


#pragma region decor

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

				RectangleShape box(v);
				box.setFillColor(Color::Red);
				box.setPosition(Vector2f(i * 64, j * 64));
				boxes.push_back(box);


				RectangleShape phantomBox(v);
				phantomBox.setFillColor(Color::Yellow);
				phantomBox.setPosition(Vector2f(box.getPosition().x, box.getPosition().y));
				phantomBoxes.push_back(phantomBox);
			}
		}
	}


#pragma endregion


	Clock clockPerso;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}





		RectangleShape phantom(v);
		phantom.setFillColor(Color::Green);
		phantom.setPosition(Vector2f(perso.getPosition().x, perso.getPosition().y));








		clockPerso.getElapsedTime().asSeconds() >= 0.05;


#pragma region deplacement
		float vitesse = 0.05;
		float phantVit = 2;
		bool intersect = false;
		bool intersectBox = false;
		int nb = 0;
		if (Keyboard::isKeyPressed(Keyboard::Right))nb = 1;
		else if (Keyboard::isKeyPressed(Keyboard::Left))nb = 2;
		else if (Keyboard::isKeyPressed(Keyboard::Up))nb = 3;
		else if (Keyboard::isKeyPressed(Keyboard::Down))nb = 4;
		
		if (nb == 1) {



			phantom.setPosition(Vector2f(perso.getPosition().x + phantVit, perso.getPosition().y));


			for (int i = 0; i < fond.size(); i++)
			{
				if (phantom.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
					intersect = true;

				}

			}
			if (intersect == false)
			{

				perso.move(vitesse, 0);

			}

			intersect = false;
		};
		if (nb == 2) {

			phantom.setPosition(Vector2f(perso.getPosition().x - phantVit, perso.getPosition().y));


			for (int i = 0; i < fond.size(); i++)
			{
				if (phantom.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
					intersect = true;
				}
			}

			if (intersect == false)
			{
				perso.move(-vitesse, 0);
			}

			intersect = false;
		};
		if (nb == 3) {

			phantom.setPosition(Vector2f(perso.getPosition().x, perso.getPosition().y - phantVit));

			for (int i = 0; i < fond.size(); i++)
			{
				if (phantom.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
					intersect = true;
				}
			}
			if (intersect == false)
			{
				perso.move(0, -vitesse);

			}

			intersect = false;

		};
		if (nb == 4) {

			phantom.setPosition(Vector2f(perso.getPosition().x, perso.getPosition().y + phantVit));

			for (int i = 0; i < fond.size(); i++)
			{
				if (phantom.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
					intersect = true;
				}
			}
			if (intersect == false)
			{
				perso.move(0, vitesse);

			}

			intersect = false;


		};
		
#pragma endregion

#pragma region box
		bool relationBoxPhantom = false;

		for (int j = 0; j < phantomBoxes.size(); j++) {
			if (phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds()) && (nb == 1)) {


				phantomBoxes[j].setPosition((boxes[j].getPosition().x + phantVit), boxes[j].getPosition().y);

				//phantomBox position par rapport à box

				for (int i = 0; i < fond.size(); i++)
				{

					if (phantomBoxes[j].getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
						intersectBox = true;

					}

				}
				//intersection phantomBox et Fond
				for (int k = 0; k < boxes.size(); k++)
				{

					if (j != k && phantomBoxes[j].getGlobalBounds().intersects(boxes[k].getGlobalBounds())) {
						//perso.setPosition(perso.getPosition().x, boxes[i].getSize()-boxes[i].getSize().y);
						cout << "contact jaune" << endl;
						intersectBox = true;
					}
				}
				if (intersectBox == false) {

					boxes[j].setPosition((boxes[j].getPosition().x + vitesse), (boxes[j].getPosition().y));

				
				}
				intersectBox = false;
			}
			else if (nb == 0) { phantomBoxes[j].setPosition((boxes[j].getPosition().x), boxes[j].getPosition().y); }

		}
		for (int j = 0; j < phantomBoxes.size(); j++) {
			if (phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds()) && (nb == 4)) {


				phantomBoxes[j].setPosition((boxes[j].getPosition().x), boxes[j].getPosition().y + phantVit);


				
				for (int i = 0; i < fond.size(); i++)
				{

					if (phantomBoxes[j].getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
						intersectBox = true;
					}

				}
				for (int k = 0; k < boxes.size(); k++)
				{

					if (j != k && phantomBoxes[j].getGlobalBounds().intersects(boxes[k].getGlobalBounds())) {
						//perso.setPosition(perso.getPosition().x, boxes[i].getSize()-boxes[i].getSize().y);
						cout << "contact jaune" << endl;
						intersectBox = true;
					}
				}
				if (intersectBox == false) {

					boxes[j].setPosition((boxes[j].getPosition().x), (boxes[j].getPosition().y + vitesse));


				}
				intersectBox = false;

			}
			else if (nb == 0) { phantomBoxes[j].setPosition((boxes[j].getPosition().x), boxes[j].getPosition().y); }

		}
		for (int j = 0; j < phantomBoxes.size(); j++) {
			if (phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds()) && (nb == 2)) {


				phantomBoxes[j].setPosition((boxes[j].getPosition().x - phantVit), boxes[j].getPosition().y);


				for (int i = 0; i < fond.size(); i++)
				{

					if (phantomBoxes[j].getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
						intersectBox = true;
					}

				}
				for (int k = 0; k < boxes.size(); k++)
				{

					if (j != k && phantomBoxes[j].getGlobalBounds().intersects(boxes[k].getGlobalBounds())) {
						//perso.setPosition(perso.getPosition().x, boxes[i].getSize()-boxes[i].getSize().y);
						cout << "contact jaune" << endl;
						intersectBox = true;
					}
				}
				if (intersectBox == false) {

					boxes[j].setPosition((boxes[j].getPosition().x - vitesse), (boxes[j].getPosition().y));

				}
				intersectBox = false;
			}
			else if (nb == 0) { phantomBoxes[j].setPosition((boxes[j].getPosition().x), boxes[j].getPosition().y); }

		}
		for (int j = 0; j < phantomBoxes.size(); j++) {
			if (phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds()) && (nb == 3)) {


				phantomBoxes[j].setPosition((boxes[j].getPosition().x), boxes[j].getPosition().y - phantVit);


				for (int i = 0; i < fond.size(); i++)
				{

					if (phantomBoxes[j].getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
						intersectBox = true;
					}
				}
				for (int k = 0; k < boxes.size(); k++)
				{

					if (j != k && phantomBoxes[j].getGlobalBounds().intersects(boxes[k].getGlobalBounds())) {
						//perso.setPosition(perso.getPosition().x, boxes[i].getSize()-boxes[i].getSize().y);
						cout << "contact jaune" << endl;
						intersectBox = true;
					}
				}

				if (intersectBox == false) {
						boxes[j].setPosition((boxes[j].getPosition().x), (boxes[j].getPosition().y - vitesse));

				}

					intersectBox = false;
				

			}
			else if (nb == 0) { phantomBoxes[j].setPosition((boxes[j].getPosition().x), boxes[j].getPosition().y); }

		}
		
#pragma region boxsolide
		if (nb == 1) {
			for (int i = 0; i < fond.size(); i++) {
				for (int j = 0; j < boxes.size(); j++) {
					if (phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds()) && phantomBoxes[j].getGlobalBounds().intersects(fond[i].getGlobalBounds())) {

						perso.setPosition(boxes[j].getPosition().x - (boxes[j].getSize().x), perso.getPosition().y);
					}
				}
				//cout << "il touche" << endl;
			}
			for (int j = 0; j < boxes.size(); j++)
			{
				for (int k = 0; k < boxes.size(); k++)
				{
					if (j != k && phantomBoxes[j].getGlobalBounds().intersects(boxes[k].getGlobalBounds()) && phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds())) {
						perso.setPosition(boxes[j].getPosition().x - (boxes[j].getSize().x), perso.getPosition().y);
					}
				}
			}
		}
		else if (nb == 2) {
			for (int i = 0; i < fond.size(); i++) {
				for (int j = 0; j < boxes.size(); j++) {
					if (phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds()) && phantomBoxes[j].getGlobalBounds().intersects(fond[i].getGlobalBounds())) {

						perso.setPosition(boxes[j].getPosition().x + (boxes[j].getSize().x), perso.getPosition().y);

						//cout << "il touche" << endl;
					}
				}
			}
			for (int j = 0; j < boxes.size(); j++)
			{
				for (int k = 0; k < boxes.size(); k++)
				{
					if (j != k && phantomBoxes[j].getGlobalBounds().intersects(boxes[k].getGlobalBounds())&& phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds())) {
						perso.setPosition(boxes[j].getPosition().x + (boxes[j].getSize().x), perso.getPosition().y);
					}
				}
			}
		}
		else if (nb == 3) {
			for (int i = 0; i < fond.size(); i++) {
				for (int j = 0; j < boxes.size(); j++) {
					if (phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds()) && phantomBoxes[j].getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
						
						perso.setPosition(perso.getPosition().x, boxes[j].getPosition().y + (boxes[j].getSize().y));

					}
				}
			}
			for (int j = 0; j < boxes.size(); j++)
			{
				for (int k = 0; k < boxes.size(); k++)
				{
					if (j != k && phantomBoxes[j].getGlobalBounds().intersects(boxes[k].getGlobalBounds()) && phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds())) {
						perso.setPosition(perso.getPosition().x, boxes[j].getPosition().y + (boxes[j].getSize().y));
					}
				}
			}
		}
		else if (nb == 4) {
			for (int i = 0; i < fond.size(); i++) {
				for (int j = 0; j < boxes.size(); j++) {

					if (phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds()) && phantomBoxes[j].getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
		
						perso.setPosition(perso.getPosition().x, boxes[j].getPosition().y - (boxes[j].getSize().y));
	
					}
				}
			}
			for (int j = 0; j < boxes.size(); j++)
			{
				for (int k = 0; k < boxes.size(); k++)
				{
					if (j!=k&&phantomBoxes[j].getGlobalBounds().intersects(boxes[k].getGlobalBounds()) && phantom.getGlobalBounds().intersects(boxes[j].getGlobalBounds())) {
						perso.setPosition(perso.getPosition().x, boxes[j].getPosition().y - (boxes[j].getSize().y));
					}
				}
			}

			
	}
		

#pragma endregion boxsolide

#pragma endregion box

		window.clear();

		for (int i = 0; i < fond.size(); i++) { window.draw(fond[i]); }
		for (int j = 0; j < boxes.size(); j++) { window.draw(phantomBoxes[j]); }
		for (int j = 0; j < boxes.size(); j++) { window.draw(boxes[j]); }
		window.draw(phantom);
		window.draw(perso);
		//window.draw(phantomBox);
		//window.draw(box);

		window.display();
	}

	return 0;
}


/*
				if (phantom.getGlobalBounds().intersects(boxes[i].getGlobalBounds())) {
					for (int j = 0; j < boxes.size(); j++) {
						for (int k = 0; k < phantomBoxes.size(); k++) {
							phantomBoxes[k].setPosition((boxes[i].getPosition().x +depX), boxes[i].getPosition().y +depY);
						}
					}
					for (int i = 0; i < fond.size(); i++)
					{
						for (int i = 0; i < phantomBoxes.size(); i++) {
							if (phantomBoxes[i].getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
								intersectBox = true;
							}
						}
					}
					if (intersectBox == false) {
						for (int i = 0; i < boxes.size(); i++) {
							boxes[i].setPosition((boxes[i].getPosition().x - 1), (boxes[i].getPosition().y));
						}
					}
					intersectBox = false;
				}
*/