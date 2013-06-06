/*
 * fillBar.cpp
 *
 *  Created on: May 29, 2013
 *      Author: User
 */

#include "FillBar.h"

FillBar::FillBar (Minion &minion)
{
	sf::Texture* temp = new sf::Texture;
	temp->loadFromFile("hp.png");
	sprite.setTexture(temp);
	sprite.setSize(sf::Vector2f(temp->getSize().x, temp->getSize().y));
	sprite.setPosition(sf::Vector2f(minion.sprite.getPosition().x, minion.sprite.getPosition().y+ 40));

	health.setSize(sf::Vector2f(temp->getSize().x-1, temp->getSize().y-2));
	health.setPosition(sprite.getPosition().x+1, sprite.getPosition().y+1);
	health.setFillColor(sf::Color::Green);

	if (minion.getHealth() > 0)
	{
		isAlive = true;
	}else
	{
		isAlive = false;
	}
}

void FillBar::update (Minion &minion)
{
	sprite.setPosition(sf::Vector2f(minion.sprite.getPosition().x, minion.sprite.getPosition().y- 15));
	health.setSize(sf::Vector2f(49 - (minion.pMaxHealth /2 - minion.getHealth()/2), health.getSize().y));
	health.setPosition(sprite.getPosition().x+1, sprite.getPosition().y+1);
	if (minion.getHealth() > 0)
	{
		isAlive = true;
	}else
	{
		isAlive = false;
	}

}

void FillBar::draw (sf::RenderWindow &App)
{
	if (isAlive)
	{
		App.draw(sprite);
		App.draw(health);
	}
}



