/*
 * Container.cpp
 *
 *  Created on: Jun 5, 2013
 *      Author: User
 */

#include "Container.h"


Container::Container()
{
}

Container::Container(Container passedContainer)
{
}

Container::Container(Minion passedMinion)
{
}

void Container::add(Minion passedMinion)
{
	contMinions.push_back(passedMinion);
}

void Container::draw(sf::RenderWindow &App)
{
	for (unsigned int i = 0; i < contMinions.size(); i++)
	{
		contMinions[i].draw(App);
	}
}
