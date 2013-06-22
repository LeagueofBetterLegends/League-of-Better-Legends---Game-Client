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

Minion::Minion(int team)
{
	sf::Texture* temp = new sf::Texture;
	sf::Image iTemp;

	util convert;

	settingsBase dif ("2.txt");

	path = new std::vector<sf::Vector2f>;

	sf::Vector2f tempPos (0,0);

	dif.getVecFloatSetting(path);

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

	destination.setSize(sf::Vector2f(6,6));

	pPosition = path->at(0);
	pTeam = team;
	pHealth = 4;
	pIsSuper = false; isVisible = true;
	sight.setOrigin(pPosition);
	isAlive = true;
	pMaxHealth = 100;
	priority = 1; curPath = 1;

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
	if (isAlive && isVisible)
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
		if (priority != 1)
		{
			if (pTeam != championToTarget.getTeam() /*&& sight.getGlobalBounds().intersects(championToTarget.sprite.getGlobalBounds())*/) // <-- Those arguments might be able to remain commented.
			{
				angle = (atan2(pPosition.y - championToTarget.getPosition().y, pPosition.x - championToTarget.getPosition().x) - 3.14159);
				float x = (float)cos((double)angle)*6;
				float y = (float)sin((double)angle)*6;
				sprite.move(x,y);
				pPosition = sprite.getPosition();
			}
		}else
		{
			destination.setOrigin(path->at(curPath));

			if (curPath < path->size())
			{
				angle = (atan2(pPosition.y - path->at(curPath).y, pPosition.x - path->at(curPath).x) - 3.14159);
				float x = (float)cos((double)angle)*6;
				float y = (float)sin((double)angle)*6;
				sprite.move(x,y);
				pPosition = sprite.getPosition();
				if (destination.getGlobalBounds().intersects(sprite.getGlobalBounds()))
				{
					destination.setOrigin(path->at(curPath+1));
					curPath++;
				}
			}
		}
	}
}
