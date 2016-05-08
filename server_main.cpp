/*
 * server.cpp
 *
 *  Created on: May 7, 2016
 *      Author: santi
 */

#include <stdlib.h>
#include <syslog.h>
#include <string>
#include <iostream>
#include "server_Server.h"

#define PORT_ARGUMENT argv[1]

int main(int argc, char *argv[]){
	if (argc != 2){
		return 1;
	}

	std::string port = PORT_ARGUMENT;

	Server server(port);
	server.begin();

	return 0;
}



