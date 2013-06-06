#include "settingsBase.h"
#include "utility/file.h"
#include <SFML/Graphics.hpp>



class settings
{
public:
	settings (std::string sFileName);

	sf::Vector2i getResolution ();

	bool getFullScreen ();



	//void reload (); Don't really know if this was to serve any real use

	//void save ();

	//void save (std::string newFile);

	~settings ();



	File fSettings;
private:
	std::vector<std::string> pSettings;
};
