/*
 * ReducerThread.cpp
 *
 *  Created on: May 8, 2016
 *      Author: santi
 */

#include "server_ReducerThread.h"

#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "server_MapParser.h"
#include "common_Map.h"

#define MAX_BUFFER_SIZE 64
#define STOP_RECEIVING_CONDITION "End\n"

ReducerThread::ReducerThread(Socket *aSocket, ThreadSafeHashMap *aThreadSafeMap) {
	socket = aSocket;
	threadSafeMap = aThreadSafeMap;
}

ReducerThread::ReducerThread() {
}

ReducerThread::~ReducerThread() {
	// TODO Auto-generated destructor stub
}

void ReducerThread::receiveDataFromClient(std::string& incomingData) {
	bool keepReceiving = true;
	// Done workaround of size + 1 to avoid valgrind error
	char buffer[MAX_BUFFER_SIZE + 1];
	buffer[MAX_BUFFER_SIZE] = 0;
	while (keepReceiving) {
		memset(&buffer[0], 0, sizeof(buffer));
		if (socket->receive(&buffer[0], MAX_BUFFER_SIZE) == -1) {
			keepReceiving = false;
		} else {
			incomingData += buffer;
			// If we find an "End\n" client was done sending
			if (incomingData.find(STOP_RECEIVING_CONDITION)
					!= std::string::npos)
				keepReceiving = false;
		}
	}

	incomingData.erase(
			incomingData.length() - sizeof(STOP_RECEIVING_CONDITION) + 1,
			incomingData.length());

}


void ReducerThread::run() {
	std::string data;
	receiveDataFromClient(data);

	std::string input;
	std::stringstream stream(data);

	//Separate incoming data in lines this is not
	while (std::getline(stream, input)) {
		MapParser mapParser = MapParser(input);

		Map *map = new Map();
		mapParser.parse(map);

		threadSafeMap->setMap(map);
	}
}

