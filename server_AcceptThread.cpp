/*
 * AcceptThread.cpp
 *
 *  Created on: May 8, 2016
 *      Author: santi
 */

#include "server_AcceptThread.h"

#include "common_Socket.h"
#include <iostream>
#include <vector>

#define MAX_LISTEN_QUEUE_SIZE 128


AcceptThread::AcceptThread(Socket *acceptSocket) {
	socket = acceptSocket;
	acceptSocket->bind();
	acceptSocket->listen(MAX_LISTEN_QUEUE_SIZE);
	endAcceptingClients = false;

	clients = new std::vector<Socket *>();
}

AcceptThread::AcceptThread() {
}

AcceptThread::~AcceptThread() {
	for(std::vector<Socket *>::iterator it = clients->begin(); it != clients->end(); ++it) {
	    delete (*it);
	}

	delete clients;
}

void AcceptThread::run() {
	while(endAcceptingClients == false) {
		Socket *client = new Socket();

		socket->accept(client);

		if (endAcceptingClients) {
			continue;
		}

		std::cout<<"Accept connection" << std::endl;



		clients->push_back(client);

	}
}

void AcceptThread::endAccepting() {
	endAcceptingClients = true;

	delete socket;
}
