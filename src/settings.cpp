#include "settings.h"

settings::settings(std::string sFileName)
{
	pSettings.push_back("Resolution"); pSettings.push_back("Fullscreen");
	//fSettings.setFileName(fileName);

}
sf::Vector2i settings::getResolution ()
{
	sf::Vector2i toReturn (0,0);
	settingsBase sbResolution ("settings.txt");
	float tempX, tempY;
	tempX = sbResolution.getVecFloatSetting(pSettings[0]).x;
	tempY = sbResolution.getVecFloatSetting(pSettings[0]).y;

	toReturn.x = tempX;
	toReturn.y = tempY;
	return toReturn;
}

bool settings::getFullScreen()
{
	bool toReturn = true;
	settingsBase sbFullScreen ("settings.txt");
	toReturn = sbFullScreen.getBoolSetting("FullScreen");
	std::cout << toReturn;
	return toReturn;
}


settings::~settings ()
{
}
