/*
 * RangeAttack.cpp
 *
 *  Created on: Jun 15, 2013
 *      Author: User
 */

#include "RangedAttack.h"

RangeAttack::RangeAttack (sf::Vector2f position, sf::Vector2f destination)
{
	rectDes.setSize(sf::Vector2f(5,5));
	rectDes.setPosition(destination);

	sf::Texture* temp = new sf::Texture;
	temp->loadFromFile("Player/RA.png");

	rectPlayer.setTexture(temp);
	rectPlayer.setSize(sf::Vector2f(temp->getSize().x, temp->getSize().y));
	rectPlayer.setPosition(position);

	damage = 1; speed = 6;

	moving = true;
}

RangeAttack::RangeAttack (sf::Vector2f position, sf::Vector2f destination, std::string texture, float damage, float speed)
{
	rectDes.setPosition(destination);

	sf::Texture* temp = new sf::Texture;
	temp->loadFromFile(texture);

	rectPlayer.setTexture(temp);
	rectPlayer.setSize(sf::Vector2f(temp->getSize())); //From the size gotten from the cursor.png the texture is being loaded.
	rectPlayer.setPosition(position); //setPosition is the function I want. Origin has vastly different results. Check the documentation

	std::cout << position.x << ", " << position.y << "\n";

	this->damage = damage;
	this->speed = speed;

	this->damage = damage;
	this->speed = speed;

	moving = true;
}

sf::Sprite* RangeAttack::isInContact (std::vector<sf::Sprite*> hitboxes)
{
	for (unsigned int i = 0; i < hitboxes.size(); i++)
	{
		if (rectPlayer.getGlobalBounds().intersects(hitboxes.at(i)->getGlobalBounds()))
		{
			return hitboxes.at(i);
		}
	}

	return false;
}

void RangeAttack::draw(sf::RenderWindow &App)
{
	if (moving && !rectPlayer.getGlobalBounds().intersects(rectDes.getGlobalBounds())) //Why is this argument always returning true?
	{
		float angle;
		angle = (atan2(rectPlayer.getPosition().y - rectDes.getPosition().y, rectPlayer.getPosition().x - rectDes.getPosition().x) - 3.14159);
		float x = (float)cos((double)angle)*speed;
		float y = (float)sin((double)angle)*speed;
		rectPlayer.move(x,y);
		App.draw(rectPlayer);
	}else
	{
		std::cout << "moving is false";
		moving = false;
	}
}
