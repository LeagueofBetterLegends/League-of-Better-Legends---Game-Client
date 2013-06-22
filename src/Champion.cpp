/*
 * Champion.cpp
 *
 *  Created on: May 16, 2013
 *      Author: User
 */

#include "Champion.h"


Champion::Champion () // This class is going to need some means of individually handling "Q,W,E,R"
{
}

Champion::Champion (std::string nameOf, int team, float movementSpeed, sf::Vector2f scale)
{
    forward1 = new sf::Texture; forward2 = new sf::Texture;
	backward1 = new sf::Texture;backward2 = new sf::Texture;

	//forward1->loadFromFile("Kennen/KennenForward1.png");
	forward1->loadFromFile(nameOf + "/" + nameOf + "Forward1.png");
	forward2->loadFromFile(nameOf + "/" + nameOf + "Forward2.png");
	backward1->loadFromFile(nameOf + "/" + nameOf + "Backward1.png");
	backward2->loadFromFile(nameOf + "/" + nameOf + "Backward2.png");

	sprite.setSize(sf::Vector2f(forward1->getSize().x, forward1->getSize().y));
	sprite.setTexture(forward1);
	//sprite.setTextureRect(sf::IntRect(0, 0, 198, 198));
	pState = 1;
	sprite.scale(scale);
	this->movementSpeed = movementSpeed;
	pTeam = team;

	//move1.loadFromFile("Kennen/Kennen1.wav");
	//move2.loadFromFile("Kennen/Kennen2.wav");
}

Champion::Champion (std::string nameOf, int team, float movementSpeed, float scaleX, float scaleY)
{
	forward1 = new sf::Texture;  forward2 = new sf::Texture;
	backward1 = new sf::Texture; backward2 = new sf::Texture;

	forward1->loadFromFile(nameOf + "/" + nameOf + "Forward1.png");
	forward2->loadFromFile(nameOf + "/" + nameOf + "Forward2.png");
	backward1->loadFromFile(nameOf + "/" + nameOf + "Backward1.png");
	backward2->loadFromFile(nameOf + "/" + nameOf + "Backward2.png");

	sprite.setSize(sf::Vector2f(forward1->getSize().x, forward1->getSize().y));
	sprite.setTexture(forward1);

	pState = 1;
	sprite.scale(scaleX, scaleY);
	//sprite.setTextureRect(sf::IntRect(0, 0, 198, 198));
	this->movementSpeed = movementSpeed;
	pTeam = team;


	//move1.loadFromFile("Kennen/Kennen1.wav");
	//move2.loadFromFile("Kennen/Kennen2.wav");
}

float Champion::getMovementSpeed ()
{
	return movementSpeed;
}

sf::Vector2f Champion::getPosition ()
{
	return sprite.getPosition();
}

void Champion::move (sf::Vector2f position)
{
	sprite.move(position);
}

void Champion::draw (sf::RenderWindow &App)
{
	App.draw(sprite);
}

void Champion::setState (int state)
{
	pState = state;

	if (state == 1)
	{
		sprite.setTexture(forward1);
	}
	else if (state == 2)
	{
		sprite.setTexture(forward2);
	}
	else if (state == 3)
	{
		sprite.setTexture(backward1);
	}
	else if (state == 4)
	{
		sprite.setTexture(backward2);
	}
}

int Champion::getState ()
{
	return pState;
}

int Champion::getTeam ()
{
	return pTeam;
}
