/*
 * Map.cpp
 *
 *  Created on: May 7, 2016
 *      Author: santi
 */

#include "common_Map.h"

#include <string>

Map::Map(int aKey, std::pair<std::string, int>aValue) {
	key = aKey;
	value = aValue;
}


Map::Map() {
	// TODO Auto-generated constructor stub

}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

void Map::setKeyWithValue(int aKey, std::pair<std::string, int>aValue) {
	key = aKey;
	value = aValue;
}

int Map::getKey() {
	return key;
}
std::pair<std::string, int> Map::getValue() {
	return value;
}


