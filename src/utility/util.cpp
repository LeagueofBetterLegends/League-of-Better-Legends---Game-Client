#include "util.h"
#include <sstream>

util::util()
{
}

std::string util::intToString (int toConvert)
{
	std::stringstream convert;
	convert << toConvert;
	std::string toReturn;
	convert >> toReturn;
	return toReturn;
}


int util::stringToInt (std::string toConvert)
{
	std::stringstream convert (toConvert);
	int toReturn;
	convert >> toReturn;
	return toReturn;
}
