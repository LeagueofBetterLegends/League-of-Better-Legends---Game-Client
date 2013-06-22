/*
 * Container.cpp
 *
 *  Created on: Jun 5, 2013
 *      Author: User
 */

#include "Container.h"


Container::Container()
{
	for (unsigned int i = 0; i < 3; i++)
	{
		toDraw.push_back(0);
	}
}

/* A very poor means of checking whether or not the contents of the vector should be drawn.*/
void Container::add(Minion passedMinion)
{
	if (toDraw[0] != 1)
	{
		toDraw[0] = 1;
	}

	contMinions.push_back(passedMinion);
}

void Container::add(Champion passedChampion)
{
	if (toDraw[1] != 1)
	{
		toDraw[1] = 1;
	}

	contChampions.push_back(passedChampion);
}

void Container::add(RangeAttack passedRangeAttack)
{
	if (toDraw[2] != 1)
	{
		toDraw[2] = 1;
	}

	contRangeAttacks.push_back(passedRangeAttack);
}

void Container::draw(sf::RenderWindow &App)
{
	for (unsigned int i = 0; i < toDraw.size(); i++)
	{
		if (toDraw[0] == 1)
		{
			for (unsigned int i = 0; i < contMinions.size(); i++)
			{
				contMinions[i].draw(App);
			}
		}else if (toDraw[1] == 1)
		{
			for (unsigned int i = 0; i < contChampions.size(); i++)
			{
				contChampions[i].draw(App);
			}

		}else if (toDraw[2] == 1)
		{
			for (unsigned int i = 0; i < contRangeAttacks.size(); i++)
			{
				contRangeAttacks[i].draw(App);
			}

		}
	}
}
