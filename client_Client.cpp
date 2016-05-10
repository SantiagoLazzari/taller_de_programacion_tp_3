/*
 * Client.cpp
 *
 *  Created on: May 7, 2016
 *      Author: santi
 */

#include <iostream>
#include "client_Client.h"
#include <sstream>
#include "common_Map.h"
#include "client_MapInputParser.h"
#include "common_MapSerializer.h"

Client::Client(const std::string &ip, const std::string& port) {
	this->socket = new Socket(ip.c_str(), port.c_str());
}

Client::Client() {
	// TODO Auto-generated constructor stub
}

Client::~Client() {
	delete this->socket;
}

void Client::begin() {
	socket->connect();

	std::string input;

	while (std::getline(std::cin, input)) {
		//If there is an empty line program must
		//jump to next line
		if (input.compare("") == 0)
			continue;

		Map *map = new Map();
		MapInputParser parser(input);
		parser.parse(map);
		MapSerializer serializer(map);

		std::string sendString(serializer.serialize());
		socket->send((char *)sendString.c_str(), sendString.length());
		std::cout<<sendString<<std::endl;

		delete map;
	}

	std::string end = "End\n";

	socket->send((char *)end.c_str(), end.length());
}

