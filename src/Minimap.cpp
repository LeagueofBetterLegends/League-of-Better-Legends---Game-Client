/*
 * Minimap.cpp
 *
 *  Created on: May 14, 2013
 *      Author: User
 */

#include "Minimap.h"
#include "settingsBase.h"

Minimap::Minimap (bool openFile) // This doesn't seem to work.
{
	if (openFile)
	{
		settingsBase sb ("minimap.txt");
		position = sb.getVecFloatSetting ("Position");

		pScale = sb.getVecFloatSetting("Scale");
		//fileName = sb.getStringSetting ("Image");
		fileName = "Treeline.png";
		sf::Image temp; temp.loadFromFile(fileName);
		temp.createMaskFromColor(temp.getPixel(0,0));
		pTexture.loadFromImage(temp);
		sMinimap.setTexture(pTexture);
		sMinimap.scale(pScale);
	}
	{
		pTexture.loadFromFile("Treeline.png");
		pScale.x = .125; pScale.y = .125;
		position.x = pTexture.getSize().x/pScale.x;
		position.y = pTexture.getSize().y/pScale.y;

	}
}

Minimap::Minimap (sf::Vector2f Position, sf::Texture &sTexture,  sf::Vector2f scale) //So is this
{
	position.x = Position.x;
	position.y = Position.y;
	//pPrivate.setTexture() // <-- That setTexture is super useful.
	pTexture = sTexture;
	pScale = scale;
	sMinimap.setTexture(pTexture);
	sMinimap.scale(pScale);
}

Minimap::Minimap (sf::Vector2f Position, sf::Texture &sTexture, float scaleX, float scaleY)
{
	position.x = Position.x;
	position.y = Position.y;
	//pPrivate.setTexture() // <-- That setTexture is super useful.
	pTexture = sTexture;
	pScale.x = scaleX; pScale.y = scaleY;
	sMinimap.setTexture(pTexture);
	sMinimap.scale(pScale);
}

sf::Vector2f Minimap::clickedOn (sf::Vector2f mousePosition) // This is for when you click the minimap. And shit.
{
	sf::Vector2f toReturn (0,0);
	toReturn.x = mousePosition.x * pScale.x; toReturn.y = mousePosition.y * pScale.y;
	return toReturn;
}

void Minimap::setPosition (sf::Vector2f passedPosition)
{
	if ((pTexture.getSize().x > passedPosition.x) || (pTexture.getSize().y > passedPosition.y))
	{
		position.x = position.x / pScale.x;
		position.y = position.y / pScale.y;
	}else
	{
		position = passedPosition;
	}
}

void Minimap::setPosition (sf::RenderWindow &App, sf::View game)
{
	position.x = game.getCenter().x*2 - 200;
	position.y = game.getCenter().y;
	//position.x = pTexture.getSize().x - App.getSize().x * pScale.x;
	//position.y = pTexture.getSize().y + App.getSize().y * pScale.y;

}

void Minimap::addIcon (sf::Texture *icon, sf::Vector2f Position)
{
	sf::CircleShape pIcon;
	pIcon.setTexture(icon, false);
	icons.push_back(pIcon);
	positions.push_back(Position);
}

void Minimap::addIcons (std::vector<sf::Texture*> icon, std::vector<sf::Vector2f> Position)
{
	sf::CircleShape pIcon;
	for (unsigned int i = 0; i < icon.size(); i++)
	{
		pIcon.setTexture(icon[i], false);
		icons.push_back(pIcon);
		positions.push_back(Position[i]);
	}
}

sf::Vector2f Minimap::getPosition ()
{
	sf::Vector2f toReturn;
	toReturn = position;
	return toReturn;
}
void Minimap::draw (sf::RenderWindow &App)
{
	sMinimap.setPosition(position);
	for (unsigned int i = 0; i < icons.size(); i++)
	{
		icons[i].setPosition (sMinimap.getPosition() + positions[i]);
		App.draw (icons[i]);
	}
	App.draw(sMinimap);
}

