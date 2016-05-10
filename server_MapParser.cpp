/*
 * MapParser.cpp
 *
 *  Created on: May 8, 2016
 *      Author: santi
 */

#include "server_MapParser.h"

#include <stdlib.h>
#include <sstream>
#include <iostream>


MapParser::MapParser(std::string aMapAsString) {
	mapAsString = aMapAsString;
}

MapParser::MapParser() {
	// TODO Auto-generated constructor stub

}

MapParser::~MapParser() {
	// TODO Auto-generated destructor stub
}

void MapParser::parse(Map *aMap) {
	std::string city,temperature, day;

	std::stringstream stream;
	stream.str(mapAsString);

	stream >> day;
	stream >> temperature;
	stream >> city;

	//std::cout<<"city : "<<city<<" temperature : "<<temperature<<" day : "<<day<<std::endl;

	aMap->setKeyWithValue(atoi(day.c_str()), std::pair<std::string, int>(city, atoi(temperature.c_str())));
}
