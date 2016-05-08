/*
 * MapInputParser.h
 *
 *  Created on: May 7, 2016
 *      Author: santi
 */

#ifndef CLIENT_MAPINPUTPARSER_H_
#define CLIENT_MAPINPUTPARSER_H_

#include "common_Map.h"

class MapInputParser {
public:
	MapInputParser(std::string inputMapString);
	MapInputParser();
	virtual ~MapInputParser();

	void parse(Map *map);

private:
	std::string inputString;
};

#endif /* CLIENT_MAPINPUTPARSER_H_ */
