/*
 * Minimap.h
 *
 *  Created on: May 14, 2013
 *      Author: User
 */

#ifndef MINIMAP_H_
#define MINIMAP_H_

#include <SFML/Graphics.hpp>
#include <iostream>

class Minimap
{
public:

	Minimap (bool openFile); // To be reserved for declaring minimaps that use saved settings - in "minimap.txt"

	Minimap (sf::Vector2f Position, sf::Texture &sTexture, sf::Vector2f scale);

	Minimap (sf::Vector2f Position, sf::Texture &sTexture, float scaleX, float scaleY);

	void addIcon (sf::Texture *icon, sf::Vector2f Position);

	void addIcons (std::vector<sf::Texture*> icon, std::vector<sf::Vector2f> Position);

	void setPosition (sf::Vector2f passedPosition);

	void setPosition (sf::RenderWindow &App, sf::View game);

	sf::Vector2f getPosition ();

	sf::Vector2f clickedOn (sf::Vector2f mousePosition);

	void draw (sf::RenderWindow &App);

private:
std::vector<sf::Vector2f> positions;
std::vector<sf::CircleShape> icons;
sf::Vector2f position;
sf::Texture pTexture;
std::string fileName;
sf::Vector2f pScale;
sf::Sprite sMinimap;

};

#endif /* MINIMAP_H_ */
