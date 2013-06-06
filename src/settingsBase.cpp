#include "settingsBase.h"

settingsBase::settingsBase (std::string settingsFile)
{
	pSettingsFile.setFileName(settingsFile);
}

std::string settingsBase::getStringSetting (std::string toFind)
{
	pSettingsFile.read();
	std::string line;
	size_t found;
	std::string toReturn = "NULL";
	for (unsigned int i = 0; i < pSettingsFile.getLength(); i++)
	{
		line = pSettingsFile.getLine(i);
		found = line.find (toFind);
		if (found != std::string::npos)
		{
			toReturn = line.substr(found +10, line.length());
		}
	}

	return toReturn;
}

int settingsBase::getIntSetting (std::string toFind)
{
	pSettingsFile.read();
	std::string line;
	size_t found;
	int toReturn = 0;
	for (unsigned int i = 0; i < pSettingsFile.getLength(); i++)
	{
		line = pSettingsFile.getLine(i);
		found = line.find (toFind);
		if (found != std::string::npos)
		{
			util convert;
			std::string temp;
			temp =	line.substr(found +2, line.length());
			toReturn = convert.stringToInt(temp);
		}
	}

	return toReturn;
}

sf::Vector2f settingsBase::getVecFloatSetting (std::string toFind)
{
	pSettingsFile.read();
	std::string line;
	size_t found;
	sf::Vector2f toReturn (0,0);

	for (unsigned int i = 0; i < pSettingsFile.getLength(); i++)
	{
		line = pSettingsFile.getLine(i);
		found = line.find (toFind); //TODO move this out of the for loop. It'd make me sleep easier.
		if (found != std::string::npos)
		{
			util convert;
			std::string temp;
			temp = line.substr(found +2, line.length()); //The +2 is to assume that the passed settings is followed by a ": ";
			found = line.find ("|");
			if (found != std::string::npos)
			{
				std::string temp;
				temp = line.substr(toFind.length()+1, found);
				toReturn.x = convert.stringToInt(temp);
				temp = line.substr(found+1, line.length());
				toReturn.y = convert.stringToInt(temp);
			}
		}
	}

	return toReturn;
}

bool settingsBase::getBoolSetting (std::string toFind)
{
	pSettingsFile.read();
	std::string line;
	bool toReturn = true;
	size_t found;
	std::string toMakeBool;
	for (unsigned int i = 0; i < pSettingsFile.getLength(); i++)
	{
		line = pSettingsFile.getLine(i);
		found = line.find (toFind);
		if (found != std::string::npos)
		{
			std::cout << toMakeBool;
			toMakeBool = line.substr(found +2, line.length());
		}

		if (toMakeBool == "true" || toMakeBool == "True" || toMakeBool == "t" || toMakeBool == "T")
		{
			toReturn = true;
		}
	}

	return toReturn;
}
