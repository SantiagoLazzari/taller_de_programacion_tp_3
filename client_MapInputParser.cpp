/*
 * MapInputParser.cpp
 *
 *  Created on: May 7, 2016
 *      Author: santi
 */

#include "client_MapInputParser.h"

#include "common_Map.h"
#include <sstream>
#include <stdlib.h>



MapInputParser::MapInputParser(std::string inputMapString) {
	inputString = inputMapString;
}


MapInputParser::MapInputParser() {
	// TODO Auto-generated constructor stub

}

MapInputParser::~MapInputParser() {
	// TODO Auto-generated destructor stub
}

void MapInputParser::parse(Map *map) {
	std::string city,temperature, day;

	std::stringstream input;
	input.str(inputString);

	input >> city;
	input>> temperature;
	input >> day;

	map->setKeyWithValue(atoi(day.c_str()), std::pair<std::string, int>(city, atoi(temperature.c_str())));
}


