/*
 * Server.cpp
 *
 *  Created on: May 7, 2016
 *      Author: santi
 */

#include "server_Server.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server_AcceptThread.h"

#define DEFAULT_IP "127.0.0.1"
#define STOP_LISTENING_KEY "q"

Server::Server(const std::string& port) {
	socket = new Socket(DEFAULT_IP, port.c_str());
	threadSafeMap = new ThreadSafeHashMap();
}

Server::Server() {
}

Server::~Server() {
	delete threadSafeMap;
	//TODO: Delete thread safe map but no socket
}

void Server::begin() {
	beginAccepting();

	threadSafeMap->description();
}

//Will accept all connections to the server and
//will reduce theme (reduce implies that elements)
//will be added to the threadSaveHash
void Server::beginAccepting() {
	std::string input;

	AcceptThread acceptThread(socket, threadSafeMap);

	acceptThread.start();

	while (std::getline(std::cin, input)) {
		if (input == STOP_LISTENING_KEY) {
			acceptThread.endAccepting();
			break;
		}
	}

	acceptThread.join();
}
