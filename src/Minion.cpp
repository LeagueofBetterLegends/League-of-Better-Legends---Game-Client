/*
 * minion.cpp
 *
 *  Created on: May 28, 2013
 *      Author: User
 */

#include "Minion.h"
#include "utility/file.h"
#include "settingsBase.h"

#include <math.h>

Minion::Minion(sf::Vector2f position, int team)
{
	sf::Texture* temp = new sf::Texture;
	sf::Image iTemp;

	settingsBase sb;

	File fPath ("Minion/" + )
	if (team == 1)
	{
		iTemp.loadFromFile("Minion/minion.png");
	}else if (team == 2)
	{
		iTemp.loadFromFile("Minion/blueMinion.png");
	}

	iTemp.createMaskFromColor(iTemp.getPixel(0,0));
	temp->loadFromImage(iTemp);

	sprite.setSize(sf::Vector2f(temp->getSize().x, temp->getSize().y));
	sprite.setTexture(temp);
	sprite.setPosition(position);

	pPosition = position;
	pTeam = team;
	pHealth = 4;
	pIsSuper = false;
	sight.setOrigin(pPosition);
	isAlive = true;
	pMaxHealth = 100;
}

Minion::Minion (sf::Vector2f position, int team, bool isSuper, int health)
{
	sf::Texture* temp = new sf::Texture;
	sf::Image iTemp; iTemp.loadFromFile("Minion/minion.png"); iTemp.createMaskFromColor(iTemp.getPixel(0,0));
	temp->loadFromImage(iTemp);
	sprite.setSize(sf::Vector2f(temp->getSize().x, temp->getSize().y));
	sprite.setTexture(temp);
	if (!isSuper)
	{
		pMaxHealth = 100;
	}else
	{
		pMaxHealth = health;
	}
	pPosition = position;
	sprite.setPosition(position);
	pTeam = team;
	pIsSuper = isSuper;
	pHealth = health;
	sight.setOrigin(pPosition);
	isAlive = true;
}

void Minion::draw (sf::RenderWindow &App)
{
	//Updates whether or not the minion is dead
	if (pHealth > 0)
	{
		isAlive = true;
	}else
	{
		isAlive = false;
	}

	//Only displays the minion if it's alive
	if (isAlive)
	{
		sprite.setPosition(pPosition);
		App.draw(sprite);
	}

}

int Minion::getHealth ()
{
	return pHealth;
}

void Minion::setHealth (int newHealth)
{
	pHealth = newHealth;
}

void Minion::offsetHealth (int offset)
{
	pHealth += offset;
}


void Minion::isSeeing (Champion championToTarget)
{
	float angle;
	sight.setOrigin(pPosition);

	if (isAlive)
	{
		if (pTeam != championToTarget.getTeam() /*&& sight.getGlobalBounds().intersects(championToTarget.sprite.getGlobalBounds())*/) // <-- Those arguments might be able to remain commented.
		{
			angle = (atan2(pPosition.y - championToTarget.getPosition().y, pPosition.x - championToTarget.getPosition().x) - 3.14159);
			float x = (float)cos((double)angle)*6;
			float y = (float)sin((double)angle)*6;
			sprite.move(x,y);
			pPosition = sprite.getPosition();
		}
	}

}


