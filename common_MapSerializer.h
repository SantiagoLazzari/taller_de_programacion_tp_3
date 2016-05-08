/*
 * MapSerializer.h
 *
 *  Created on: May 8, 2016
 *      Author: santi
 */

#ifndef COMMON_MAPSERIALIZER_H_
#define COMMON_MAPSERIALIZER_H_

#include "common_Map.h"
#include <string>

class MapSerializer {
public:
	MapSerializer(Map *aMap);
	MapSerializer();
	virtual ~MapSerializer();

	std::string serialize();

private:
	Map *map;
};

#endif /* COMMON_MAPSERIALIZER_H_ */
