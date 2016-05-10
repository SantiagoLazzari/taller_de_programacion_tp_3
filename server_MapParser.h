/*
 * MapParser.h
 *
 *  Created on: May 8, 2016
 *      Author: santi
 */

#ifndef SERVER_MAPPARSER_H_
#define SERVER_MAPPARSER_H_

#include <string>
#include "common_Map.h"

class MapParser {
public:
	MapParser(std::string aMapAsString);
	MapParser();
	virtual ~MapParser();
	void parse(Map *aMap);

private:
	std::string mapAsString;
};

#endif /* SERVER_MAPPARSER_H_ */
