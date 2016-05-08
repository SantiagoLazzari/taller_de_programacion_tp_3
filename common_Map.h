/*
 * Map.h
 *
 *  Created on: May 7, 2016
 *      Author: santi
 */

#ifndef COMMON_MAP_H_
#define COMMON_MAP_H_

#include <string>

class Map {
public:
	Map(int aKey, std::pair<std::string, int>aValue);
	Map();
	virtual ~Map();
	void setKeyWithValue(int aKey, std::pair<std::string, int>aValue);
	int getKey();
	std::pair<std::string, int> getValue();

private:
	int key;
	std::pair<std::string, int> value;

};

#endif /* COMMON_MAP_H_ */
