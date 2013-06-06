/*
 * fillBar.h
 *
 *  Created on: May 29, 2013
 *      Author: User
 */

#ifndef FILLBAR_H_
#define FILLBAR_H_

#include <SFML/Graphics.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Minion.h"

class FillBar
{
public:

	sf::RectangleShape sprite;
	sf::RectangleShape health;

	//Minion &tempMinion;

	FillBar (Minion &minion);

	void update (Minion &minion);

	void draw (sf::RenderWindow &App);
private:
	bool isAlive;
};


#endif /* FILLBAR_H_ */
