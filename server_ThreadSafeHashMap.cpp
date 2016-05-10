/*
 * ThreadSafeHashMap.cpp
 *
 *  Created on: May 8, 2016
 *      Author: santi
 */

#include "server_ThreadSafeHashMap.h"

#include <map>
#include <vector>
#include "common_Lock.h"
#include <sstream>
#include <iostream>
#include <algorithm>

ThreadSafeHashMap::ThreadSafeHashMap() {
}

ThreadSafeHashMap::~ThreadSafeHashMap() {
	for(std::vector<Map *>::iterator it = maps.begin(); it != maps.end(); ++it) {
	    delete (*it);
	}

	maps.clear();
}

void ThreadSafeHashMap::setMap(Map *aMap) {
	Lock lock(mutex);

	//Add map and when object is destroyed then
	//destroy all maps
	maps.push_back(aMap);

	if (threadSafeMap[aMap->getKey()].size() > 0) {
		Map *firstElement = threadSafeMap[aMap->getKey()].front();

		int aMapTemperature = aMap->getValue().second;
		int firstElementTemperature = firstElement->getValue().second;

		//We have to clean the vector asociated and replace it
		//With a new map
		if (aMapTemperature > firstElementTemperature) {
			threadSafeMap[aMap->getKey()].clear();
			threadSafeMap[aMap->getKey()].push_back(aMap);
		}
		//We have to add this map to the vector becouse they are
		//tied with the other temperatures
		else if (aMapTemperature == firstElementTemperature) {
			//TODO : Check various cities
			threadSafeMap[aMap->getKey()].push_back(aMap);
		}
	//If map has no element then push it
	} else {
		threadSafeMap[aMap->getKey()].push_back(aMap);
	}
}



void ThreadSafeHashMap::description() {
	for (std::map<int, std::vector<Map *> >::iterator it=threadSafeMap.begin(); it!=threadSafeMap.end(); ++it) {
		std::stringstream stream;
		stream<<it->first<<": ";

		//Vector asociated to a specific day
		std::vector<Map *> mapsFromCurrentKey = it->second;

		//I just want days with inputs
		if (mapsFromCurrentKey.size() == 0)
			continue;

		Map *currentMap = mapsFromCurrentKey.front();

		//If there is more than one city with the same
		//temperature
		if (mapsFromCurrentKey.size() > 0) {
			std::vector<std::string> orderedCities;
			vectorOfCitiesWithVectorOfMapsAtKey(currentMap->getKey(), &orderedCities);

			std::string firstCity = (*orderedCities.begin());

			stream<<firstCity;

			for (std::vector<std::string>::iterator it = (++orderedCities.begin()) ; it != orderedCities.end(); ++it) {
				std::string currentCity = *it;
				stream<<"/"<<currentCity;
			}
			stream<<" ";
		} else {
			stream<<currentMap->getValue().first<<" ";

		}

		stream<<"("<<currentMap->getValue().second<<")\n";

		std::cout<<stream.str();
	}
}

void ThreadSafeHashMap::vectorOfCitiesWithVectorOfMapsAtKey(int key, std::vector<std::string> *aVector) {
	std::vector<Map *> mapsFromCurrentKey = threadSafeMap[key];

	for (std::vector<Map *>::iterator it = mapsFromCurrentKey.begin() ; it != mapsFromCurrentKey.end() ; ++it) {
		aVector->push_back((*it)->getValue().first);
	}

	sort(aVector->begin(), aVector->end());
}
