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


AcceptThread::AcceptThread(Socket *acceptSocket, ThreadSafeHashMap *aThreadSafeMap) {
	socket = acceptSocket;
	acceptSocket->bind();
	acceptSocket->listen(MAX_LISTEN_QUEUE_SIZE);

	threadSafeMap = aThreadSafeMap;

	endAcceptingClients = false;

	clients = new std::vector<Socket *>();
	reducers = new std::vector<ReducerThread *>();
}

AcceptThread::AcceptThread() {
}

AcceptThread::~AcceptThread() {
	for(std::vector<Socket *>::iterator it = clients->begin(); it != clients->end(); ++it) {
	    delete (*it);
	}

	clients->clear();

	for(std::vector<ReducerThread *>::iterator it = reducers->begin(); it != reducers->end(); ++it) {
		delete (*it);
	}

	reducers->clear();

	delete reducers;
	delete clients;
}

void AcceptThread::run() {
	while(endAcceptingClients == false) {
		Socket *client = new Socket();

		socket->accept(client);
		clients->push_back(client);

		if (endAcceptingClients) {
			continue;
		}

		ReducerThread *reducerThread = new ReducerThread(client, threadSafeMap);
		reducers->push_back(reducerThread);

		reducerThread->start();
	}

	joinReducers();
}

void AcceptThread::joinReducers() {
	for(std::vector<ReducerThread *>::iterator it = reducers->begin(); it != reducers->end(); ++it) {
		    (*it)->join();
	}
}

void AcceptThread::endAccepting() {
	endAcceptingClients = true;

	delete socket;
}
