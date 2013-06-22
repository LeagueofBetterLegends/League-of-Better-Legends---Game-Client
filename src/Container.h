/*
 * Container.h
 *
 *  Created on: Jun 5, 2013
 *      Author: Charlie Miller
 *
 * Purpose:
 * This is a very poorly done idea of making a generic class that holds arbitrary objects.
 * It's already super specific, and not much dynamic. Although, it may very well make my main loop look prettier.
 *
 * Cheers
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Champion.h>
#include <RangedAttack.h>

#include "Minion.h"

class Container
{
public:

	Container ();

	//Container (Container &passedContainer);

	/* Container for Minion class */

	//Container (Minion passedMinion);

	void add (Minion passedMinion);

	void add (Champion passedChampion);

	void add (RangeAttack passedRangeAttack);

	Minion at (unsigned int passedPlacement); //Returns a specific Minion of the container

	void draw (sf::RenderWindow &App); // Generic drawing function that draws all loaded Minions in the container

	std::vector<Minion> contMinions; //toDraw placement is 1
	std::vector<Champion> contChampions; //toDraw placement is 2
	std::vector<RangeAttack> contRangeAttacks; //toDraw placement is 3

	std::vector<int> toDraw; //TODO Replace me with something that checks for the size of the above vectors.

	/* Next */

	void addContainer (Container passedContainer);


};


#endif /* CONTAINER_H_ */
