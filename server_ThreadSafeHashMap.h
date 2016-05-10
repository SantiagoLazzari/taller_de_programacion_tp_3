/*
 * ThreadSafeHashMap.h
 *
 *  Created on: May 8, 2016
 *      Author: santi
 */

#ifndef SERVER_THREADSAFEHASHMAP_H_
#define SERVER_THREADSAFEHASHMAP_H_

#include "common_Mutex.h"
#include "common_Map.h"
#include <map>
#include <vector>
#include <string>

class ThreadSafeHashMap {
public:
	ThreadSafeHashMap();
	virtual ~ThreadSafeHashMap();
	void setMap(Map *aMap);

	void description();
private:
	//To make it thread safe
	Mutex mutex;

	//This map is a Max map, this means that will only save
	//the max value (in this case temperature of a Map object)
	std::map<int, std::vector<Map *> > threadSafeMap;

	//Get cities from a list of maps
	void vectorOfCitiesWithVectorOfMapsAtKey(int key, std::vector<std::string> *aVector);

	//Map Thread garbaje
	std::vector<Map *> maps;

};

#endif /* SERVER_THREADSAFEHASHMAP_H_ */
