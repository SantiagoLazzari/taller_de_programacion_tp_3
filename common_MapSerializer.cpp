/*
 * MapSerializer.cpp
 *
 *  Created on: May 8, 2016
 *      Author: santi
 */

#include "common_MapSerializer.h"

#include <string>
#include <sstream>

MapSerializer::MapSerializer(Map *aMap) {
	map = aMap;
}

MapSerializer::MapSerializer() {
	// TODO Auto-generated constructor stub

}

MapSerializer::~MapSerializer() {
	// TODO Auto-generated destructor stub
}

std::string MapSerializer::serialize() {
	std::stringstream serializedStream;

	serializedStream << map->getKey() << " " << map->getValue().second << " " << map->getValue().first << "\n";

	return serializedStream.str();
}

