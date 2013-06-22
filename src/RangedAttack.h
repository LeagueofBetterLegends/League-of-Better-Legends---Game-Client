/*
 * RangedAttack.h
 *
 *  Created on: Jun 15, 2013
 *      Author: User
 */

#ifndef RANGEDATTACK_H_
#define RANGEDATTACK_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class RangeAttack
{
public:

	RangeAttack (sf::Vector2f position, sf::Vector2f destination);

	RangeAttack (sf::Vector2f position, sf::Vector2f destination, std::string texture, float damage, float speed);

	sf::Sprite* isInContact (std::vector<sf::Sprite*> hitboxes);

	void draw (sf::RenderWindow &App);

	sf::RectangleShape rectPlayer, rectDes;

	float damage, speed;

	bool moving;
};
#endif /* RANGEDATTACK_H_ */
