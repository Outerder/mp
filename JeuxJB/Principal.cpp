#include <SFML/Graphics.hpp>
using namespace sf;
#include <vector>
#include <iostream>
using namespace std;

int gmain()
{
	sf::RenderWindow window(sf::VideoMode(320, 320), "SFML works!");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);


	Vector2f v(31.f, 31.f);



	int map[10][10] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 2, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

	};


	vector <RectangleShape> fond;
	vector <RectangleShape> boxes;

	RectangleShape perso(v);
	perso.setFillColor(Color::Blue);
	perso.setPosition(Vector2f(32, 32));

	RectangleShape box(v);
	box.setFillColor(Color::Yellow);
	box.setPosition(Vector2f(128, 128));



#pragma region decor

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (map[j][i] == 1) {

				RectangleShape carre(v);

				carre.setFillColor(sf::Color::Red);
				carre.setPosition(Vector2f(i * 32, j * 32));
				fond.push_back(carre);
			}
			if (map[j][i] == 2) {

				//RectangleShape box(v);
				//box.setFillColor(Color::Yellow);
				//box.setPosition(Vector2f(i * 32, j * 32));
				//boxes.push_back(box);
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

		RectangleShape phantomBox(v);
		phantomBox.setFillColor(Color::Cyan);
		phantomBox.setPosition(Vector2f(box.getPosition().x, box.getPosition().y));






		clockPerso.getElapsedTime().asSeconds() >= 0.025;


#pragma region deplacement
		float vitesse = 0.025;
		bool intersect = false;
		bool intersectBox = false;
		int nb = 0;
		if (Keyboard::isKeyPressed(Keyboard::Right))nb = 1;
		if (Keyboard::isKeyPressed(Keyboard::Left))nb = 2;
		if (Keyboard::isKeyPressed(Keyboard::Up))nb = 3;
		if (Keyboard::isKeyPressed(Keyboard::Down))nb = 4;
		if (nb == 1) {



			phantom.setPosition(Vector2f(perso.getPosition().x + vitesse, perso.getPosition().y));


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

			phantom.setPosition(Vector2f(perso.getPosition().x - vitesse, perso.getPosition().y));


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

			phantom.setPosition(Vector2f(perso.getPosition().x, perso.getPosition().y - vitesse));

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

			phantom.setPosition(Vector2f(perso.getPosition().x, perso.getPosition().y + vitesse));

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
		if (phantom.getGlobalBounds().intersects(box.getGlobalBounds()) && (nb == 1)) {

			phantomBox.setPosition((box.getPosition().x + 1), box.getPosition().y);//phantomBox position par rapport à box

			for (int i = 0; i < fond.size(); i++)
			{
				if (phantomBox.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
					intersectBox = true;

				}
			}
			//intersection phantomBox et Fond

			if (intersectBox == false) {
				box.setPosition((box.getPosition().x + 1), (box.getPosition().y));
				if (nb == 1 && intersect == false) { intersect = true; }
			}
			intersectBox = false;
		}
		if (phantom.getGlobalBounds().intersects(box.getGlobalBounds()) && (nb == 4)) {

			phantomBox.setPosition((box.getPosition().x), box.getPosition().y + 1);

			for (int i = 0; i < fond.size(); i++)
			{
				if (phantomBox.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
					intersectBox = true;
				}
			}
			if (intersectBox == false) {
				box.setPosition((box.getPosition().x), (box.getPosition().y + 1));

			}
			intersectBox = false;

		}
		if (phantom.getGlobalBounds().intersects(box.getGlobalBounds()) && (nb == 2)) {

			phantomBox.setPosition((box.getPosition().x - 1), box.getPosition().y);

			for (int i = 0; i < fond.size(); i++)
			{
				if (phantomBox.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
					intersectBox = true;
				}
			}
			if (intersectBox == false) {
				box.setPosition((box.getPosition().x - 1), (box.getPosition().y));

			}
			intersectBox = false;
		}
		if (phantom.getGlobalBounds().intersects(box.getGlobalBounds()) && (nb == 3)) {

			phantomBox.setPosition((box.getPosition().x), box.getPosition().y - 1);

			for (int i = 0; i < fond.size(); i++)
			{
				if (phantomBox.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {
					intersectBox = true;
				}
			}
			if (intersectBox == false) {
				box.setPosition((box.getPosition().x), (box.getPosition().y - 1));

			}
			intersectBox = false;
		}

#pragma region boxsolide
		if (nb == 1) {
			for (int i = 0; i < fond.size(); i++) {
				if (phantom.getGlobalBounds().intersects(box.getGlobalBounds()) && phantomBox.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {

					perso.setPosition(box.getPosition().x - (box.getSize().x), perso.getPosition().y);

					//cout << "il touche" << endl;
				}
			}
		}
		if (nb == 2) {
			for (int i = 0; i < fond.size(); i++) {
				if (phantom.getGlobalBounds().intersects(box.getGlobalBounds()) && phantomBox.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {

					perso.setPosition(box.getPosition().x + (box.getSize().x), perso.getPosition().y);

					//cout << "il touche" << endl;
				}
			}
		}
		if (nb == 3) {
			for (int i = 0; i < fond.size(); i++) {
				if (phantom.getGlobalBounds().intersects(box.getGlobalBounds()) && phantomBox.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {

					//perso.setPosition(box.getPosition().x + (box.getSize().x), perso.getPosition().y);
					perso.setPosition(perso.getPosition().x, box.getPosition().y + (box.getSize().y));

					//cout << "il touche" << endl;
				}
			}
		}
		if (nb == 4) {
			for (int i = 0; i < fond.size(); i++) {
				if (phantom.getGlobalBounds().intersects(box.getGlobalBounds()) && phantomBox.getGlobalBounds().intersects(fond[i].getGlobalBounds())) {

					//perso.setPosition(box.getPosition().x + (box.getSize().x), perso.getPosition().y);
					perso.setPosition(perso.getPosition().x, box.getPosition().y - (box.getSize().y));

					//cout << "il touche" << endl;
				}
			}
		}
#pragma endregion boxsolide

#pragma endregion box

		window.clear();

		for (int i = 0; i < fond.size(); i++)window.draw(fond[i]);
		window.draw(phantom);
		window.draw(perso);
		window.draw(phantomBox);
		window.draw(box);

		window.display();
	}

	return 0;
}