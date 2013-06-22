#include <iostream>
#include <SFML/Graphics.hpp>
#include "utility/file.h"
#include "utility/util.h"

class settingsBase
{
public:

	settingsBase (std::string settingsFile);

	std::string getStringSetting (std::string toFind);

	int getIntSetting (std::string toFind);

	sf::Vector2f getVecFloatSetting (std::string toFind);

	void getVecFloatSetting (std::vector<sf::Vector2f>* toFill);

	bool getBoolSetting (std::string toFind);

	File pSettingsFile;

};
