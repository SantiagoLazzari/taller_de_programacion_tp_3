/*
 * client.cpp


 *
 *  Created on: May 7, 2016
 *      Author: santi
 */

#include <stdlib.h>
#include <syslog.h>
#include <string>
#include <iostream>

#include "client_Client.h"

#define IP_ARGUMENT argv[1]
#define PORT_ARGUMENT argv[2]


int main(int argc, char *argv[]){
	if (argc != 3){
		return 1;
	}

	std::string ip = IP_ARGUMENT;
	std::string port = PORT_ARGUMENT;

	std::cout<<"ip : "<<ip<<", port : "<<port<<std::endl;
	Client client(ip, port);
	client.begin();

	std::cout<<"Entre al main del client"<<std::endl;

	return 0;
}

