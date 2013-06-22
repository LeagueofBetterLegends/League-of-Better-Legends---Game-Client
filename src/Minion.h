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

	int priority;

	bool isVisible;

	Minion (sf::Vector2f position, int team, bool isSuper, int health);

	Minion (int team);

	void draw (sf::RenderWindow &App);

	int getHealth ();

	void setHealth (int newHealth);

	void offsetHealth (int offset);

	void isSeeing (Champion championToTarget); //Not descriptive

	sf::RectangleShape sprite, destination;

	sf::Vector2f pPosition;

	sf::CircleShape sight;

	std::vector<sf::Vector2f>* path;

private:

int pTeam;
bool pIsSuper, isAlive;
int pHealth, curPath;

private:

};


#endif /* MINION_H_ */
