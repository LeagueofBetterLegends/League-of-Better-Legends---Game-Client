#include <iostream>
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <math.h>

#include "settings.h"
#include "Minimap.h"
#include "Champion.h"
#include "Minion.h"
#include "timer.h"
#include "FillBar.h"

int main ()
{
	/* Application Initilization*/
	settings settings ("settings.txt"); // Load the settings configuration

	sf::RenderWindow App (sf::VideoMode((int)settings.getResolution().x, (int)settings.getResolution().y, 32), "League of Better Legends - Game Client v.Test", sf::Style::Fullscreen);

	if (settings.getFullScreen()) // By default this enables fullscreen (with the provided resolution from settings.txt)
	{
		App.create(sf::VideoMode((int)settings.getResolution().x, (int)settings.getResolution().y, 32), "League of Better Legends - Game Client v.Test" , sf::Style::Fullscreen);
	}

	settingsBase sb ("settings.txt");
	std::string championName = sb.getStringSetting("Champion");


	float angle, factorX, factorY;
	sf::RectangleShape target (sf::Vector2f(5,5));
	target.setFillColor(sf::Color::Black);

	/* Cursor Initilization */
	App.setMouseCursorVisible(true);
	sf::Texture cursor; cursor.loadFromFile("cursor.png");
	sf::Sprite sCursor; sCursor.setTexture(cursor);

	/* Map and Minimap Initilization */
	sf::Texture map; sf::Texture *test = new sf::Texture;
	test->loadFromFile("Treeline.png");
	map.loadFromFile("Treeline.png");
	sf::Sprite sMap; sMap.setTexture(map);
	sf::Vector2f position (0,0);
	sMap.setScale(1 ,1);

	/* Minimap Initilization. Not currently used */
	Minimap mini (position,  map, sf::Vector2f(.125,.125));

	/* Player Initilization */
	Champion masterYi (championName, 2, 12, 0.5, 0.5); masterYi.sprite.setPosition(1024, 534);

	sf::RectangleShape playerBox (sf::Vector2f(100,100));

	sf::View game (sf::FloatRect(1024, 534, 800, 600));
	game.setCenter(masterYi.getPosition());

	/*Random Garbage*/
	bool modifier = 0;
	bool moving = false;
	bool screenLock = true;
	float destinationX = masterYi.getPosition().x; float destinationY = masterYi.getPosition().y;
	factorX = game.getSize().x/App.getSize().x; factorY = game.getSize().y/App.getSize().y;
	bool inFocus = false;
	bool soundEnabled = true;
	int minionTeam = 2;
	//sf::Sound sound;
	std::vector<Minion> lMinions; std::vector<FillBar> lFillBars;

 	while (App.isOpen())
	{
 		playerBox.setPosition(masterYi.getPosition());
 		sf::Event event;
		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				App.close();
			}
			if (event.type == sf::Event::LostFocus)
			{
				inFocus = false;
			}else if (event.type == sf::Event::GainedFocus)
			{
				inFocus = true;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			destinationX = sf::Mouse::getPosition(App).x; destinationY = sf::Mouse::getPosition(App).y;
			angle = (atan2(masterYi.getPosition().y - destinationY, masterYi.getPosition().x - destinationX) - 3.14159);
			target.setPosition(destinationX, destinationY);
			moving = true;

			if (soundEnabled)
			{
				if(minionTeam == 1)
				{
					//sound.setBuffer(masterYi.move1);
				}else if (minionTeam == 2)
				{
					//sound.setBuffer(masterYi.move2);
				}
				//sound.play();
			}

		}else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) /*&& sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)*/)
		{
			Minion* newMinion = new Minion (sCursor.getPosition(), minionTeam);
			lMinions.push_back(*newMinion);
			FillBar* newFillBar = new FillBar (*newMinion);
			lFillBars.push_back(*newFillBar);

		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		{
			minionTeam = 1;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			minionTeam = 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			if (screenLock)
			{
				screenLock = false;
			}else
			{
				screenLock = true;
			}
			sf::sleep(sf::seconds(.01));
		}
		if (moving && !target.getGlobalBounds().intersects(playerBox.getGlobalBounds()))
		{
			float x = (float)cos((double)angle)*(masterYi.getMovementSpeed()+modifier);//The multiplication is to imply the movement speed.
			float y = (float)sin((double)angle)*(masterYi.getMovementSpeed()+modifier);
			sf::Vector2f temp (x,y);
			if (destinationY > masterYi.getPosition().y)
			{
				if (masterYi.getState() == 1)
				{
					masterYi.setState(2); //Value must be 1-4
				}else
				{
					masterYi.setState(1);
				}
			}else
			{
				if (masterYi.getState() == 3)
				{
					masterYi.setState(4);
				}else
				{
					masterYi.setState(3);
				}
			}
		masterYi.move(temp);
		}else
		{
			moving = false;
		}

		if (screenLock)
		{
			game.setCenter(masterYi.getPosition());
		}

		App.setView(game);
		mini.setPosition(sf::Vector2f(game.getCenter().x + 200, game.getCenter().y + 100));

		sCursor.setPosition(sf::Mouse::getPosition(App).x , sf::Mouse::getPosition(App).y);
		App.clear(sf::Color(255,255,255));
		App.draw(sMap);
		mini.draw(App);
		masterYi.draw(App);

		for (unsigned int i = 0; i < lMinions.size(); i++)
		{
			lMinions[i].isSeeing(masterYi);
			lFillBars[i].update(lMinions[i]);
			if (lMinions[i].getHealth() < 99)
			{
				lMinions[i].offsetHealth(1);
			}

			lFillBars[i].draw(App);
			lMinions[i].draw(App);
		}
		App.draw(sCursor);
		App.display();
		sf::sleep(sf::seconds(0.05));
	}
}
