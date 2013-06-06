/*
 * Container.h
 *
 *  Created on: Jun 5, 2013
 *      Author: User
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Minion.h"

class Container
{

	Container ();

	Container (Container passedContainer);

	/* Container for Minion class */

	Container (Minion passedMinion);

	void add (Minion passedMinion);

	Minion at (unsigned int passedPlacement); //Returns a specific Minion of the container

	void draw (sf::RenderWindow &App); // Generic drawing function that draws all loaded Minions in the container

	std::vector<Minion> contMinions;

	/* Next */

	Container ()

	void addContainer (Container passedContainer);


};


#endif /* CONTAINER_H_ */
