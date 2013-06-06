/*
 * Turret.h
 *
 *  Created on: May 29, 2013
 *      Author: User
 */

#ifndef TURRET_H_
#define TURRET_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Turret
{
public:

	Turret (sf::Vector2f position, int team);

	void setTarget ();

	void fire ();

};


#endif /* TURRET_H_ */
