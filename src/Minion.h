#/*
 * minion.h
 *
 *  Created on: May 28, 2013
 *      Author: User
 */

#ifndef MINION_H_
#define MINION_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Champion.h"

class Minion
{
public:

	int pMaxHealth;

	Minion (sf::Vector2f position, int team, bool isSuper, int health);

	Minion (sf::Vector2f position, int team);

	void draw (sf::RenderWindow &App);

	int getHealth ();

	void setHealth (int newHealth);

	void offsetHealth (int offset);

	void isSeeing (Champion championToTarget); //Not descriptive

	sf::RectangleShape sprite;

	sf::Vector2f pPosition;

	sf::CircleShape sight;

private:

int pTeam;
bool pIsSuper, isAlive;
int pHealth;

private:

};


#endif /* MINION_H_ */
