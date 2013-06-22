/*
 * Champion.h
 *
 *  Created on: May 16, 2013
 *      Author: User
 */

#ifndef CHAMPION_H_
#define CHAMPION_H_

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>

class Champion
{
public:

	sf::RectangleShape sprite;
	float movementSpeed;

	//sf::SoundBuffer move1;
	//sf::SoundBuffer move2;

	Champion ();

	Champion (std::string nameOf, int team, float movementSpeed, sf::Vector2f scale);

	Champion (std::string nameOf, int team, float movementSpeed, float scaleX, float scaleY);

	float getMovementSpeed ();

	void setState (int state);

	sf::Vector2f getPosition ();

	void move (sf::Vector2f position);

	void draw (sf::RenderWindow &App);

	int getState ();

	int getTeam ();

	void addAbility (); //Try to consider how this is gonna work?

	sf::Texture* forward1; sf::Texture* forward2;
	sf::Texture* backward1; sf::Texture* backward2;

private:

int pState;
int pTeam;
};


#endif /* CHAMPION_H_ */
