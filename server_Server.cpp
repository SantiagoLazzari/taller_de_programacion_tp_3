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
#define MAX_BUFFER_SIZE 64
#define STOP_RECEIVING_CONDITION "End\n"
#define STOP_LISTENING_KEY "q"

Server::Server(const std::string& port) {
	this->socket = new Socket(DEFAULT_IP, port.c_str());
}

Server::Server() {
}

Server::~Server() {
}

void receiveFromClient(std::string& incomingData, Socket socket) {
	bool keepReceiving = true;
	// Done workaround of size + 1 to avoid valgrind error
	char buffer[MAX_BUFFER_SIZE + 1];
	buffer[MAX_BUFFER_SIZE] = 0;
	while (keepReceiving) {
		memset(&buffer[0], 0, sizeof(buffer));
		if (socket.receive(&buffer[0], MAX_BUFFER_SIZE) == -1) {
			keepReceiving = false;
		} else {
			incomingData += buffer;

			std::cout<<incomingData<<std::endl;
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

void Server::begin() {
	beginAccepting();

	std::cout<<"Server begin"<<std::endl;
}

void Server::beginAccepting() {
	std::string input;

	AcceptThread acceptThread = AcceptThread(this->socket);

	acceptThread.start();

	while (std::getline(std::cin, input)) {
		if (input == STOP_LISTENING_KEY) {
			std::cout<<"Listening"<<std::endl;
			acceptThread.endAccepting();
			break;
		}
	}

	acceptThread.join();
}

